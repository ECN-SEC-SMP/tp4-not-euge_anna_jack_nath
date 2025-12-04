
#include <fstream>
#include <stdexcept>

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

std::vector<std::string> Fichier::open(std::string file) {
    std::string line;
    std::vector<std::string> out;

    // open file for reading
    std::ifstream fich(this->inputDir + file, std::ios::in);
    if (!fich.is_open())
        throw std::invalid_argument(std::string(PROJECT_PATH) + "/" + this->inputDir + file + " does not exist");
    else
    {
        while (!fich.eof())
        {
            std::getline(fich, line);
            out.push_back(line);
            
            std::getline(fich, line);
            
            out.back() += " " + line;
        }
    }

    return out;
}

void Fichier::write(std::string file, std::string data) {

    std::ofstream fich(this->outputDir + file, std::ios::app);

    if (!fich.is_open())
        throw std::invalid_argument(std::string(PROJECT_PATH) + "/" + this->inputDir + file + " does not exist");
    else
    {
        fich << data;
    }

    return;
}
