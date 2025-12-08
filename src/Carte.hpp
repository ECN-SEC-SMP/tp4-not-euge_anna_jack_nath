#ifndef _CARTE_HPP_
#define _CARTE_HPP_

#include "Parcelle.hpp"
#include <vector>

/**
 * @brief La carte représente le plan cadastre
 *
 */
template <typename T>
class Carte
{
private:
    /**
     * @brief Liste des parcelles constituant la carte
     *
     */
    std::vector<Parcelle<T> *> listeParcelle;

    /**
     * @brief Surface total de la carte
     *
     */
    float surface;

public:
    /**
     * @brief Construct a new Carte object
     *
     */
    Carte::Carte(void)
    {
        this->listeParcelle = {};
        this->surface = 0;
    }

    /**
     * @brief Construit une carte à partir d'une liste de parcelles
     *
     * @param lParcelle Liste de parcelles
     */
    Carte::Carte(std::vector<Parcelle<T> *> lParcelles)
    {
        this->listeParcelle = lParcelles;
        this->surface = 0; // Faut sommer la taille des parcelles
    }

    /**
     * @brief Construit une carte à partir d'un fichier
     *
     * @param file Nom du fichier
     */
    Carte::Carte(std::string file)
    {
        throw std::runtime_error("N'est pas implémenté");
    }

    /**
     * @brief Destroy the Carte object
     *
     */
    Carte::~Carte(void)
    {
    }

    /**
     * @brief Sauvegarde une carte dans un fichier
     *
     * @param file Nom du fichier
     */
    void Carte::save(std::string file)
    {
        throw std::runtime_error("N'est pas implémenté");
    }
};

#endif