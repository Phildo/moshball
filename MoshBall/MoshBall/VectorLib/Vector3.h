#ifndef _dmsVector3_h_
#define _dmsVector3_h_

/* with ideas liberally taken from OpenGL Performer's pfVec3 &
 Magic Software's MgcVector3 */

#import <OpenGL/OpenGL.h>
#import <GLUT/GLUT.h>
#include <iostream>

class Vector3
{
public:
    GLfloat vec[3];
    
    Vector3(void);
    Vector3(GLfloat x, GLfloat y, GLfloat z);
    Vector3(const GLfloat *v);
    Vector3(const Vector3 &v);
    Vector3& operator= (const Vector3& v);
    void set(GLfloat x, GLfloat y, GLfloat z);
    
    GLfloat& operator[](int i);
    GLfloat operator[](int i) const;
    
    Vector3& operator+=(const Vector3& v);
    Vector3& operator-=(const Vector3& v);
    Vector3& operator*=(GLfloat s);
    Vector3& operator/=(GLfloat s);
    Vector3 operator+(const Vector3& v) const;
    Vector3 operator-(const Vector3& v) const;
    Vector3 operator*(GLfloat s) const;
    Vector3 operator/(GLfloat s) const;
    Vector3 operator-(void) const;
    bool operator==(const Vector3& v) const;
    bool operator!=(const Vector3& v) const;
    
    GLfloat length(void) const;
    GLfloat lengthSquared(void) const;
    void normalize(void);
    Vector3 getNormal(void) const;
    GLfloat dot(const Vector3& v) const;
    Vector3 cross(const Vector3& v) const;
    GLfloat distance(const Vector3& v) const;
    GLfloat distanceSquared(const Vector3& v) const;
    
    Vector3 rotateAroundVect3(const Vector3& rav, double deg) const;
    Vector3 projectOnto(const Vector3& pv) const;
    Vector3 bounceOffNormal(const Vector3& nv) const;
    Vector3 interpolateVect3(const Vector3 & iv, double t) const;
    
    void drawLine(void) const;
    
    static const Vector3 Zero;
    static const Vector3 X_Axis;
    static const Vector3 Y_Axis;
    static const Vector3 Z_Axis;
    
private:
};


inline std::ostream& operator<< (std::ostream& s, const Vector3& v)
{ return s << "(" << v.vec[0] << ", " << v.vec[1] << ", " << v.vec[2] << ")"; }

inline Vector3 operator* (GLfloat s, const Vector3& v) { return v*s; }

#endif
