#include "Ball.h"

bool Ball::compiled;
GLuint Ball::displayList;

Ball::Ball()
{
	if(!Ball::compiled) {
        Ball::compileDL();
    }
    pos.set(0.0,0.0,0.0);
    dir.set(0.0,0.0,-1.0);
    vel = 0;
    unhit();
}

Ball::~Ball()
{
    
}

void Ball::compileDL()
{
    if(Ball::compiled) return;
    Ball::displayList = glGenLists(1);
    glNewList(Ball::displayList, GL_COMPILE);
    gluSphere(gluNewQuadric(),BALL_RADIUS,10,10);
    glEndList();
    Ball::compiled = true;
}

void Ball::draw()
{
    if(!Ball::compiled) return;
    glCallList(Ball::displayList);
}

void Ball::drawAtPosition()
{
    if(active) 
    {
        displayTimer();
    }    
    setGLColor();
    
    glPushMatrix();
    glTranslated(pos[0], pos[1], pos[2]);
    draw();
    glPopMatrix();
}


bool Ball::checkCollisionWithMovable(Movable * m)
{
    if(m->pos[0] > this->pos[0]-(BALL_RADIUS*2) && m->pos[0] < this->pos[0]+(BALL_RADIUS*2) &&
       m->pos[1] > this->pos[1]-(BALL_RADIUS*2) && m->pos[1] < this->pos[1]+(BALL_RADIUS*2) &&
       m->pos[2] > this->pos[2]-(BALL_RADIUS*2) && m->pos[2] < this->pos[2]+(BALL_RADIUS*2))
    {
        this->hit();
        return true;
    }
    return false;
}

void Ball::hit()
{
    this->active = true;
    this->timeHit = Model::currTime; //now
    this->timeLeft = FULL_TIME;
    setColor(1.0, 0.0, 0.0, 1.0, 0.25, 0.25, 0.5);
}

void Ball::unhit()
{
    this->active = false;
    this->timeHit = NULL;
    this->timeLeft = 0;
    setColor(0.0, 1.0, 0.0, 1.0, 0.25, 0.25, 0.5);
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