#include "Point2D.hpp"

int main() {
    Point2D<int> p(3, 4);
    std::cout << p << std::endl;  // (3, 4)

    p.translate(2, -1);
    std::cout << p << std::endl;  // (5, 3)

    return 0;
}