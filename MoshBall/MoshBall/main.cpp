#define HOURS_SPENT 3+2.5

#import <OpenGL/OpenGL.h>
#import <GLUT/GLUT.h>
#include <cstdlib>
#include <math.h>
#include <time.h>
#include <iostream>
#include "Model.h"
#include "VectorLib/Vectors.h"
#include "Arena.h"
#include "Player.h"
#include "Ball.h"
#include "highprecisiontime.h"

bool paused = false;

double mouseX, mouseY;
int height, width;
int mode;
bool collision;

Arena *arena;
Player *player;
Ball *bArray[NUM_BALLS];

double rangeRand(double start, double end)
{
    return ((rand()/(double)RAND_MAX)*(end-start))+start;
}

void initGame()
{
    srand(SEED);
    
    Model::setUpModel();
    
    HighPrecisionTime *hTime;
    hTime = new HighPrecisionTime();
    
    arena = new Arena();
    player = new Player();
    
    Vector2 posVec;
    for(int i = 0; i < NUM_BALLS; i++) 
    {
        bArray[i] = new Ball();
        GLfloat x = (GLfloat) rangeRand(-.5*arena->getWidth()+BALL_RADIUS, .5*arena->getWidth()-BALL_RADIUS);
        GLfloat y = (GLfloat) rangeRand(-.5*arena->getLength()+BALL_RADIUS, .5*arena->getLength()-BALL_RADIUS);
        posVec.set(x,y);
        bArray[i]->setPos(posVec);
    }
}

void drawBalls()
{
    for(int i = 0; i < NUM_BALLS; i++)
    {
        bArray[i]->draw();
    }
}

void drawCrosshair()
{
    glPushMatrix();
    glTranslated((GLdouble)player->getPos()[0], (GLdouble)0.0, (GLdouble)player->getPos()[1]);
    
    //glCallList(playerList);
    glPopMatrix();
}

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

bool checkWallCollisions(const Vector2 & newPos)
{
    collision = false;
    if(newPos[1] < ARENA_LENGTH*-.5+BALL_RADIUS)
    {
        player->setDir(player->getDir().reflectOverVector(Model::SouthVect));
        collision = true;
    }
    else if(newPos[1] > ARENA_LENGTH*.5-BALL_RADIUS)
    {
        player->setDir(player->getDir().reflectOverVector(Model::NorthVect));
        collision = true;
    }
    else if(newPos[0] < ARENA_WIDTH*-.5+BALL_RADIUS)
    {
        player->setDir(player->getDir().reflectOverVector(Model::EastVect));
        collision = true;
    }
    else if(newPos[0] > ARENA_WIDTH*.5-BALL_RADIUS)
    {
        player->setDir(player->getDir().reflectOverVector(Model::WestVect));
        collision = true;
    }
    
    return collision;
}

bool checkBallCollisions(const Vector2 & newPos)
{
    collision = false;
    for(int i = 0; i < NUM_BALLS; i++)
    {
        collision = bArray[i]->checkCollisionWithPlayer(player);
        if(collision)
            return true;
    }
    return false;
}

void updatePlayer(double timePassed)
{
    player->setDir(player->getDir().rotate(mouseX*-1*timePassed));
    player->setVel(mouseY*-100);
    Vector2 newPos  = player->getPos()+(player->getDir()*(player->getVel()*timePassed));
            
    if(checkWallCollisions(newPos))
    {
        newPos  = player->getPos()+(player->getDir()*(player->getVel()*timePassed));
    }
    
    if(checkBallCollisions(newPos))
    {
        newPos  = player->getPos()+(player->getDir()*(player->getVel()*timePassed));
    }
    
    player->setPos(newPos);

    //std::cout << "Pos:" << player->getPos()[0] << "," << player->getPos()[1] << " Dir:" << player->getDir()[0] << "," << player->getDir()[1] << std::endl;
}

void updateBalls(double timePassed)
{
    
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

void renderSelf(bool withSelf)
{
    arena->draw();
    if(withSelf) player->draw();
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
    gluLookAt(player->getPos()[0], 0.0, player->getPos()[1], player->getPos()[0]+player->getDir()[0], 0.0, player->getPos()[1]+player->getDir()[1], 0.0, 1.0, 0.0);
    
	//Aim Light
    GLfloat pos[4] = {player->getPos()[0], 10.0f, player->getPos()[1], 1.0f};
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

//Called to update display
void DisplayFunc()
{
    //Clear screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    drawMain();
    drawHud();
        
	//DoubleBuffering
	glutSwapBuffers();
}

//Gets key input
void KeyboardFunc(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'p':
            paused = !paused;
            break;
    }
}

//Gets special keys (only utilized for F1)
void SpecialFunc(int key, int x, int y)
{
    if(key == GLUT_KEY_F1){
        mode = (mode + 1)%NUM_MODES;
    }
}

//Called on Window Resize
void ReshapeFunc(int w, int h)
{
	if (h <= 0) 
		return;
	height = h;
	width = w;
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
    glShadeModel(GL_SMOOTH);
    
    //Aim Light
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