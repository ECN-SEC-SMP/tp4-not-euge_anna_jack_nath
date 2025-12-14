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
    ZN(int num, std::string prop, Polygone<T> *forme) : Parcelle<T>(num, prop, 0, forme)
    {
        this->type = "ZN";
    }

    /**
     * @brief Destroy the ZN object
     *
     */
    ~ZN() {}

    /**
     * @brief Print the type of the object
     *
     * @param s
     * @param type
     * @return ZN
     */
    friend std::ostream &operator<<(std::ostream &s, const ZN &zone)
    {
        //s << "(" << "Type " << this.getType() << ")";
        return s;
    }
};

#endif