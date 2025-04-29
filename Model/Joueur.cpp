#include "Joueur.h"


Joueur::Joueur(string pNom, PokemonComplet* pPokemons[6]) : Entraineur(pNom, pPokemons) {
    nbBadgesRemportes = 0;
    nbCombatsGagnes = 0;
    nbCombatsPerdus = 0;
}

Joueur::~Joueur() {
    
}
