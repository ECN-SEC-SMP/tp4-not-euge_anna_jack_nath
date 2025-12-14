#ifndef _PARCELLE_HPP
#define _PARCELLE_HPP

#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>

#include "Polygone.hpp"

template <typename T>
class Parcelle
{
protected:
    /**
     * @brief Type de la parcelle
     *
     */
    std::string type;

    /**
     * @brief Numéro de la parcelle
     *
     */
    int numero;

    /**
     * @brief Nom du propriétaire de la parcelle
     *
     */
    std::string proprietaire;

    /**
     * @brief Surface de la parcelle
     *
     */
    float surface;

    /**
     * @brief Forme de la parcelle
     *
     */
    Polygone<T> *forme;

    /**
     * @brief Pourcentage de surface constructible
     *
     * This value is between 0 and 1
     */
    float pConstructible;

public:
    /**
     * @brief Construct a new Parcelle object
     *
     * @param num Numéro de la parcelle
     * @param prop Nom du propriétaire
     * @param pConstructible Pourcentage constructible de la surface
     * @param forme Forme de la parcelle
     *
     */
    Parcelle(int num, std::string prop, float pConstructible, Polygone<T> *forme)
    {
        // Check that the number is a positive number
        if (num < 0)
        {
            throw std::invalid_argument("Num doit être supérieur ou égale à 0");
        }

        // Check that the name of the owner is not empty
        if (prop.size() == 0)
        {
            throw std::invalid_argument("Prop ne peut pas être vide");
        }

        // Check that the shape object is not null
        if (forme == nullptr)
        {
            throw std::invalid_argument("Forme ne peut pas être un pointeur null");
        }

        // Verify that pConstructible is a percentage
        if ((pConstructible < 0) || (pConstructible > 1)) {
            throw std::invalid_argument("pConstructible doit etre entre 0 et 1");
        }

        this->forme = forme;
        this->numero = num;
        this->proprietaire = prop;
        this->pConstructible = pConstructible;
        this->surface = this->forme->calcSurface(); // On va récupérer la taille de forme
        this->type = "";   // Pour l'instant rien ?
    }

    /**
     * @brief Construct a new Parcelle object
     *
     * @param parc La parcelle à recopier
     */
    Parcelle(const Parcelle &parc)
    {
        this->numero = parc.getNumero();
        this->type = parc.getType();
        this->forme = parc.getForme();
        this->pConstructible = parc.getPConstructible();
        this->proprietaire = parc.getProprietaire();
        this->surface = parc.getSurface();
    }

    /**
     * @brief Destroy the Parcelle object
     *
     */
    ~Parcelle(void)
    {
        if (this->forme != nullptr) {
            delete this->forme; // Free forme
        }

        this->forme = nullptr;
    }

    /**
     * @brief Get the Numero object
     *
     * @return int
     */
    int getNumero(void) const
    {
        return this->numero;
    }

    /**
     * @brief Get the Proprietaire object
     *
     * @return std::string
     */
    std::string getProprietaire(void) const
    {
        return this->proprietaire;
    }

    /**
     * @brief Get the Surface object
     *
     * @return float
     */
    float getSurface(void) const
    {
        return this->surface;
    }

    /**
     * @brief Récupère la forme de la parcelle
     *
     * @return La forme de la parcelle
     *
     */
    Polygone<T> *getForme(void) const
    {
        return this->forme;
    }

    /**
     * @brief Get the Type object
     *
     * @return std::string
     */
    std::string getType(void) const
    {
        return this->type;
    }

    /**
     * @brief Récupère le pourcentage constructible
     *
     * @return int
     */
    int getPConstructible(void) const
    {
        return this->pConstructible;
    }

    /**
     * @brief Set the Numero object
     *
     * @param numero Le numéro de la parcelle
     */
    void setNumero(int numero)
    {
        if (numero < 0)
        {
            throw std::invalid_argument("Numero doit être supérieur ou égale à 0");
        }
        this->numero = numero;
    }

    /**
     * @brief Set the Proprietaire object
     *
     * @param proprio Le nom du propriétaire
     */
    void setProprietaire(std::string proprio)
    {
        if (proprio.size() == 0)
        {
            throw std::invalid_argument("Le propriétaire ne peut pas être vide");
        }
        this->proprietaire = proprio;
    }

    /**
     * @brief Set pConstructible object
     *
     * @param pCons La valeur du pourcentage
     */
    void setPConstructible(int pCons)
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

    /**
     * @brief Set the Surface object
     *
     * @param surface La surface de la parcelle
     */
    void setSurface(float surface)
    {
        if (surface < 0)
        {
            throw std::invalid_argument("La surface ne peut pas être inférieur à 0");
        }
        this->surface = surface;
    }

    /**
     * @brief Défini la forme de la parcelle
     *
     * @param forme La nouvelle forme
     */
    void setForme(Polygone<T> *forme)
    {
        if (forme == nullptr)
        {
            throw std::invalid_argument("On ne peut pas avoir une forme de parcelle null");
        }
        this->forme = forme;
    }

    operator std::string() const
    {
        std::string stringify = "Parcelle n° " + std::to_string(this->numero) + "\n";
        stringify += "\tType : " + this->type + "\n";
        stringify += "\tPolygone : " + std::string(*this->getForme()) + "\n";
        stringify += "\tPropriétaire : " + this->getProprietaire() + "\n";
        stringify += "\tSurface : " + std::to_string(this->surface) + "\n";

        return stringify;
    }

    friend std::ostream &operator<<(std::ostream &s, const Parcelle &parcelle)
    {
        s << std::string(parcelle);
        return s;
    }
};

#endif