#include "ZA.hpp"


ZA :: ZA(int num, std::string prop, std::string culture /*,Polygone<int,float> *forme*/) : Constructible(num, prop /*,forme*/)
{
    this->type = "ZA";
    this->typeCulture = culture;
};


std::string ZA :: getTypeCulture() const
{
    return this->typeCulture;
}

void ZA :: setTypeCulture(std::string culture)
{
    this->typeCulture = culture;
}

ZA :: ~ZA() { };