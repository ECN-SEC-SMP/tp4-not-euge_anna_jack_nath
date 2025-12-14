/**
 * @file PolygoneTest.cpp
 * @brief 
 * @version 0.1
 * @date 2025-12-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>
#include "PolygoneTest.hpp"
#include "Polygone.hpp"


//crée un polygone, teste le constructeur par copie, 
//ajoute un point et applique une translation, 
//en affichant le tout pour vérifier que tout fonctionne correctement
void PolygoneTest() {
    // Création de points
    Point2D<int> p1(0, 0);
    Point2D<int> p2(1, 0);
    Point2D<int> p3(1, 1);

    // Création d'un polygone avec une liste de points
    std::vector<Point2D<int>> liste = {p1, p2, p3};
    Polygone<int> poly1(liste);

    std::cout << "Polygone initial : " << poly1 << std::endl;

    // Test du constructeur par copie
    Polygone<int> poly2(poly1);
    std::cout << "Polygone copié : " << poly2 << std::endl;

    // Ajouter un point
    Point2D<int> p4(0, 1);
    poly1.addPoint(p4);
    std::cout << "Polygone après ajout d'un point : " << poly1 << std::endl;
    std::cout << "Polygone copié (non modifié) : " << poly2 << std::endl;

    // Translation
    poly1.translate(10, 20);
    std::cout << "Polygone après translation : " << poly1 << std::endl;
    std::cout << "Polygone copié (toujours non modifié) : " << poly2 << std::endl;

    // Surface calculée
    std::cout << "Surface du polygone initial (triangle 0,0 - 1,0 - 0,1) : "
    << poly2.calcSurface() << std::endl;

    // Après ajout d’un point (quadrilatère)
    std::cout << "Surface du polygone modifié : "
    << poly1.calcSurface() << std::endl;

}