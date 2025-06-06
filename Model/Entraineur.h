#ifndef ENTRAINEUR_H
#define ENTRAINEUR_H

#include<string>
#include "PokemonTypes.h"
using namespace std;

class Entraineur {
    protected:
        string nom;
        PokemonComplet* pokemons[6];

    public:
        Entraineur(string pNom, PokemonComplet* pPokemons[6]);
        virtual ~Entraineur();

        string getNom();
        string interaction();
        PokemonComplet* getPokemon(int index);

        PokemonComplet** getPokemons();
        
        bool operator==(const Entraineur& autre) const;
        
};

#endif