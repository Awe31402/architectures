#include <iostream>
#include <vector>
#include <memory>

class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
};

class Rectangle : public Shape {
private:
    double width_;
    double height_;
public:
    Rectangle(double width, double height) : width_(width), height_(height) {}
    void set_width(double width) { width_ = width; }
    void set_height(double height) { height_ = height; }
    double area() const override { return width_ * height_; }
};

class Square : public Shape {
private:
    double side_;
public:
    explicit Square(double side) : side_(side) {}
    void set_side(double side) { side_ = side; }
    double area() const override { return side_ * side_; }
};

void print_area(const Shape& s) {
    std::cout << "The area of this shape is: " << s.area() << std::endl;
}

int main() {
    auto rect = std::make_unique<Rectangle>(5, 10);
    auto square = std::make_unique<Square>(5);

    std::cout << "Demonstrating Liskov Substitution Principle with a common interface:" << std::endl;
    
    print_area(*rect);
    print_area(*square);

    rect->set_width(7);
    std::cout << "\nAfter changing Rectangle width to 7:" << std::endl;
    print_area(*rect);

    square->set_side(10);
    std::cout << "\nAfter changing Square side to 10:" << std::endl;
    print_area(*square);

    return 0;
}
