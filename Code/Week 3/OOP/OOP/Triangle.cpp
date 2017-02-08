#include "Triangle.h"

Triangle::Triangle() {

}

Triangle::Triangle(double width, double height) : BaseShape(width, height) {
    
}

//double Triangle::area() {
//    return mWidth * mHeight / 2.0;
//}

double Triangle::area() const{
    return mWidth * mHeight / 2.0;
}
