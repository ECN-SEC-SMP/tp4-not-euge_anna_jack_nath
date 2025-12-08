#include "Parcelle.hpp"

Parcelle::Parcelle(int num, std::string prop /* Polygone<int,float> *forme*/)
{
    if (num < 0)
    {
        throw std::invalid_argument("Num doit être supérieur ou égale à 0");
    }
    if (prop.size() == 0)
    {
        throw std::invalid_argument("Prop ne peut pas être vide");
    }

    // if (forme == nullptr) {
    //     throw std::invalid_argument("Forme ne peut pas être un pointeur null");
    // }

    // this->forme = forme;
    this->numero = num;
    this->proprietaire = prop;
    this->pConstructible = 0;
    this->surface = 0; // On va récupérer la taille de forme
    this->type = "";   // Pour l'instant rien ?
}

Parcelle::Parcelle(const Parcelle &parc)
{
    this->numero = parc.getNumero();
    this->type = parc.getType();
    // this->forme = parc.getForme():
    this->pConstructible = parc.getPConstructible();
    this->proprietaire = parc.getProprietaire();
    this->surface = parc.getSurface();
}

Parcelle::~Parcelle()
{
    // this->forme = nullptr;
}

int Parcelle::getNumero(void) const
{
    return this->numero;
}

std::string Parcelle::getProprietaire(void) const
{
    return this->proprietaire;
}
std::string Parcelle::getType(void) const
{
    return this->type;
}
int Parcelle::getPConstructible(void) const
{
    return this->pConstructible;
}
// Polygone<int,float*>* Parcelle::getForme(void) const {
// return this->forme;
// }
float Parcelle::getSurface(void) const
{
    return this->surface;
}

void Parcelle::setNumero(int numero)
{
    if (numero < 0)
    {
        throw std::invalid_argument("Numero doit être supérieur ou égale à 0");
    }
    this->numero = numero;
}
void Parcelle::setType(std::string type)
{
    if (type.size() == 0)
    {
        throw std::invalid_argument("Type ne doit pas être vide");
    }
    this->type = type;
}
void Parcelle::setPConstructible(int pConstructible)
{
    if (pConstructible > 100)
    {
        throw std::invalid_argument("Le pourcentage constructible ne peut pas excéder 100");
    }
    if (pConstructible < 0)
    {
        throw std::invalid_argument("Le pourcentage constructible ne peut pas être inférieur à 0");
    }
    this->pConstructible = pConstructible;
}

void Parcelle::setProprietaire(std::string prop)
{
    if (prop.size() == 0)
    {
        throw std::invalid_argument("Le propriétaire ne peut pas être vide");
    }
    this->proprietaire = prop;
}
void Parcelle::setSurface(float surface)
{
    if (surface < 0)
    {
        throw std::invalid_argument("La surface ne peut pas être inférieur à 0");
    }
    this->surface = surface;
}
// void Parcelle::setForme(Polygone<int, float>* forme) {
// if (forme == nullptr) {
// throw std::invalid_argument("On ne peut pas avoir une forme de parcelle null");
// }
// this->forme = forme
// }