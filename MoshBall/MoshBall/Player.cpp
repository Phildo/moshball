#include "Player.h"

GLuint Player::playerList;
bool Player::compiled = false;

Player::Player()
{
	if(!compiled) {
        Player::compile();
    }
    Vector2 newDir;
    newDir.set(0, -1);
    setDir(newDir);
}


void Player::setPos(const Vector2 & newPos)
{
	pos[0] = newPos[0];
	pos[1] = newPos[1];
}

Vector2 Player::getPos()
{
	return pos;
}

void Player::setDir(const Vector2 & newDir)
{
	dir[0] = newDir[0];
	dir[1] = newDir[1];
}

Vector2 Player::getDir()
{
	return dir;
}

void Player::setVel(double newVel)
{
	vel = newVel;
}

double Player::getVel()
{
	return vel;
}

void Player::updatePos(double elapsedTime)
{
	pos = pos + (dir*vel) * elapsedTime;
}

void Player::setColor(const Vector3 & newColor)
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

void Player::compile()
{
    if(compiled) return;
    playerList = glGenLists(1);
    glNewList(playerList, GL_COMPILE);
    gluSphere(gluNewQuadric(),50,50,50);
    glEndList();
    compiled = true;
}

void Player::draw()
{
    if(!compiled) return;
    glCallList(playerList);
}

