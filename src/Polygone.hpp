#ifndef POLYGONE_H
#define POLYGONE_H

#include <iostream>
#include "Point2D.hpp"
#include <vector>

template <typename T>
class Polygone
{
private:
    std::vector<Point2D<T>> sommets;
public:
    // Constructeurs
    Polygone() {}

    // Constructeurs liste sommets
    Polygone(const std::vector<Point2D<T>>& listeSommets)
        : sommets(listeSommets) {}
    
    // Constructeurs copie
    Polygone(const Polygone<T>& poly) {
        poly = poly.sommets;
    }

    // Getters
    std::vector<Point2D<T>> getSommets(void) const {
        return sommets;
    }

    // Setters
    void setSommets(std::vector<Point2D<T>> listeSommets) {
        sommets = listeSommets;
    }

    // Méthode addPoint
    void addPoint(Point2D<T>& p) {
        sommets.push_back(p);
    }

    // Méthode de translation
    void translate(T dx,T dy) {
        for(Point2D<T>& p : sommets) {
            p.translate(dx,dy);
        }
    }

    // Surchage operator
    friend std::ostream& operator<< (std::ostream &o, forme <T>const& poly) {
        o << "Polynome[" << poly.getSommets() << "]" ;
        return o;
    }
};

#endif