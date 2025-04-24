#include "PokemonController.h"
#include <fstream>
#include <iostream>

void PokemonController::addAllPokemons() {
    ifstream fichier("mon_fichier.txt"); // nom du fichier à lire

    if (!fichier) {
        cerr << "Erreur lors de l'ouverture du fichier" << endl;

    } else {
        string ligne;
        while (getline(fichier, ligne)) {
            cout << ligne << endl;  // Affiche chaque ligne
        }
    
        fichier.close();
    }

    
}

void PokemonController::typesInit() {
    alTypes[0] = new Type("Feu");
    alTypes[1] = new Type("Eau");
    alTypes[2] = new Type("Plante");
    alTypes[3] = new Type("Életrik");
    alTypes[4] = new Type("Glace");
    alTypes[5] = new Type("Combat");
    alTypes[6] = new Type("Poison");
    alTypes[7] = new Type("Sol");
    alTypes[8] = new Type("Vol");
    alTypes[9] = new Type("Psy");
    alTypes[10] = new Type("Insecte");
    alTypes[11] = new Type("Roche");
    alTypes[12] = new Type("Spectre");
    alTypes[13] = new Type("Dragon");
    alTypes[14] = new Type("Ténèbres");
    alTypes[15] = new Type("Acier");
    alTypes[16] = new Type("Fée");
    alTypes[17] = new Type("Normal");

    // Type Fée : Combat, Insecte, Ténèbres, Dragon
    alTypes[16]->resistances.push_back(alTypes[5]);
    alTypes[16]->resistances.push_back(alTypes[10]);
    alTypes[16]->resistances.push_back(alTypes[13]);
    alTypes[16]->resistances.push_back(alTypes[14]);

    // Type Acier : Normal, Plante, Glace, Vol, Psy, Insecte, Roche, Dragon, Acier, Fée
    alTypes[15]->resistances.push_back(alTypes[2]);
    alTypes[15]->resistances.push_back(alTypes[4]);
    alTypes[15]->resistances.push_back(alTypes[8]);
    alTypes[15]->resistances.push_back(alTypes[9]);
    alTypes[15]->resistances.push_back(alTypes[10]);
    alTypes[15]->resistances.push_back(alTypes[11]);
    alTypes[15]->resistances.push_back(alTypes[13]);
    alTypes[15]->resistances.push_back(alTypes[15]);
    alTypes[15]->resistances.push_back(alTypes[16]);
    alTypes[15]->resistances.push_back(alTypes[17]);

    // Type Ténèbre : Spectre, Psy, Ténèbres
    alTypes[14]->resistances.push_back(alTypes[9]);
    alTypes[14]->resistances.push_back(alTypes[12]);
    alTypes[14]->resistances.push_back(alTypes[14]);

    // Type Dragon : Feu, Eau, Électrik, Plante
    alTypes[13]->resistances.push_back(alTypes[0]);
    alTypes[13]->resistances.push_back(alTypes[1]);
    alTypes[13]->resistances.push_back(alTypes[2]);
    alTypes[13]->resistances.push_back(alTypes[3]);

    // Type Spectre : Poison, Insecte
    alTypes[12]->resistances.push_back(alTypes[8]);
    alTypes[12]->resistances.push_back(alTypes[10]);

    // Type Roche : Feu, Vol, Poison, Normal
    alTypes[11]->resistances.push_back(alTypes[0]);
    alTypes[11]->resistances.push_back(alTypes[6]);
    alTypes[11]->resistances.push_back(alTypes[8]);
    alTypes[11]->resistances.push_back(alTypes[17]);

    // Type Insecte : Plante, Combat, Sol
    alTypes[10]->resistances.push_back(alTypes[2]);
    alTypes[10]->resistances.push_back(alTypes[5]);
    alTypes[10]->resistances.push_back(alTypes[7]);

    // Type Psy : Combat, Psy
    alTypes[9]->resistances.push_back(alTypes[5]);
    alTypes[9]->resistances.push_back(alTypes[9]);

    // Type Vol : Plante, Combat, Insecte
    alTypes[8]->resistances.push_back(alTypes[2]);
    alTypes[8]->resistances.push_back(alTypes[5]);
    alTypes[8]->resistances.push_back(alTypes[10]);

    // Type Sol : Poison, Roche
    alTypes[7]->resistances.push_back(alTypes[6]);
    alTypes[7]->resistances.push_back(alTypes[11]);

    // Type Poison : Plante, Fée, Combat, Poison, Insecte
    alTypes[6]->resistances.push_back(alTypes[2]);
    alTypes[6]->resistances.push_back(alTypes[5]);
    alTypes[6]->resistances.push_back(alTypes[6]);
    alTypes[6]->resistances.push_back(alTypes[10]);
    alTypes[6]->resistances.push_back(alTypes[16]);

    // Type Combat : Roche, Insecte, Ténèbres
    alTypes[5]->resistances.push_back(alTypes[10]);
    alTypes[5]->resistances.push_back(alTypes[11]);
    alTypes[5]->resistances.push_back(alTypes[14]);

    // Type Glace : Glace
    alTypes[4]->resistances.push_back(alTypes[4]);

    // Type Électrik : Vol, Acier, Électrik
    alTypes[3]->resistances.push_back(alTypes[3]);
    alTypes[3]->resistances.push_back(alTypes[8]);
    alTypes[3]->resistances.push_back(alTypes[15]);

    // Type Plante : résistances Eau, Sol, Roche
    alTypes[2]->resistances.push_back(alTypes[0]);
    alTypes[2]->resistances.push_back(alTypes[7]);
    alTypes[2]->resistances.push_back(alTypes[11]);

    // Type Eau : résistances Feu, Eau, Glace, Acier
    alTypes[1]->resistances.push_back(alTypes[0]);
    alTypes[1]->resistances.push_back(alTypes[1]);
    alTypes[1]->resistances.push_back(alTypes[4]);
    alTypes[1]->resistances.push_back(alTypes[15]);

    // Type Feu : résistance Plante, Glace, Insecte, Acier, Fée
    alTypes[0]->resistances.push_back(alTypes[2]);
    alTypes[0]->resistances.push_back(alTypes[4]);
    alTypes[0]->resistances.push_back(alTypes[10]);
    alTypes[0]->resistances.push_back(alTypes[15]);
    alTypes[0]->resistances.push_back(alTypes[16]);

    // Type Fée : Poison, Acier
    alTypes[16]->faiblesses.push_back(alTypes[6]);
    alTypes[16]->faiblesses.push_back(alTypes[15]);

    // Type Acier : Feu, Combat, Sol
    alTypes[15]->faiblesses.push_back(alTypes[0]);
    alTypes[15]->faiblesses.push_back(alTypes[5]);
    alTypes[15]->faiblesses.push_back(alTypes[7]);

    // Type Ténèbres : Combat, Insecte, Fée
    alTypes[14]->faiblesses.push_back(alTypes[5]);
    alTypes[14]->faiblesses.push_back(alTypes[10]);
    alTypes[14]->faiblesses.push_back(alTypes[16]);

    // Type Dragon : Glace, Dragon, Fée
    alTypes[13]->faiblesses.push_back(alTypes[4]);
    alTypes[13]->faiblesses.push_back(alTypes[13]);
    alTypes[13]->faiblesses.push_back(alTypes[16]);

    // Type Spectre : Spectre, Ténèbres
    alTypes[12]->faiblesses.push_back(alTypes[12]);
    alTypes[12]->faiblesses.push_back(alTypes[14]);

    // Type Roche : Eau, Plante, Combat, Sol, Acier
    alTypes[11]->faiblesses.push_back(alTypes[1]);
    alTypes[11]->faiblesses.push_back(alTypes[2]);
    alTypes[11]->faiblesses.push_back(alTypes[5]);
    alTypes[11]->faiblesses.push_back(alTypes[7]);
    alTypes[11]->faiblesses.push_back(alTypes[15]);

    // Type Insecte : Feu, Vol, Roche
    alTypes[10]->faiblesses.push_back(alTypes[0]);
    alTypes[10]->faiblesses.push_back(alTypes[8]);
    alTypes[10]->faiblesses.push_back(alTypes[11]);

    // Type Psy : faiblesses Insecte, Spectre, Ténèbres
    alTypes[9]->faiblesses.push_back(alTypes[10]);
    alTypes[9]->faiblesses.push_back(alTypes[12]);
    alTypes[9]->faiblesses.push_back(alTypes[14]);

    // Type Vol : faiblesses Électrik, Glace, Roche
    alTypes[8]->faiblesses.push_back(alTypes[3]);
    alTypes[8]->faiblesses.push_back(alTypes[4]);
    alTypes[8]->faiblesses.push_back(alTypes[11]);

    // Type Sol : faiblesses Eau, Plante, Glace
    alTypes[7]->faiblesses.push_back(alTypes[1]);
    alTypes[7]->faiblesses.push_back(alTypes[2]);
    alTypes[7]->faiblesses.push_back(alTypes[4]);

    // Type Poison : faiblesses Sol, Psy
    alTypes[6]->faiblesses.push_back(alTypes[7]);
    alTypes[6]->faiblesses.push_back(alTypes[9]);

    // Type Combat : faiblesses Vol, Psy, Fée
    alTypes[5]->faiblesses.push_back(alTypes[8]);
    alTypes[5]->faiblesses.push_back(alTypes[9]);
    alTypes[5]->faiblesses.push_back(alTypes[16]);

    // Type Glace : faiblesses Feu, Combat, Roche, Acier
    alTypes[4]->faiblesses.push_back(alTypes[0]);
    alTypes[4]->faiblesses.push_back(alTypes[5]);
    alTypes[4]->faiblesses.push_back(alTypes[11]);
    alTypes[4]->faiblesses.push_back(alTypes[15]);

    // Type Feu : faiblesses Eau, Roche, Sol
    alTypes[0]->faiblesses.push_back(alTypes[11]);
    alTypes[0]->faiblesses.push_back(alTypes[1]);
    alTypes[0]->faiblesses.push_back(alTypes[7]);

    // Type Eau : faiblesses Plante, Électrik
    alTypes[1]->faiblesses.push_back(alTypes[2]);
    alTypes[1]->faiblesses.push_back(alTypes[3]);

    // Type Plante : faiblesses Feu, Glace, Poison, Vol, Insecte
    alTypes[2]->faiblesses.push_back(alTypes[1]);
    alTypes[2]->faiblesses.push_back(alTypes[4]);
    alTypes[2]->faiblesses.push_back(alTypes[6]);
    alTypes[2]->faiblesses.push_back(alTypes[8]);
    alTypes[2]->faiblesses.push_back(alTypes[10]);

    // Type Électrik : faiblesse Sol
    alTypes[3]->faiblesses.push_back(alTypes[7]);
    
    
}

