#ifndef JEU_HPP
#define JEU_HPP

#include "Plateau.hpp"
#include "Joueur.hpp"
#include "Case.hpp"
#include "Pion.hpp"
#include "Chateau.hpp"
#include <string>
#include <vector>
#include "functions.hpp"
#include "Paysan.hpp"
#include "Guerrier.hpp"
#include "Seigneur.hpp"

using namespace std;

class Jeu
{
protected:
    Plateau *m_plateau;
    Joueur *m_j1;
    Joueur *m_j2;

    int m_tourJ; // 0 = J1  1 = J2
    int m_nb_tour; // Numero de Tour
    int etatTourPhase1; // Tour Phase 1 sans taxe or Chateaux
    int etatTourClassique; // Tour classique

    /* Voir TODO */
    bool gameOver; // false durant toute la partie pour afficher un message

    vector<Case *> vecCasesJoueur1;
    vector<Case *> vecCasesJoueur2;

    vector<Case *> vecCasesAdj;
    vector<Case *> vecCasesMvts;
    vector<Case *> vecCasesActives;
    vector<Case *> vecCasesEnnemis;

    // vector<Case*> vecCasesJ1;

public:
    Jeu();
    void Init();
    void Start();
    void initPlateau(int x, int y);
    /**
     * TODO: A faire
     */
    void Quitter();

    /* Affichage & Menus */
    void InterfaceJoueur();
    void afficheMenuTour();
    void affichePion(vector<Case *> &vecCases);

    /* Sélections Switch */
    void selectionMenu(vector<Case *> &vecCases);
    void selectPion(vector<Case *> &vecCases);

    void vecCasesAdjacentes(int x, int y, vector<Case *> &vec);
    void vecCasesAdjEnnemis(int x, int y, vector<Case *> &vec, vector<Case *> &vecEnnemis);
    void vecCasesDeplacement1(int x, int y, vector<Case *> &vecADJ, vector<Case *> &vecDPL);
    void vecCasesDeplacement2(int x, int y, vector<Case *> &vecADJ, vector<Case *> &vecDPL);
    void vecCasesDeplacement3(int x, int y, vector<Case *> &vecADJ, vector<Case *> &vecDPL);
    void vecCasesDeplacement5(int x, int y, vector<Case *> &vecADJ, vector<Case *> &vecDPL);
    void updateCasesActives(vector<Case *> &vecCases);
    void updateCasesJoueurs(vector<Case *> &vecCases, Joueur *j);

    /* Actions Pions */
    void switchActionsPaysan(int choix, int x, int y);
    void switchActionsChateau(int choix, int x, int y);
    void switchActionsGuerrier(int choix, int x, int y);
    void switchActionsSeigneur(int choix, int x, int y);

    void estGameOver();
    /**
     * TODO: Seigneur Transforme en chateau()
     * ? Verifier qu'elle fonctionne
     * il faut peut se tranformer dans Seigneur
     * si assez d'or tout simplement == 1 action du seigneur
     * de quoi ?
     * comment çà ?
     * S1 = C1 = S4 = C4 =  ,  S2 S3
     * bah oui non 1 transformation = terminé
     * et bool du Chateau  a false
     * pareil pour Seigneur qui pop
     * * Guerrier( Déplacement *3 + Attaque )
     * subit des dégats
     * TODO: Etat des TOurs (résumés)
     * Dans un autre fichier LOG
     */

    /********************************************************
     *                      Accesseurs                      *
     ********************************************************/
    Plateau *getPlateau() const;
    Joueur *getJoueur1() const;
    Joueur *getJoueur2() const;
    Case *selectionPion(int num, vector<Case *> vecCases) const;
    Case *selectionCase(int num, vector<Case *> vecCases);
    void transformerEnChateau(int x, int y);
    void marqueCasesAdj(vector<Case *> &vecCases);
    void marqueCasesAdjEnnemis(vector<Case *> &vec, int x, int y);
    void cleanCasesMvt(vector<Case *> &vec);
    int getNbTour() const;
    /********************************************************
     *                      Mutateurs                       *
     ********************************************************/
    void setCase(Pion *p, int x, int y);
    void setNbTour();
};

#endif // JEU_HPP