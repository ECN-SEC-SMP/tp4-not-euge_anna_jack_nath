#ifndef _ZN_HPP
#define _ZN_HPP

#include <iostream>
#include "Parcelle.hpp"

class ZN : public Parcelle
{
private :

public:
    // Constructeur
    ZN(int num, std::string prop /*,Polygone<int,float> *forme*/);

    // Destructeur
    ~ZN() {};

    // Affichage
    friend std::ostream &operator<<(std::ostream &s, const ZN &type)
    {
        s << "(" << "Type " << type.Parcelle::type << ")";
        return s;
    }
};

#endif