#include "Joueur.h"


Joueur::Joueur(string pNom, PokemonComplet* pPokemons[6]) : Entraineur(pNom, pPokemons) {
    nbBadgesRemportes = 0;
    nbCombatsGagnes = 0;
    nbCombatsPerdus = 0;
}

string Joueur::statistiques() {
    string result = "";
    result += "Badges Remportés : " + to_string(nbBadgesRemportes) + "\n";
    result += "Combats Gagnés : " + to_string(nbCombatsGagnes) + "\n";
    result += "Combats Perdus : " + to_string(nbCombatsPerdus);
    return result;
}

void Joueur::ajouterBadge() {
    nbBadgesRemportes++;
}

void Joueur::ajouterCombatGagne() {
    nbCombatsGagnes++;
}

void Joueur::ajouterCombatPerdu() {
    nbCombatsPerdus++;
}

void Joueur::changerEmplacement(int idChange, int idNouveau) {
    if(idChange == idNouveau)
        return;
    int nbPoke = 0;
    for(int i = 0; i < 7; i++) {
        if(pokemons[i] != nullptr)
            nbPoke++; // Obtenir le nombre de Pokemons
    }
    if(idChange < 0 || idNouveau < 0 || idChange >= nbPoke || idNouveau >= nbPoke)
        return;
    PokemonComplet* temp = pokemons[idChange];
    if(idChange < idNouveau) {
        // Décaler vers la gauche
        for(int i = idChange; i < idNouveau; i++) {
            pokemons[i] = pokemons[i+1];
        }
    } else{ 
        // Décaler vers la droite
        for(int i = idChange; i > idNouveau; i--) {
            pokemons[i] = pokemons[i - 1];
        }
    }
    pokemons[idNouveau] = temp;
}

Joueur::~Joueur() {

}
