#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "Case.hpp"
#include <cstring>

using namespace std;

class Plateau
{
private:
    // std::array<Case,20*20> m_plateau;
    /**
     * * Tableau de tableau de cases
     * TODO: Faire une enum pour l'affichage
     * TODO: faire une méthode deplacerPion() avec move d'une case à une autre
     */
    int m_lig;
    int m_col;
    Case ***tabCase;

public:
    Plateau(int nbx, int nby);
    void affiche();
    Case ***getTabCase() const;
};

Case *** Plateau::getTabCase() const
{
    return tabCase;
}

/* Constructeur */
Plateau::Plateau(int nbx, int nby)
{
    m_lig = nbx;
    m_col = nby;
    tabCase = new Case **[m_lig];
    for (int x = 0; x < m_lig; x++)
    {
        tabCase[x] = new Case *[m_col];
        for (int y = 0; y < m_col; y++)
        {
            /* init du constr de Case dans chaque cellule */
            tabCase[x][y] = new Case();
        }
    }
}

void Plateau::affiche()
{
    /**
     * TODO: Revoir l'affichage en utilisant enum (A,B,C ... chess)
     */
    cout << endl;
    cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = " << endl;
    for (int i = 0; i < m_lig; i++)
    {
        for (int j = 0; j < m_col; j++)
        {
            if (strlen(tabCase[i][j]->getPion()->getRef()) == 2)
                cout << tabCase[i][j]->getPion()->getRef() << ", ";
            else
                cout << "   , ";
        }
        cout << endl;
    }
    cout << endl;
}

#endif // PLATEAU_HPP