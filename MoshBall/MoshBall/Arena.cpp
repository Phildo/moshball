#include "Arena.h"

GLuint Arena::arenaList;
bool Arena::compiled = false;

Arena::Arena()
{
	if(!compiled) {
        Arena::compile();
    }
}

double Arena::getWidth()
{
    return ARENA_WIDTH;
}

double Arena::getLength()
{
    return ARENA_LENGTH;
}

void Arena::compile()
{
    if(compiled) return;
    arenaList = glGenLists(1);
    glNewList(arenaList, GL_COMPILE);
    glBegin(GL_TRIANGLES);
    
    //Floor
    glVertex3d(-.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
    
    glVertex3d(-.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
    glVertex3d(-.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    
    //West Wall
    glNormal3d(1.0, 0.0, 0.0);
    
    glVertex3d(-.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
    glVertex3d(-.5*ARENA_WIDTH, .5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
    glVertex3d(-.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    
    glVertex3d(-.5*ARENA_WIDTH, .5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
    glVertex3d(-.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    glVertex3d(-.5*ARENA_WIDTH, .5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    
    //East Wall
    glNormal3d(-1.0, 0.0, 0.0);
    
    glVertex3d(.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, .5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    
    glVertex3d(.5*ARENA_WIDTH, .5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, .5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    
    //North Wall
    glNormal3d(0.0, 0.0, 1.0);
    
    glVertex3d(-.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
    glVertex3d(-.5*ARENA_WIDTH, .5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
    
    glVertex3d(-.5*ARENA_WIDTH, .5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, .5*ARENA_HEIGHT, -.5*ARENA_LENGTH);

    
    //South Wall
    glNormal3d(0.0, 0.0, -1.0);
    
    glVertex3d(-.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    glVertex3d(-.5*ARENA_WIDTH, .5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    
    glVertex3d(-.5*ARENA_WIDTH, .5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, .5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    
    glEnd();
    glEndList();
    compiled = true;
}

void Arena::draw()
{
    if(!compiled) return;
    glCallList(arenaList);
}

