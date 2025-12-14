#ifndef POLYGONE_H
#define POLYGONE_H

#include <iostream>
#include "Point2D.hpp"
#include <vector>
#include <math.h>
#include <algorithm>

/**
 * @class Polygone
 * @brief Représente un polygone générique composé d'une liste de sommets en 2D.
 *
 * Cette classe template permet de manipuler des polygones dont les coordonnées
 * des sommets sont de type T (int, float, double…).
 *
 * @tparam T Type numérique utilisé pour les coordonnées des points.
 */

template <typename T>
class Polygone
{
private:
    std::vector<Point2D<T>> sommets;

public:
    // Constructeurs
    Polygone() {}

    // Constructeurs liste sommets
    Polygone(const std::vector<Point2D<T>> &listeSommets)
        : sommets(listeSommets) {}

    // Constructeurs copie
    Polygone(const Polygone<T> &poly)
        : sommets(poly.sommets) {}

    // Getters
    std::vector<Point2D<T>> getSommets(void) const
    {
        return sommets;
    }

    // Setters
    void setSommets(std::vector<Point2D<T>> listeSommets)
    {
        sommets = listeSommets;
    }

    // Méthode addPoint
    void addPoint(Point2D<T> &p)
    {
        sommets.push_back(p);
    }

    // Méthode de translation
    void translate(T dx, T dy);

    double calcSurface() const {
        double surface = 0;
        int n = sommets.size();

        // Erreur si le Polynome a - de 3 sommets
        if (n < 3)
        {
            throw std::runtime_error("Le polynome a moins de 3 sommets");
        }

        for(int i=0; i < n; ++i ){
            const Point2D<T>& p1 = sommets[i];
            const Point2D<T>& p2 = sommets[(i + 1) % n]; // sommet suivant (retour à 0)

            surface += static_cast<double>(p1.getX()) * static_cast<double>(p2.getY()) 
                 - static_cast<double>(p2.getX()) * static_cast<double>(p1.getY());
        }

        if (surface == 0)
        {
            throw std::runtime_error("Le polynome est croisé");
        }
        
        return std::abs(surface) / 2;

    }

    // Surchage operator
    friend std::ostream &operator<<(std::ostream &o, Polygone<T> const &poly)
    {
        o << "[";

        const auto &sommet = poly.getSommets();
        for (int i = 0; i < sommet.size(); ++i)
        {
            o << sommet[i];
            if (i < sommet.size() - 1)
            {
                o << ",";
            }
        }
        o << "]";
        return o;
    }

    operator std::string() const
    {
        std::string stringify;

        for (size_t i = 0; i < sommets.size(); i++)
        {
            stringify += "[" + std::to_string(sommets[i].getX()) + ";" + std::to_string(sommets[i].getY()) + "]";

            if (i != sommets.size() - 1)
                stringify += " ";
        }

        return stringify;
    }
};

template <typename T>
void Polygone<T>::translate(T dx, T dy)
{
    for (Point2D<T> &p : sommets)
    {
        p.translate(dx, dy);
    }
}

#endif