#include "Ball.h"

GLuint Ball::ballList;
bool Ball::compiled = false;

Ball::Ball()
{
	if(!compiled) {
        Ball::compile();
    }
    active = false;
}

void Ball::setPos(const Vector2 & newPos)
{
	pos[0] = newPos[0];
	pos[1] = newPos[1];
}

Vector2 Ball::getPos()
{
	return pos;
}

void Ball::setColor(const Vector3 & newColor)
{
	//Sets specular, ambient, and diffuse
	color[0] = newColor[0];
	color[1] = newColor[1];
	color[2] = newColor[2];
    specular[0] = 0.6f;
    specular[1] = 0.6f;
    specular[2] = 0.6f;
    specular[3] = 1.0f;
    ambient[0] = (float)color[0];
    ambient[1] = (float)color[1];
    ambient[2] = (float)color[2];
    ambient[3] = 1.0f;
    diffuse[0] = (float)color[0];
    diffuse[1] = (float)color[1];
    diffuse[2] = (float)color[2];
    diffuse[3] = 1.0f;
}

void Ball::compile()
{
    if(compiled) return;
    ballList = glGenLists(1);
    glNewList(ballList, GL_COMPILE);
    gluSphere(gluNewQuadric(),50,50,50);
    glEndList();
    compiled = true;
}

void Ball::draw()
{
    if(!compiled) return;
    Vector3 newCol;
    if(active) newCol.set((GLfloat)0.5, (GLfloat)1.0, (GLfloat)0.0);
    else newCol.set((GLfloat)0.5, (GLfloat)1.0, (GLfloat)0.0);
    setColor(newCol);
    glPushMatrix();
    glTranslated((GLdouble)this->pos[0], (GLdouble)0.0, (GLdouble)this->pos[1]);
    glCallList(ballList);
    glPopMatrix();
}

