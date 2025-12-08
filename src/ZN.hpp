#ifndef _ZN_HPP
#define _ZN_HPP

#include <iostream>
#include "Parcelle.hpp"

class ZN : public Parcelle
{
private :

public:
    /**
     * @brief Construct a new ZN object
     * 
     */
    ZN(int num, std::string prop /*,Polygone<int,float> *forme*/);

    /**
     * @brief Destroy the ZN object
     * 
     */
    ~ZN() {};

    /**
     * @brief Print the type of the object
     * 
     * @param s 
     * @param type 
     * @return ZN
     */
    friend std::ostream &operator<<(std::ostream &s, const ZN &type)
    {
        s << "(" << "Type " << type.Parcelle::type << ")";
        return s;
    }
};

#endif