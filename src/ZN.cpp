#include "ZN.hpp"

ZN :: ZN(int num, std::string prop /*,Polygone<int,float> *forme*/) : Parcelle(num, prop /*,Polygone<int,float> *forme*/)
{
    this->type = "ZN";
}

ZN :: ~ZN() { };