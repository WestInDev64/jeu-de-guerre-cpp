#include <iostream>
#include <string>
#include "Jeu.hpp"


int main()
{
    Jeu game;
    //game.Init();
    game.initPlateau();
    game.getPlateau()->affiche();

    return 0;
}

