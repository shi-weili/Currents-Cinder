#ifndef Triangle_h
#define Triangle_h

#include "BaseShape.h"

//// Data abstraction:
//class Triangle {
//public:
//    double mWidth;
//    double mHeight;
//    double area(); // User doesn't need to know that the implmentation is different from Rectangle::area().
//};

class Triangle : public BaseShape {
public:
    Triangle(); // Constructors are not inherited
    Triangle(double width, double height);
    double area() const; // Overriding (not overloading) the same function of BaseShape
};

#endif /* Triangle_h */
