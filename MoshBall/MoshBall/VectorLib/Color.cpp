#import <OpenGL/OpenGL.h>
#import <GLUT/GLUT.h>
#include "Color.h"

const Color Color::White(1.0, 1.0, 1.0, 1.0);
const Color Color::Black(0.0, 0.0, 0.0, 1.0);

const Color Color::Red(1.0, 0.0, 0.0, 1.0);
const Color Color::Green(0.0, 1.0, 0.0, 1.0);
const Color Color::Blue(0.0, 0.0, 1.0, 1.0);
const Color Color::Cyan(0.0, 1.0, 1.0, 1.0);
const Color Color::Magenta(1.0, 0.0, 1.0, 1.0);
const Color Color::Yellow(1.0, 1.0, 0.0, 1.0);

const Color Color::Grey10(0.1, 0.1, 0.1, 1.0);
const Color Color::Grey20(0.2, 0.2, 0.2, 1.0);
const Color Color::Grey30(0.3, 0.3, 0.3, 1.0);
const Color Color::Grey40(0.4, 0.4, 0.4, 1.0);
const Color Color::Grey50(0.5, 0.5, 0.5, 1.0);
const Color Color::Grey60(0.6, 0.6, 0.6, 1.0);
const Color Color::Grey70(0.7, 0.7, 0.7, 1.0);
const Color Color::Grey80(0.8, 0.8, 0.8, 1.0);
const Color Color::Grey90(0.9, 0.9, 0.9, 1.0);



Color::Color(void) : Vector4(0.0, 0.0, 0.0, 1.0)
    {
    }


Color::Color(GLfloat r,GLfloat g,GLfloat b,GLfloat a) : Vector4(r, g, b, a)
    {
    }


void Color::apply(void) const
    {
    glColor4fv(vec);
    }

