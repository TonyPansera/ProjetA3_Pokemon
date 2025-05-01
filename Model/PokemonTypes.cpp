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

void PokemonComplet::setPvActuels() {
    pvActuels = pv;
}

string PokemonComplet::toString() {
    string result = "Nom : " + nom + "\n";
    if(types.size() == 1) {
        result += "Type : ";
    } else {
        result += "Types : ";
    }
    for(int i = 0; i < types.size(); i++) {
        result += types[i]->getType() + " ";
    }
    result += "\n";
    result += "PV actuels : " + to_string(pvActuels);
    result += "\n";
    result += "PV max : " + to_string(pv);
    result += "\n";
    result += "Attaque : " + attaque + "\n";
    result += "Dégâts : " + to_string(degatsAttaque);

    return result;
}

PokemonComplet::PokemonComplet(string pNom, int pPv, string pAttaque, int pDegats, vector<Type*> pTypes) : Pokemon(pNom, pPv, pAttaque, pDegats) {
    pvActuels = pPv;
    types = pTypes;
}

vector<Type*> PokemonComplet::getTypes() {
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

