#ifndef _CONSTRUCTIBLE_HPP
#define _CONSTRUCTIBLE_HPP

#include "Parcelle.hpp"

/**
 * @brief Classe Constructible qui hérite de Parcelle
 *
 */
class Constructible : public Parcelle
{
private:
    float surfaceCons;

public:
    Constructible(int num, std::string prop /*,Polygone<int,float> *forme*/);

    /**
     * @brief Construct a new Constructible area object 
     * 
     * @return float 
     */
    virtual float surfaceConstructible();

    /**
     * @brief Get the constructible surface of the object
     * 
     * @return float 
     */
    float getSurfaceConstructible() const;

    /**
     * @brief Set the constructible surface of the object
     * 
     * @param surfaceCons 
     */
    void setSurfaceConstructible( float surfaceCons );


    /**
     * @brief Construct on the area of the object
     * 
     * @return true 
     * @return false 
     */
    bool construire(); // Polygone necessaire  
};

#endif