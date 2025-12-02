#ifndef _ZA_HPP
#define _ZA_HPP

#include "Constructible.hpp"
#include <string>
#include <iostream>

/**
 * @brief Classe Zonne Agricole qui hérite de Constructible
 * 
 */
class ZA : public Constructible
{
private :
    std::string typeCulture;

public:
    /**
     * @brief Construct a new ZA object
     * 
     */
    ZA(int num, std::string prop, std::string culture /*,Polygone<int,float> *forme*/);

    /**
     * @brief Get the type of the culture growing on the parcel
     * 
     * @return std::string 
     */
    std::string getTypeCulture() const;

    /**
     * @brief Set the type of the culture growing on the parcel
     * 
     * @param culture 
     */
    void setTypeCulture(std::string culture);

    /**
     * @brief Destroy the ZA object
     * 
     */
    ~ZA() {};

      /**
     * @brief Print the type of the object
     * 
     * @param s 
     * @param type 
     * @return ZA
     */
    friend std::ostream &operator<<(std::ostream &s, const ZA &type)
    {
        s << "(" << "Type " << type.Constructible::type << ")";
        return s;
    }

};


#endif