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

#include <Parcelle.hpp>

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
    Polygone<T> getPolygone(std::string pointList);

    /**
     * @brief Get the Parcelle object
     * 
     * @tparam T typename for Parcelle
     * @param format Must be a Format defined in Fichier.hpp
     * @return Parcelle<T> 
     */
    template<typename T>
    Parcelle<T> getParcelle(std::string format);
};

template<typename T>
Polygone<T>* getPolygone(std::string pointList) {
    std::vector<Point2D<T>> points;
    std::stringstream ss(pointList);
    std::string tok;

    int xn;
    int yn;

    while (getline(ss, tok, ' ')) {
        sscanf(tok, POINT_FORMAT, xn, yn);
        points.push_back(Point2D<T>(static_cast<T>(xn), static_cast<T>(yn)))
    }
    
    return Polygone<T>(points);
}

template<typename T>
Parcelle<T> getParcelle(std::string format) {

    std::string token;
    std::stringstream sformat(format);

    std::string type;
    std::string owner;
    int num;

    getline(sformat, token, ' ');

    if (token == "ZAU") {
        std::sscanf(texte.at(i).c_str(), PARCELLE_FORMAT_ZAU, 
            pc_type, &number, pc_name, &percentConstructible, &charRed);



        std::cout << "\tType : " << std::string(pc_type) << "\n";
        std::cout << "\tNumber : " << number << "\n";
        std::cout << "\tName : " << std::string(pc_name) << "\n";
        std::cout << "\t%Construct : " << percentConstructible << "\n";
        std::cout << "\tPoints : " << texte.at(i).substr(charRed)  << "\n";
    }
    else if (token = "ZA") {
        std::sscanf(texte.at(i).c_str(), PARCELLE_FORMAT_ZA, 
            pc_type, &number, pc_name, pc_culture, &charRed);

        std::cout << "\tType : " << std::string(pc_type) << "\n";
        std::cout << "\tNumber : " << number << "\n";
        std::cout << "\tName : " << std::string(pc_name) << "\n";
        std::cout << "\tCulture : " << std::string(pc_culture) << "\n";
        std::cout << "\tPoints : " << texte.at(i).substr(charRed) << "\n";
    }
    else if (token = "ZU") {
        std::sscanf(texte.at(i).c_str(), PARCELLE_FORMAT_ZU, 
            pc_type, &number, pc_name, &percentConstructible, &surfaceConstruite, &charRed);

        std::cout << "\tType : " << std::string(pc_type) << "\n";
        std::cout << "\tNumber : " << number << "\n";
        std::cout << "\tName : " << std::string(pc_name) << "\n";
        std::cout << "\t%Construct : " << percentConstructible << "\n";
        std::cout << "\tsurfConstr : " << surfaceConstruite << "\n";
        std::cout << "\tPoints : " << texte.at(i).substr(charRed) << "\n";
    }
    else if (token = "ZN") {
        std::sscanf(texte.at(i).c_str(), PARCELLE_FORMAT_ZN, 
            pc_type, &number, pc_name, &charRed);

        std::cout << "\tType : " << std::string(pc_type) << "\n";
        std::cout << "\tNumber : " << number << "\n";
        std::cout << "\tName : " << std::string(pc_name) << "\n";
        std::cout << "\tPoints : " << texte.at(i).substr(charRed) << "\n";
    }
    else {
        std::cerr << "Unknow type : " << texte.at(i) << "\n";
    }

}


#endif  /* FICHIER_HPP_ */