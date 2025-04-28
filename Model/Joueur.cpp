#include "Joueur.h"


Joueur::Joueur(string pNom, PokemonComplet* pPokemons[6]) : Entraineur(pNom, pPokemons) {
    nbBadgesRemportes = 0;
    nbCombatsGagnes = 0;
    nbCombatsPerdus = 0;
}

Joueur::~Joueur() {
    for(int i = 0; i < 6; i++) {
        if(pokemons[i] != nullptr) {
            delete pokemons[i];
            pokemons[i] = nullptr;
        }
    }
}
