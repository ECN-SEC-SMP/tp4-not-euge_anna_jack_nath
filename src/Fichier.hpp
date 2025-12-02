/**
 * @file Fichier.hpp
 * @brief 
 * @version 0.1
 * @date 2025-12-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef FICHIER_HPP_
#define FICHIER_HPP_

#include <string>

class Fichier
{
private:
    std::string inputDir;
    std::string outputDir;
public:
    Fichier(std::string inputDir, std::string outputDir);
    ~Fichier();

};


#endif  /* FICHIER_HPP_ */