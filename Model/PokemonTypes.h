#ifndef POKEMONTYPES_H
#define POKEMONTYPES_H

#include<string>
#include<vector>
#include "Pokemon.h"

using namespace std;

struct Type {
    const string type;
    vector<Type*> faiblesses;
    vector<Type*> resistances;

    Type(string nom);
    string getType();

    bool isFaiblesse(string nomType);
    
    bool isRes(string nomType);
}; 

class PokemonComplet : public Pokemon {
    private:
        vector<Type*> types;
        
        int pvActuels;
    
    public:
        PokemonComplet(string pNom, int pPv, string pAttaque, int pDegats, vector<Type*> pTypes);
        ~PokemonComplet();

        vector<Type*> getTypes();
        string getNom();
        int getPv();
        string getAttaque();
        int getDegats();
        int getPvActuels();

        void setPvActuels();

        string toString();
};

#endif 