#ifndef CHATEAU_HPP
#define CHATEAU_HPP

#include "Pion.hpp"
#include <array>

class Chateau : public Pion
{

private:
    array<int,3> m_coutrect;
public:
    /* Méthodes */
    Chateau(Joueur *j);

    /* Un chateau peut recruter si le joueur à assez d'or (minimum requis 10 d'or) */
    bool peutRecruter(Joueur *j);

    /**
     * Retourne un Pion dont le joueur veut construire
     * Exemple : Le paramètre est P le Chateau recrute un Paysan; 
     * */
    void construirePion(int i);

    /* Méthodes Affichages */
    string affichetype();
    void afficheActions();
    void afficheRecruter();
};

#endif //CHATEAU_HPP