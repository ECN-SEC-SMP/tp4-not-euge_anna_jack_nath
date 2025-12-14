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
    Carte(void)
    {
        this->listeParcelle = {};
        this->surface = 0;
    }

    /**
     * @brief Construit une carte à partir d'une liste de parcelles
     *
     * @param lParcelle Liste de parcelles
     */
    Carte(std::vector<Parcelle<T> *> lParcelles)
    {
        this->listeParcelle = lParcelles;
        this->surface = 0; // Faut sommer la taille des parcelles
        for (auto p : listeParcelle)
        {
            surface += p-> getSurface();
        }
    }

    /**
     * @brief Construit une carte à partir d'un fichier
     *
     * @param file Nom du fichier
     */
    Carte(std::string file)
    {
        throw std::runtime_error("N'est pas implémenté");
    }

    /**
     * @brief Destroy the Carte object
     *
     */
    ~Carte(void)
    {
        for (unsigned int i = 0; i < this->listeParcelle.size(); i++)
        {
            if (this->listeParcelle.at(0) != nullptr) {
                delete this->listeParcelle.at(i);
            }
        }
    }

    /**
     * @brief Sauvegarde une carte dans un fichier
     *
     * @param file Nom du fichier
     */
    void save(std::string file)
    {
        throw std::runtime_error("N'est pas implémenté");
    }

    /**
     * @brief Ajoute une parcelle à la carte.
     *
     * @param p Pointeur vers une parcelle.
     */
    void addParcelle(Parcelle<T>* p)
    {
        listeParcelle.push_back(p);
        surface += p->getSurface();
    }

    /**
     * @brief Retourne la surface totale de la carte.
     */
    float getSurface() const { return surface; }

    /**
     * @brief Retourne la liste des parcelles.
     */
    std::vector<Parcelle<T>*> getParcelles() const { return listeParcelle; }

};

#endif