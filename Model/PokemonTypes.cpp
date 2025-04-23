#include "PokemonTypes.h"

string Type::getType() {
    return type;
}

bool Type::isFaiblesse(string nomType) {
    for(Type* t : faiblesses) {
        if(t->getType() == nomType) {
            return true;
        }
    }
    return false;
}

bool Type::isRes(string nomType) {
    for(Type* t : resistances) {
        if(t->getType() == nomType) {
            return true;
        }
    }
    return false;
}

PokemonComplet::PokemonComplet(string pNom, int pPv, string pAttaque, int pDegats, vector<Type> pTypes) : Pokemon(pNom, pPv, pAttaque, pDegats) {
    pvActuels = pPv;
    types = pTypes;
}