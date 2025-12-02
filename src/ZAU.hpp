#ifndef _ZAU_HPP
#define _ZAU_HPP

#include "Parcelle.hpp"
#include <string>

class ZAU : public Parcelle
{
public:
    // Constructeur
    ZAU(int num, std::string prop /*,Polygone<int,float> *forme*/);

    // Destructeur
    ~ZAU() {};
};


#endif