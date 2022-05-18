#include "Guerrier.hpp"
#include "functions.hpp"
#include <iostream>
#include <vector>
#include "Case.hpp"

Guerrier::Guerrier(Joueur *j, int x, int y) : Pion(j, x, y)
{
    m_pow = 5;
    m_pdv = 10;
    m_pdm = 3;
    m_prod = 0;
    m_cout = 10;
    m_ref = "G" + j->getCouleur();
    m_joueur = j;
}

void Guerrier::attaque(Pion *p)
{
    p->setPdv(p->getPdv() - this->m_pow);
}

string Guerrier::affichetype()
{
    return "Guerrier";
}

bool Guerrier::peutSeDeplacer() const
{
    return m_seDeplace;
}

void Guerrier::setSeDeplacer(bool b)
{
    m_seDeplace = b;
}

void Guerrier::attaquePossible(vector<Case *> &vecCases)
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

void Guerrier::afficheActions()
{
    cout << "SELECT: [ " << this->affichetype()
         << " (" << enumToChar(this->getX())
         << ", " << this->getY() << ") ]" << endl;
    cout << endl
         << "# Menu action :" << endl;
    cout << "   1 - Se Déplacer" << endl;
    cout << "   2 - Attaquer" << endl;
    cout << "   3 - Retour" << endl;
}

void Guerrier::dplPossible(vector<Case *> &vecCases)
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