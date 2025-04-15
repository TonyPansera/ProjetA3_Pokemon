#ifndef JOUEUR_H
#define JOUEUR_H

#include<string>
#include "Entraineur.h"

using namespace std;

class Joueur : protected Entraineur {
    private:
        int nbBadgesRemportes;
        int nbCombatsGagnes;
        int nbCombatsPerdus;

    public:
        Joueur(string pNom, Pokemon* pPokemons[6]);
};

#endif