#ifndef JOUEUR_HPP
#define JOUEUR_HPP

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
    void setNbChateau();
    void taxeDesChateaux();
};


#endif // JOUEUR_HPPPP
