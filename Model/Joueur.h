#ifndef JOUEUR_H
#define JOUEUR_H

#include<string>
#include "Entraineur.h"


using namespace std;

class Joueur : public Entraineur {
    private:
        int nbBadgesRemportes;
        int nbCombatsGagnes;
        int nbCombatsPerdus;

    public:
        Joueur(string pNom, PokemonComplet* pPokemons[6]);
        ~Joueur();

        void ajouterBadge();
        void ajouterCombatGagne();
        void ajouterCombatPerdu();
        void changerEmplacement(int idChange, int idNouveau);
        string statistiques();
};

#endif