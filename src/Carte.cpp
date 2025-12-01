#include "Carte.hpp"

Carte::Carte(void)
{
    this->listeParcelle = {};
    this->surface = 0;
}

Carte::Carte(std::vector<Parcelle *> lParcelles)
{
    this->listeParcelle = lParcelles;
    this->surface = 0; // Faut sommer la taille des parcelles
}

Carte::Carte(std::string file)
{

    throw std::runtime_error("N'est pas implémenté");
}

Carte::~Carte(void)
{
}

void Carte::save(std::string file)
{
    throw std::runtime_error("N'est pas implémenté");
}