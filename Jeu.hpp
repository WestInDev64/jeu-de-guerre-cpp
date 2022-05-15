#ifndef JEU_HPP
#define JEU_HPP

#include "Plateau.hpp"
#include "Joueur.hpp"
#include <string>
#include <vector>

using namespace std;

class Jeu
{
protected:
    Plateau *m_plateau;
    Joueur *m_j1;
    Joueur *m_j2;

    bool m_tourJ1;
    int etatTourPhase1;
    int etatTourPhase2;

    vector<Case *> vecCasesJoueur1;
    vector<Case *> vecCasesJoueur2;
    // vector<Case*> vecCasesJ1;

public:
    Jeu();
    void Init();
    void Start();
    void initPlateau();
    void InterfaceJoueur();
    int Commandes(Joueur *j);
    void afficheMenuSelection();

    /* accesseurs */
    Plateau *getPlateau() const;
    Joueur *getJoueur1() const;
    Joueur *getJoueur2() const;
    Case *selectionPion(int num) const;

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
    vecCasesJoueur1.push_back(m_plateau->getTabCase()[1][1]);
    vecCasesJoueur1.push_back(m_plateau->getTabCase()[1][2]);

    Pion *chatj2 = new Chateau(m_j2);
    Pion *payj2 = new Paysan(m_j2);
    setCase(chatj2, 8, 8);
    setCase(payj2, 8, 7);
    vecCasesJoueur2.push_back(m_plateau->getTabCase()[8][8]);
    vecCasesJoueur2.push_back(m_plateau->getTabCase()[8][7]);
}

void Jeu::Start()
{
    this->getPlateau()->affiche();
    InterfaceJoueur();
    if (m_tourJ1)
    {
        cout << " > C'est au tour de : [ " << getJoueur1()->getNom() << " ] de jouer ..." << endl;
        int n = Commandes(m_j1);
        afficheMenuSelection();
    }
    else
    {
        cout << " > C'est au tour de : [ " << getJoueur2()->getNom() << " ] de jouer ..." << endl;
        Commandes(m_j2);
    }
}

void Jeu::InterfaceJoueur()
{
    int lig = 4;
    int col = 1;
    string labels[4] = {"Nom: ", "Couleur: ", "Or: ", "Nb de Chateau: "};
    string inputsj1[4] = {m_j1->getNom(),
                          (m_j1->getCouleur() == 'R') ? ("Rouge") : ("Bleu"),
                          to_string(m_j1->getOr()),
                          to_string(m_j1->getNbChateau())};

    string inputsj2[4] = {m_j2->getNom(),
                          (m_j2->getCouleur() == 'R') ? ("Rouge") : ("Bleu"),
                          to_string(m_j2->getOr()),
                          to_string(m_j2->getNbChateau())};

    cout << "+" << setfill('-') << setw(17) << "+" << setw(9) << "+" << setw(8) << "+" << setw(17) << "+" << setw(9) << "+" << endl;
    cout << "|" << setfill(' ') << setw(38) << "Interface Joueurs" << setw(22) << "|" << endl;
    cout << "+" << setfill('-') << setw(17) << "+" << setw(9) << "+" << setw(8) << "+" << setw(17) << "+" << setw(9) << "+" << endl;
    for (int i = 0; i < lig; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "|" << setfill(' ') << setw(16) << left << labels[i] << "|" << setw(8) << internal << inputsj1[i] << "|";
            cout << setfill(' ') << setw(8);
            cout << "|" << setfill(' ') << setw(16) << left << labels[i] << "|" << setw(8) << internal << inputsj2[i] << "|" << endl;
        }
    }
    cout << "+" << setfill('-') << setw(17) << "+" << setw(9) << "+" << setw(8) << "+" << setw(17) << "+" << setw(9) << "+" << endl;
    cout << endl;
}

int Jeu::Commandes(Joueur *j)
{
    int num;
    cout << endl;
    cout << "# Liste des commandes:" << endl;
    cout << "____________________" << endl;
    cout << "   1-Sélectionner un pion" << endl;
    cout << "   2- " << endl;
    cout << "   3-Passer son tour" << endl;

    cout << "Sélectionner une commande :" << endl;
    cin >> num ;
    return num;

}

void Jeu::afficheMenuSelection()
{
    if (m_tourJ1)
    {
        cout << "Vous possédez " << vecCasesJoueur1.size() << " pions." << endl;
        for (int i = 0 ; i < (int)vecCasesJoueur1.size(); i++)
        {
            cout <<  (i + 1)  
                 << "- Pion: "
                 << vecCasesJoueur1[i]->getPion()->affichetype()
                 << " " << vecCasesJoueur1[i]->getPion()->getRef()
                 << "(" << enumToChar(vecCasesJoueur1[i]->getX()) << ", " << vecCasesJoueur1[i]->getY() << ")" << endl;
        }
    }
    else
    {
        cout << "Vous possédez " << vecCasesJoueur2.size() << " pions." << endl;
        for (int i = 0 ; i < (int)vecCasesJoueur2.size(); i++)
        {
            cout << "- Pion: "
                 << vecCasesJoueur2[i]->getPion()->affichetype()
                 << " " << vecCasesJoueur2[i]->getPion()->getRef()
                 << "(" << vecCasesJoueur2[i]->getX() << ", " << vecCasesJoueur2[i]->getY() << ")" << endl;
        }
    }
}

Case *Jeu::selectionPion(int num) const
{
    if (m_tourJ1)
        return vecCasesJoueur1[num];
    else
        return vecCasesJoueur2[num];
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