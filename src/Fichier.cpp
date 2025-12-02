
#include "Fichier.hpp"

/**
 * @brief Construct a new Fichier:: Fichier object
 * 
 * @param inputDir 
 * @param outputDir 
 */
Fichier::Fichier(std::string inputDir, std::string outputDir) {
    this->inputDir = inputDir;
    this->outputDir = outputDir;
}

Fichier::~Fichier() {

}
