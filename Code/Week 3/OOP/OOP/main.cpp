#include <iostream>
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
//    // Define an object of the Rectangle class:
//    Rectangle rect1;
//    rect1.mWidth = 20.0; // Access member variable
//    rect1.mHeight = 10.0;
////    rect1.mArea = RectangleArea(rect1.mWidth, rect1.mHeight); // No taste...
////    // What if the user doesn't access the data in the right way?
////    rect1.mArea = rect1.mWidth + rect1.mHeight;
//    cout << rect1.area() << endl;
//    
//    // Using the interface without knowing the implementation:
//    Triangle tri1;
//    tri1.mWidth = 20.0;
//    tri1.mHeight = 10.0;
//    cout << tri1.area() << endl; // The result is different from that of the rectangle, because of different implementations.
    
    // Still, our code doesn't prevent us from doing bad things:
    Rectangle rect2;
//    rect2.mWidth = -20.0; // Makes no sense...
    // We don't want user to have unlimited access to our internal data. We can add protection to it by abstraction.
    // By making mWidth private, we prevent the user from accessing it.
    rect2.width(-20.0);
    cout << rect2.width() << endl;
    
    // Our class need to make sure it's always properly initiallized.
    Rectangle rect3;
    cout << rect3.area() << endl;
    // We can achieve this by implementing its default constructor.
    
    Rectangle rect4(5.0, 5.0); // Calling constructor with arguments.
    cout << rect4.area() << endl;
    
    // Data encapulation, abstraction, constructors... These are all good stuff. Now we want the same for Triangle, but we don't want to write duplicate code...
    // Introudcing inheritance. We can move all those common functionalies into a base class, and make Rectangle and Triangle inherit from it.
    Triangle tri2;
    cout << tri2.area() << endl;
    
    // A pointer to a rectangle:
    Rectangle* rectPtr = &rect4;
    cout << rectPtr->area() << endl;
    BaseShape* baseShapePtr = rectPtr; // This is all good, because a Rectangle (or Triangle) is a BaseShape.
    cout << baseShapePtr->area() << endl; // Won't call the right version of area() without polymorphism.
    
    return 0;
}
