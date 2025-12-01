#ifndef _ZN_HPP
#define _ZN_HPP

#include <iostream>

class ZN
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