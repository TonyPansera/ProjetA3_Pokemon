
#ifndef POKEMON_H
#define POKEMON_H

#include <string>
using namespace std;

class Pokemon {
    protected: 
        string nom;
        int pv;
        string attaque;
        int degatsAttaque;
    
    public: 
        Pokemon(string pNom, int pPv, string pAttaque, int pDegats);
        virtual ~Pokemon() {}
};

#endif