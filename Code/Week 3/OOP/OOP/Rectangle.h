#ifndef Rectangle_h
#define Rectangle_h

#include "BaseShape.h"

//// Class definition:
//class Rectangle {
//public:
//    double mWidth; // Member variable. Best practice: prefix member variables with "m".
//    double mHeight;
//    double mArea;
//};

//// A first but not good try to calculate the size of a Rectangle:
//double RectangleArea(double width, double height);

//// Definition of constant values:
//const double DefaultWidth = 100.0;
//const double DefaultHeight = 100.0;
//
//// Data encapsulation and abstraction:
//class Rectangle {
//public: // Only the public members are accessable by outsiders (interface)
//    Rectangle(); // Default constructor
//    Rectangle(double width, double height); // Constructor can also have parameters
////    double mWidth;
////    double mHeight;
//    double width() const; // Getter. "Const" means its never changes data members. If you have a constant Rectangle, you can still can this function, because the compiler konws it wont' change the Rectangle's  data members. Best practice: add "const" whenever you can.
//    void width(double width); // Setter. Function overloading here.
//    double height() const;
//    void height(double width);
//    double area() const; // Also note that we only provides an "getter" of area. User cannot change area without changing width or height.
//        // Data encapsulation: the function and the data it uses are encapsulated together in the class.
//        // Abstraction: the user doesn't need to understand the implementation in order to use it.
//private: // Private members are hidden from the outside world (implementation)
//    double mWidth;
//    double mHeight;
//};

class Rectangle : public BaseShape {
public:
    Rectangle(); // Constructors are not inherited
    Rectangle(double width, double height);
    double area() const; // Overriding (not overloading) the same function of BaseShape
};


#endif /* Rectangle_h */
