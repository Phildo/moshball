#ifndef _dmsVector4_h_
#define _dmsVector4_h_

/* with ideas liberally taken from OpenGL Performer's pfVec3 &
   Magic Software's MgcVector4 */

#import <OpenGL/OpenGL.h>
#import <GLUT/GLUT.h>
#include <iostream>

class Vector4
    {
    public:
        GLfloat vec[4];

        Vector4(void);
        Vector4(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
        Vector4(const GLfloat *v);
        Vector4(const Vector4 &v);
        Vector4& operator= (const Vector4& v);
        void set(GLfloat x, GLfloat y, GLfloat z, GLfloat w);

        GLfloat& operator[](int i);
        GLfloat operator[](int i) const;

        Vector4& operator+=(const Vector4& v);
        Vector4& operator-=(const Vector4& v);
        Vector4& operator*=(GLfloat s);
        Vector4& operator/=(GLfloat s);
        Vector4 operator+(const Vector4& v) const;
        Vector4 operator-(const Vector4& v) const;
        Vector4 operator*(GLfloat s) const;
        Vector4 operator/(GLfloat s) const;
        Vector4 operator-(void) const;
        bool operator==(const Vector4& v) const;
        bool operator!=(const Vector4& v) const;
        
        GLfloat length(void) const;
        GLfloat lengthSquared(void) const;
        void normalize(void);
        GLfloat dot(const Vector4& v) const;
        GLfloat distance(const Vector4& v) const;
        GLfloat distanceSquared(const Vector4& v) const;
        
        static const Vector4 Zero;
    private:
    };


inline std::ostream& operator<< (std::ostream& s, const Vector4& v)
        { return s << "(" << v.vec[0] << ", " << v.vec[1] << ", "
                   << v.vec[2] << ", " << v.vec[3] << ")"; }

#endif
