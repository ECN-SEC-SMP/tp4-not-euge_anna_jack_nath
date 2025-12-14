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
#include <sstream>
#include <vector>

#include <Parcelle.hpp>
#include <ZA.hpp>
#include <ZAU.hpp>
#include <ZN.hpp>
#include <ZU.hpp>

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

    /**
     * @brief Get the Polygone object
     * 
     * @tparam T typename for Polygone
     * @param pointList Must be a string in the format "[x1,y1] [x2,y2] ... [xn,yn]"
     * @return Polygone<T> 
     */
    template<typename T>
    Polygone<T>* getPolygone(std::string pointList);

    /**
     * @brief Get the Parcelle object
     * 
     * @tparam T typename for Parcelle
     * @param format Must be a Format defined in Fichier.hpp
     * @return Parcelle<T> 
     */
    template<typename T>
    Parcelle<T>* getParcelle(std::string format);
};

template<typename T>
Polygone<T>* Fichier::getPolygone(std::string pointList) {
    std::vector<Point2D<T>> points;
    std::stringstream ss(pointList);
    std::string tok;

    int xn;
    int yn;

    // DEBUG
    std::cout << __func__ << "\n" << "\t";
    std::cout << pointList << "\n";

    while (std::getline(ss, tok, ' ')) {
        sscanf(tok.c_str(), POINT_FORMAT, &xn, &yn);
        points.push_back(Point2D<T>(static_cast<T>(xn), static_cast<T>(yn)));
    }
    
    return new Polygone<T>(points);
}

template<typename T>
Parcelle<T>* Fichier::getParcelle(std::string format) {

    // DEBUG
    std::cout << __func__ << "\n" << "\t";
    std::cout << format << "\n";

    Parcelle<T>* retParcelle;
    Polygone<T>* forme;

    std::string token;
    std::stringstream sformat(format);

    std::string type;
    std::string owner;
    std::string culture;
    int num;

    float pConstr;  // Buildable percentage
    float surfConstr; // Built area

    // Get type
    std::getline(sformat, token, ' ');
    type = token;
    
    // Get number
    std::getline(sformat, token, ' ');
    num = std::stoi(token);
    
    // Get owner
    std::getline(sformat, token, ' ');
    owner = token;
    
    if (type == "ZAU") {
        std::getline(sformat, token, ' ');
        pConstr = (std::stof(token) / 100);

        // Get points list and parse it into a polygone
        std::getline(sformat, token);
        forme = getPolygone<T>(token);

        retParcelle = new ZAU(num, owner, pConstr, forme);
    }
    else if (type == "ZA") {
        std::getline(sformat, token, ' ');
        culture = token;
        
        // Get points list and parse it into a polygone
        std::getline(sformat, token);
        forme = getPolygone<T>(token);

        retParcelle = new ZA(num, owner, culture, forme);
    }
    else if (type == "ZU") {
        std::getline(sformat, token, ' ');
        pConstr = (std::stof(token) / 100);

        std::getline(sformat, token, ' ');
        surfConstr = (std::stof(token) / 100);

        std::cout << "pcontsdtdf " << pConstr << "\n";
        std::cout << "surfConstr " << surfConstr << "\n";
        
        // Get points list and parse it into a polygone
        std::getline(sformat, token);
        forme = getPolygone<T>(token);

        retParcelle = new ZU(num, owner, pConstr, surfConstr, forme);
    }
    else if (type == "ZN") {
        
        // Get points list and parse it into a polygone
        std::getline(sformat, token);
        forme = getPolygone<T>(token);

        retParcelle = new ZN(num, owner, forme);
    }
    else {
        std::cerr << "Unknow type : " << type << "\n";
    }

    return retParcelle;
}


#endif  /* FICHIER_HPP_ */