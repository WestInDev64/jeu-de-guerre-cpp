#ifndef JEU_HPP
#define JEU_HPP

#include "Plateau.hpp"
#include "Joueur.hpp"
#include "Case.hpp"
#include "Pion.hpp"
#include "Chateau.hpp"
#include <string>
#include <vector>

using namespace std;

inline int choixMenu();

class Jeu
{
protected:
    Plateau *m_plateau;
    Joueur *m_j1;
    Joueur *m_j2;

    int m_tourJ1;
    int etatTourPhase1;
    int etatTourPhase2;
    bool gameOver; // false durant toute la partie pour afficher un message
    bool victoire; // pareil oui

    vector<Case *> vecCasesJoueur1;
    vector<Case *> vecCasesJoueur2;
    // vector<Case*> vecCasesJ1;

public:
    Jeu();
    void Init();
    void Start();
    void initPlateau();

    /* Affichage & Menus */
    void InterfaceJoueur();
    void afficheMenuTour();
    void afficheSelectionPion(vector<Case *> vecCases);
    void selectionMenu(vector<Case *> vecCases);
    void choixPion(vector<Case *> vecCases);

    /**
     * TODO: Méthode estGameOver()
     * nbChateau = 0
     * TODO: Méthode estVainqueur()
     * détruire les chateaux adv
     * ya pas d'autre conditions de victoires ?
     * ok on peut en rajouter
     * 20 TOURS == ok comptabilité
     * TODO: Seigneur Transforme en chateau()
     * il faut peut se tranformer dans Seigneur
     * si assez d'or tout simplement == 1 action du seigneur
     *
     * de quoi ?
     * comment çà ?
     * S1 = C1 = S4 = C4 =  ,  S2 S3
     *
     * bah oui non 1 transformation = terminé
     * et bool du Chateau  a false
     * pareil pour Seigneur qui pop
     *
     * TODO: Calculs Fin de tour (Récoltes etc booléens)
     * Passer son tour non car si il crée un chateau après
     * il aura pas son or
     * alors qu'a la fin il aura tout son or
     * ah ok faut noter
     * Récolte OR du chateau créer actif au prochain tour
     * oui voila
     *
     */

    /* accesseurs */
    Plateau *getPlateau() const;
    Joueur *getJoueur1() const;
    Joueur *getJoueur2() const;
    Case *selectionPion(int num, vector<Case *> vecCases) const;

    /* mutateurs */
    void setCase(Pion *p, int x, int y);
};

#endif // JEU_HPP