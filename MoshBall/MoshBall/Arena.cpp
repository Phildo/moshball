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

void Arena::setColor(const Vector3 & newColor)
{
	//Sets specular, ambient, and diffuse
	color[0] = newColor[0];
	color[1] = newColor[1];
	color[2] = newColor[2];
    specular[0] = 0.0f;
    specular[1] = 0.0f;
    specular[2] = 0.0f;
    specular[3] = 0.0f;
    ambient[0] = (float)color[0];
    ambient[1] = (float)color[1];
    ambient[2] = (float)color[2];
    ambient[3] = 1.0f;
    diffuse[0] = (float)color[0];
    diffuse[1] = (float)color[1];
    diffuse[2] = (float)color[2];
    diffuse[3] = 1.0f;
}

void Arena::compile()
{
    if(compiled) return;
    arenaList = glGenLists(1);
    glNewList(arenaList, GL_COMPILE);
    
    Vector3 col;
    col.set(0.4f, 0.4f, 1.0f);
    this->setColor(col);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);  
    glColor3d(color[0], color[1], color[2]);
    
    glBegin(GL_QUADS);
    
    //Floor
    glNormal3d(0.0, 1.0, 0.0);
    glVertex3d(-.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, .5*ARENA_LENGTH);
    glVertex3d(.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
    glVertex3d(-.5*ARENA_WIDTH, -.5*ARENA_HEIGHT, -.5*ARENA_LENGTH);
    
    
    col.set(0.2f, 0.2f, 1.0f);
    this->setColor(col);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);  
    glColor3d(color[0], color[1], color[2]);
    
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
    compiled = true;
}

void Arena::draw()
{
    if(!compiled) return;
    glCallList(arenaList);
}

