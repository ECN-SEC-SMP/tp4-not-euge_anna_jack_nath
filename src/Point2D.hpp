#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

template <typename T>
class Point2D {
private:
    T x;
    T y;

public:
    // Constructeurs par défault
    Point2D() : x(0), y(0) {}

    // Constructeur valeur
    Point2D(T x, T y) : x(x), y(y) {}

    // Constructeur copie
    Point2D(const Point2D<T>& p) {
        x = p.x;
        y = p.y;
    }

    // Getters
    T getX() const { return x; }
    T getY() const { return y; }

    // Setters
    void setX(T x) { this->x = x; }
    void setY(T y) { this->y = y; }

    // Méthode de translation
    void translate(T dx,T dy);

    // Surchage operator
    friend std::ostream& operator<< (std::ostream &o, Point2D<T>const& p) {
        o<<"("<< p.getX() << ";" << p.getY() << ")";
        return o;
    }
};


template <typename T>
void Point2D<T>::translate(T dx,T dy) {
    this -> x += dx;
    this -> y += dy;
}

#endif