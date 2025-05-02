#ifndef MAITRE_H
#define MAITRE_H

#include<string>
#include "Entraineur.h"

using namespace std;

class Maitre : public Entraineur {
    public:
        Maitre(string pNom, PokemonComplet* pPokemons[6]);
};

#endif 