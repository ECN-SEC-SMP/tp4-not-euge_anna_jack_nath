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
#include <vector>

// ==================================================
// Defines
// ==================================================
#define POINT_FORMAT "[%d;%d]"

// Type Number Name point [point point ...]
#define PARCELLE_FORMAT_ZN  "%s %hu %s %n"

// Type Number Name Culture [point point point ...]
#define PARCELLE_FORMAT_ZA  "%s %hu %s %s %n"

// Type Number Name %Constructible surfaceConstruite [point point point ...]
#define PARCELLE_FORMAT_ZU  "%s %hu %s %hu %hu %n"

// Type Number Name %Constructible [point point point ...]
#define PARCELLE_FORMAT_ZAU "%s %hu %s %hu %n"

/**
 * @brief This class should be used to read data for this project.
 * 
 * It read a file 2 lines per 2 lines and return datas in 1 string without Line Feed (\n).
 * 
 */
class Fichier
{
private:
    std::string inputDir;
    std::string outputDir;
public:
    Fichier(std::string inputDir, std::string outputDir);
    ~Fichier();


    /**
     * @brief Read a file if it exist.
     * 
     * Return a vector of string, each string contain data to create a Parcelle object.  
     * There is define that describe the format for each type of parcelle.
     * 
     * @param file Name of the file
     * @return std::vector<std::string>
     */
    std::vector<std::string> open(std::string file);

    /**
     * @brief Write data in a file.
     * 
     * @param file Name of the file
     * @param data 
     */
    void write(std::string file, std::string data);
};


#endif  /* FICHIER_HPP_ */