#include "Seigneur.hpp"
#include "functions.hpp"
#include <iostream>
#include <vector>
#include "Case.hpp"

Seigneur::Seigneur(Joueur *j, int x, int y) : Pion(j, x, y)
{
    m_pow = 3;
    m_pdv = 5;
    m_pdm = 1;
    m_prod = 0;
    m_cout = 10;
    m_ref = "S" + j->getCouleur();
    m_joueur = j;
}

/* Un Seigneur peut se Transformer si le joueur à assez d'or */
bool Seigneur::peutSeTransformer()
{
    if (m_joueur->getOr() >= 15)
    {
        return true;
    }
    return false;
}

void Seigneur::payerChateau(Pion &p)
{
    m_joueur->enleverOr(p.getCout());
}

void Seigneur::attaque(Pion &p)
{
    p.setPdv(p.getPdv() - this->m_pow);
}

bool Seigneur::getSeDeplace()
{
    return m_seDeplace;
}

void Seigneur::s_estDeplacer()
{
    m_seDeplace = true;
}

string Seigneur::affichetype()
{
    return "Seigneur";
}
