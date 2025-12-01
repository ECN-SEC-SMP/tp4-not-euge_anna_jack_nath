#ifndef _ZN_HPP
#define _ZN_HPP

#include <iostream>

#include "Parcelle"

class ZN : public Parcelle
{
private :

public:
    // Constructeur
    ZN();

    // Destructeur
    ~ZN() {};

    // Affichage
    friend std::ostream &operator<<(std::ostream &s, const ZN &type)
    {
        s << "(" << "Type " << ZN.type << ")";
        return s;
    }
};

#endif