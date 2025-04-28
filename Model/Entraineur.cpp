#include "Entraineur.h"

Entraineur::Entraineur(string pNom, PokemonComplet* pPokemons[6]) {
    nom = pNom;
    for (int i = 0; i < 6; ++i) {
        pokemons[i] = pPokemons[i];
    }
}

Entraineur::~Entraineur() {
    
}