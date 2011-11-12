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

bool Ball::checkCollisionWithPlayer(Player * p)
{
    if(p->getPos()[0] > this->pos[0]-(BALL_RADIUS*2) && p->getPos()[0] < this->pos[0]+(BALL_RADIUS*2) &&
       p->getPos()[1] > this->pos[1]-(BALL_RADIUS*2) && p->getPos()[1] < this->pos[1]+(BALL_RADIUS*2))
    {
        p->setDir(p->getDir().reflectOverVector((this->pos-p->getPos())).rotate(2/3.1415));
        this->hit();
        return true;
    }
    return false;
}

void Ball::compile()
{
    if(compiled) return;
    ballList = glGenLists(1);
    glNewList(ballList, GL_COMPILE);
    gluSphere(gluNewQuadric(),BALL_RADIUS,10,10);
    glEndList();
    compiled = true;
}

void Ball::hit()
{
    this->active = true;
    this->timeHit = Model::currTime; //now
    this->timeLeft = FULL_TIME;
}

void Ball::unhit()
{
    this->active = false;
    this->timeHit = NULL;
    this->timeLeft = 0;
}

void Ball::updateTime()
{
    if(active)
    {
        timeLeft = FULL_TIME - difftime(Model::currTime, timeHit);
        if(timeLeft <= 0)
            unhit();
    }
}

void Ball::displayTimer()
{
    
}

void Ball::draw()
{
    if(!compiled) return;
    Vector3 newCol;
    if(active) 
    {
        newCol.set((GLfloat)1.0, (GLfloat)0.0, (GLfloat)0.0);
        displayTimer();
    }    
    else
    {
       newCol.set((GLfloat)0.5, (GLfloat)1.0, (GLfloat)0.0); 
    }
    setColor(newCol);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);  
    glColor3d(color[0], color[1], color[2]);
    glPushMatrix();
    glTranslated((GLdouble)this->pos[0], (GLdouble)0.0, (GLdouble)this->pos[1]);
    glCallList(ballList);
    glPopMatrix();
}

