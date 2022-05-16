#ifndef JEU_HPP
#define JEU_HPP

#include "Plateau.hpp"
#include "Joueur.hpp"
#include <string>
#include <vector>

using namespace std;

int choixMenu()
{
    int choix;
    cin >> choix;
    return choix;
}

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
    m_tourJ1 = 1;
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
    etatTourPhase1 = 1;
    do
    {
        this->getPlateau()->affiche();
        InterfaceJoueur();
        switch (m_tourJ1)
        {
        case 1:
            cout << " > C'est au tour de : [ " << getJoueur1()->getNom() << " ] de jouer ..." << endl;
            selectionMenu(vecCasesJoueur1);
            m_tourJ1 = 0;
            break;
        case 0:
            cout << " > C'est au tour de : [ " << getJoueur2()->getNom() << " ] de jouer ..." << endl;
            selectionMenu(vecCasesJoueur2);
            m_tourJ1 = 1;
            break;
        default:
            break;
        }
    } while (etatTourPhase1);
}

/**
 * Interface des 2 joueurs à chaque display
 * Juste la quantite d'or et de chateau
 *
 * non le joueur voit en fonction de lui ses actions
 */
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

/**
 * TODO: Voir pour utiliser map pour menu
 *
 */
void Jeu::afficheSelectionPion(vector<Case *> vecCases)
{
    cout << "Vous possédez " << vecCases.size() << " pions." << endl;
    for (int i = 0; i < (int)vecCases.size(); i++)
    {
        cout << (i + 1)
             << " - Pion: "
             << vecCases[i]->getPion()->affichetype()
             << " " << vecCases[i]->getPion()->getRef()
             << "(" << enumToChar(vecCases[i]->getX()) << ", " << vecCases[i]->getY() << ")" << endl;
    }
    cout << ((int)vecCases.size() + 1)
         << " - Retour au menu précédent" << endl;
}

void Jeu::afficheMenuTour()
{
    cout << "# Menu Principal :" << endl;
    cout << "   1 - Sélectionner un pion" << endl;
    cout << "   2 - Finir son tour" << endl;
    cout << "   3 - Pause" << endl;
    cout << "   4 - Quitter la partie" << endl;
}

void Jeu::selectionMenu(vector<Case *> vecCases)
{
    int choix = 0;
    do
    {
        cout << endl;
        afficheMenuTour();
        cout << endl;
        cout << "Sélectionner un menu: ";
        choix = choixMenu();
        cin.clear();
        switch (choix)
        {
        case 1:
            choixPion(vecCases);
            break;
        case 2:
            /**
             * TODO: A faire..
             */
            cout << "Finir son tour" << endl;
            
            break;
        case 3:
            cout << "Pause";
            break;
        case 4:
            cout << endl;
            cout << "Vous quittez la partie !" << endl;
            exit(1);
            break;
        default:
            break;
        }
    } while ((choix != 4) && (choix != 2));
}

void Jeu::choixPion(vector<Case *> vecCases)
{
    int choix = 0;

    afficheSelectionPion(vecCases);
    choix = choixMenu() - 1;
    cin.clear();
    if (choix == (int)vecCases.size())
        selectionMenu(vecCases);
    else
        selectionPion(choix, vecCases);
    return;
}

/* Fonctions tests */
Case *Jeu::selectionPion(int num, vector<Case *> vecCases) const
{
    if (num > (int)vecCases.size() && (int)vecCases.size() == 0)
        exit(1);
    return vecCases[num];
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