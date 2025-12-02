#include "Constructible.hpp"


Constructible :: Constructible(int num, std::string prop /*,Polygone<int,float> *forme*/) : Parcelle(num, prop /*,forme*/)
{
    this->surfaceCons = 0.0;
}

float Constructible :: getSurfaceConstructible() const
{
    return this->surfaceCons;
}


void Constructible :: setSurfaceConstructible( float surfaceCons )
{
    this->surfaceCons = surfaceCons;
}


// bool Constructible :: construire() // Polygone necessaire