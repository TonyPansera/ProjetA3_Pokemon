#ifndef LEADER_H
#define LEADER_H

#include<string>
#include "Entraineur.h"

using namespace std;

class Leader : public Entraineur {
    private:
        string badge;
        string gymnase;
    
    public:
        Leader(string pNom, PokemonComplet* pPokemons[6], string pBadge, string pGymnase);
        ~Leader();
};

#endif