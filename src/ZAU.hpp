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
    ZAU(int num, std::string prop, Polygone<T> *forme) : Constructible<T>(num, prop, forme)
    {
        this->type = "ZAU";
    }

    /**
     * @brief Destroy the ZAU object
     *
     */
    ~ZAU() {}

    /**
     * @brief Redefine tostring operator for object
     * 
     * @return std::string 
     */
    operator std::string() const
    {
        std::string stringify = Parcelle<int>::operator std::string();

        return stringify;
    }

    /**
     * @brief Print the type of the object
     *
     * @param s
     * @param zau
     * @return ZAU
     */
    friend std::ostream &operator<<(std::ostream &s, const ZAU &zau)
    {
        s << std::string(zau);
        return s;
    }
};

#endif