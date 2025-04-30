#include "Entraineur.h"

Entraineur::Entraineur(string pNom, PokemonComplet* pPokemons[6]) {
    nom = pNom;
    
    for (int i = 0; i < 6; ++i) {
        pokemons[i] = pPokemons[i];
    }
}

string Entraineur::getNom() {
    return nom;
}

PokemonComplet* Entraineur::getPokemon(int index) {
    if (index >= 0 && index < 6) {
        return pokemons[index];
    }
    return nullptr; // ou lancer une exception si tu préfères
}

Entraineur::~Entraineur() {
}