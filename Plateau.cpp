#include "Plateau.hpp"
#include <cstring>
#include "functions.hpp"



/* Constructeur de plateau */
Plateau::Plateau(int nbx, int nby)
{
    m_lig = nbx;
    m_col = nby;
    m_taille = nbx * nby;
    tabCase = new Case **[m_lig];
    for (int x = 0; x < m_lig; x++)
    {
        tabCase[x] = new Case *[m_col];
        for (int y = 0; y < m_col; y++)
        {
            /* init du constr de Case dans chaque cellule */
            tabCase[x][y] = new Case(x, y);
        }
    }
}

Case ***Plateau::getTabCase() const
{
    return tabCase;
}

/**
 * * Affichage du Plateau paramétrer sur 10*10
 * TODO: A rectifier pour 2eme affichage (Pinaillage)
 */
void Plateau::affiche()
{
    cout.clear();
    cout << endl;
    cout << "       0   1   2   3   4   5   6   7   8   9  " << endl;
    for (int i = 0; i < m_lig; i++)
    {
        cout << "     +---+---+---+---+---+---+---+---+---+---+" << endl;
        cout << setfill(' ') << setw(3) << enumToChar(i) << "  |";
        // cout << "  +---+---+---+---+---+---+---+---+---+---+" << endl;
        for (int j = 0; j < m_col; j++)
        {
            /* IL FAUT AUTRE CHOSE QUE STRLEN  oui
            Pourquoi 8 tt a l'heure ? ah bah si le pointeur
            */
            /* ICI */
            cout << setfill(' ') << setw(3) << tabCase[i][j]->getPion()->getRef() << "|";
        }
        cout << endl;
    }
    cout << "     +---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << endl;
    getchar();
}

int Plateau::getNbCol() const
{
    return m_col;
}

int Plateau::getTaille() const 
{
    return m_taille;
}