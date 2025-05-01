#include "Pokemon.h"

Pokemon::Pokemon(string pNom, int pPv, string pAttaque, int pDegats) {
    nom = pNom;
    pv = pPv;
    attaque = pAttaque;
    degatsAttaque = pDegats;
}

Pokemon::~Pokemon() {
    
}

string Pokemon::interaction() {
    string res = "";
    res += nom + " : ";
    for(int i = 0; i < nom.size()/2 + 1; i++) {
        res+= nom[i];
    }
    for(int i = 0; i < nom.size()/2 + 1; i++) {
        res+= nom[i];
    }

    return res;
}