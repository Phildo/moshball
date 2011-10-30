#ifndef _dmsVector2_h_
#define _dmsVector2_h_

#import <OpenGL/OpenGL.h>
#import <GLUT/GLUT.h>
#include <iostream>

class Vector2
    {
    public:
        GLfloat vec[2];

        Vector2(void);
        Vector2(GLfloat x, GLfloat y);
        Vector2(const GLfloat *v);
        Vector2(const Vector2 &v);
        Vector2& operator= (const Vector2& v);
        void set(GLfloat x, GLfloat y);

        GLfloat& operator[](int i);
        GLfloat operator[](int i) const;

        Vector2& operator+=(const Vector2& v);
        Vector2& operator-=(const Vector2& v);
        Vector2& operator*=(GLfloat s);
        Vector2& operator/=(GLfloat s);
        Vector2 operator+(const Vector2& v) const;
        Vector2 operator-(const Vector2& v) const;
        Vector2 operator*(GLfloat s) const;
        Vector2 operator/(GLfloat s) const;
        Vector2 operator-(void) const;
        bool operator==(const Vector2& v) const;
        bool operator!=(const Vector2& v) const;
        
        GLfloat length(void) const;
        GLfloat lengthSquared(void) const;
        void normalize(void);
        GLfloat dot(const Vector2& v) const;
        GLfloat distance(const Vector2& v) const;
        GLfloat distanceSquared(const Vector2& v) const;
        
        void drawLine(void) const;
        
        static const Vector2 Zero;
        static const Vector2 X_Axis;
        static const Vector2 Y_Axis;
    private:
    };


inline std::ostream& operator<< (std::ostream& s, const Vector2& v)
        { return s << "(" << v.vec[0] << ", " << v.vec[1] << ")"; }

#endif
