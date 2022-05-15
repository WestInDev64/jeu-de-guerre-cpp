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

    /* Accesseurs */
    char getCouleur() const;
    string getNom() const;
    int getOr() const;
    int getNbChateau() const;

    /* Mutateurs */
    void setOr(int o);
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


/********************************************************
 *                      Accesseurs                      *
 ********************************************************/  

char Joueur::getCouleur() const 
{
    return m_couleur;
}

string Joueur::getNom() const
{
    return m_name;
}


int Joueur::getOr() const
{
    return m_qteOr;
}


int Joueur::getNbChateau() const
{
    return m_nbChateau;
}


/********************************************************
 *                      Mutateurs                       *
 ********************************************************/

void Joueur::setOr(int o)
{

    m_qteOr += o;
}

#endif // JOUEUR_HPP
