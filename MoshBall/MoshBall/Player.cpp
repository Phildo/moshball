#include "Player.h"

bool Player::compiled;
GLuint Player::displayList;

Player::Player()
{
	if(!Player::compiled) {
        setColor(0.0, 0.0, 1.0, 1.0, 0.5, 1.0, 1.0);
        Player::compileDL();
    }
    pos.set(0.0,0.0,0.0);
    dir.set(0.0,0.0,-1.0);
    vel = 0;
}

Player::~Player()
{
}

void Player::compileDL()
{
    if(Player::compiled) return;
    Player::displayList = glGenLists(1);
    glNewList(Player::displayList, GL_COMPILE);
    setGLColor();
    gluSphere(gluNewQuadric(),50,50,50);
    glEndList();
    Player::compiled = true;
}

void Player::draw()
{
    if(!Player::compiled) return;
    glCallList(Player::displayList);
}

void Player::drawAtPosition()
{
    glPushMatrix();
    glTranslated(pos[0], pos[1], pos[2]);
    draw();
    glPopMatrix();
}

