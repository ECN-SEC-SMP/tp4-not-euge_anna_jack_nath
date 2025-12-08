#include "ZATest.hpp"

void ZATest()
{

    std::cout << "Debut test ZA:" << std::endl;

    ZAtest_contructeur();
    ZAtest_setCulture();
    ZAtest_getCulture();
    ZAtest_affichage();
    std::cout << "ZA : OK" << std::endl;
}

void ZAtest_contructeur(void)
{
    std::vector<Point2D<int>> points;

    points.push_back(Point2D<int>(1, 2));
    points.push_back(Point2D<int>(3, 4));
    points.push_back(Point2D<int>(-1, 5));

    Polygone<int> *poly = new Polygone<int>(points);

    ZA zoneAgricole = ZA<int>(1, "Jack", "Maïs", poly);

    assert(zoneAgricole.getNumero() == 1);
    assert(zoneAgricole.getProprietaire() == "Jack");
    assert(zoneAgricole.getType() == "ZA");
    assert(zoneAgricole.getTypeCulture() == "Maïs");
    assert(zoneAgricole.getForme() == poly);
}

void ZAtest_affichage(void)
{
    std::vector<Point2D<int>> points;

    points.push_back(Point2D<int>(1, 2));
    points.push_back(Point2D<int>(3, 4));
    points.push_back(Point2D<int>(-1, 5));

    Polygone<int> *poly = new Polygone<int>(points);

    ZA zoneAgricole = ZA<int>(1, "Jack", "Maïs", poly);
    std::cout << zoneAgricole << std::endl;
}
void ZAtest_setCulture(void)
{
    std::vector<Point2D<int>> points;

    points.push_back(Point2D<int>(1, 2));
    points.push_back(Point2D<int>(3, 4));
    points.push_back(Point2D<int>(-1, 5));

    Polygone<int> *poly = new Polygone<int>(points);

    ZA zoneAgricole = ZA<int>(1, "Jack", "Maïs", poly);

    assert(zoneAgricole.getTypeCulture() == "Maïs");

    zoneAgricole.setTypeCulture("Blé");

    assert(zoneAgricole.getTypeCulture() == "Blé");
}
void ZAtest_getCulture(void)
{
    std::vector<Point2D<int>> points;

    points.push_back(Point2D<int>(1, 2));
    points.push_back(Point2D<int>(3, 4));
    points.push_back(Point2D<int>(-1, 5));

    Polygone<int> *poly = new Polygone<int>(points);

    ZA zoneAgricole = ZA<int>(1, "Jack", "Maïs", poly);

    assert(zoneAgricole.getTypeCulture() == "Maïs");
}
