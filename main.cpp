#include <iostream>
#include "Jeu.hpp"


int main()
{
    Jeu game;
    game.Init();
    game.initPlateau();
    Joueur * j = new Joueur("test", 'R'); 
    Pion * p = new Guerrier(j);
    game.setCase(p,0,0);
    game.getPlateau()->affiche();
    

    return 0;
}

