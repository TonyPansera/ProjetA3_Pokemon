#ifndef POKEMONCONTROLLER_H
#define POKEMONCONTROLLER_H

#include <string>
#include "../Model/PokemonTypes.h"
#include "../Model/Joueur.h"
#include "../Model/Maitre.h"
#include "../Model/Leader.h"

using namespace std;

class PokemonController {
    private:
        vector<PokemonComplet> alPokemons;
        vector<Joueur> alJoueurs;
        vector<Maitre> alMaitres;
        vector<Leader> alLeaders;

        vector<Entraineur> entraineursBattus;
        int nbEntraineursBattus;

        Type* alTypes[18];

        void typesInit();
        void addAllPokemons();
        void addJoueurs();
        void addMaitres();
        void addLeaders();

    public:
        PokemonController();
        ~PokemonController();

        int getNbEntraineursBattus();
        void addEntraineursBattus();

        vector<Joueur>& getAllJoueurs();
        vector<Leader>& getAllLeader();
        Entraineur getBeatenTrainer();     
        string combatMaitre(Joueur& joueur, Leader& leader);
};

#endif