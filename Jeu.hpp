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

using namespace std;

class Jeu
{
protected:
    Plateau *m_plateau;
    Joueur *m_j1;
    Joueur *m_j2;

    int m_tourJ; // 0 = J1  1 = J2
    int m_nb_tour;
    int etatTourPhase1;
    int etatTourPhase2;

    /* Voir TODO */
    bool gameOver; // false durant toute la partie pour afficher un message
    bool victoire; // pareil oui


    vector<Case *> vecCasesJoueur1;
    vector<Case *> vecCasesJoueur2;
    
    /* A vérifier si possibilité de comparer avec m_plateau  */
    vector<Case*> vecCasesAdjacentes; 
    
    // vector<Case*> vecCasesJ1;

public:
    Jeu();
    void Init();
    void Start();
    void initPlateau();
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


    void vecCasesAjacentes(int x, int y , vector<Case*> & vec);

    /**
     * TODO: Méthode estGameOver()
     * nbChateau = 0 puis bool vrai ou false
     * TODO: Méthode estVainqueur()
     * détruire les chateaux adv idem 
     * ya pas d'autre conditions de victoires ?
     * ok on peut en rajouter
     * 20 TOURS == ok comptabilité
     * TODO: Seigneur Transforme en chateau()
     * ? Verifier qu'elle fonctionne 
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
    void transformerEnChateau(int x, int y);
    void marqueCasesAdj(vector<Case *> &vecCases);
    int getNbTour() const;
    /* mutateurs */
    void setCase(Pion *p, int x, int y);
    void setNbTour();
};

#endif // JEU_HPP