#include "Paysan.hpp"
#include "functions.hpp"
#include <iostream>
#include <vector>
#include "Case.hpp"


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
void Paysan::produireOrS()
{
    m_joueur->ajouterOr(m_prod);
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

void Paysan::mvtPossible(vector<Case *> &vecCases)
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


void Paysan::selectActions()
{
    int choix;
    do
    {
        choix = choixMenu();
        cin.clear();
        switch (choix)
        {
        case 1:
            //mvtPossible();
            //construirePion(choixMenu());
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
