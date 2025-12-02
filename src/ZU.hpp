#ifndef _ZU_HPP
#define _ZU_HPP

#include "Parcelle.hpp"

class ZU : public Parcelle
{
private :
    float surfaceConstruite;

public:
    // Constructeurs
    ZU(int num, std::string prop /*,Polygone<int,float> *forme*/);
    ZU(int num, std::string prop, float surfaceC /*,Polygone<int,float> *forme*/);

    //getters et setters
    float getSurfaceConstruite() const;
    void setSurfaceConstruite(float surfaceC);

    // Destructeur
    ~ZU() {};
};




#endif