#include <iostream>
#include "../Controller/PokemonController.h"

using namespace std;


int main() {
    PokemonController poke;
    cout << "Tesst" << endl;

    int option = 0;
    int idJoueur = -1;

    // Choisir un joueur
    cout << "Bienvenue sur le jeu Pokemon !" << endl;
    cout << "Veuillez choisir un joueur : " << endl;
    for(int i = 1; i <= poke.getAllJoueurs().size(); i++) {
        cout << i << " - " << poke.getAllJoueurs()[i-1].getNom() << endl;
    }
    cin >> idJoueur;

    while (idJoueur < 1 || idJoueur > poke.getAllJoueurs().size()) {
        cout << "Numéro de joueur incorrect ! Veuillez réessayer" << endl;;
        cout << "Veuillez choisir un joueur : " << endl;
        for(int i = 1; i <= poke.getAllJoueurs().size(); i++) {
            cout << i << " - " << poke.getAllJoueurs()[i-1].getNom() << endl;
        }
        cin >> idJoueur;
    }
    cout << "Joueur choisi : " + poke.getAllJoueurs()[idJoueur-1].getNom() << endl;

    idJoueur--;

    do {
        cout << "Veuillez choisir une option : " << endl;
        cout << "1. Afficher les Pokemons et leurs attributs" << endl;
        cout << "2. Récupérer les points de vie (HP) des Pokemons" << endl;
        cout << "3. Changer l'ordre des Pokemons dans l'équipe" << endl;
        cout << "4. Afficher les statistiques du Joueur" << endl;
        cout << "5. Affronter un Gymnase" << endl;
        cout << "6. Affronter un Maître Pokemon" << endl;
        cout << "7. Intéragir avec les Pokemons ou les entraîneurs vaincus" << endl;
        cout << "8. Quitter le jeu" << endl;

        cin >> option;
        if(option <= 0 || option > 8) {
            while(option <= 0 || option > 8) {
                cout << "Option incorrecte, veuillez choisir une autre option" << endl;
                cin >> option;
            }
        }

        if(option == 1) {
            cout << "Pokémons possédés par le joueur : " << endl;
            for(int i = 0; i < 7; i++) {
                if(poke.getAllJoueurs()[idJoueur].getPokemon(i) != nullptr) {
                    cout << "Pokemon " << i + 1 << endl;
                    cout << poke.getAllJoueurs()[idJoueur].getPokemon(i)->toString() << "\n" << endl;
                }
                
            }
        }

    } while(option != 8);

    

    return 0;
}