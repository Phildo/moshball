#define HOURS_SPENT 3

#import <OpenGL/OpenGL.h>
#import <GLUT/GLUT.h>
#include <cstdlib>
#include <math.h>
#include <iostream>
#include "VectorLib/Vectors.h"
#include "Arena.h"
#include "Player.h"
#include "Ball.h"
#include "highprecisiontime.h"

#define NUM_MODES 2
#define NUM_BALLS 500
#define SEED 0

bool paused = false;

double mouseX, mouseY;
int height, width;
int mode;

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
    
    HighPrecisionTime *hTime;
    hTime = new HighPrecisionTime();
    
    arena = new Arena();
    
    Vector2 posVec;
    for(int i = 0; i < NUM_BALLS; i++) 
    {
        bArray[i] = new Ball();
        GLfloat x = (GLfloat) rangeRand(-.5*arena->getWidth(), .5*arena->getWidth());
        GLfloat y = (GLfloat) rangeRand(-.5*arena->getLength(), .5*arena->getLength());
        posVec.set(x,y);
        bArray[i]->setPos(posVec);
    }
}

//Draws the xyz axis at current frame of reference
void drawAxis(double size)
{
	glPushMatrix();

	//z
	gluCylinder(gluNewQuadric(),0.01*size,0.01*size,1*size,10,1);

	//y
	glRotatef(-90, 1.0f, 0.0f, 0.0f);
	gluCylinder(gluNewQuadric(),0.01*size,0.01*size,1*size,10,1);

	//x
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	gluCylinder(gluNewQuadric(),0.01*size,0.01*size,1*size,10,1);

	glPopMatrix();
}

void drawBalls()
{
    for(int i = 0; i < NUM_BALLS; i++)
    {
        bArray[i]->draw();
    }
}

//Called when mouse dragged (sets mouseX and mouseY from -1 to 1)
//(only needs to 'look' correct)
void MotionFunc(int x, int y)
{
	mouseX = -2.0*(x-(width/2.0))/width;
	mouseY = 2.0*(y-(height/2.0))/height;
}

//Called to update display
void DisplayFunc()
{
	//Clear screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Set camera to look relative to position of mouse on screen
	gluLookAt(0.0f,0.0f,-5.0f,mouseX*10,mouseY*10,-10.0f,0.0f,1.0f,0.0f);

	//Aim Light
    GLfloat pos[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, pos);

	//Enable depth, lighting, and fog ONLY AFTER stars are drawn
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    //glEnable(GL_FOG);

	arena->draw();
    drawBalls();

	//Disable depth, lighting, and fog for stars to be drawn next time
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    //glDisable(GL_FOG);

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
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0 , ((double) w) / ((double) h) , 1.0f , 10000.0);
	glViewport(0 , 0 , w , h);
}

int main(int argc, char * argv[])
{
	//Set up Window
    glutInit(&argc , argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutInitWindowPosition(0 , 0);
	glutInitWindowSize(width,height);
	glutCreateWindow("Moshball");
    
	//One-Time setups
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_FLAT);
    glEnable(GL_NORMALIZE);
    
	//Fog data
    /*
    float fogColor[] = { 0.0f, 0.0f, 0.0f, 1 };
    glFogfv(GL_FOG_COLOR, fogColor);
	glFogf(GL_FOG_START, 500);
	glFogf(GL_FOG_END, 1000);
    glFogf (GL_FOG_DENSITY, 0.9f);
    glHint (GL_FOG_HINT, GL_FASTEST);
    glFogi(GL_FOG_MODE, GL_LINEAR);
     */
	
    //Callback Functions
	glutDisplayFunc(DisplayFunc);
	glutReshapeFunc(ReshapeFunc);
	glutIdleFunc(DisplayFunc);
	glutMotionFunc(MotionFunc);
    glutKeyboardFunc(KeyboardFunc);
    glutSpecialFunc(SpecialFunc);

    //Init
    initGame();
    
	//Initiate program
	glutMainLoop();
	return 0;
}