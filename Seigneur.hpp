#ifndef SEIGNEUR_HPP
#define SEIGNEUR_HPP

#include "Pion.hpp"
#include "Case.hpp"



class Seigneur : public Pion
{
private:
    bool m_seDeplace = false;

public:
    Seigneur(Joueur *j, int x, int y);

    /* Un Seigneur peut se Transformer si le joueur à assez d'or */
    bool peutSeTransformer();
    void payerChateau(Pion &p);
    void attaque(Pion &p);
    bool getSeDeplace();
    void s_estDeplacer();
    string affichetype();
};

#endif