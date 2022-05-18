#ifndef CHATEAU_HPP
#define CHATEAU_HPP

#include "Pion.hpp"
#include <array>
#include <vector>
#include "Case.hpp"

class Chateau : public Pion
{
private:
    array<int,3> m_coutrect;
public:
    /* Méthodes */
    Chateau(Joueur *j,  int x, int y);

    /* Un chateau peut recruter si le joueur à assez d'or (minimum requis 10 d'or) */
    bool peutRecruter(int price);

    /**
     * Retourne un Pion dont le joueur veut construire
     * Exemple : Le paramètre est P le Chateau recrute un Paysan; 
     * */
    void construirePion(int choix, int x, int y, Pion * p);
    void empPossible(vector<Case *> &vecCases);

    /* Méthodes Affichages */
    string affichetype();
    void afficheActions();
    void afficheRecruter();
    int getCout() const;

};

#endif //CHATEAU_HPP