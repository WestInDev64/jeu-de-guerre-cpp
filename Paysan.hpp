#ifndef PAYSAN_HPP
#define PAYSAN_HPP

#include "Pion.hpp"

class Paysan : public Pion
{
private:
    bool m_seDeplace = false;

public:
    Paysan(Joueur *j, int x, int y);
    void produireOrS(Joueur *j);
    bool getSeDeplace();
    void s_estDeplacer();
    string affichetype();
    void afficheActions();
    void selectActions();
    void mvtPossible(vector<Case *> &vecCases);
};

#endif // PAYSAN_HPP