#include "Joueur.hpp"

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

/* Les chateaux rapportent de l'or au début du tour d'un joueur */
void Joueur::taxeDesChateaux() {
    m_qteOr += m_nbChateau * 2;
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

void Joueur::setNbChateau()
{
    m_nbChateau += 1;
}