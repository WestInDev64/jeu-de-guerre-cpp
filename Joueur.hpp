#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <string>

using namespace std;

class Joueur
{
    string m_name;
    int m_qteOr;
    bool m_tour;
    string m_couleur;
    int m_nbChateau;

public:
    Joueur();
    Joueur(string const& name, string const& color);

    /* Accesseurs */
    string getCouleur() const;
    string getNom() const;
    int getOr() const;
    int getNbChateau() const;

    /* Mutateurs */
    void ajouterOr(int o);
    void enleverOr(int o);
    void setNbChateau();
    void taxeDesChateaux();
    
};


#endif // JOUEUR_HPP
