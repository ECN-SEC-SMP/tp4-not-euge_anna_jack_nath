#include "ZUTest.hpp"

void ZUTests()
{
    std::cout << "Debut test ZU:" << std::endl;

    ZUtest_constructeur();
    ZUtest_setSurfaceConstruite();
    ZUtest_getSurfaceConstruite();
    ZUtest_affichage();
    std::cout << "ZU : OK" << std::endl;
}

void ZUtest_constructeur(void)
{
    std::vector<Point2D<int>> points;

    points.push_back(Point2D<int>(1, 2));
    points.push_back(Point2D<int>(3, 4));
    points.push_back(Point2D<int>(-1, 5));

    Polygone<int> *poly = new Polygone<int>(points);

    ZU zoneUrbaine_1 = ZU<int>(1, "Jack", poly);
    assert(zoneUrbaine_1.getNumero() == 1);
    assert(zoneUrbaine_1.getProprietaire() == "Jack");
    assert(zoneUrbaine_1.getSurfaceConstruite() == 0);
    assert(zoneUrbaine_1.getType() == "ZU");
    assert(zoneUrbaine_1.getForme() == poly);

    ZU zoneUrbaine_2 = ZU<int>(1, "Jack", 12.1, poly);
    assert(zoneUrbaine_2.getNumero() == 1);
    assert(zoneUrbaine_2.getProprietaire() == "Jack");
    assert(zoneUrbaine_2.getSurfaceConstruite() == float(12.1));
    assert(zoneUrbaine_2.getType() == "ZU");
    assert(zoneUrbaine_2.getForme() == poly);
}
void ZUtest_setSurfaceConstruite(void)
{
    std::vector<Point2D<int>> points;

    points.push_back(Point2D<int>(1, 2));
    points.push_back(Point2D<int>(3, 4));
    points.push_back(Point2D<int>(-1, 5));

    Polygone<int> *poly = new Polygone<int>(points);

    ZU zoneUrbaine = ZU<int>(1, "Jack", poly);
    assert(zoneUrbaine.getSurfaceConstruite() == 0);
    zoneUrbaine.setSurfaceConstruite(15.2);
    assert(zoneUrbaine.getSurfaceConstruite() == float(15.2));
}
void ZUtest_getSurfaceConstruite(void)
{
    std::vector<Point2D<int>> points;

    points.push_back(Point2D<int>(1, 2));
    points.push_back(Point2D<int>(3, 4));
    points.push_back(Point2D<int>(-1, 5));

    Polygone<int> *poly = new Polygone<int>(points);

    ZU zoneUrbaine = ZU<int>(1, "Jack", 16.7, poly);
    assert(zoneUrbaine.getSurfaceConstruite() == float(16.7));
}

void ZUtest_affichage(void)
{
    std::vector<Point2D<int>> points;

    points.push_back(Point2D<int>(1, 2));
    points.push_back(Point2D<int>(3, 4));
    points.push_back(Point2D<int>(-1, 5));

    Polygone<int> *poly = new Polygone<int>(points);

    ZU zoneUrbaine_1 = ZU<int>(1, "Jack", poly);
    ZU zoneUrbaine_2 = ZU<int>(1, "Jack", 12.1, poly);

    std::cout << zoneUrbaine_1 << std::endl;
    std::cout << zoneUrbaine_2 << std::endl;
}