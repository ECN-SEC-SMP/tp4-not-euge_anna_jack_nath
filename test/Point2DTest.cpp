/**
 * @file Point2DTest.cpp
 * @brief 
 * @version 0.1
 * @date 2025-12-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>
#include "Point2DTest.hpp"
#include "Point2D.hpp"

void Point2DTest(void) {
    
    Point2D<int> p(3, 4);
    std::cout << p << std::endl;  // (3, 4)

    p.translate(2, -1);
    std::cout << p << std::endl;  // (5, 3)

    return;
}