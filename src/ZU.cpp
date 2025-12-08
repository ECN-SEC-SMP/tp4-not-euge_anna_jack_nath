#include "ZU.hpp"

ZU::ZU(int num, std::string prop /*,Polygone<int,float> *forme*/) : Parcelle(num, prop /*,Polygone<int,float> *forme*/)
{
    this->type = "ZU";
}

ZU::ZU(int num, std::string prop, float surfaceC /*,Polygone<int,float> *forme*/) : Parcelle(num, prop /*,Polygone<int,float> *forme*/)
{
    this->type = "ZU";
    this->surfaceConstruite = surfaceC;
}


float ZU::getSurfaceConstruite() const
{
    return this->surfaceConstruite;
}

void ZU::setSurfaceConstruite(float surfaceC)
{
    this->surfaceConstruite = surfaceC;
}


ZU::~ZU() { };