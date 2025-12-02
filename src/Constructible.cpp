#include "Constructible.hpp"



float Constructible :: getsurfaceConstructible()
{
    return this->surfaceCons;
}


void Constructible :: setSurfaceConstructible( float surfaceCons )
{
    this->surfaceCons = surfaceCons;
}


// bool Constructible :: construire() // Polygone necessaire