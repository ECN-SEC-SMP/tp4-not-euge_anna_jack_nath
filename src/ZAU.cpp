#include "ZAU.hpp"


ZAU :: ZAU(int num, std::string prop /*,Polygone<int,float> *forme*/) : Parcelle(num, prop /*,Polygone<int,float> *forme*/)
{
    this->type = "ZAU";
}

ZAU :: ~ZAU() { };
