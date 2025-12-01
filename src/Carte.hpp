#ifndef _CARTE_HPP_
#define _CARTE_HPP_

#include "Parcelle.hpp"
#include <vector>

/**
 * @brief La carte représente le plan cadastre
 *
 */
class Carte
{
private:
    /**
     * @brief Liste des parcelles constituant la carte
     *
     */
    std::vector<Parcelle *> listeParcelle;

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
    Carte::Carte(void);

    /**
     * @brief Construit une carte à partir d'une liste de parcelles
     *
     * @param lParcelle Liste de parcelles
     */
    Carte::Carte(std::vector<Parcelle *> lParcelle);

    /**
     * @brief Construit une carte à partir d'un fichier
     *
     * @param file Nom du fichier
     */
    Carte::Carte(std::string file);

    /**
     * @brief Destroy the Carte object
     *
     */
    Carte::~Carte(void);

    /**
     * @brief Sauvegarde une carte dans un fichier
     *
     * @param file Nom du fichier
     */
    void Carte::save(std::string file);
};

#endif