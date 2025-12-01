#ifndef _CONSTRUCTIBLE_HPP
#define _CONSTRUCTIBLE_HPP

// #include "Parcelle"

class Constructible : public Parcelle
{
private:
    float surfaceConstructible;
public:
    virtual float surfaceConstructible();
    float getSurfaceConstructible();
    void setSurfaceConstructible( float surfaceCons );
    bool construire(Polygone<int> poly); // Utile ???
};

#endif