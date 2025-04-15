#include "Leader.h"

Leader::Leader(string pNom, Pokemon* pPokemons[6], string pBadge, string pGymnase) 
    : Entraineur(pNom, pPokemons) {
        badge = pBadge;
        gymnase = pGymnase;
}