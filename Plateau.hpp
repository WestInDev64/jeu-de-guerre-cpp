#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "Case.hpp"
#include <cstring>
#include <iomanip>

using namespace std;

enum Alphabet
{
    A,B,C,D,E,F,G,H,I,J,K,L,M,
    N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
};

class Plateau
{
private:
    // std::array<Case,20*20> m_plateau;
    /**
     * * Tableau de tableau de cases
     * TODO: faire une méthode deplacerPion() avec move d'une case à une autre
     */
    int m_lig;
    int m_col;
    Case ***tabCase;

public:
    Plateau(int nbx, int nby);
    void affiche();
    Case ***getTabCase() const;
    char enumToChar(int abc);
};

Case ***Plateau::getTabCase() const
{
    return tabCase;
}

/* Constructeur de plateau */
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

/**
 * * Affichage du Plateau paramétrer sur 10*10
 */
void Plateau::affiche()
{
    cout << endl;
    size_t fieldWidth = 3; // length of longest text
    cout << "       0   1   2   3   4   5   6   7   8   9  " << endl;
    for (int i = 0; i < m_lig; i++)
    {
        cout << "     +---+---+---+---+---+---+---+---+---+---+" << endl;
        cout << setw(fieldWidth) << internal << enumToChar(i) << "  |";
        // cout << "  +---+---+---+---+---+---+---+---+---+---+" << endl;
        for (int j = 0; j < m_col; j++)
        {
            if (strlen(tabCase[i][j]->getPion()->getRef()) == 2)
                cout << "" << tabCase[i][j]->getPion()->getRef() << " |";
            else
                cout << " "
                     << "  |";
        }
        cout << endl;
    }
    cout << "     +---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << endl;
}

/**
 * Méthode qui retourne un char en fonction de notre enum
 */ 
char Plateau::enumToChar(int abc)
{
    switch (abc)
    {
    case A:
        return 'A';
    case B:
        return 'B';
    case C:
        return 'C';
    case D:
        return 'D';
    case E:
        return 'E';
    case F:
        return 'F';
    case G:
        return 'G';
    case H:
        return 'H';
    case I:
        return 'I';
    case J:
        return 'J';
    case K:
        return 'K';
    case L:
        return 'L';
    case M:
        return 'M';
    case N:
        return 'N';
    case O:
        return 'O';
    case P:
        return 'P';
    case Q:
        return 'Q';
    case R:
        return 'R';
    case S:
        return 'S';
    case T:
        return 'T';
    case U:
        return 'U';
    case V:
        return 'V';
    case W:
        return 'W';
    case X:
        return 'X';
    case Y:
        return 'Y';
    case Z:
        return 'Z';
    default:
        return '.';
    }
}

#endif // PLATEAU_HPP