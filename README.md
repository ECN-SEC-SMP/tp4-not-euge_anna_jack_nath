# CPP - TP4 Noté

- Eugénie
- Annabelle
- Jack
- Nathan

## Sommaire

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

Run default
```bash
./build/CPP_TP4
```

## Tests

Run Tests
```bash
./build/CPP_TP4_Test nomClasse

ex:
./build/CPP_TP4_Test Point Polygon Fichier
```

## Codes de test

Les codes de test doivent être mis dans le dossier `test/`

![rdme_test_dir_test.png](assets/readme/rdme_test_dir_test.png)

### Ajout fonction de test

Le `mainTest()` utilise un `map<>` pour lier le nom des classes au fonctions de test.

Il faut donc faire les modification suivantes :

> Ajout du `.hpp` des fichiers de test.  
> ![rdme_test_ajout_include.png](assets/readme/rdme_test_ajout_include.png)  

> Ajout du de la fonction de test dans le `map<>`.  
> ![rdme_test_ajout_func_in_map.png](assets/readme/rdme_test_ajout_func_in_map.png)

