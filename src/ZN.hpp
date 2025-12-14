#ifndef _ZN_HPP
#define _ZN_HPP

#include <iostream>
#include "Parcelle.hpp"

template <typename T>
class ZN : public Parcelle<T>
{
private:
public:
    /**
     * @brief Construct a new ZN object
     *
     */
    ZN(int num, std::string prop, Polygone<T> *forme) : Parcelle<T>(num, prop, forme)
    {
        this->type = "ZN";
    }

    /**
     * @brief Destroy the ZN object
     *
     */
    ~ZN() {}

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
     * @param zn
     * @return ZN
     */
    friend std::ostream &operator<<(std::ostream &s, const ZN &zn)
    {
        s << std::string(zn);
        return s;
    }
};

#endif