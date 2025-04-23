#ifndef POKEMONTYPES_H
#define POKEMONTYPES_H

#include<string>
#include<vector>
#include "Pokemon.h"

using namespace std;

struct Type {
    string type;
    vector<Type*> faiblesses;
    vector<Type*> resistances;

    string getType();

    bool isFaiblesse(string nomType);
    
    bool isRes(string nomType);
}; 

class PokemonComplet : public Pokemon {
    private:
        vector<Type> types;
        
        int pvActuels;
    
    public:
        PokemonComplet(string pNom, int pPv, string pAttaque, int pDegats, vector<Type> pTypes);
};

#endif 