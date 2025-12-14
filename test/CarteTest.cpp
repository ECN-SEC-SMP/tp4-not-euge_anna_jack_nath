/**
 * @file CarteTest.cpp
 * @brief 
 */
#include <iostream>
#include "CarteTest.hpp"
#include "Carte.hpp"
#include "Parcelle.hpp"
#include "ZN.hpp"

// Test 1 - carte vide

void testCarteVide() {
    Carte<int> c;

    std::cout << "[TEST 1] Carte vide" << std::endl;
    std::cout << "Surface attendue = 0, surface obtenue = " << c.getSurface() << std::endl;
    std::cout << "Nb parcelles attendu = 0, obtenu = " << c.getParcelles().size() << std::endl;
}

// Test 2 - Ajout parcelle
void testAjoutSimple() {
    // Polygone factice
    Polygone<int>* poly = new Polygone<int>(std::vector<Point2D<int>>{{0,0},{1,0},{1,1}});

    Parcelle<int>* p = new ZN<int>(1, "Alice", poly);

    Carte<int> c;
    c.addParcelle(p);

    std::cout << "[TEST 2] Ajout simple" << std::endl;
    std::cout << "Surface attendue = 10, surface obtenue = " << c.getSurface() << std::endl;
    std::cout << "Nb parcelles = " << c.getParcelles().size() << std::endl;

}


void CarteTest(void) {

    testCarteVide();

    testAjoutSimple();

}