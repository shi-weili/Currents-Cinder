#include "Rectangle.h"

//double RectangleSize(double width, double height) {
//    return width * height;
//}

//Rectangle::Rectangle() {
//    mWidth = DefaultWidth;
//    mHeight = DefaultHeight;
//}

//// Alternatively, using initilization list:
//Rectangle::Rectangle(): mWidth(DefaultWidth), mHeight(DefaultHeight) {
//
//}
//

Rectangle::Rectangle() {
    // Base class's default constructors are automatically called.
    // Because we are not changing the constructor's behavior, nothing to do here.
}

//Rectangle::Rectangle(double width, double height) {
//    // We want to use the width() and height() functions for protection.
//    // But the name "width" refers to the parameter here. How to call width()?
//    this->width(width); // "this" is a pointer to the object itself. "->" is the way to access the members of the pointed object.
////      (*this).width(width); // Equivalent
//    this->height(height);
//}
//

// If we want to call non-default constructors of the inheried class, we have to do it using initilization list:
Rectangle::Rectangle(double width, double height) : BaseShape(width, height) {

}

//double Rectangle::width() const {
//    return mWidth;
//}
//
//void Rectangle::width(double width) {
//    if (width > 0.0) {
//        mWidth = width;
//    } else {
//        // If user input is negative, set width to the default value:
//        mWidth = DefaultWidth;
//    }
//}
//
//double Rectangle::height() const {
//    return mHeight;
//}
//
//void Rectangle::height(double height) {
//    if (height > 0.0) {
//        this->mHeight = height; // "this" is a pointer to the object itself. "->" is the way to access the members of the pointed object.
//        //      (*this).mHeight = height; // Equivalent
//    } else {
//        // If user input is negative, set width to the default value:
//        this->mHeight = DefaultHeight;
//    }
//}

double Rectangle::area() const {
    return mWidth * mHeight;
}
