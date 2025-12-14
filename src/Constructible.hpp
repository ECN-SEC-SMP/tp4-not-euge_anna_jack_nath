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

    /**
     * @brief Surface construite
     * 
     */
    float surfaceConstruite;

public:

    /**
     * @brief Construct a new Constructible object
     * 
     * @param num Numero de la parcelle
     * @param prop Propriétaire de la parcelle
     * @param surfaceConstruite Surface construite sur la parcelle
     * @param pConstructible Pourcentage constructible de la parcelle, 0 < valeur < 1 
     * @param forme Forme de la parcelle
     */
    Constructible(int num, std::string prop, float pConstructible, float surfaceConstruite, Polygone<T> *forme) : Parcelle<T>(num, prop, pConstructible, forme)
    {
        this->surfaceConstruite = surfaceConstruite;
        
        // TODO : Wait for getSurface correct implementation in Parcelle
        // Verify that surfaceConstruite is less or equal to buildable area
        // if (surfaceConstruite >= (this->getSurface() * this->pConstructible)) {
        //     throw std::invalid_argument("surfaceConstruite ne peut pas etre superieur");
        // }
    }

    /**
     * @brief Get the constructible surface of the object
     *
     * @return float
     */
    float getSurfaceConstructible() const
    {
        return this->getSurface() * this->pConstructible;
    }

    /**
     * @brief Get the Surface Construite of the object
     *
     * @return float
     */
    float getSurfaceConstruite() const
    {
        return this->surfaceConstruite;
    }

    /**
     * @brief Set the built area
     * 
     * @param surfaceConstruite 
     */
    void setSurfaceConstruite(float const surfaceConstruite) {
        this->surfaceConstruite = surfaceConstruite;
    }

};

#endif