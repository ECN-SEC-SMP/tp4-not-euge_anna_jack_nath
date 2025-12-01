/**
 * @file mainTest.cpp
 * @brief Main de test
 * @version 0.1
 * @date 2025-12-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <cstdint>
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>

// Test includes
#include "FichierTest.hpp"

typedef void (*testFunc_t)(void);

std::map<std::string, testFunc_t> testMap = {
    {"Fichier", FichierTest}
};

 int main(int argc, char const *argv[])
 {
    std::cout << "==============================" << "\n";
    std::cout << "CPP TP4 - TEST Euge Anna Jack Nath " << "\n";
    std::cout << "==============================" << "\n";
    std::cout << std::endl;

    std::cout << "Classes Tested :\n";
    for (uint16_t i = 0; i < argc; i++)
    {
        std::cout << argv[i] << "\n";
    }
    std::cout << "\n";

    if (argc <= 1) {
        
        throw std::invalid_argument( "Except at least 1 class name to test" );
    }

    for (uint8_t i = 1; i < argc; i++)
    {
        // Check if current argument is Valid
        // If contains is not recognized : go to settings " @ext:ms-vscode.cpptools cppStandard " set c++20 
        if (!(testMap.contains(argv[i]))) {
            throw std::invalid_argument( std::string(argv[i]) + " does not exist" );
        }

        std::cout << "=============== " << argv[i] << " ===============" << "\n";

        // Call test function
        testMap[argv[i]]();

        std::cout << "\n";
    }


    return 0;
 }
 