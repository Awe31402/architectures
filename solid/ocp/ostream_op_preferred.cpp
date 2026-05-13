#include <iostream>
#include <ostream>

template <typename T, typename U> class my_pair
{
public:
    my_pair(T first, U second) : first_(first), second_(second) {}

    T get_first() const { return first_; }
    U get_second() const { return second_; }
private:
    T first_;
    U second_;
    int some_other_data_; // This member is not relevant to the ostream operator
};

std::ostream &operator<<(std::ostream &stream, const my_pair<int, std::string> &pair) {
    stream << pair.get_first() << ", " << pair.get_second();
    return stream;
}

int main(int argc, char* argv[]) {
    my_pair<int, std::string> pair(42, "Hello");
    std::cout << pair << std::endl;
    return 0;
}