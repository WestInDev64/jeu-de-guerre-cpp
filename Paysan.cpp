#include "Paysan.hpp"
#include "functions.hpp"
#include <iostream>

using namespace std;

Paysan::Paysan(Joueur *j, int x, int y) : Pion(j,x,y)
{
    m_pow = 0;
    m_pdv = 1;
    m_pdm = 2;
    m_prod = 5;
    m_cout = 20;
    m_ref = "P" + j->getCouleur();
    m_joueur = j;
}
void Paysan::produireOrS(Joueur *j)
{
    j->setOr(m_prod);
}

bool Paysan::getSeDeplace()
{
    return m_seDeplace;
}

void Paysan::s_estDeplacer()
{
    m_seDeplace = true;
}

string Paysan::affichetype()
{
    return "Paysan";
}

void Paysan::afficheActions()
{
    cout << "SELECT: [ " << this->affichetype()
         << " (" << enumToChar(this->getX())
         << ", " << this->getY() << ") ]" << endl;
    cout << endl
         << "# Menu action :" << endl;
    cout << "   1 - Se Déplacer" << endl;
    cout << "   2 - Amasser des ressources" << endl;
    cout << "   3 - Retour" << endl;
}