#ifndef _PARCELLE_HPP
#define _PARCELLE_HPP

#include <string>
#include <exception>
#include <stdexcept>

class Parcelle
{
private:
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
    // Polygone<int>* forme;

    /**
     * @brief Pourcentage de surface constructible
     *
     */
    int pConstructible;

public:
    /**
     * @brief Construct a new Parcelle object
     *
     * @param num Numéro de la parcelle
     * @param prop Nom du propriétaire
     * @param forme Forme de la parcelle
     *
     */
    Parcelle(int num, std::string prop /*,Polygone<int,float> *forme*/);

    /**
     * @brief Construct a new Parcelle object
     *
     * @param parc La parcelle à recopier
     */
    Parcelle(const Parcelle &parc);

    /**
     * @brief Destroy the Parcelle object
     *
     */
    ~Parcelle(void);

    /**
     * @brief Get the Numero object
     *
     * @return int
     */
    int getNumero(void) const;

    /**
     * @brief Get the Proprietaire object
     *
     * @return std::string
     */
    std::string getProprietaire(void) const;

    /**
     * @brief Get the Surface object
     *
     * @return float
     */
    float getSurface(void) const;

    /**
     * @brief Récupère la forme de la parcelle
     *
     * @return La forme de la parcelle
     *
     */
    // Polygone<int,float> getForme(void) const;

    /**
     * @brief Get the Type object
     *
     * @return std::string
     */
    std::string getType(void) const;

    /**
     * @brief Récupère le pourcentage constructible
     * 
     * @return int 
     */
    int getPConstructible(void) const;

    /**
     * @brief Set the Numero object
     *
     * @param numero Le numéro de la parcelle
     */
    void setNumero(int numero);

    /**
     * @brief Set the Proprietaire object
     *
     * @param proprio Le nom du propriétaire
     */
    void setProprietaire(std::string proprio);

    /**
     * @brief Set pConstructible object
     * 
     * @param pCons La valeur du pourcentage
     */
    void setPConstructible(int pCons);

    /**
     * @brief Set the Surface object
     * 
     * @param surface La surface de la parcelle
     */
    void setSurface(float surface);

    /**
     * @brief Défini la forme de la parcelle
     *
     */
    // void setForme(Polygone<int,float> forme);

    /**
     * @brief Set the Type object
     *
     * @param type Type de parcelle
     */
    virtual void setType(std::string type) = 0;
};

#endif