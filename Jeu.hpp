#ifndef JEU_HPP
#define JEU_HPP

#include "Plateau.hpp"
#include "Joueur.hpp"
#include <string>

using namespace std;

class Jeu
{
protected:
    Plateau *m_plateau;
    Joueur *m_j1;
    Joueur *m_j2;
    bool m_tourJ1;

public:
    Jeu();
    void Init();
    void Start();
    void initPlateau();
    void InterfaceJoueur(Joueur * j);
    void Commandes(Joueur *j);

    /* accesseurs */
    Plateau *getPlateau() const;
    Joueur *getJoueur1() const;
    Joueur *getJoueur2() const;

    /* mutateurs */
    void setCase(Pion *p, int x, int y);
};

Jeu::Jeu()
{
}

void Jeu::Init()
{
    char c1 = '-', c2 = '-';
    string name1 = "";
    string name2 = "";

    cout << "Nouvelle Partie : LA GUERRE" << endl;
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
        cout << "Veuillez sélectionner une couleur : Rouge / Bleu (R/B) ?";
        cin >> c1;
        cout << c1 << endl;
        if (c1 != 'R' && c1 != 'B')
            cout << "Erreur lors du choix de la couleur !" << endl;
    } while (c1 != 'R' && c1 != 'B');

    /* Init Joueur 2 */
    do
    {
        cout << "Joueur2 veuillez entrer votre nom: ";
        cin >> name2;
        if (name2 == "")
            cout << "Erreur, veuillez entrer un nom valide." << endl;
    } while (name2 == "");

    c1 == 'R' ? c2 = 'B' : c2 = 'R';

    /* Affichage couleur du 2eme joueur */
    c2 == 'R' ? cout << name2 << " sera donc le joueur Rouge" << endl : cout << name2 << " sera donc le joueur Bleu" << endl;

    /* Fin de fonction  */
    /* Allocations Joueurs */
    m_j1 = new Joueur(name1, c1);
    m_j2 = new Joueur(name2, c2);

    /* Attribution du tour */
    m_tourJ1 = true;
}

void Jeu::initPlateau()
{
    m_plateau = new Plateau(10, 10);

    Pion *chatj1 = new Chateau(m_j1);
    Pion *payj1 = new Paysan(m_j1);
    setCase(chatj1, 1, 1);
    setCase(payj1, 1, 2);

    Pion *chatj2 = new Chateau(m_j2);
    Pion *payj2 = new Paysan(m_j2);
    setCase(chatj2, 8, 8);
    setCase(payj2, 8, 7);
}

void Jeu::Start()
{
    this->getPlateau()->affiche();
    if (m_tourJ1){
        cout << " > C'est au tour de : [ " << getJoueur1()->getNom() << " ] de jouer ..." << endl;
        InterfaceJoueur(m_j1);
        Commandes(m_j1);
    }
    else{
        cout << " > C'est au tour de : [ " << getJoueur2()->getNom() << " ] de jouer ..." << endl;
        InterfaceJoueur(m_j2);
        Commandes(m_j2);
    }
    
}

void Jeu::InterfaceJoueur(Joueur *j)
{
    int lig = 4;
    int col = 1;
    string labels[4] = {"Nom: ", "Couleur: ", "Or: ", "Nb de Chateau: "};
    string inputs[4] = {j->getNom(),
                        (j->getCouleur() == 'R') ? ("Rouge") : ("Bleu"),
                        to_string(j->getOr()),
                        to_string(j->getNbChateau())};

    cout << "+-----------------------------+" << endl;
    cout << "|" << setfill(' ') << setw(29) << left << " Interface Joueur " << "|" << endl;
    cout << "+--------------------+--------+" << endl;
    for (int i = 0; i < lig; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "|" << setfill(' ') << setw(20) << left << labels[i] << "|" << setw(8) << internal << inputs[i] << "|" << endl;
        }
    }
    cout << "+--------------------+--------+" << endl;
    cout << endl;
}

void Jeu::Commandes(Joueur *j){
    cout << endl;
    cout << "Liste des commandes:" << endl; 
    cout << "____________________" << endl; 
    cout << "   1-Menu" << endl; 
    cout << "   1-Menu" << endl; 
    cout << "   1-Menu" << endl; 
}


/********************************************************
 *                      Accesseurs                      *
 ********************************************************/

Plateau *Jeu::getPlateau() const
{
    return m_plateau;
}

Joueur *Jeu::getJoueur1() const
{
    return m_j1;
}

Joueur *Jeu::getJoueur2() const
{
    return m_j2;
}

/********************************************************
 *                      Mutateurs                       *
 ********************************************************/
void Jeu::setCase(Pion *p, int x, int y)
{
    m_plateau->getTabCase()[x][y]->setPion(p);
}

#endif // JEU_HPP