#ifndef _CONSTRUCTIBLE_HPP
#define _CONSTRUCTIBLE_HPP

#include "Parcelle.hpp"

/**
 * @brief Classe Constructible qui hérite de Parcelle
 *
 */
template <typename T>
class Constructible : public Parcelle<T>
{
private:
    float surfaceCons;

public:
    Constructible(int num, std::string prop, Polygone<T> *forme) : Parcelle<T>(num, prop, forme)
    {
        this->surfaceCons = 0.0;
    }

    /**
     * @brief Construct a new Constructible area object
     *
     * @return float
     */
    virtual float surfaceConstructible();

    /**
     * @brief Get the constructible surface of the object
     *
     * @return float
     */
    float getSurfaceConstructible() const
    {
        return this->surfaceCons;
    }

    /**
     * @brief Set the constructible surface of the object
     *
     * @param surfaceCons
     */
    void setSurfaceConstructible(float surfaceCons)
    {
        this->surfaceCons = surfaceCons;
    }
};

#endif