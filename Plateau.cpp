#include "Plateau.hpp"

/**
 * Méthode qui retourne un char en fonction de notre enum
 */
char enumToChar(int abc)
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
        cout << setw(3) << enumToChar(i) << "  |";
        // cout << "  +---+---+---+---+---+---+---+---+---+---+" << endl;
        for (int j = 0; j < m_col; j++)
        {
            if (strlen(tabCase[i][j]->getPion()->getRef()) == 2)
                cout << tabCase[i][j]->getPion()->getRef() << " |";
            else
                cout << "   |";
        }
        cout << endl;
    }
    cout << "     +---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << endl;
    getchar();
}