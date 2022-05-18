#ifndef GUERRIER_HPP
#define GUERRIER_HPP

#include "Pion.hpp"
#include "Case.hpp"
#include <vector>

class Guerrier : public Pion
{
private:
    /* Pour que le Guerrier puisse se déplacer puis attaquer */
    bool m_seDeplace = true;

public:
    Guerrier(Joueur *j, int x, int y);

    void attaque(Pion *p);
    string affichetype();
    bool peutSeDeplacer() const;
    void setSeDeplacer(bool b);
    void attaquePossible(vector<Case *> &vecCases);
    void afficheActions();
    void dplPossible(vector<Case *> &vecCases);
};

#endif