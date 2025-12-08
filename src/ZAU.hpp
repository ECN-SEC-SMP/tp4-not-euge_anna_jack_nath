#ifndef _ZAU_HPP
#define _ZAU_HPP

#include "Constructible.hpp"
#include <iostream>

class ZAU : public Constructible
{
public:
    /**
     * @brief Construct a new ZAU object
     * 
     */
    ZAU(int num, std::string prop /*,Polygone<int,float> *forme*/);

    /**
     * @brief Destroy the ZAU object
     * 
     */
    ~ZAU() {};

      /**
     * @brief Print the type of the object
     * 
     * @param s 
     * @param type 
     * @return ZAU
     */
    friend std::ostream &operator<<(std::ostream &s, const ZAU &type)
    {
        s << "(" << "Type " << type.Constructible::type << ")";
        return s;
    }
};


#endif