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

void Seigneur::attaque(Pion *p)
{
    p->setPdv(p->getPdv() - this->m_pow);
}

bool Seigneur::peutSeDeplacer() const
{
    return m_seDeplace;
}

void Seigneur::setSeDeplacer(bool b)
{
    m_seDeplace = b;
}

string Seigneur::affichetype()
{
    return "Seigneur";
}

void Seigneur::attaquePossible(vector<Case *> &vecCases)
{
    cout << "Attaques possibles: " << vecCases.size() << " positions: " << endl;
    for (int i = 0; i < (int)vecCases.size(); i++)
    {
        cout << "   "
             << (i + 1)
             << " - Case: "
             << "(" << enumToChar(vecCases[i]->getX()) << "," << vecCases[i]->getY() << ")" << endl;
    }
    cout << "   "
         << ((int)vecCases.size() + 1)
         << " - Retour au menu précédent" << endl;
}

void Seigneur::afficheActions()
{
    cout << "SELECT: [ " << this->affichetype()
         << " (" << enumToChar(this->getX())
         << ", " << this->getY() << ") ]" << endl;
    cout << endl
         << "# Menu action :" << endl;
    cout << "   1 - Se Déplacer" << endl;
    cout << "   2 - Attaquer" << endl;
    cout << "   3 - Se Transformer en Chateau" << endl;
    cout << "   4 - Retour" << endl;
}

void Seigneur::dplSPossible(vector<Case *> &vecCases)
{
    cout << "Déplacements possibles: " << vecCases.size() << " positions: " << endl;
    for (int i = 0; i < (int)vecCases.size(); i++)
    {
        cout << "   "
             << (i + 1)
             << " - Case: "
             << "(" << enumToChar(vecCases[i]->getX()) << "," << vecCases[i]->getY() << ")" << endl;
    }
    cout << "   "
         << ((int)vecCases.size() + 1)
         << " - Retour au menu précédent" << endl;
}

void Seigneur::afficheEmplPossible(vector<Case *> &vecCases)
{
    cout << endl;
    cout << "Emplacements possibles: " << vecCases.size() << " positions: " << endl;
    for (int i = 0; i < (int)vecCases.size(); i++)
    {
        cout << "   "
             << (i + 1)
             << " - Case: "
             << "(" << enumToChar(vecCases[i]->getX()) << "," << vecCases[i]->getY() << ")" << endl;
    }
    cout << "   "
         << ((int)vecCases.size() + 1)
         << " - Retour au menu précédent" << endl;
}