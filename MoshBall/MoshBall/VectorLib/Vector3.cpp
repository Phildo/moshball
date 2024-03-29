#include <math.h>
#include "Vector3.h"

const Vector3 Vector3::Zero(0.0, 0.0, 0.0);
const Vector3 Vector3::X_Axis(1.0, 0.0, 0.0);
const Vector3 Vector3::Y_Axis(0.0, 1.0, 0.0);
const Vector3 Vector3::Z_Axis(0.0, 0.0, 1.0);


Vector3::Vector3(void)
{
    set(0, 0, 0);
}


Vector3::Vector3(GLfloat x, GLfloat y, GLfloat z)
{
    set(x, y, z);
}


Vector3::Vector3(const GLfloat *v)
{
    set(v[0], v[1], v[2]);
}


Vector3::Vector3(const Vector3 &v)
{
    set(v.vec[0], v.vec[1], v.vec[2]);
}


Vector3& Vector3::operator= (const Vector3& v)
{
    set(v.vec[0], v.vec[1], v.vec[2]);
    return *this;
}


void Vector3::set(GLfloat x, GLfloat y, GLfloat z)
{
    vec[0] = x;
    vec[1] = y;
    vec[2] = z;
}


GLfloat& Vector3::operator[](int i)
{
    if ((i >= 0) && (i < 3))
        return vec[i];
    else if (i < 0)
        return vec[0];
    else if (i > 2)
        return vec[2];
    else
        return vec[0];
}


GLfloat Vector3::operator[](int i) const
{
    if ((i >= 0) && (i < 3))
        return vec[i];
    else if (i < 0)
        return vec[0];
    else if (i > 2)
        return vec[2];
    else
        return vec[0];
}


Vector3& Vector3::operator+=(const Vector3& v)
{
    vec[0] += v.vec[0];
    vec[1] += v.vec[1];
    vec[2] += v.vec[2];
    return *this;
}


Vector3& Vector3::operator-=(const Vector3& v)
{
    vec[0] -= v.vec[0];
    vec[1] -= v.vec[1];
    vec[2] -= v.vec[2];
    return *this;
}


Vector3& Vector3::operator*=(GLfloat s)
{
    vec[0] *= s;
    vec[1] *= s;
    vec[2] *= s;
    return *this;
}


Vector3& Vector3::operator/=(GLfloat s)
{
    vec[0] /= s;
    vec[1] /= s;
    vec[2] /= s;
    return *this;
}


Vector3 Vector3::operator+(const Vector3& v) const
{
    return Vector3(vec[0]+v.vec[0], vec[1]+v.vec[1], vec[2]+v.vec[2]);
}


Vector3 Vector3::operator-(const Vector3& v) const
{
    return Vector3(vec[0]-v.vec[0], vec[1]-v.vec[1], vec[2]-v.vec[2]);
}


Vector3 Vector3::operator-(void) const
{
    return Vector3(-vec[0],-vec[1], -vec[2]);
}


Vector3 Vector3::operator*(GLfloat s) const
{
    return Vector3(vec[0]*s, vec[1]*s, vec[2]*s);
}


Vector3 Vector3::operator/(GLfloat s) const
{
    return Vector3(vec[0]/s, vec[1]/s, vec[2]/s);
}


bool Vector3::operator==(const Vector3& v) const
{
    return ((vec[0] == v.vec[0]) &&
            (vec[1] == v.vec[1]) &&
            (vec[2] == v.vec[2]));
}


bool Vector3::operator!=(const Vector3& v) const
{
    return ((vec[0] != v.vec[0]) ||
            (vec[1] != v.vec[1]) ||
            (vec[2] != v.vec[2]));
}


GLfloat Vector3::length(void) const
{
    return sqrt(lengthSquared());
}


GLfloat Vector3::lengthSquared(void) const
{
    return vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2];
}


void Vector3::normalize(void)
{
    float len = length();
    if (len > 0)
    {
        vec[0] /= len;
        vec[1] /= len;
        vec[2] /= len;
    }
}

Vector3 Vector3::getNormal(void) const
{
    float len = length();
    if(len > 0) return Vector3(vec[0]/len, vec[1]/len, vec[2]/len);
    else return Vector3();
}

GLfloat Vector3::dot(const Vector3& v) const
{
    return vec[0]*v.vec[0] + vec[1]*v.vec[1] + vec[2]*v.vec[2];
}


Vector3 Vector3::cross(const Vector3& v) const
{
    return Vector3(vec[1] * v.vec[2] - vec[2] * v.vec[1],
                   vec[2] * v.vec[0] - vec[0] * v.vec[2],
                   vec[0] * v.vec[1] - vec[1] * v.vec[0]);
}


GLfloat Vector3::distance(const Vector3& v) const
{
    return sqrt(distanceSquared(v));
}


GLfloat Vector3::distanceSquared(const Vector3& v) const
{
    float dx, dy, dz;
    dx = vec[0] - v.vec[0];
    dy = vec[1] - v.vec[1];
    dz = vec[2] - v.vec[2];
    return dx*dx + dy*dy + dz*dz;
}

Vector3 Vector3::rotateAroundVect3(const Vector3& rav, double deg) const
{
    GLfloat dp = this->dot(rav);
    double rad = deg*(3.14159265/180.0);
    GLfloat u = rav.vec[0];
    GLfloat v = rav.vec[1];
    GLfloat w = rav.vec[2];
    GLfloat x = vec[0];
    GLfloat y = vec[1];
    GLfloat z = vec[2];
    
    return Vector3((u * dp) + (((x*((v*v)+(w*w)))-(u*((v*y)+(w*z))))*(cos(rad))) + (((-1*w*y)+(v*z))*(sin(rad))),
                   (v * dp) + (((y*((u*u)+(w*w)))-(v*((u*x)+(w*z))))*(cos(rad))) + ((( 1*w*x)-(u*z))*(sin(rad))),
                   (w * dp) + (((z*((u*u)+(v*v)))-(w*((u*x)+(v*y))))*(cos(rad))) + (((-1*v*x)+(u*y))*(sin(rad))));
}

Vector3 Vector3::projectOnto(const Vector3& pv) const
{
    return pv.getNormal()*(this->length()*(this->getNormal().dot(pv.getNormal())));
}

Vector3 Vector3::bounceOffNormal(const Vector3& nv) const
{
    return this->operator+(this->projectOnto(nv)*-2);
}

Vector3 Vector3::interpolateVect3(const Vector3 & iv, double t) const
{
    return Vector3(t*(iv.vec[0]-this->vec[0])+this->vec[0],
                   t*(iv.vec[1]-this->vec[1])+this->vec[1],
                   t*(iv.vec[2]-this->vec[2])+this->vec[2]);
}

void Vector3::drawLine(void) const
{
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3fv(vec);
    glEnd();
}
