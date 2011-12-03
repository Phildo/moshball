#define HOURS_SPENT 6+5+2+4+6

#import <OpenGL/OpenGL.h>
#import <GLUT/GLUT.h>
#include <cstdlib>
#include <math.h>
#include <time.h>
#include <iostream>

#include "Model.h"
#include "Collision.h"
#include "VectorLib/Vectors.h"

static double mouseX, mouseY;
static int height, width;

Player * player;
Skybox * skybox;
Arena * arena;
Ball ** balls;
Arrow * compass;
Jumbotron * jOne;
Jumbotron * jTwo;
Jumbotron * jThree;
Jumbotron * jFour;


/*
 *
 *
 *
 */
int debug = 0;
/*
 *
 *
 *
 */






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

void drawJumbos()
{
    glPushMatrix();
    glTranslated(ARENA_LENGTH*.5, ARENA_HEIGHT*-.5, ARENA_WIDTH*.5);
    glRotated(45, 0, 1, 0);
    jOne->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(ARENA_LENGTH*-.5, ARENA_HEIGHT*-.5, ARENA_WIDTH*.5);
    glRotated(125, 0, 1, 0);
    jTwo->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(ARENA_LENGTH*.5, ARENA_HEIGHT*-.5, ARENA_WIDTH*-.5);
    glRotated(125, 0, 1, 0);
    jThree->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(ARENA_LENGTH*-.5, ARENA_HEIGHT*-.5, ARENA_WIDTH*-.5);
    glRotated(45, 0, 1, 0);
    jFour->draw();
    glPopMatrix();
}

void drawCrosshair()
{
    glPushMatrix();
    glLoadIdentity();
    glLineWidth(3);
    glDisable(GL_LIGHTING);
    glColor4d(1.0,1.0,1.0,1.0);
    glBegin(GL_LINES);
    glVertex3d(-2, 0, -20);
    glVertex3d(2, 0, -20);
    glVertex3d(0, -2, -20);
    glVertex3d(0, 2, -20);
    glEnd();
    glEnable(GL_LIGHTING);
    glPopMatrix();
}

void renderSelf(bool forMap)
{
    arena->draw();
    drawBalls();
    if(forMap)
    {
        player->drawAtPosition();
        compass->draw();
    }
    else 
    {
        glPushMatrix();
        glTranslated(player->pos[0], player->pos[1], player->pos[2]);
        skybox->draw();
        glPopMatrix();
        drawJumbos();
    }
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
    
    drawCrosshair();

	renderSelf(false);
}

void drawJumboHud()
{

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
void frameBuffer()
{
    glGenFramebuffersEXT(1, &frame_buffer_object);
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, frame_buffer_object);
    glGenRenderbuffersEXT(1, &depth_buffer);
    glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, depth_buffer);
    glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, GL_DEPTH_COMPONENT, frame_buffer_width, frame_buffer_height);
    glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, depth_buffer);
    
    glGenTextures(1, &jumbotron_id);
    glBindTexture(GL_TEXTURE_2D, jumbotron_id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, frame_buffer_width, frame_buffer_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
    glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, jumbotron_id, 0);
    GLenum status = glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);
    if (status != GL_FRAMEBUFFER_COMPLETE_EXT)
        throw std::string("Frame buffer failed to initialize properly");
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
}
*/















/*
 * GAME LOGIC
 */

void collide(Movable *a, Movable *b)
{
    a->hit();
    b->hit();
    bool negA = false;
    bool negB = false;
    if(a->vel < 0) negA = true;
    if(b->vel < 0) negB = true;
    
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
    if(negA) 
    {
        bForceOna = bForceOna*-1; 
        a->vel *= -1;
    }
    if(negA)
    {
        aForceOnb = aForceOnb*-1;
        b->vel *= -1;
    }
    a->dir = bForceOna.getNormal();
    b->dir = aForceOnb.getNormal();
}

double findTofIntersection(Movable * aM, Movable * bM, double timePassed)
{
    //MATH FROM http://stackoverflow.com/questions/1073336/circle-line-collision-detection
    //USER 'bobobobo'
    
    Vector2 d;
    Vector2 f;
    d.set((aM->dir*aM->vel*timePassed)[0], (aM->dir*aM->vel*timePassed)[2]);
    f.set((bM->pos-aM->pos)[0], (bM->pos-aM->pos)[2]);
    float a = d.dot(d);
    float b = 2*f.dot(d);
    float c = f.dot(f) - (2*BALL_RADIUS*2*BALL_RADIUS);
    
    float discriminant = b*b-4*a*c;
    if(discriminant < 0)
    {
        return NO_COLLISION;
    }
    else
    {
        discriminant = sqrtf(discriminant);
        float t1 = (-b + discriminant)/(2*a);
        //float t2 = (-b - discriminant)/(2*a);
        
        if(t1 >= 0 && t1 <= 1)
        {
            return t1 * timePassed;
        }
        else
        {
            return NO_COLLISION;
        }
    }
    return NO_COLLISION; //Really shouldn't get here... just makes compiler happy
}

void checkWallCollisions(Movable * m, double timePassed, Collision & c)
{
    Vector3 newPos = m->pos+(m->dir*m->vel*timePassed);
    
    //North Wall
    if(newPos[2] < (ARENA_LENGTH*-.5+BALL_RADIUS))
    {
        double t = ((ARENA_LENGTH*-.5+BALL_RADIUS)-m->pos[2])/(newPos[2]-m->pos[2]);
        if(t*timePassed < c.timePassed)
        {
            arena->pos.set((m->pos+(t*m->dir*m->vel*timePassed))[0], 0.0, (ARENA_LENGTH*-.5-BALL_RADIUS));
            arena->dir = Model::SouthVect;
            arena->vel = (m->vel*m->dir).projectOnto(Model::SouthVect).length();
            c.timePassed = t*timePassed;
            c.b = arena;
        }
    }
    //South Wall
    else if(newPos[2] > ARENA_LENGTH*.5-BALL_RADIUS)
    {
        double t = ((ARENA_LENGTH*.5-BALL_RADIUS)-m->pos[2])/(newPos[2]-m->pos[2]);
        if(t*timePassed < c.timePassed)
        {
            arena->pos.set((m->pos+(t*m->dir*m->vel*timePassed))[0], 0.0, (ARENA_LENGTH*.5+BALL_RADIUS));
            arena->dir = Model::NorthVect;
            arena->vel = (m->vel*m->dir).projectOnto(Model::NorthVect).length();
            c.timePassed = t*timePassed;
            c.b = arena;
        }
    }
    
    //West Wall
    if(newPos[0] < ARENA_WIDTH*-.5+BALL_RADIUS)
    {
        double t = ((ARENA_WIDTH*-.5+BALL_RADIUS)-m->pos[0])/(newPos[0]-m->pos[0]);
        if(t*timePassed < c.timePassed)
        {
            arena->pos.set((ARENA_WIDTH*-.5-BALL_RADIUS), 0.0, (m->pos+(t*m->dir*m->vel*timePassed))[2]);
            arena->dir = Model::EastVect;
            arena->vel = (m->vel*m->dir).projectOnto(Model::EastVect).length();
            c.timePassed = t*timePassed;
            c.b = arena;
        }
    }
    //East Wall
    else if(newPos[0] > ARENA_WIDTH*.5-BALL_RADIUS)
    {
        double t = ((ARENA_WIDTH*.5-BALL_RADIUS)-m->pos[0])/(newPos[0]-m->pos[0]);
        if(t*timePassed < c.timePassed)
        {
            arena->pos.set((ARENA_WIDTH*.5+BALL_RADIUS), 0.0, (m->pos+(t*m->dir*m->vel*timePassed))[2]);
            arena->dir = Model::WestVect;
            arena->vel = (m->vel*m->dir).projectOnto(Model::WestVect).length();
            c.timePassed = t*timePassed;
            c.b = arena;
        }        
    }
}

void checkBallCollisions(Movable * m, int ignoreBall, double timePassed, Collision & c)
{
    double returnedColTime;
    for(int i = 0; i < NUM_BALLS; i++)
    {
        if(i != ignoreBall)
        {
            returnedColTime = findTofIntersection(m, balls[i], timePassed);
            if(returnedColTime < c.timePassed)
            {
                c.timePassed = returnedColTime;
                c.b = balls[i];
            }
        }
    }
    if(ignoreBall != -1)
    {
        returnedColTime = findTofIntersection(m, player, timePassed);
        if(returnedColTime < c.timePassed)
        {
            c.timePassed = returnedColTime;
            c.b = player;
        }
    }
}

void updatePathWithCollisions(Movable * me, int ignoreBall, double timePassed)
{
    Collision c;
    c.timePassed = NO_COLLISION;
    c.a = me;
    
    checkWallCollisions(me, timePassed, c);
    checkBallCollisions(me, ignoreBall, timePassed, c);
    
    if(c.timePassed != NO_COLLISION)
    {
        me->pos = me->pos+(me->dir*me->vel*c.timePassed);
        timePassed-=c.timePassed;
        collide(me, c.b);
        updatePathWithCollisions(me, ignoreBall, timePassed);
    }
    else
    {
        
        me->pos = me->pos+(me->dir*me->vel*timePassed);
    }
}

void updateBalls(double timePassed)
{
    for(int i = 0; i < NUM_BALLS; i++)
    {        
        updatePathWithCollisions(balls[i], i, timePassed);
        balls[i]->vel *= FRICTION;
        balls[i]->updateTime();
    }
}

void updatePlayer(double timePassed)
{
    
    player->dir = player->dir.rotateAroundVect3(Model::UpVect, mouseX*ROT_SPEED*timePassed);
    player->vel = mouseY*-SPEED;
    
    updatePathWithCollisions(player, -1, timePassed);
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
    drawJumboHud();
    
	//DoubleBuffering
	glutSwapBuffers();
}

void IdleFunc()
{
    double timePassed;
    timePassed = .01;
    
    //Update Model
    updatePlayer(timePassed);
    //updateBalls(timePassed);
    
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
    skybox = Model::skybox;
    arena = Model::arena;
    balls = Model::balls;
    compass = Model::compass;
    jOne = Model::jOne;
    jTwo = Model::jTwo;
    jThree = Model::jThree;
    jFour = Model::jFour;
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
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_NORMALIZE);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_FLAT);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    //Aim Stationary Light
    GLfloat pos[4] = {0.0f, 10000.0f, 0.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    GLfloat full[4] = { 0.5f, 0.5f, 0.5f, 0.5f };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, full);
    glLightfv(GL_LIGHT0, GL_SPECULAR, full);
    glLightfv(GL_LIGHT0, GL_AMBIENT, full);
    
    //Set up Moving Light
    glLightfv(GL_LIGHT1, GL_DIFFUSE, full);
    glLightfv(GL_LIGHT1, GL_SPECULAR, full);
    glLightfv(GL_LIGHT1, GL_AMBIENT, full);
	
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