/**
 * @file CarteTest.cpp
 * @brief 
 */
#include <iostream>
#include "ParcelleTest.hpp"
#include "Parcelle.hpp"
#include "Polygone.hpp"
#include "Carte.hpp"

/**
 * @brief Test du constructeur de Parcelle
 */
void testConstructeurParcelle() {

    std::cout << "\n[TEST] Constructeur de Parcelle" << std::endl;

    // Création de points
    Point2D<int> p1(0, 0);
    Point2D<int> p2(1, 0);
    Point2D<int> p3(0, 1);

    // Création d'un polygone avec une liste de points
    std::vector<Point2D<int>> liste = {p1, p2, p3};
    Polygone<int> poly1(liste);
    std::cout << "Polygone initial : " << poly1 << std::endl;

    try {
        Parcelle<int> parc(1, "Dupont", &poly1);

        std::cout << " - Numéro : " << parc.getNumero() << std::endl;
        std::cout << " - Propriétaire : " << parc.getProprietaire() << std::endl;
        std::cout << " - Constructible : " << parc.getPConstructible() << "%" << std::endl;
        std::cout << " - Surface : " << parc.getSurface() << std::endl;
        std::cout << " - Forme OK" << std::endl;

    } catch (std::exception& e) {
        std::cout << "[ERREUR] Exception levée : " << e.what() << std::endl;
    }
}