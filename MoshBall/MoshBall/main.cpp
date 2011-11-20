#define HOURS_SPENT 6+5+2+4+6

#import <OpenGL/OpenGL.h>
#import <GLUT/GLUT.h>
#include <cstdlib>
#include <math.h>
#include <time.h>
#include <iostream>

#include "Model.h"
#include "VectorLib/Vectors.h"

static double mouseX, mouseY;
static int height, width;

Player * player;
Arena * arena;
Ball ** balls;
Arrow * compass;

/*
 * HELPER FUNCTIONS
 */

double rangeRand(double start, double end)
{
    return ((rand()/(double)RAND_MAX)*(end-start))+start;
}








/*
 * DRAWING FUNCTIONS
 */

void drawBalls()
{
    for(int i = 0; i < NUM_BALLS; i++)
    {
        balls[i]->drawAtPosition();
    }
}

void drawCrosshair()
{
    glPushMatrix();
    glTranslated(player->pos[0], player->pos[1], player->pos[2]);
    
    //glCallList(playerList);
    glPopMatrix();
}

void renderSelf(bool withSelf)
{
    arena->draw();
    if(withSelf) player->drawAtPosition();
    else drawCrosshair();
    drawBalls();
    compass->draw();
}

void drawMain()
{
    glEnable(GL_LIGHTING);
    
    //Main Viewport
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0 , ((double) width) / ((double) height), 1.0f , 10000.0);
	glViewport(0 , 0 , width, height);
    
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    gluLookAt(player->pos[0], player->pos[1], player->pos[2], 
              player->pos[0]+player->dir[0], player->pos[1]+player->dir[1], player->pos[2]+player->dir[2], 
              0.0, 1.0, 0.0);
    
	//Aim Light
    GLfloat pos[4] = {player->pos[0], 10.0f, player->pos[2], 1.0f};
    glLightfv(GL_LIGHT1, GL_POSITION, pos);
    
	renderSelf(false);
}

void drawHud()
{
    glDisable(GL_LIGHTING);
    
    int hudLeft = 50;
    int hudBottom = 50;
    int hudWidth = width/3;
    int hudHeight = height/3;
    
    glEnable(GL_SCISSOR_TEST);
    glScissor(hudLeft, hudBottom, hudWidth, hudHeight);
    glClear(GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30, ((double) width) / ((double) height), 1.0f, 100000.0);
    glViewport(hudLeft, hudBottom, hudWidth, hudHeight);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 10000.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
    renderSelf(true);
    glDisable(GL_SCISSOR_TEST);
}

















/*
 * GAME LOGIC
 */

void collide(Movable *a, Movable *b)
{
    //Sets forces as directly opposing vectors
    Vector3 aForceOnb = (b->pos - a->pos);
    Vector3 bForceOna = (a->pos - b->pos);
    
    //Projects velocity vector onto the direct opposition vectors
    aForceOnb = (a->dir*a->vel).projectOnto(aForceOnb);
    bForceOna = (b->dir*b->vel).projectOnto(bForceOna);
    
    //Equal and opposite force applied
    aForceOnb-=bForceOna;
    bForceOna-=(aForceOnb+bForceOna);

    //Adds force to initial velocity to get 
    //resulting velocity vector
    aForceOnb+=(b->dir*b->vel);
    bForceOna+=(a->dir*a->vel);
    
    //splits velocity vector into scalar vel and normalized vector dir
    a->vel = bForceOna.length();
    b->vel = aForceOnb.length();
    a->dir = bForceOna.getNormal();
    b->dir = aForceOnb.getNormal();
}

void checkWallCollisions(Movable * m, const Vector3 & newPos)
{
    //North Wall
    if(newPos[2] < ARENA_LENGTH*-.5+BALL_RADIUS)
    {
        arena->pos.set(m->pos[0], 0.0, -ARENA_LENGTH);
        arena->dir.set(m->dir[0], m->dir[1], -m->dir[2]);// = Model::SouthVect;
        arena->vel = m->vel;
        collide(m, arena);
    }
    //South Wall
    else if(newPos[2] > ARENA_LENGTH*.5-BALL_RADIUS)
    {
        arena->pos.set(m->pos[0], 0.0, ARENA_LENGTH);
        arena->dir.set(m->dir[0], m->dir[1], -m->dir[2]);// = Model::NorthVect;
        arena->vel = m->vel;
        collide(m, arena);
    }
    //West Wall
    else if(newPos[0] < ARENA_WIDTH*-.5+BALL_RADIUS)
    {
        arena->pos.set(-ARENA_WIDTH, 0.0, m->pos[2]);
        arena->dir.set(-m->dir[0], m->dir[1], m->dir[2]);// = Model::EastVect;
        arena->vel = m->vel;
        collide(m, arena);
    }
    //East Wall
    else if(newPos[0] > ARENA_WIDTH*.5-BALL_RADIUS)
    {
        arena->pos.set(ARENA_WIDTH, 0.0, m->pos[2]);
        arena->dir.set(-m->dir[0], m->dir[1], m->dir[2]);// = Model::WestVect;
        arena->vel = m->vel;
        collide(m, arena);
    }
}

void checkBallCollisions(Movable * m, const Vector3 & newPos, int ignoreBall)
{
    for(int i = 0; i < NUM_BALLS; i++)
    {
        if(i != ignoreBall)
        {
            if(balls[i]->checkCollisionWithMovable(m))
                collide(m, balls[i]);
        }
    }
}

void updatePositionAndDetectCollisions(Movable *m, int i)
{
    
}

void updateBalls(double timePassed)
{
    for(int i = 0; i < NUM_BALLS; i++)
    {
        Vector3 newPos  = balls[i]->pos+(balls[i]->dir*(balls[i]->vel*timePassed));
        
        checkWallCollisions(balls[i], newPos);
        checkBallCollisions(balls[i], newPos, i);
        balls[i]->updatePos(timePassed);
        balls[i]->vel *= 0.9999;
    }
}

void updatePlayer(double timePassed)
{
    player->dir = player->dir.rotateAroundVect3(Model::UpVect, mouseX*ROT_SPEED*timePassed);
    
    player->vel = mouseY*-SPEED;
    Vector3 newPos  = player->pos+(player->dir*(player->vel*timePassed));
    
    checkWallCollisions(player, newPos);
    checkBallCollisions(player, newPos, -1);
    player->updatePos(timePassed);
}

















/*
 * GL CALLBACK FUNCS
 */

//Called when mouse dragged (sets mouseX and mouseY from -1 to 1)
void PassiveMotionFunc(int x, int y)
{
    int neg = 1;
    mouseX = (-2.0*x/width)+1.0;
    if(mouseX < 0) neg = -1;
    mouseX *= mouseX*neg;
    //Create 'go straight' zone between -.1 and .1
    if(mouseX > MOVEMENT_TOLERANCE)
        mouseX-=MOVEMENT_TOLERANCE;
    else if(mouseX < -MOVEMENT_TOLERANCE)
        mouseX+=MOVEMENT_TOLERANCE;
    else
        mouseX = 0;
    
    neg = 1;
	mouseY = (2.0*y/height)-1.0;
    if(mouseY < 0) neg = -1;
    mouseY *= mouseY*neg;
    //Create 'turn only' zone between -.1 and .1
    if(mouseY > MOVEMENT_TOLERANCE)
        mouseY-=MOVEMENT_TOLERANCE;
    else if(mouseY < -MOVEMENT_TOLERANCE)
        mouseY+=MOVEMENT_TOLERANCE;
    else
        mouseY = 0;
}

void DisplayFunc()
{
    //Clear screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    drawMain();
    drawHud();
    
	//DoubleBuffering
	glutSwapBuffers();
}

void IdleFunc()
{
    double timePassed;
    timePassed = .01;
    
    //Update Model
    updatePlayer(timePassed);
    updateBalls(timePassed);
    
    glutPostRedisplay();
}

void KeyboardFunc(unsigned char key, int x, int y)
{
    /*
     switch(key)
     {
     case 'p':
     paused = !paused;
     break;
     }
     */
}

void SpecialFunc(int key, int x, int y)
{
    /*
     if(key == GLUT_KEY_F1){
     mode = (mode + 1)%NUM_MODES;
     }
     */
}

//Called on Window Resize
void ReshapeFunc(int w, int h)
{
	if (h <= 0) 
		return;
	height = h;
	width = w;
}


















/*
 * INIT FUNCTIONS
 */

void allocBalls()
{
    for(int i = 0; i < NUM_BALLS; i++) 
    {
        balls[i] = new Ball();
        GLfloat x = (GLfloat) rangeRand(-.5*ARENA_WIDTH+BALL_RADIUS, .5*ARENA_WIDTH-BALL_RADIUS);
        GLfloat z = (GLfloat) rangeRand(-.5*ARENA_LENGTH+BALL_RADIUS, .5*ARENA_LENGTH-BALL_RADIUS);
        balls[i]->pos.set(x,0,z);
    }
}

void initGame()
{
    srand(SEED);
    
    Model::setUpModel();
    player = Model::player;
    arena = Model::arena;
    balls = Model::balls;
    compass = Model::compass;
    allocBalls();
}


int main(int argc, char * argv[])
{
	//Set up Window
    glutInit(&argc , argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutInitWindowPosition(0 , 0);
    width = 500;
    height = 400;
	glutInitWindowSize(width,height);
	glutCreateWindow("Moshball");
    
	//One-Time setups
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_NORMALIZE);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_FLAT);
    
    //Aim Stationary Light
    GLfloat pos[4] = {0.0f, 10000.0f, 0.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
	
    //Callback Functions
	glutDisplayFunc(DisplayFunc);
	glutReshapeFunc(ReshapeFunc);
	glutIdleFunc(IdleFunc);
    glutPassiveMotionFunc(PassiveMotionFunc);
    glutKeyboardFunc(KeyboardFunc);
    glutSpecialFunc(SpecialFunc);
    
    //Init
    initGame();
    
	//Initiate program
	glutMainLoop();
	return 0;
}