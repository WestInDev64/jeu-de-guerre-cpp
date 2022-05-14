#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <iostream>
#include <string>
#include "Plateau.hpp"

using namespace std;

class Joueur
{
    string m_name;
    int m_qteOr;
    bool m_tour;
    char m_color; 
    int m_nbChateau;

public:
    Joueur();
    Joueur(string const& name, char const& color);
    void init();
    
    //~Joueur();
    //void afficherPions();
    int nbOr();
    //void creerChateau(Plateau plateau, int x, int y);
};


Joueur::Joueur()
{
    m_qteOr = 20;
    m_tour = false;
}

Joueur::Joueur(string const &name, char const &color)
{
    m_name = name;
    m_qteOr = 20;
    m_tour = false;
    m_color = color;
}

int Joueur::nbOr()
{
    return m_qteOr;
}

void Joueur::init(){
    
}


#endif // JOUEUR_HPP
