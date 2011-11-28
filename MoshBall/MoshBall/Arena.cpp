#include "Arena.h"

bool Arena::compiled;
GLuint Arena::displayList;

Arena::Arena()
{
	if(!Arena::compiled) {
        Arena::compileDL();
    }
}

Arena::~Arena()
{

}

void Arena::compileDL()
{
    if(Arena::compiled) return;
    Arena::displayList = glGenLists(1);
    glNewList(Arena::displayList, GL_COMPILE);
 
    setColor(0.4, 0.2, 0.4, 1.0, 0.25, 0.25, 0.5);
    setGLColor();
 
    glBegin(GL_QUADS);
 
    //Floor
    glNormal3d(0.0, 1.0, 0.0);
    glVertex3d(-.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
    glVertex3d(-.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
 
 
    setColor(0.4, 0.6, 0.0, 1.0, 0.25, 0.25, 0.5);
    setGLColor();
 
    //West Wall
    glNormal3d(1.0, 0.0, 0.0);
    glVertex3d(-.5*ARENA_WIDTH, .5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
    glVertex3d(-.5*ARENA_WIDTH, .5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    glVertex3d(-.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    glVertex3d(-.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
 
    //East Wall
    glNormal3d(-1.0, 0.0, 0.0);
    glVertex3d(.5*ARENA_WIDTH, .5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, .5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
 
    //North Wall
    glNormal3d(0.0, 0.0, 1.0);
    glVertex3d(-.5*ARENA_WIDTH, .5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, .5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
    glVertex3d(-.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
 
    //South Wall
    glNormal3d(0.0, 0.0, -1.0);
    glVertex3d(-.5*ARENA_WIDTH, .5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, .5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    glVertex3d(-.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, .5*ARENA_LENGTH);
 
    glEnd();
    glEndList();
    Arena::compiled = true;
}

void Arena::draw()
{
    if(!Arena::compiled) return;
    glCallList(Arena::displayList);
}