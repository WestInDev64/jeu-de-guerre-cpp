#ifndef JEU_HPP
#define JEU_HPP

#include "Plateau.hpp"
#include "Joueur.hpp"

using namespace std;

class Jeu
{
protected:
    Plateau *m_grille;
    Joueur *m_j1;
    Joueur *m_j2;

public:
    Jeu();
    void Init();
    void initPlateau();
    Plateau *getPlateau();
};

Jeu::Jeu()
{
}

void Jeu::Init()
{
    char c1 = '-', c2 = '-';
    string name1 = "";
    string name2 = "";

    /* Init Joueur 1 */
    do
    {
        cout << "Joueur1 veuillez entrer votre nom: ";
        cin >> name1;
        if (name1 == "")
            cout << "Erreur, veuillez entrer un nom valide." << endl;
    } while (name1 == "");

    cout << name1 << endl;

    do
    {
        cout << "Veuillez sélectionner une couleur : Rouge / Bleu (r/b) ?";
        cin >> c1;
        cout << c1 << endl;
        if (c1 != 'r' && c1 != 'b')
            cout << "Erreur lors du choix de la couleur !" << endl;
    } while (c1 != 'r' && c1 != 'b');

    /* Init Joueur 2 */
    do
    {
        cout << "Joueur2 veuillez entrer votre nom: ";
        cin >> name2;
        if (name2 == "")
            cout << "Erreur, veuillez entrer un nom valide." << endl;
    } while (name2 == "");

    c1 == 'r' ? c2 = 'b' : c2 = 'r';

    /* Affichage couleur du 2eme joueur */
    c2 == 'r' ? cout << name2 << " sera donc le joueur Rouge" << endl : cout << name2 << " sera donc le joueur Bleu" << endl;

    /* Fin de fonction  */
    /* Allocations Joueurs */
    m_j1 = new Joueur(name1, c1);
    m_j2 = new Joueur(name2, c2);
}

void Jeu::initPlateau()
{
    m_grille = new Plateau();
}

Plateau *Jeu::getPlateau()
{
    return m_grille;
}

#endif // JEU_HPP