#include <iostream>

class Rectangle {
protected:
    double width_;
    double height_;

public:
    Rectangle(double width, double height) : width_(width), height_(height) {}
    virtual ~Rectangle() = default;

    virtual void set_width(double width) {
        width_ = width;
    }

    virtual void set_height(double height) {
        height_ = height;
    }

    double area() const {
        return width_ * height_;
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}

    void set_width(double width) override {
        width_ = width;
        height_ = width;
    }

    void set_height(double height) override {
        width_ = height;
        height_ = height;
    }
};

void process(Rectangle& r) {
    r.set_width(5);
    r.set_height(10);
    std::cout << "Expected area: 50, Actual area: " << r.area() << std::endl;
}

int main() {
    Rectangle r(2, 3);
    process(r);

    Square s(5);
    process(s);

    return 0;
}
