#include "Leader.h"
#include<iostream>

using namespace std;



Leader::Leader(string pNom, PokemonComplet* pPokemons[6], string pBadge, string pGymnase) 
    : Entraineur(pNom, pPokemons) {
        badge = pBadge;
        gymnase = pGymnase;
}

Leader::~Leader(){

}