#ifndef POLYGONE_H
#define POLYGONE_H

#include <iostream>
#include "Point2D.hpp"
#include <vector>

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