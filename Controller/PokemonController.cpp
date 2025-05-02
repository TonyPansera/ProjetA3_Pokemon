#include "PokemonController.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include <algorithm>


PokemonController::PokemonController() {
    this->typesInit();
    this->addAllPokemons();
    this->addJoueurs();
    this->addLeaders();
    this->addMaitres();
    nbEntraineursBattus = 0;
}

string PokemonController::affronterMaitre(Joueur& joueur, Entraineur& leader) {
    string result = "";
    if(alLeaders.size() == 0) {
        result += combat(joueur, leader, true);
    } else {
        result += "Vous n'avez pas battu tous les Leaders !";
    }
    return result;
}


string PokemonController::combat(Joueur& joueur, Entraineur& leader, bool isMaitre) {
    string result = "";
    int pokemonJoueurIndex = 0; // Obtenir le pokemon joueur démarrant
    bool found = false;
    for(int i = 0; i < 6 && !found; i++) {
        if(joueur.getPokemon(i) != nullptr && joueur.getPokemon(i)->getPvActuels() > 0) {
            found = true;
            pokemonJoueurIndex = i;
        } else {
            pokemonJoueurIndex++;
        }
    }

    int pokemonLeaderIndex = 0; // Obtenir le pokemon leader démarrant
    found = false;
    for(int i = 0; i < 6 && !found; i++) {
        if(leader.getPokemon(i) != nullptr && leader.getPokemon(i)->getPvActuels() > 0) {
            found = true;
            pokemonLeaderIndex = i;
        } else{
            pokemonLeaderIndex++;
        }
    }

    while(pokemonJoueurIndex < 6 && pokemonLeaderIndex < 6 && 
        leader.getPokemon(pokemonLeaderIndex) != nullptr && joueur.getPokemon(pokemonJoueurIndex) != nullptr) {
            
            // JOUEUR QUI ATTAQUE ENTRAINEUR
            int deg = joueur.getPokemon(pokemonJoueurIndex)->getDegats();
            int baseDeg = deg;
            result += joueur.getPokemon(pokemonJoueurIndex)->attaqueString() + "\n";
           

            // OK ça commence à être un peu le bordel là
            // Première boucle qui parcours les types du pokémon attaquant
            for(int i = 0; i < joueur.getPokemon(pokemonJoueurIndex)->getTypes().size(); i++) {

                // Deuxième boucle qui parcours les types du pokemon défendant
                for(int j = 0; j < leader.getPokemon(pokemonLeaderIndex)->getTypes().size(); j++) {

                    // Troisième boucle qui parcours les faiblesses du pokémon défendant, en fonction de 
                    // ses types (donc on a getTypes()[j])
                    for(int k = 0; k < leader.getPokemon(pokemonLeaderIndex)->getTypes()[j]->faiblesses.size(); k++) {
                        if(joueur.getPokemon(pokemonJoueurIndex)->getTypes()[i]->getType() == 
                        leader.getPokemon(pokemonLeaderIndex)->getTypes()[j]->faiblesses[k]->getType()) {
                            deg *= 2;
                        }
                    }

                    // Quatrième boucle qui parcours les résistances du pokémon défendant, en fonction de 
                    // ses types (donc on a getTypes()[j])
                    for(int k = 0; k < leader.getPokemon(pokemonLeaderIndex)->getTypes()[j]->resistances.size(); k++) {
                        if(joueur.getPokemon(pokemonJoueurIndex)->getTypes()[i]->getType() == 
                        leader.getPokemon(pokemonLeaderIndex)->getTypes()[j]->resistances[k]->getType()) {
                            deg /= 2;
                        }
                    }
                }
            }

            if(deg > baseDeg) {
                result += "C'est très efficace ! " + joueur.getPokemon(pokemonJoueurIndex)->getNom() + " inflige "
                + to_string(deg) + " dégats ! \n";
            } else if(deg < baseDeg) {
                result += "Ce n'est pas très efficace..." + joueur.getPokemon(pokemonJoueurIndex)->getNom() + " inflige "
                + to_string(deg) + " dégats. \n";
            } else {
                result += joueur.getPokemon(pokemonJoueurIndex)->getNom() + " inflige "
                + to_string(deg) + " dégats. \n";
            }

            if(leader.getPokemon(pokemonLeaderIndex)->getPvActuels() <= deg) {
                leader.getPokemon(pokemonLeaderIndex)->setPvActuels(0);
                result += leader.getPokemon(pokemonLeaderIndex)->getNom() + " est K.O. \n";
                pokemonLeaderIndex++;
            } else {
                leader.getPokemon(pokemonLeaderIndex)->setPvActuels(leader.getPokemon(pokemonLeaderIndex)->getPv() - deg);
            }


            if(pokemonJoueurIndex < 6 && pokemonLeaderIndex < 6 && 
                leader.getPokemon(pokemonLeaderIndex) != nullptr && joueur.getPokemon(pokemonJoueurIndex) != nullptr) {
                    // ENTRAINEUR QUI ATTAQUE JOUEUR
                deg = leader.getPokemon(pokemonLeaderIndex)->getDegats();
                baseDeg = deg;
                result += leader.getPokemon(pokemonLeaderIndex)->attaqueString() + "\n";

                // OK ça commence à être un peu le bordel là
                // Première boucle qui parcours les types du pokémon attaquant
                for(int i = 0; i < leader.getPokemon(pokemonLeaderIndex)->getTypes().size(); i++) {

                    // Deuxième boucle qui parcours les types du pokemon défendant
                    for(int j = 0; j < joueur.getPokemon(pokemonJoueurIndex)->getTypes().size(); j++) {

                        // Troisième boucle qui parcours les faiblesses du pokémon défendant, en fonction de 
                        // ses types (donc on a getTypes()[j])
                        for(int k = 0; k < joueur.getPokemon(pokemonJoueurIndex)->getTypes()[j]->faiblesses.size(); k++) {
                            if(leader.getPokemon(pokemonLeaderIndex)->getTypes()[i]->getType() == 
                            joueur.getPokemon(pokemonJoueurIndex)->getTypes()[j]->faiblesses[k]->getType()) {
                                deg *= 2;
                            }
                        }

                        // Quatrième boucle qui parcours les résistances du pokémon défendant, en fonction de 
                        // ses types (donc on a getTypes()[j])
                        for(int k = 0; k < joueur.getPokemon(pokemonJoueurIndex)->getTypes()[j]->resistances.size(); k++) {
                            if(leader.getPokemon(pokemonLeaderIndex)->getTypes()[i]->getType() == 
                            joueur.getPokemon(pokemonJoueurIndex)->getTypes()[j]->resistances[k]->getType()) {
                                deg /= 2;
                            }
                        }
                    }
                }

                if(deg > baseDeg) {
                    if(isMaitre)
                        deg *= 1.25;
                    result += "C'est très efficace ! " + leader.getPokemon(pokemonLeaderIndex)->getNom() + " inflige "
                    + to_string(deg) + " dégats ! \n";
                } else if(deg < baseDeg) {
                    if(isMaitre)
                        deg *= 1.25;
                    result += "Ce n'est pas très efficace..." + leader.getPokemon(pokemonLeaderIndex)->getNom() + " inflige "
                    + to_string(deg) + " dégats. \n";
                } else {
                    if(isMaitre)
                        deg *= 1.25;
                    result += leader.getPokemon(pokemonLeaderIndex)->getNom() + " inflige "
                    + to_string(deg) + " dégats. \n";
                }

                if(joueur.getPokemon(pokemonJoueurIndex)->getPvActuels() <= deg) {
                    joueur.getPokemon(pokemonJoueurIndex)->setPvActuels(0);
                    result += joueur.getPokemon(pokemonJoueurIndex)->getNom() + " est K.O. \n";
                    pokemonJoueurIndex++;
                } else {
                    joueur.getPokemon(pokemonJoueurIndex)->setPvActuels(joueur.getPokemon(pokemonJoueurIndex)->getPv() - deg);
                }
            }

            
    }
    // FIN DU JEU
    if(pokemonJoueurIndex >= 6 || joueur.getPokemon(pokemonJoueurIndex) == nullptr) {
        result += "Vous avez perdu... Revenez une prochaine fois !";
        joueur.ajouterCombatPerdu();
    } else if(pokemonLeaderIndex >= 6 || leader.getPokemon(pokemonLeaderIndex) == nullptr) {
        result += "Vous avez gagné ! \n";
        if(isMaitre) {
            result += "Vous avez battu un Maitre !";
            entraineursBattus.push_back(leader);
            alMaitres.erase(std::remove(alMaitres.begin(), alMaitres.end(), leader), alMaitres.end());
        } else {
            alLeaders.erase(std::remove(alLeaders.begin(), alLeaders.end(), leader), alLeaders.end()); // enlever le leader battu
            addEntraineursBattus();
            entraineursBattus.push_back(leader);
            joueur.ajouterBadge();
        }
        joueur.ajouterCombatGagne();
    }

    return result;
    

}

vector<Leader>& PokemonController:: getAllLeader() {
    return alLeaders;
}

int PokemonController::getNbEntraineursBattus() {
    return nbEntraineursBattus;
}

void PokemonController::addEntraineursBattus() {
    nbEntraineursBattus++;
}

Entraineur PokemonController::getBeatenTrainer() {
     // initialisation une seule fois

    int n = std::rand() % entraineursBattus.size(); // nombre entre 1 et 6

    return entraineursBattus[n];

    
};

vector<Maitre>& PokemonController::getAllMaitre() {
    return alMaitres;
}

vector<Joueur>& PokemonController::getAllJoueurs() {
    return alJoueurs;
}

void PokemonController::addMaitres() {
    ifstream fichier("../Controller/maitres.csv"); 

    if (!fichier) {
        cerr << "Erreur lors de l'ouverture du fichier" << endl;

    } else {
        string ligne;
        string morceau;
        string champs[7];  // Taille connue à l'avance
        getline(fichier, ligne);

        while (getline(fichier, ligne)) {
            stringstream ss(ligne);

            int i = 0;
            while (getline(ss, morceau, ',') && i < 7) {
                champs[i++] = morceau;
            }
            
            PokemonComplet* pokemon[6];
            for (int i = 0; i < 6; ++i) {
                pokemon[i] = nullptr;
            }
            int j = 1;
            while(!champs[j].empty() && champs[j] != "" && j < 7) {
                for(int k = 0; k < alPokemons.size(); k++) {
                    if(alPokemons[k].getNom() == champs[j]) {
                        PokemonComplet* copiePoke = new PokemonComplet(alPokemons[k].getNom(), 
                    alPokemons[k].getPv(), alPokemons[k].getAttaque(), alPokemons[k].getDegats(),
                    alPokemons[k].getTypes());

                        pokemon[j-1] = copiePoke;
                        
                    }
                }
                j++;
            }

            Maitre maitre(champs[0], pokemon);
            alMaitres.push_back(maitre);
            
        }
    
        fichier.close();
    }
}

void PokemonController::addLeaders() {
    ifstream fichier("../Controller/leaders.csv"); 

    if (!fichier) {
        cerr << "Erreur lors de l'ouverture du fichier" << endl;

    } else {
        string ligne;
        string morceau;
        string champs[9];  // Taille connue à l'avance
        getline(fichier, ligne);

        while (getline(fichier, ligne)) {
            stringstream ss(ligne);

            int i = 0;
            while (getline(ss, morceau, ',') && i < 9) {
                champs[i++] = morceau;
            }
            
            PokemonComplet* pokemon[6];
            for (int i = 0; i < 6; ++i) {
                pokemon[i] = nullptr;
            }
            int j = 3;
            while(!champs[j].empty() && champs[j] != "" && j < 9) {
                for(int k = 0; k < alPokemons.size(); k++) {
                    if(alPokemons[k].getNom() == champs[j]) {
                        PokemonComplet* copiePoke = new PokemonComplet(alPokemons[k].getNom(), 
                    alPokemons[k].getPv(), alPokemons[k].getAttaque(), alPokemons[k].getDegats(),
                    alPokemons[k].getTypes());

                        pokemon[j-3] = copiePoke;
                        
                    }
                }
                j++;
            }

            Leader leader(champs[0], pokemon, champs[2], champs[1]);
            alLeaders.push_back(leader);
            
        }
    
        fichier.close();
    }
}

void PokemonController::addJoueurs() {
    ifstream fichier("../Controller/joueur.csv"); 

    if (!fichier) {
        cerr << "Erreur lors de l'ouverture du fichier" << endl;

    } else {
        string ligne;
        string morceau;
        string champs[7];  // Taille connue à l'avance
        getline(fichier, ligne);

        while (getline(fichier, ligne)) {
            stringstream ss(ligne);

            int i = 0;
            while (getline(ss, morceau, ',') && i < 7) {
                champs[i++] = morceau;
            }
            
            PokemonComplet* pokemon[6];
            for (int i = 0; i < 6; ++i) {
                pokemon[i] = nullptr;
            }
            int j = 1;
            while(!champs[j].empty() && champs[j] != "" && j < 7) {
                for(int k = 0; k < alPokemons.size(); k++) {
                    if(alPokemons[k].getNom() == champs[j]) {
                        PokemonComplet* copiePoke = new PokemonComplet(alPokemons[k].getNom(), 
                    alPokemons[k].getPv(), alPokemons[k].getAttaque(), alPokemons[k].getDegats(),
                    alPokemons[k].getTypes());

                        pokemon[j-1] = copiePoke;
                        
                    }
                }
                j++;
            }

            Joueur joueur(champs[0], pokemon);
            alJoueurs.push_back(joueur);
            
        }
    
        fichier.close();
    }
}

void PokemonController::addAllPokemons() {
    ifstream fichier("../Controller/pokemon.csv"); 

    if (!fichier) {
        cerr << "Erreur lors de l'ouverture du fichier" << endl;

    } else {
        string ligne;
        string morceau;
        string champs[6];  // Taille connue à l'avance
        getline(fichier, ligne);

        while (getline(fichier, ligne)) {
            stringstream ss(ligne);

            int i = 0;
            while (getline(ss, morceau, ',') && i < 6) {
                champs[i++] = morceau;
            }

            vector<Type*> typesPoke;
            if(champs[1] == "Plante" || champs[2] == "Plante")
                typesPoke.push_back(alTypes[2]);
            if(champs[1] == "Feu" || champs[2] == "Feu")
                typesPoke.push_back(alTypes[0]);
            if(champs[1] == "Eau" || champs[2] == "Eau")
                typesPoke.push_back(alTypes[1]);
            if(champs[1] == "Insecte" || champs[2] == "Insecte")
                typesPoke.push_back(alTypes[10]);
            if(champs[1] == "Normal" || champs[2] == "Normal")
                typesPoke.push_back(alTypes[17]);
            if(champs[1] == "Poison" || champs[2] == "Poison")
                typesPoke.push_back(alTypes[6]);
            if(champs[1] == "Électrik" || champs[2] == "Électrik")
                typesPoke.push_back(alTypes[3]);
            if(champs[1] == "Sol" || champs[2] == "Sol")
                typesPoke.push_back(alTypes[7]);
            if(champs[1] == "Fée" || champs[2] == "Fée")
                typesPoke.push_back(alTypes[16]);
            if(champs[1] == "Psy" || champs[2] == "Psy")
                typesPoke.push_back(alTypes[9]);
            if(champs[1] == "Combat" || champs[2] == "Combat")
                typesPoke.push_back(alTypes[5]);
            if(champs[1] == "Glace" || champs[2] == "Glace")
                typesPoke.push_back(alTypes[4]);
            if(champs[1] == "Vol" || champs[2] == "Vol")
                typesPoke.push_back(alTypes[8]);
            if(champs[1] == "Roche" || champs[2] == "Roche")
                typesPoke.push_back(alTypes[11]);
            if(champs[1] == "Ténèbres" || champs[2] == "Ténèbres")
                typesPoke.push_back(alTypes[14]);
            if(champs[1] == "Acier" || champs[2] == "Acier")
                typesPoke.push_back(alTypes[15]);
            if(champs[1] == "Dragon" || champs[2] == "Dragon")
                typesPoke.push_back(alTypes[13]);

            PokemonComplet pokemon(champs[0], stoi(champs[3]), champs[4], stoi(champs[5]), typesPoke);
            alPokemons.push_back(pokemon);
            
        }
    
        fichier.close();
    }

    
}

PokemonController::~PokemonController() {
    for (int i = 0; i < 18; i++) {
        if(alTypes[i] != nullptr) {
            delete alTypes[i]; 
            alTypes[i] = nullptr;
        }
    }

}

void PokemonController::typesInit() {
    alTypes[0] = new Type("Feu");
    alTypes[1] = new Type("Eau");
    alTypes[2] = new Type("Plante");
    alTypes[3] = new Type("Életrik");
    alTypes[4] = new Type("Glace");
    alTypes[5] = new Type("Combat");
    alTypes[6] = new Type("Poison");
    alTypes[7] = new Type("Sol");
    alTypes[8] = new Type("Vol");
    alTypes[9] = new Type("Psy");
    alTypes[10] = new Type("Insecte");
    alTypes[11] = new Type("Roche");
    alTypes[12] = new Type("Spectre");
    alTypes[13] = new Type("Dragon");
    alTypes[14] = new Type("Ténèbres");
    alTypes[15] = new Type("Acier");
    alTypes[16] = new Type("Fée");
    alTypes[17] = new Type("Normal");

    // Type Fée : Combat, Insecte, Ténèbres, Dragon
    alTypes[16]->resistances.push_back(alTypes[5]);
    alTypes[16]->resistances.push_back(alTypes[10]);
    alTypes[16]->resistances.push_back(alTypes[13]);
    alTypes[16]->resistances.push_back(alTypes[14]);

    // Type Acier : Normal, Plante, Glace, Vol, Psy, Insecte, Roche, Dragon, Acier, Fée
    alTypes[15]->resistances.push_back(alTypes[2]);
    alTypes[15]->resistances.push_back(alTypes[4]);
    alTypes[15]->resistances.push_back(alTypes[8]);
    alTypes[15]->resistances.push_back(alTypes[9]);
    alTypes[15]->resistances.push_back(alTypes[10]);
    alTypes[15]->resistances.push_back(alTypes[11]);
    alTypes[15]->resistances.push_back(alTypes[13]);
    alTypes[15]->resistances.push_back(alTypes[15]);
    alTypes[15]->resistances.push_back(alTypes[16]);
    alTypes[15]->resistances.push_back(alTypes[17]);

    // Type Ténèbre : Spectre, Psy, Ténèbres
    alTypes[14]->resistances.push_back(alTypes[9]);
    alTypes[14]->resistances.push_back(alTypes[12]);
    alTypes[14]->resistances.push_back(alTypes[14]);

    // Type Dragon : Feu, Eau, Électrik, Plante
    alTypes[13]->resistances.push_back(alTypes[0]);
    alTypes[13]->resistances.push_back(alTypes[1]);
    alTypes[13]->resistances.push_back(alTypes[2]);
    alTypes[13]->resistances.push_back(alTypes[3]);

    // Type Spectre : Poison, Insecte
    alTypes[12]->resistances.push_back(alTypes[8]);
    alTypes[12]->resistances.push_back(alTypes[10]);

    // Type Roche : Feu, Vol, Poison, Normal
    alTypes[11]->resistances.push_back(alTypes[0]);
    alTypes[11]->resistances.push_back(alTypes[6]);
    alTypes[11]->resistances.push_back(alTypes[8]);
    alTypes[11]->resistances.push_back(alTypes[17]);

    // Type Insecte : Plante, Combat, Sol
    alTypes[10]->resistances.push_back(alTypes[2]);
    alTypes[10]->resistances.push_back(alTypes[5]);
    alTypes[10]->resistances.push_back(alTypes[7]);

    // Type Psy : Combat, Psy
    alTypes[9]->resistances.push_back(alTypes[5]);
    alTypes[9]->resistances.push_back(alTypes[9]);

    // Type Vol : Plante, Combat, Insecte
    alTypes[8]->resistances.push_back(alTypes[2]);
    alTypes[8]->resistances.push_back(alTypes[5]);
    alTypes[8]->resistances.push_back(alTypes[10]);

    // Type Sol : Poison, Roche
    alTypes[7]->resistances.push_back(alTypes[6]);
    alTypes[7]->resistances.push_back(alTypes[11]);

    // Type Poison : Plante, Fée, Combat, Poison, Insecte
    alTypes[6]->resistances.push_back(alTypes[2]);
    alTypes[6]->resistances.push_back(alTypes[5]);
    alTypes[6]->resistances.push_back(alTypes[6]);
    alTypes[6]->resistances.push_back(alTypes[10]);
    alTypes[6]->resistances.push_back(alTypes[16]);

    // Type Combat : Roche, Insecte, Ténèbres
    alTypes[5]->resistances.push_back(alTypes[10]);
    alTypes[5]->resistances.push_back(alTypes[11]);
    alTypes[5]->resistances.push_back(alTypes[14]);

    // Type Glace : Glace
    alTypes[4]->resistances.push_back(alTypes[4]);

    // Type Électrik : Vol, Acier, Électrik
    alTypes[3]->resistances.push_back(alTypes[3]);
    alTypes[3]->resistances.push_back(alTypes[8]);
    alTypes[3]->resistances.push_back(alTypes[15]);

    // Type Plante : résistances Eau, Sol, Roche
    alTypes[2]->resistances.push_back(alTypes[0]);
    alTypes[2]->resistances.push_back(alTypes[7]);
    alTypes[2]->resistances.push_back(alTypes[11]);

    // Type Eau : résistances Feu, Eau, Glace, Acier
    alTypes[1]->resistances.push_back(alTypes[0]);
    alTypes[1]->resistances.push_back(alTypes[1]);
    alTypes[1]->resistances.push_back(alTypes[4]);
    alTypes[1]->resistances.push_back(alTypes[15]);

    // Type Feu : résistance Plante, Glace, Insecte, Acier, Fée
    alTypes[0]->resistances.push_back(alTypes[2]);
    alTypes[0]->resistances.push_back(alTypes[4]);
    alTypes[0]->resistances.push_back(alTypes[10]);
    alTypes[0]->resistances.push_back(alTypes[15]);
    alTypes[0]->resistances.push_back(alTypes[16]);

    // Type Fée : Poison, Acier
    alTypes[16]->faiblesses.push_back(alTypes[6]);
    alTypes[16]->faiblesses.push_back(alTypes[15]);

    // Type Acier : Feu, Combat, Sol
    alTypes[15]->faiblesses.push_back(alTypes[0]);
    alTypes[15]->faiblesses.push_back(alTypes[5]);
    alTypes[15]->faiblesses.push_back(alTypes[7]);

    // Type Ténèbres : Combat, Insecte, Fée
    alTypes[14]->faiblesses.push_back(alTypes[5]);
    alTypes[14]->faiblesses.push_back(alTypes[10]);
    alTypes[14]->faiblesses.push_back(alTypes[16]);

    // Type Dragon : Glace, Dragon, Fée
    alTypes[13]->faiblesses.push_back(alTypes[4]);
    alTypes[13]->faiblesses.push_back(alTypes[13]);
    alTypes[13]->faiblesses.push_back(alTypes[16]);

    // Type Spectre : Spectre, Ténèbres
    alTypes[12]->faiblesses.push_back(alTypes[12]);
    alTypes[12]->faiblesses.push_back(alTypes[14]);

    // Type Roche : Eau, Plante, Combat, Sol, Acier
    alTypes[11]->faiblesses.push_back(alTypes[1]);
    alTypes[11]->faiblesses.push_back(alTypes[2]);
    alTypes[11]->faiblesses.push_back(alTypes[5]);
    alTypes[11]->faiblesses.push_back(alTypes[7]);
    alTypes[11]->faiblesses.push_back(alTypes[15]);

    // Type Insecte : Feu, Vol, Roche
    alTypes[10]->faiblesses.push_back(alTypes[0]);
    alTypes[10]->faiblesses.push_back(alTypes[8]);
    alTypes[10]->faiblesses.push_back(alTypes[11]);

    // Type Psy : faiblesses Insecte, Spectre, Ténèbres
    alTypes[9]->faiblesses.push_back(alTypes[10]);
    alTypes[9]->faiblesses.push_back(alTypes[12]);
    alTypes[9]->faiblesses.push_back(alTypes[14]);

    // Type Vol : faiblesses Électrik, Glace, Roche
    alTypes[8]->faiblesses.push_back(alTypes[3]);
    alTypes[8]->faiblesses.push_back(alTypes[4]);
    alTypes[8]->faiblesses.push_back(alTypes[11]);

    // Type Sol : faiblesses Eau, Plante, Glace
    alTypes[7]->faiblesses.push_back(alTypes[1]);
    alTypes[7]->faiblesses.push_back(alTypes[2]);
    alTypes[7]->faiblesses.push_back(alTypes[4]);

    // Type Poison : faiblesses Sol, Psy
    alTypes[6]->faiblesses.push_back(alTypes[7]);
    alTypes[6]->faiblesses.push_back(alTypes[9]);

    // Type Combat : faiblesses Vol, Psy, Fée
    alTypes[5]->faiblesses.push_back(alTypes[8]);
    alTypes[5]->faiblesses.push_back(alTypes[9]);
    alTypes[5]->faiblesses.push_back(alTypes[16]);

    // Type Glace : faiblesses Feu, Combat, Roche, Acier
    alTypes[4]->faiblesses.push_back(alTypes[0]);
    alTypes[4]->faiblesses.push_back(alTypes[5]);
    alTypes[4]->faiblesses.push_back(alTypes[11]);
    alTypes[4]->faiblesses.push_back(alTypes[15]);

    // Type Feu : faiblesses Eau, Roche, Sol
    alTypes[0]->faiblesses.push_back(alTypes[11]);
    alTypes[0]->faiblesses.push_back(alTypes[1]);
    alTypes[0]->faiblesses.push_back(alTypes[7]);

    // Type Eau : faiblesses Plante, Électrik
    alTypes[1]->faiblesses.push_back(alTypes[2]);
    alTypes[1]->faiblesses.push_back(alTypes[3]);

    // Type Plante : faiblesses Feu, Glace, Poison, Vol, Insecte
    alTypes[2]->faiblesses.push_back(alTypes[1]);
    alTypes[2]->faiblesses.push_back(alTypes[4]);
    alTypes[2]->faiblesses.push_back(alTypes[6]);
    alTypes[2]->faiblesses.push_back(alTypes[8]);
    alTypes[2]->faiblesses.push_back(alTypes[10]);

    // Type Électrik : faiblesse Sol
    alTypes[3]->faiblesses.push_back(alTypes[7]);
    
    
}

