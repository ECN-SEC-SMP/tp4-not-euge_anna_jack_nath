/**
 * @file FichierTest.cpp
 * @brief 
 * @version 0.1
 * @date 2025-12-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>
#include <cstdint>

#include "Fichier.hpp"

void FichierTest(void) {

    Fichier fich = Fichier("assets/", "output/");

    // Parcelle params
    char pc_type[50];
    uint16_t number;
    char pc_name[50];
    char pc_points[50];

    // ZA
    char pc_culture[50];

    // ZU / ZAU
    uint16_t percentConstructible;
    uint16_t surfaceConstruite;

    std::vector<std::string> texte;

    uint32_t charRed;

    try
    {
        texte = fich.open("Becherele.txt");
    }
    catch(const std::invalid_argument& e)
    {
        std::cout << "Got invalid argument as expected" << "\n";
    }
    
    try
    {
        texte = fich.open("Parcelles_short.txt");
    }
    catch(const std::invalid_argument& e)
    {
        std::cout << "File exist but got invalid argument" << "\n";
        std::cout << e.what() << "\n";
    }

    std::cout << "File content :\n";
    for (uint8_t i = 0; i < texte.size(); i++)
    {
        std::cout << texte.at(i) << "\n";
        if (texte.at(i).starts_with("ZAU")) {
            std::sscanf(texte.at(i).c_str(), PARCELLE_FORMAT_ZAU, 
                pc_type, &number, pc_name, &percentConstructible, &charRed);

            std::cout << "\tType : " << std::string(pc_type) << "\n";
            std::cout << "\tNumber : " << number << "\n";
            std::cout << "\tName : " << std::string(pc_name) << "\n";
            std::cout << "\t%Construct : " << percentConstructible << "\n";
            std::cout << "\tPoints : " << texte.at(i).substr(charRed)  << "\n";
        }
        else if (texte.at(i).starts_with("ZA")) {
            std::sscanf(texte.at(i).c_str(), PARCELLE_FORMAT_ZA, 
                pc_type, &number, pc_name, pc_culture, &charRed);

            std::cout << "\tType : " << std::string(pc_type) << "\n";
            std::cout << "\tNumber : " << number << "\n";
            std::cout << "\tName : " << std::string(pc_name) << "\n";
            std::cout << "\tCulture : " << std::string(pc_culture) << "\n";
            std::cout << "\tPoints : " << texte.at(i).substr(charRed) << "\n";
        }
        else if (texte.at(i).starts_with("ZU")) {
            std::sscanf(texte.at(i).c_str(), PARCELLE_FORMAT_ZU, 
                pc_type, &number, pc_name, &percentConstructible, &surfaceConstruite, &charRed);

            std::cout << "\tType : " << std::string(pc_type) << "\n";
            std::cout << "\tNumber : " << number << "\n";
            std::cout << "\tName : " << std::string(pc_name) << "\n";
            std::cout << "\t%Construct : " << percentConstructible << "\n";
            std::cout << "\tsurfConstr : " << surfaceConstruite << "\n";
            std::cout << "\tPoints : " << texte.at(i).substr(charRed) << "\n";
        }
        else if (texte.at(i).starts_with("ZN")) {
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
        std::cout << "===\n";
    }

    std::cout << "===== Ecriture\n";

    fich.write("FichierTests_results.txt", "Parcelle n 43\n");
    fich.write("FichierTests_results.txt", "\tType : ZU\n");
    fich.write("FichierTests_results.txt", "\tPolygone : [0;30] [60;100] [0;100]\n");
    fich.write("FichierTests_results.txt", "\tPropriétaire : bdaerz\n");
    fich.write("FichierTests_results.txt", "\tSurface : 2100.0\n");
    fich.write("FichierTests_results.txt", "\t% constructible : 55%\n");
    fich.write("FichierTests_results.txt", "\tsurface construite : 479.12198\n");
    fich.write("FichierTests_results.txt", "\tsurface à construire restante : 675.87805\n");

    
    return;
}