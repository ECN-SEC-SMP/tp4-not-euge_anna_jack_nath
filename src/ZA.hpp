#ifndef _ZA_HPP
#define _ZA_HPP

#include "Constructible.hpp"
#include <string>
#include <iostream>

#define ZA_P_CONSTRUCTIBLE  0.1f
#define ZA_MAX_SURFACE_CONSTRUITE  200 // m²

/**
 * @brief Classe Zonne Agricole qui hérite de Constructible
 *
 */
template <typename T>
class ZA : public Constructible<T>
{
private:
    std::string typeCulture;

public:
    /**
     * @brief Construct a new ZA object
     *
     */
    ZA(int num, std::string prop, std::string culture, Polygone<T> *forme) 
        : Constructible<T>(num, prop, 0, ZA_P_CONSTRUCTIBLE, forme)
    {
        this->type = "ZA";
        this->typeCulture = culture;
    }

    /**
     * @brief Get the type of the culture growing on the parcel
     *
     * @return std::string
     */
    std::string getTypeCulture() const
    {
        return this->typeCulture;
    }

    /**
     * @brief Set the type of the culture growing on the parcel
     *
     * @param culture
     */
    void setTypeCulture(std::string culture)
    {
        this->typeCulture = culture;
    }

    /**
     * @brief Destroy the ZA object
     *
     */
    ~ZA() {}

    /**
     * @brief Redefine tostring operator for object
     *
     * @return std::string
     */
    operator std::string() const
    {
        std::string stringify = Parcelle<int>::operator std::string();

        stringify += "\tCulture : " + this->typeCulture;

        return stringify;
    }
    /**
     * @brief Print the type of the object
     *
     * @param s
     * @param za
     * @return ZA
     */
    friend std::ostream &operator<<(std::ostream &s, const ZA &za)
    {
        s << std::string(za);
        return s;
    }
};

#endif