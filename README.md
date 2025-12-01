# CPP - TP4 Noté

- Eugénie
- Annabelle
- Jack
- Nathan


## Build

Create build dir
```bash
mkdir build
```

Compile
```bash
cmake -Bbuild
cmake --build build/
```

Run
```bash
./build/CPP_TP4
```

## Diagramme

``` mermaid
--- 
title: PLU class Diagram
---
classDiagram
    Parcelle <|-- Constructible
    Parcelle <|-- ZN
    Constructible <|-- ZAU
    Constructible <|-- ZU
    Constructible <|-- ZA
    ZN <|-- ZA
    Point~T~ *-- Polygone
    Polygone *-- Parcelle
    Carte *-- Parcelle

    class Point~T~{
        - x : T
        - y : T
        + Point(T x, T y)
        + Point()
        + Point(Point~T~ p)
        + ~Point()
        + getX() T
        + getY() T
        + setX(T x) void
        + setY(T y) void
        + translate(T x, T y) void
    }
    class Polygone{
        - sommets: Vector~Point~T~~
        + Polygone()
        + Polygone(Vector~Point~T~~ listeSommets)
        + Polygone(Polygone~T~ poly)
        + ~Polygone()
        + getSommets() Vector~Point~T~~
        + setSommets(Vector~Point~T~~ listeSommets) void
        + addPoint(Point~T~ point) void
        + translate(T x, T y) void 

    }
    class Parcelle{
        - type: string
        - numero : int
        - proprietaire: string
        - surface: float
        - forme: Polygone~int~
        - pConstructible: int
        + Parcelle(int num, string prop, Polygone~int,float~ forme)
        + Parcelle(Parcelle parc)
        + ~Parcelle()
        + getNumero() int
        + getProprietaire() string
        + getSurface() float
        + getForme() Polygone~int,float~
        + getType() string
        + setNumero(int numero) void
        + setProprietaire(string proprio) void
        + setForme(Polygone~int~ forme) void
        + setType(string type) = 0*
    }
    class Carte {
        - listeParcelles: Vector~Parcelle~
        - surface: float
        + Carte()
        + Carte(Vector~Parcelle~ parcelles)
        + Carte(string file)
        + ~Carte()
        + save(string file)
    }
    class Constructible {
        <<abstract>>
        - surfaceConstructible float
        + surfaceConstructible() = 0*
        + getSurfaceConstructible() float
        + setSurfaceConstructible(float surfaceCons) void
        + construire(Polygone~int~ poly) boolean
    }
    class ZN {
        + ZN()
        +~ZN()
    }
    class ZA {
        - typeCulture: string
        + ZA(string typeCulture)
        + ~ZA()
        + setTypeCulture(string typeCulture) void
        + getTypeCulture() string
    }
    class ZU {
        - surfaceConstruite: float
        + ZU()
        + ZU(float surfaceConstruite)
        + ~ZU()
        + setSurfaceConstruite(float surfaceC) void
        + getSurfaceConstruite() float
    }
    class ZAU {
        + ZAU()
        + ~ZAU()
    }
```