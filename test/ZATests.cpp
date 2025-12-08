#include "ZATests.hpp"


void ZATests() {

    // Test parcelle ZA
    Polygone<int>* forme = new Polygone<int>();
    ZA parcelle1(1, "Anna", "Blé", forme);
    std::cout << "ZA parcelle: " << parcelle1 << " numéro " << parcelle1->getNumero() << " propriétaire " << parcelle1->getProprietaire() << " forme " << parcelle1->getForme() << " type de culture " << parcelle1->getTypeCulture() << std::endl;

    //Tests du setter et du getter
    parcelle1.setTypeCulture("Maïs");
    std::cout << "Après modification, type de culture : " << parcelle1.getTypeCulture() << std::endl;

    //Besoin de nettoyer ?

    return;
}