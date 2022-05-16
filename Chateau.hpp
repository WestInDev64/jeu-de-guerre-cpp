#ifndef CHATEAU_HPP
#define CHATEAU_HPP

#include "Pion.hpp"

class Chateau : public Pion
{

private:
public:
    /* Méthodes */
    Chateau(Joueur *j);

    /* Un chateau peut recruter si le joueur à assez d'or (minimum requis 10 d'or) */
    bool peutRecruter(Joueur *j);

    /** Retourne une chaine pour indiquer qu'elle sont les pions qui peuvent être recruter
     * Exemple : Si le joueur à 15 d'or, la chaine sera "SG" car il a pas assez d'or pour un paysan
     */
    string recrutementPossible(Joueur *j);

    /** Produit de l'or passivement au début du tour du joueur
     *  (Ne compte pas comme une action)
     */
    void produireOr(Joueur *j);
    /**
     * Retourne un Pion dont le joueur veut construire
     * Exemple : Le paramètre est P le Chateau recrute un Paysan; 
     * */
    Pion *construirePion(char c);

    /* Méthodes Affichages */
    string affichetype();
    void afficheActions();
    void afficheRecruter();
};

#endif //CHATEAU_HPP