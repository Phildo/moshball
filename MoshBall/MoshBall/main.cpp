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
Ball * balls[NUM_BALLS];

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
    gluPerspective(30, ((double) width) / ((double) height), 1.0f, 10000000.0);
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

void collide(Movable *a, Movable *b, double ir)
{
    if(ir > 1) ir = 1;
    if(ir < 0) ir = 0;
    
    double effectOnA = 1-ir;
    double effectOnB = ir;
    Vector3 perfectReflectionOffB = a->dir.bounceOffNormal(b->pos-a->pos);
    Vector3 perfectReflectionOffA = b->dir.bounceOffNormal(a->pos-b->pos);
    
}

bool checkWallCollisions(const Vector3 & newPos)
{
    bool collision = false;
    if(newPos[2] < ARENA_LENGTH*-.5+BALL_RADIUS)
    {
        player->dir = player->dir.bounceOffNormal(Model::SouthVect);
        collision = true;
    }
    else if(newPos[2] > ARENA_LENGTH*.5-BALL_RADIUS)
    {
        player->dir = player->dir.bounceOffNormal(Model::NorthVect);
        collision = true;
    }
    else if(newPos[0] < ARENA_WIDTH*-.5+BALL_RADIUS)
    {
        player->dir = player->dir.bounceOffNormal(Model::EastVect);
        collision = true;
    }
    else if(newPos[0] > ARENA_WIDTH*.5-BALL_RADIUS)
    {
        player->dir = player->dir.bounceOffNormal(Model::WestVect);
        collision = true;
    }
    
    return collision;
}

bool checkBallCollisions(const Vector3 & newPos)
{
    return false;
    bool collision = false;
    for(int i = 0; i < NUM_BALLS; i++)
    {
        collision = balls[i]->checkCollisionWithPlayer(player);
        if(collision)
            return true;
    }
    return false;
}

void updatePlayer(double timePassed)
{
    player->dir = player->dir.rotateAroundVect3(Model::UpVect, mouseX*ROT_SPEED*timePassed);
    player->vel = mouseY*-SPEED;
    Vector3 newPos  = player->pos+(player->dir*(player->vel*timePassed));
    
    if(checkWallCollisions(newPos))
    {
        newPos  = player->pos+(player->dir*(player->vel*timePassed));
    }
    
    if(checkBallCollisions(newPos))
    {
        newPos  = player->pos+(player->dir*(player->vel*timePassed));
    }
    
    player->pos = newPos;
}

void updateBalls(double timePassed)
{
    
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
    arena = new Arena();
    player = new Player();
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