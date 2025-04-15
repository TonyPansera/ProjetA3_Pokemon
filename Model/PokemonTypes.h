#ifndef POKEMONTYPES_H
#define POKEMONTYPES_H

#include<string>
#include<vector>
#include "Pokemon.h"

using namespace std;

struct Type {
    string type;

    string getType() {
        return type;
    }
};

class PokemonComplet : public Pokemon {
    private:
        vector<Type> types;
        vector<Type> faiblesses;
        vector<Type> resistances;
        int pvActuels;
    
    public:
        PokemonComplet(string pNom, int pPv, string pAttaque, int pDegats);
};

#endif 