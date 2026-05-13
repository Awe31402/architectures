#include <iostream>
#include <ostream>

template <typename T, typename U> class my_pair
{
public:
    my_pair(T first, U second) : first_(first), second_(second), some_other_data_(0) {}

    T get_first() const { return first_; }
    U get_second() const { return second_; }

    template <typename T1, typename U1>
    friend std::ostream& operator<<(std::ostream& os, const my_pair<T1, U1>& p);
private:
    T first_;
    U second_;
    int some_other_data_; // This member is not relevant to the ostream operator
};

template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const my_pair<T, U>& p) {
    os << "First: " << p.first_ << ", Second: " << p.second_;
    os << " (some_other_data_: " << p.some_other_data_ << ")"; // Accessing the private member
    return os;
}

int main(int argc, char* argv[]) {
    my_pair<int, std::string> pair(42, "Hello");
    std::cout << pair << std::endl;
    return 0;
}