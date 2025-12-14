#ifndef _ZU_HPP
#define _ZU_HPP

#include "Constructible.hpp"
#include <iostream>

template <typename T>
class ZU : public Constructible<T>
{
public:

    /**
     * @brief Construct a new ZU object with a given constructed surface
     *
     */
    ZU(int num, std::string prop, float pConstructible, float surfaceC, Polygone<T> *forme)
        : Constructible<T>(num, prop, pConstructible, surfaceC, forme)
    {
        this->type = "ZU";
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
        // s << "(" << "Type " << Constructible::type << ")";
        return s;
    }
};

#endif