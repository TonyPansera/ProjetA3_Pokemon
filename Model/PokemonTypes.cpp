#include "PokemonTypes.h"

string Type::getType() {
    return type;
}

Type::Type(string nom) : type(nom) {
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

PokemonComplet::PokemonComplet(string pNom, int pPv, string pAttaque, int pDegats, vector<Type*>& pTypes) : Pokemon(pNom, pPv, pAttaque, pDegats) {
    pvActuels = pPv;
    types = &pTypes;
}

PokemonComplet::~PokemonComplet() {
    if (types != nullptr) {
        for (Type* type : *types) {
            delete type; 
            type = nullptr;
        }
        delete types; 
        types = nullptr;
    }
}
