#ifndef SEIGNEUR_HPP
#define SEIGNEUR_HPP

#include "Pion.hpp"
#include "Case.hpp"
#include <vector>



class Seigneur : public Pion
{
private:
    bool m_seDeplace = false;

public:
    Seigneur(Joueur *j, int x, int y);

    /* Un Seigneur peut se Transformer si le joueur à assez d'or */
    bool peutSeTransformer();
    void payerChateau(Pion &p);
    void attaque(Pion *p);
    void attaquePossible(vector<Case *> &vecCases);
    bool peutSeDeplacer() const;
    void setSeDeplacer(bool b);
    string affichetype();
    void afficheActions();
    void dplSPossible(vector<Case *> &vecCases);
    void afficheEmplPossible(vector<Case *> &vecCases);
};

#endif