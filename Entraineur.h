#ifndef ENTRAINEUR_H
#define ENTRAINEUR_H

#include<string>
#include "Pokemon.h"
using namespace std;

class Entraineur {
    protected:
        string nom;
        Pokemon* pokemons[6];

    public:
        Entraineur(string pNom, Pokemon* pPokemons[6]);
        virtual ~Entraineur();
};

#endif