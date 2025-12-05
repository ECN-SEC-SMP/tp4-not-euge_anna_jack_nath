#ifndef _ZU_HPP
#define _ZU_HPP

#include "Constructible.hpp"
#include <iostream>

class ZU : public Constructible
{
private :
    float surfaceConstruite;

public:
    /**
     * @brief Construct a new ZU object
     * 
     */
    ZU(int num, std::string prop /*,Polygone<int,float> *forme*/);

    /**
     * @brief Construct a new ZU object with a given constructed surface
     * 
     */
    ZU(int num, std::string prop, float surfaceC /*,Polygone<int,float> *forme*/);

    /**
     * @brief Get the Surface Construite of the object
     * 
     * @return float 
     */
    float getSurfaceConstruite() const;

    /**
     * @brief Set the Surface Construite of the object
     * 
     * @param surfaceC 
     */
    void setSurfaceConstruite(float surfaceC);

    /**
     * @brief Destroy the ZU object
     * 
     */
    ~ZU() {};

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