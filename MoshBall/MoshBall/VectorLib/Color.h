#ifndef _dmsColor_h_
#define _dmsColor_h_

#include "Vector4.h"

#define DMS_RED     0
#define DMS_GREEN   1
#define DMS_BLUE    2
#define DMS_ALPHA   3

class Color : public Vector4
    {
    public:
        Color(void);
        Color(GLfloat r,GLfloat g,GLfloat b,GLfloat a);
        void apply(void) const;
        
        static const Color White;
        static const Color Black;
        static const Color Red;
        static const Color Green;
        static const Color Blue;
        static const Color Cyan;
        static const Color Magenta;
        static const Color Yellow;
        static const Color Grey10;
        static const Color Grey20;
        static const Color Grey30;
        static const Color Grey40;
        static const Color Grey50;
        static const Color Grey60;
        static const Color Grey70;
        static const Color Grey80;
        static const Color Grey90;

    private:
    };


#endif
