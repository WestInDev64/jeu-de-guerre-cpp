#include "Jeu.hpp"

int main()
{
    Jeu game;
    game.Init();
    game.initPlateau(10,10);
    //Joueur * j = new Joueur("test", 'R'); 
    //Pion * p = new Guerrier(j);
    //game.setCase(p,0,0);
    //game.getPlateau()->affiche();
    game.Start();
    

    return 0;
}

