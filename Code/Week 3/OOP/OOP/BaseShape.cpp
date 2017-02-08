#include "BaseShape.h"

BaseShape::BaseShape(): mWidth(DefaultWidth), mHeight(DefaultHeight) {
    
}

BaseShape::BaseShape(double width, double height) {
    this->width(width);
    this->height(height);
}

double BaseShape::width() const {
    return mWidth;
}

void BaseShape::width(double width) {
    if (width > 0.0) {
        mWidth = width;
    } else {
        mWidth = DefaultWidth;
    }
}

double BaseShape::height() const {
    return mHeight;
}

void BaseShape::height(double height) {
    if (height > 0.0) {
        this->mHeight = height;    } else {
        this->mHeight = DefaultHeight;
    }
}

double BaseShape::area() const {
    return 0.0; // Return zero here, because we have no idea how to calculate the area of a BaseShape.
}
