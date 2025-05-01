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

PokemonComplet** Entraineur::getPokemons() {
    return pokemons;
}



string Entraineur::interaction() {
    string quotes[6] = {
        "Astuce : Lors d'un combat, choisi un Pokemon en fonction des faiblesses et résistances que l'adversaire !",
        "Astuce : Le plus de Pokemons tu possèdes, le plus tu as de chances de gagner un combat !",
        "Conseil : Ne part pas au combat avant d'avoir soigné tes Pokemons !",
        "BOMBARDILO CROCODILO",
        "TUNG TUNG TUNG TUNG TUNG TUNG SAHUR",
        "TRALALERO TRALALA"
    };

    int n = std::rand() % 6; // nombre entre 0 et 5
    string res = "";
    res += nom + " dit : " + quotes[n];
    return res;
}

PokemonComplet* Entraineur::getPokemon(int index) {
    if (index >= 0 && index < 6) {
        return pokemons[index];
    }
    return nullptr; // ou lancer une exception si tu préfères
}

Entraineur::~Entraineur() {
}