#include "ZUTests.hpp"

void ZUTests() {

    // Test parcelle ZU sans surface construite
    Polygone<int>* forme = new Polygone<int>();
    ZU parcelle1(1, "Anna", forme);
    std::cout << "ZU parcelle: " << parcelle1 << " numéro " << parcelle1.getNumero() << " propriétaire " << parcelle1.getProprietaire() << "forme" << parcelle1.getForme() << std::endl;

    // Test parcelle ZU avec surface construite
    ZU parcelle2(2, "Jack", 150.0, forme);
    std::cout << "ZU parcelle: " << parcelle2 << " numéro " << parcelle2.getNumero() << " propriétaire " << parcelle2.getProprietaire() << " forme " << parcelle2.getForme() << " surface construite " << parcelle2.getSurfaceConstruite() << std::endl;


   //Tests du setter et du getter
    parcelle2.setSurfaceConstruite(200.0);
    std::cout << "Après modification, surface construite : " << parcelle2.getSurfaceConstruite() << std::endl;


    return;
}