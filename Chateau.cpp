#include "Chateau.hpp"
#include <iostream>
#include "functions.hpp"
#include "Paysan.hpp"

/* Méthodes */
Chateau::Chateau(Joueur *j) : Pion(j)
{
    m_pow = 0;
    m_pdv = 20;
    m_pdm = 0;
    m_prod = 2;
    m_cout = 15;
    m_ref = "C" + j->getCouleur();
    m_joueur = j;
    m_coutrect = {10, 10, 20};
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
 * !ERROR DESTRUCTEUR 
 *
 * */
void Chateau::construirePion(int i)
{
    Pion *p = nullptr;
    switch (i)
    {
    case 1:
        if (this->m_joueur->getOr() >= 10)
            p = new Seigneur(this->m_joueur);
        else
            cout << "Recrutement impossible, il vous faut : " << dynamic_cast<Seigneur *>(this)->getCout() << " d'or !" << endl;
        break;
    case 2:
        if (this->m_joueur->getOr() >= 10)
            p = new Guerrier(this->m_joueur);
        else
            cout << "Recrutement impossible, il vous faut : " << dynamic_cast<Guerrier *>(this)->getCout() << " d'or !" << endl;
        break;
    case 3:
        if (this->m_joueur->getOr() >= 20)
            p = new Paysan(this->m_joueur);
        else
            cout << "Recrutement impossible, il vous faut : " << dynamic_cast<Paysan *>(this)->getCout() << " d'or !" << endl;
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
    cout << "SELECT: [ " << this->affichetype()
         << " (" << enumToChar(this->getX())
         << ", " << this->getY() << ") ]" << endl;
    cout << endl
         << "# Menu action :" << endl;
    cout << "   1 - Recruter un pion" << endl;
    cout << "   2 - Ne fait rien" << endl;
    cout << "   3 - Retour" << endl;
}

void Chateau::afficheRecruter()
{
    cout << endl
         << "# Menu Recrutement :" << endl;
    cout << "   1 - Recruter un Seigneur *" << m_coutrect[0] << " D'OR |" << endl;
    cout << "   2 - Recruter un Guerrier *" << m_coutrect[1] << " D'OR |" << endl;
    cout << "   3 - Recruter un Paysan *" << m_coutrect[2] << " D'OR |" << endl;
    cout << "   4 - Retour" << endl;
}

void Chateau::selectActions()
{
    int choix;
    do
    {
        choix = choixMenu();
        cin.clear();
        switch (choix)
        {
        case 1:
            afficheRecruter();
            construirePion(choixMenu());
            break;
        case 2:
            break;
        case 3:
            cout << " ../Retour " << endl;
            break;
        default:
            cout << "Erreur saisie ! ... " << endl;
            break;
        }
    } while (choix != 3);
}