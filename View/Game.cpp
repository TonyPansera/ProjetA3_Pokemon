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
        } else if(option == 2) {
            cout << "Récupération des PV des Pokemons... " << endl;
            for(int i = 0; i < 7; i++) {
                if(poke.getAllJoueurs()[idJoueur].getPokemon(i) != nullptr) {
                    poke.getAllJoueurs()[idJoueur].getPokemon(i)->setPvActuels();
                }
            }
            cout << "PV récupérés !" << endl;
        } else if(option == 3) {
            int idChange = -1; // id du Pokemon à déplacer
            int idNouveau = -1; // nouvel emplacement du Pokemon

            cout << "Les Pokemons sont actuellement dans cet ordre : " << endl;
            int a = 0; // Pour avoir le nombre de pokemons possédés
            for(int i = 0; i < 7; i++) {
                if(poke.getAllJoueurs()[idJoueur].getPokemon(i) != nullptr) {
                    cout << i + 1 << ". " + poke.getAllJoueurs()[idJoueur].getPokemon(i)->getNom() << endl;
                    a++;
                }
            }
            cout << "Choisir le Pokemon à changer de place : " << endl;
            cin >> idChange;
            while(idChange <= 0 || idChange > a) {
                // [1 - nombre de pokémon possédés]
                cout << "Numéro incorrect ! " << endl;
                cout << "Choisir le Pokemon à changer de place : " << endl;
                cin >> idChange;
            }
            cout << "Choisir le nouvel emplacement : " << endl;
            cin >> idNouveau;
            while(idNouveau <= 0 || idNouveau > a) {
                // [1 - nombre de pokémon possédés]
                cout << "Numéro incorrect ! " << endl;
                cout << "Choisir le nouvel emplacement : " << endl;
                cin >> idNouveau;
            }
            poke.getAllJoueurs()[idJoueur].changerEmplacement(idChange-1, idNouveau-1);
            cout << "Échange effectué !" << endl;

            cout << "Les Pokemons sont maintenant dans cet ordre : " << endl;
            for(int i = 0; i < 7; i++) {
                if(poke.getAllJoueurs()[idJoueur].getPokemon(i) != nullptr) {
                    cout << i + 1 << ". " + poke.getAllJoueurs()[idJoueur].getPokemon(i)->getNom() << endl;
                }
            }
        } else if(option == 4) {
            cout << "Statistiques du Joueur :" << endl;
            cout << poke.getAllJoueurs()[idJoueur].statistiques() << endl;
        }

    } while(option != 8);

    

    return 0;
}