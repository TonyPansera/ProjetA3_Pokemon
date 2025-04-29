#include <iostream>
#include "../Controller/PokemonController.h"

using namespace std;


int main() {
    PokemonController poke;
    cout << "Tesst" << endl;

    cout << "Bienvenue sur le jeu Pokemon !" << endl;
    cout << "Veuillez choisir une option : " << endl;
    cout << "1. Afficher les Pokemons et leurs attributs" << endl;
    cout << "Récupérer les points de vie (HP) des Pokemons" << endl;
    cout << "Changer l'ordre des Pokemons dans l'équipe" << endl;
    cout << "Afficher les statistiques du Joueur" << endl;
    cout << "Affronter un Gymnase" << endl;
    cout << "Affronter un Maître Pokemon" << endl;
    cout << "Intéragir avec les Pokemons ou les entraîneurs vaincus" << endl;

    return 0;
}