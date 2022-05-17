#include "Jeu.hpp"
#include <limits>

using namespace std;

Jeu::Jeu()
{
}

void Jeu::Init()
{
    string c1 = "-", c2 = "-";
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
        if (c1 != "R" && c1 != "B")
            cout << "Erreur lors du choix de la couleur !" << endl;
    } while (c1 != "R" && c1 != "B");

    /* Init Joueur 2 */
    do
    {
        cout << "Joueur2 veuillez entrer votre nom: ";
        cin >> name2;
        if (name2 == "")
            cout << "Erreur, veuillez entrer un nom valide." << endl;
    } while (name2 == "");

    c1 == "R" ? c2 = "B" : c2 = "R";

    /* Affichage couleur du 2eme joueur */
    c2 == "R" ? cout << name2 << " sera donc le joueur Rouge" << endl : cout << name2 << " sera donc le joueur Bleu" << endl;

    /* Fin de fonction  */
    /* Allocations Joueurs */
    m_j1 = new Joueur(name1, c1);
    m_j2 = new Joueur(name2, c2);

    /* Attribution du tour */
    m_nb_tour = 0;
    m_tourJ = 0;
}

/**
 * TODO: Ajouter paramètres a l'init plateau nb_lig / nb_col
 * calculer l'emplacement de départ chateau + paysan automatiquement
 */
void Jeu::initPlateau()
{
    m_plateau = new Plateau(10, 10);

    Pion *chatj1 = new Chateau(m_j1,1,1);
    Pion *payj1 = new Paysan(m_j1,1,2);
    setCase(chatj1, 1, 1);
    setCase(payj1, 1, 2);
    vecCasesJoueur1.push_back(m_plateau->getTabCase()[1][1]);
    vecCasesJoueur1.push_back(m_plateau->getTabCase()[1][2]);
    m_j1->setNbChateau();

    Pion *chatj2 = new Chateau(m_j2,8,8);
    Pion *payj2 = new Paysan(m_j2,8,7);
    setCase(chatj2, 8, 8);
    setCase(payj2, 8, 7);
    vecCasesJoueur2.push_back(m_plateau->getTabCase()[8][8]);
    vecCasesJoueur2.push_back(m_plateau->getTabCase()[8][7]);
    m_j2->setNbChateau();
}

void Jeu::Start()
{
    etatTourPhase2 = 1;
    do
    {
        setNbTour();
        switch (m_tourJ)
        {
        case 0:
            //!1 - Taxe chateaux
            if (!etatTourPhase1)
                m_j1->taxeDesChateaux();
            //! Affichage Plateau + Interface
            this->getPlateau()->affiche();
            InterfaceJoueur();

            //! Affiche Menu Principal
            afficheMenuTour();

            //! Sélectionne Menu Tour
            selectionMenu(vecCasesJoueur1);
            m_tourJ = 1;
            break;
        case 1:
            if (!etatTourPhase1)
                m_j2->taxeDesChateaux();
            this->getPlateau()->affiche();
            InterfaceJoueur();
            selectionMenu(vecCasesJoueur2);
            m_tourJ = 0;

            etatTourPhase1 = 0;
            break;
        default:
            break;
        }
    } while (etatTourPhase2);
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
                          (m_j1->getCouleur() == "R") ? ("Rouge") : ("Bleu"),
                          to_string(m_j1->getOr()),
                          to_string(m_j1->getNbChateau())};

    string inputsj2[4] = {m_j2->getNom(),
                          (m_j2->getCouleur() == "R") ? ("Rouge") : ("Bleu"),
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

    cout << "TOUR N°: " << m_nb_tour << endl << endl;
    if(m_tourJ == 0)
        cout << " > C'est au tour de : [ " << getJoueur1()->getNom() << " ] de jouer ..." << endl;
    else
        cout << " > C'est au tour de : [ " << getJoueur2()->getNom() << " ] de jouer ..." << endl;
}

/**
 * TODO: Voir pour utiliser map pour menu
 *
 */
void Jeu::affichePion(vector<Case *> &vecCases)
{
    cout << "Vous possédez " << vecCases.size() << " pions:" << endl;
    for (int i = 0; i < (int)vecCases.size(); i++)
    {
        cout << "   "
             << (i + 1)
             << " - Pion: "
             << vecCases[i]->getPion()->affichetype()
             << " " << vecCases[i]->getPion()->getRef()
             << "(" << enumToChar(vecCases[i]->getX()) << ", " << vecCases[i]->getY() << ")" << endl;
    }
    cout << "   "
         << ((int)vecCases.size() + 1)
         << " - Retour au menu précédent" << endl;
}

void Jeu::afficheMenuTour()
{
    cout << "# Menu Principal :" << endl;
    cout << "   1 - Sélectionner un pion" << endl;
    cout << "   2 - Finir son tour" << endl;
    cout << "   3 - Pause (OFF)" << endl;
    cout << "   4 - Sauvegarder (OFF)" << endl;
    cout << "   5 - Charger la partie (OFF)" << endl;
    cout << "   6 - Quitter la partie" << endl;
}



void Jeu::selectionMenu(vector<Case *> &vecCases)
{
    int choix = 0;
    do
    {
        cout << endl;

        cout << endl;
        cout << "Sélectionner un menu: ";
        choix = choixMenu();
        /* CLEAR BUFFER après mauvaises saisies  */
        cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choix)
        {
        case 1:
            /**
             * TODO: Faire un systeme d'affichage par pion ayant action true
             */
            selectPion(vecCases);
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
            break;
        case 5:
            break;
        case 6:
            cout << endl;
            cout << "Vous quittez la partie !" << endl;
            exit(1);
            break;
        default:
            break;
        }
    } while ((choix != 4) && (choix != 2));
}

void Jeu::selectPion(vector<Case *> &vecCases)
{
    int choix = 0;

    affichePion(vecCases);
    choix = choixMenu() - 1;
    cin.clear();

    /* Retour menu précédent */
    if (choix != (int)vecCases.size())
    {
        /**
         * 1 - Renvoi la case sélectionné
         * 2 - Affiche les actions
         * 3 - select Actions
         * 4 - 
         * 
         * 2 - Retourne un vecteur de cases adjacentes
         * 3 - Affiche les cases adjacentes dans le tableau
         * 4 - Affiche le tableau
         */
        Case * caseCourante  = selectionPion(choix, vecCases);
        caseCourante->getPion()->afficheActions();
        caseCourante->getPion()->selectActions();
        vecCasesAjacentes(caseCourante->getX(), caseCourante->getY(), vecCasesAdjacentes);
        this->getPlateau()->affiche();
    }
    return;
}

/* Fonctions tests */
Case *Jeu::selectionPion(int num, vector<Case *> vecCases) const
{
    if (num > (int)vecCases.size() && (int)vecCases.size() == 0)
        exit(1);
    return vecCases[num];
}

/**
 * Renvoi un Vecteur de cases adjacentes à la case sélectionnée
 */
void Jeu::vecCasesAjacentes(int x, int y, vector<Case *> &vec)
{
    int nb_col = m_plateau->getNbCol();
    int posCase = x * nb_col + y; // 11
    vec.clear();
    cout << "TEST DEBT " << endl;

    /**
     * TODO: Refaire les positions + affichage adjacents
     * TODO: push back dans vecteur adjacents aussi
     *
     */
    if (posCase / nb_col != 0) // <- si pas 1ere ligne
    {
        vec.push_back(m_plateau->getTabCase()[x - 1][y]);
        if (posCase % nb_col != 0) // <- si pas à la 1ere col
            vec.push_back(m_plateau->getTabCase()[x][y - 1]);
        if (posCase % nb_col != (nb_col - 1)) // < si pas a la der col
            vec.push_back(m_plateau->getTabCase()[x][y + 1]);
    }

    if (posCase / nb_col != (nb_col - 1)) // <- Si pas dernière ligne
    {
        vec.push_back(m_plateau->getTabCase()[x + 1][y]); //
        if (posCase % nb_col != 0)                        // <- si pas à la 1ere col
            vec.push_back(m_plateau->getTabCase()[x][y - 1]);
        if (posCase % nb_col != (nb_col - 1)) // < si pas a la der col
            vec.push_back(m_plateau->getTabCase()[x][y + 1]);
    }

    if (posCase % nb_col != 0) // <-si  pas à la 1ere colonne
    {
        vec.push_back(m_plateau->getTabCase()[x][y - 1]);
    }
    if (posCase % nb_col != (nb_col - 1)) // <- si pas dernière colonne
    {
        vec.push_back(m_plateau->getTabCase()[x][y + 1]);
    }
    /* Marquage des cases adjacentes vide */
    marqueCasesAdj(vec);
}

/* Transforme un Seigneur en Chateau */
void Jeu::transformerEnChateau(int x, int y)
{
    /* Recupere le pion en x, y */
    Pion *p = m_plateau->getTabCase()[x][y]->getPion();

    /* Création d'un chateau */
    Chateau *c = new Chateau(p->getM_Joueur(),x,y);

    /* Set le Chateau c dans la case x y */
    m_plateau->getTabCase()[x][y]->setPion(c);

    /* Pour dire que le chateau qui
    vient d'être construit ne peut
    pas faire d'action */
    c->setAction(true);

    /* delete p  */
    delete p;
}

void Jeu::marqueCasesAdj(vector<Case *> &vec)
{
    for (auto e : vec)
    {
        if (e->getPion()->getRef() == " " || e->getPion()->getRef() == " + ")
            e->setPion(new PionVide(e->getX(), e->getY()));
    }
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

int Jeu::getNbTour() const
{
    return m_nb_tour;
}

/********************************************************
 *                      Mutateurs                       *
 ********************************************************/
void Jeu::setCase(Pion *p, int x, int y)
{
    m_plateau->getTabCase()[x][y]->setPion(p);
}

void Jeu::setNbTour(){
    m_nb_tour += 1;
}
