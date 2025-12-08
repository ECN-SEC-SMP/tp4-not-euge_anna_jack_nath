#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

/**
 * @class Point2D
 * @brief Représente un point dans un plan cartésien à deux dimensions.
 *
 * La figure décrit les éléments attendus dans cette classe. Vous surchargerez l’opérateur << 
 * pour permettre l’affichage d’un Point2D à l’écran.
 *
 * @tparam T Type numérique utilisé pour les coordonnées des points.
 * @brief Elle permet de manipuler des points génériques avec différents types 
 * numériques : int, float, double, etc.
 * 
 * @tparam Coordonnée en axe X.
 * @tparam Coordonnée en axe Y.
 */

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