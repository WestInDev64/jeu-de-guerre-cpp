#ifndef JEU_HPP
#define JEU_HPP

#include "Plateau.hpp"
#include "Joueur.hpp"

using namespace std;

class Jeu
{
protected:
    Plateau *m_plateau;
    Joueur *m_j1;
    Joueur *m_j2;

public:
    Jeu();
    void Init();
    void initPlateau();
    Plateau *getPlateau();
    void setCase( Pion * p, int x, int y);
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
}

void Jeu::initPlateau()
{
    m_plateau = new Plateau(20,20);
    
    Pion * chatj1 = new Chateau(m_j1);
    Pion * payj1 = new Paysan(m_j1);
    setCase(chatj1,1,4);
    setCase(payj1,1,5);

    
    Pion * chatj2 = new Chateau(m_j2);
    Pion * payj2 = new Paysan(m_j2);
    setCase(chatj2,19,16);
    setCase(payj2,19,15);
 }

Plateau *Jeu::getPlateau()
{
    return m_plateau;
}


void Jeu::setCase(Pion *p, int x, int y)
{
    m_plateau->getTabCase()[x][y]->setPion(p);
}


#endif // JEU_HPP