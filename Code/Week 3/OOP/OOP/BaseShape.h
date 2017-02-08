#ifndef BaseShape_h
#define BaseShape_h

const double DefaultWidth = 100.0;
const double DefaultHeight = 100.0;

class BaseShape {
public:
    BaseShape();
    BaseShape(double width, double height);
    double width() const;
    void width(double width);
    double height() const;
    void height(double width);
//    double area() const;
    virtual double area() const; // Best practice: if you plan to override a member function in derived classes, you usually want it to be virtual in order to have polymorphism.
protected: // Private members can't be accessed by derived classes, but protected members can.
    double mWidth;
    double mHeight;
};

#endif /* BaseShape_h */
