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
     * @param zu
     * @return ZU
     */
    friend std::ostream &operator<<(std::ostream &s, const ZU &zu)
    {
        s << std::string(zu);
        return s;
    }
};

#endif