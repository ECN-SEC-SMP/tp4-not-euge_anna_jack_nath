#include "ZATests.hpp"


void ZATests() {

    // Test parcelle ZA
    Polygone<int>* forme = new Polygone<int>();
    ZA parcelle1 = ZA<int>(1, "Anna", "Blé", forme);
    std::cout << "Parcelle de type : " << parcelle1 << " numéro : " << parcelle1.getNumero() << " propriétaire : " << parcelle1.getProprietaire() << " forme : " << parcelle1.getForme() << " type de culture : " << parcelle1.getTypeCulture() << std::endl;
    

    //Tests du setter et du getter
    parcelle1.setTypeCulture("Maïs");
    std::cout << "Après modification, le type de culture est " << parcelle1.getTypeCulture() << std::endl;

    return;
}