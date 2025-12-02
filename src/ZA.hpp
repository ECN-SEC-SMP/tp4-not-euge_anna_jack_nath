#ifndef _ZA_HPP
#define _ZA_HPP

#include "Parcelle.hpp"
#include <string>

class ZA : public Parcelle
{
private :
    std::string typeCulture;

public:
    // Constructeur
    ZA(int num, std::string prop, std::string culture /*,Polygone<int,float> *forme*/);

    // Destructeur
    ~ZA() {};

    std::string getTypeCulture() const;
    void setTypeCulture(std::string culture);

};


#endif