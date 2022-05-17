#include "functions.hpp"
#include <iostream>

using namespace std;

int choixMenu()
{
    int choix;
    cin >> choix;
    return choix;
}

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