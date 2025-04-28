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

vector<Type*>* PokemonComplet::getTypes() {
    return types;
}

string PokemonComplet::getNom() {
    return nom;
}

int PokemonComplet::getPv() {
    return pv;
}

int PokemonComplet::getDegats() {
    return degatsAttaque;
}

int PokemonComplet::getPvActuels() {
    return pvActuels;
}

string PokemonComplet::getAttaque() {
    return attaque;
}

PokemonComplet::~PokemonComplet() {
    // Libération des objets Type* dans le vecteur
    /*for (Type* type : *types) {
        if (type != nullptr) {
            delete type;  // Supprime chaque objet Type* dans le vecteur
        }
    } */
    // Pas besoin de supprimer 'types' lui-même, car il n'a pas été alloué dynamiquement
}

