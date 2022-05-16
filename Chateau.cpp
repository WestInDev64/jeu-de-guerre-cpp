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

/** Retourne une chaine pour indiquer qu'elle sont les pions qui peuvent être recruter
 * Exemple : Si le joueur à 15 d'or, la chaine sera "SG" car il a pas assez d'or pour un paysan
 *
 */
string Chateau::recrutementPossible(Joueur *j)
{
    string pionRecrutable = "";
    if (j->getOr() >= 20)
    {
        pionRecrutable += "P";
    }
    if (j->getOr() >= 10)
    {
        pionRecrutable += "SG";
    }
    return pionRecrutable;
}

/** Produit de l'or passivement au début du tour du joueur
 *  (Ne compte pas comme une action)
 *
 */
void Chateau::produireOr(Joueur *j)
{
    j->setOr(m_prod);
}

/**
 * Retourne un Pion dont le joueur veut construire
 *  Exemple : Le paramètre est P le Chateau recrute un Paysan;
 *
 * */
Pion *Chateau::construirePion(char c)
{
    Pion *p;
    switch (c)
    {
    case 'P':
        p = new Paysan(this->m_joueur);
        break;

    case 'S':
        p = new Seigneur(this->m_joueur);
        break;

    case 'G':
        p = new Guerrier(this->m_joueur);
        break;
    }
    m_action = true;
    return p;
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
    cout << "   1 - Recruter un Seigneur | "
         << "   2 - Recruter un Guerrier | "
         << "   3 - Recruter un Paysan" << endl;
    cout << "   4 - Retour" << endl;
}