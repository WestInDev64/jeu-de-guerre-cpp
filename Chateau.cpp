#include "Chateau.hpp"
#include <iostream>

/* Méthodes */
Chateau::Chateau(Joueur *j) : Pion(j)
{
    m_pow = 0;
    m_pdv = 20;
    m_pdm = 0;
    m_prod = 2;
    m_cout = 15;
    m_ref[0] = 'C';
    m_ref[1] = j->getCouleur();
    m_joueur = j;
}

/* Un chateau peut recruter si le joueur à assez d'or (minimum requis 10 d'or) */
bool Chateau::peutRecruter(Joueur *j)
{
    if (j->getOr() < 10)
    {
        return false;
    }
    return true;
}

/**
 * Retourne un Pion dont le joueur veut construire
 *  Exemple : Le paramètre est P le Chateau recrute un Paysan;
 *
 * */
void Chateau::construirePion(int i)
{
    Pion *p;
    switch (i)
    {
    case 3:
        if (this->m_joueur->getOr() >= 20)
        {
            p = new Paysan(this->m_joueur);
        }
        else
        {
            cout << "Recrutement impossible, il vous faut : " << Paysan::getCout() << " d'or !" << endl;
        }
        break;

    case 1:
        if (this->m_joueur->getOr() >= 10)
        {
            p = new Seigneur(this->m_joueur);
        }
        else
        {
            cout << "Recrutement impossible, il vous faut : " << Seigneur::getCout() << " d'or !" << endl;
        }
        break;
    case 2:
        if (this->m_joueur->getOr() >= 10)
        {
            p = new Guerrier(this->m_joueur);
        }
        else
        {
            cout << "Recrutement impossible, il vous faut : " << Guerrier::getCout() << " d'or !" << endl;
        }
        break;
    }
    this->m_action = true;
}

string Chateau::affichetype()
{
    return "Chateau";
}

void Chateau::afficheActions()
{
    cout << "# Menu Principal :" << endl;
    cout << "   1 - Recruter un pion" << endl;
    cout << "   2 - Ne fait rien" << endl;
    cout << "   3 - Retour" << endl;
}

void Chateau::afficheRecruter()
{
    cout << "# Menu Principal :" << endl;
    cout << "   1 - Recruter un Seigneur | *" << Seigneur::getCout() << " D'OR"
         << "   2 - Recruter un Guerrier | *" << Guerrier::getCout() << " D'OR*"
         << "   3 - Recruter un Paysan   | *" << Paysan::getCout() << " D'OR" << endl;
    cout << "   4 - Retour" << endl;
}