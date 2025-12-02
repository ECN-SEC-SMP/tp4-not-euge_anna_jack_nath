#ifndef _CONSTRUCTIBLE_HPP
#define _CONSTRUCTIBLE_HPP

#include "Parcelle.hpp"

class Constructible : public Parcelle
{
private:
    float surfaceCons;

public:
    virtual float surfaceConstructible();
    float getsurfaceConstructible();
    void setSurfaceConstructible( float surfaceCons );
    bool construire(); // Polygone necessaire  
};

#endif