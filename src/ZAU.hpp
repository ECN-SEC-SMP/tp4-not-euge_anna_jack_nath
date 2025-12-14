#ifndef _ZAU_HPP
#define _ZAU_HPP

#include "Constructible.hpp"
#include <iostream>

template <typename T>
class ZAU : public Constructible<T>
{
public:
    /**
     * @brief Construct a new ZAU object
     *
     */
    ZAU(int num, std::string prop, float pConstructible, Polygone<T> *forme) 
        : Constructible<T>(num, prop, 0, pConstructible, forme)
    {
        this->type = "ZAU";
    }

    /**
     * @brief Destroy the ZAU object
     *
     */
    ~ZAU() {}

    /**
     * @brief Print the type of the object
     *
     * @param s
     * @param type
     * @return ZAU
     */
    friend std::ostream &operator<<(std::ostream &s, const ZAU &type)
    {
        // s << "(" << "Type " << type.Constructible::type << ")";
        return s;
    }
};

#endif