#ifndef PAYSAN_HPP
#define PAYSAN_HPP

#include "Pion.hpp"

class Paysan : public Pion
{
private:
    bool m_seDeplace = false;

public:
    Paysan(Joueur *j);
    void produireOrS(Joueur *j);
    bool getSeDeplace();
    void s_estDeplacer();
    string affichetype();
    void afficheActions();


};

#endif // PAYSAN_HPP