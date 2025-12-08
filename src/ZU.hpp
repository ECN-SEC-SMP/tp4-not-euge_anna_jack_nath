#ifndef _ZU_HPP
#define _ZU_HPP

#include "Constructible.hpp"
#include <iostream>

template <typename T>
class ZU : public Constructible<T>
{
private:
    float surfaceConstruite;

public:
    /**
     * @brief Construct a new ZU object
     *
     */
    ZU(int num, std::string prop, Polygone<T> *forme) : Constructible<T>(num, prop, forme)
    {
        this->type = "ZU";
        this->surfaceCons = 0;
    }

    /**
     * @brief Construct a new ZU object with a given constructed surface
     *
     */
    ZU(int num, std::string prop, float surfaceC, Polygone<T> *forme) : Constructible<T>(num, prop, forme)
    {
        this->surfaceCons = surfaceC;
        this->type = "ZU";
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
     * @brief Set the Surface Construite of the object
     *
     * @param surfaceC
     */
    void setSurfaceConstruite(float surfaceC)
    {
        this->surfaceConstruite = surfaceC;
    }

    /**
     * @brief Destroy the ZU object
     *
     */
    ~ZU() {}

    /**
     * @brief Print the type of the object
     *
     * @param s
     * @param type
     * @return ZU
     */
    friend std::ostream &operator<<(std::ostream &s, const ZU &type)
    {
        s << "(" << "Type " << type.Constructible::type << ")";
        return s;
    }
};

#endif