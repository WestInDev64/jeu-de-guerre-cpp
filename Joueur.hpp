#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <iostream>
#include <string>


using namespace std;

class Joueur
{
    string m_name;
    int m_qteOr;
    bool m_tour;
    char m_couleur; 
    int m_nbChateau;

public:
    Joueur();
    Joueur(string const& name, char const& color);
    char getCouleur() const;
    int nbOr();
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
    m_couleur = color;
}

int Joueur::nbOr()
{
    return m_qteOr;
}


char Joueur::getCouleur() const 
{
    return m_couleur;
}


#endif // JOUEUR_HPP
