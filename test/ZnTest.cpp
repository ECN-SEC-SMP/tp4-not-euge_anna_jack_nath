#include "ZnTest.hpp"

void ZnTest(void)
{
    std::cout << "Debut test ZN:" << std::endl;

    test_constructeur();
    test_affichage();

    std::cout << "ZN : OK" << std::endl;
}

void test_constructeur(void)
{
    std::vector<Point2D<int>> points;

    points.push_back(Point2D<int>(1, 2));
    points.push_back(Point2D<int>(3, 4));
    points.push_back(Point2D<int>(-1, 5));

    Polygone<int> *poly = new Polygone<int>(points);

    ZN zoneNaturel = ZN<int>(1, "Jack", poly);

    assert(zoneNaturel.getNumero() == 1);
    assert(zoneNaturel.getProprietaire() == "Jack");
    assert(zoneNaturel.getType() == "ZN");
    assert(zoneNaturel.getForme() == poly);
}

void test_affichage(void)
{
    std::vector<Point2D<int>> points;

    points.push_back(Point2D<int>(1, 2));
    points.push_back(Point2D<int>(3, 4));
    points.push_back(Point2D<int>(-1, 5));

    Polygone<int> *poly = new Polygone<int>(points);

    ZN zoneNaturel = ZN<int>(1, "Jack", poly);

    std::cout << zoneNaturel << std::endl;
}
