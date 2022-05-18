#include "Jeu.hpp"
#include <limits>
#include <iostream>
#include <vector>

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
void Jeu::initPlateau(int x, int y)
{
    m_plateau = new Plateau(x, y);

    Pion *chatj1 = new Chateau(m_j1, 1, 1);
    Pion *payj1 = new Paysan(m_j1, 1, 2);
    setCase(chatj1, 1, 1);
    setCase(payj1, 1, 2);
    vecCasesJoueur1.push_back(m_plateau->getTabCase()[1][1]);
    vecCasesJoueur1.push_back(m_plateau->getTabCase()[1][2]);
    m_j1->setNbChateau();

    Pion *chatj2 = new Chateau(m_j2, x - 2, y - 2);
    Pion *payj2 = new Paysan(m_j2, x - 2, y - 3);
    setCase(chatj2, x - 2, y - 2);
    setCase(payj2, x - 2, y - 3);
    vecCasesJoueur2.push_back(m_plateau->getTabCase()[x - 2][y - 2]);
    vecCasesJoueur2.push_back(m_plateau->getTabCase()[x - 2][y - 3]);
    m_j2->setNbChateau();
}

void Jeu::Start()
{
    etatTourPhase1 = 1; // sans taxe chateaux
    etatTourPhase2 = 1; // avec taxe chateaux
    do
    {
        setNbTour();
        switch (m_tourJ)
        {
        case 0:
            //  1 - Taxe chateaux
            if (!etatTourPhase1)
                m_j1->taxeDesChateaux();

            // Affichage Plateau + Interface
            this->getPlateau()->affiche();
            InterfaceJoueur();

            // Sélection Menu Joueur
            selectionMenu(vecCasesJoueur1);

            // Update actions des pions
            for (auto e : vecCasesJoueur1)
            {
                e->getPion()->setAction(true);
                e->getPion()->setDeplacer(true);
            }
            m_tourJ = 1;
            break;
        case 1:
            //  1 - Taxe chateaux
            if (!etatTourPhase1)
                m_j2->taxeDesChateaux();

            // Affichage Plateau + Interface
            this->getPlateau()->affiche();
            InterfaceJoueur();

            // Sélection Menu Joueur
            selectionMenu(vecCasesJoueur2);

            // Update actions des pions
            for (auto e : vecCasesJoueur2)
            {
                e->getPion()->setAction(true);
                e->getPion()->setDeplacer(true);
            }
            m_tourJ = 0;

            etatTourPhase1 = 0;
            break;
        default:
            break;
        }
    } while (etatTourPhase2);

    cout << "FIN DE PARTIE" << endl;
}

/**
 * Interface des 2 joueurs à chaque display
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

    cout << "TOUR N°: " << m_nb_tour << endl
         << endl;
    if (m_tourJ == 0)
        cout << " > C'est au tour de : [ " << getJoueur1()->getNom() << " ] de jouer ..." << endl;
    else
        cout << " > C'est au tour de : [ " << getJoueur2()->getNom() << " ] de jouer ..." << endl;
}

/**
 * TODO: Voir pour utiliser map pour menu
 * Conditions Pions Actions à TRUE
 */
void Jeu::affichePion(vector<Case *> &vecCases)
{
    cout << endl;
    cout << "Vous possédez " << vecCases.size() << " pions:" << endl;
    for (int i = 0; i < (int)vecCases.size(); i++)
    {
        if (vecCases[i]->getPion()->getAction() != false)
        {
            cout << "   "
                 << (i + 1)
                 << " (" << enumToChar(vecCases[i]->getX()) << ", " << vecCases[i]->getY() << ") <- "
                 << vecCases[i]->getPion()->affichetype();
            if (vecCases[i]->getPion()->getM_Joueur()->getCouleur() == "R")
                cout << " Rouge";
            if (vecCases[i]->getPion()->getM_Joueur()->getCouleur() == "B")
                cout << " Bleu";
            cout
                << " | PV["
                << vecCases[i]->getPion()->getPdv()
                << "] - PDM["
                << vecCases[i]->getPion()->getPdm()
                << "] - POW["
                << vecCases[i]->getPion()->getPow()
                << "]"
                << endl;
        }
    }
    cout << "   "
         << ((int)vecCases.size() + 1)
         << " - Retour au menu précédent" << endl;
}

void Jeu::afficheMenuTour()
{
    cout << endl;
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
        afficheMenuTour();
        cout << "Sélectionner un menu: ";
        choix = choixMenu();
        switch (choix)
        {
        case 1: // ! Sélectionner un Pion
            updateCasesActives(vecCases);
            /* Sélection des pions */
            selectPion(vecCasesActives);
            break;
        case 2:
            cout << "Votre tour est terminé " << endl;
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
    } while ((choix != 6) && (choix != 2));
}

void Jeu::selectPion(vector<Case *> &vecCases)
{

    int choix;
    affichePion(vecCases);
    choix = choixCase(vecCases);

    /* Si le choix n'est pas "Retour " */
    if (choix != (int)vecCases.size())
    {
        /* Case sélectionnée */
        Case *caseCourante = selectionPion(choix, vecCases);

        /* switch en fonction de la référence de pion */
        switch (caseCourante->getPion()->getRef()[0])
        {
        case 'C': // ! CHATEAU (FAIT)
            /*  affiche les actions du pion sélectionné*/
            caseCourante->getPion()->afficheActions();
            cout << "Selectionner une action: ";
            int choixC;
            choixC = choixMenu();
            /* Switch concernant le choix saisi */
            switchActionsChateau(choixC, caseCourante->getX(), caseCourante->getY());

            /* Aperçu */
            this->getPlateau()->affiche();
            InterfaceJoueur();
            break;
        case 'P': // ! PAYSAN (FAIT)
            /* Affiche menu Action du Paysan */
            caseCourante->getPion()->afficheActions();
            /* Recupère saisi joueur */
            cout << "Selectionner une action: ";
            int choixP;
            choixP = choixMenu();
            /* Switch concernant le choix saisi */
            switchActionsPaysan(choixP, caseCourante->getX(), caseCourante->getY());

            /* Aperçu */
            this->getPlateau()->affiche();
            InterfaceJoueur();
            break;
        case 'G': // ! GUERRIER (FAIT)
            /*  affiche les actions du pion sélectionné*/
            caseCourante->getPion()->afficheActions();
            cout << "Selectionner une action: ";
            /* Recupère saisi joueur */
            int choixG;
            choixG = choixMenu();
            /* Switch concernant le choix saisi */
            switchActionsGuerrier(choixG, caseCourante->getX(), caseCourante->getY());

            /* Aperçu */
            this->getPlateau()->affiche();
            InterfaceJoueur();
            break;
        case 'S': // ! SEIGNEUR (A FAIRE)
            /*  affiche les actions du pion sélectionné*/
            caseCourante->getPion()->afficheActions();
            cout << "Selectionner une action: ";
            /* Recupère saisi joueur */
            int choixS;
            choixS = choixMenu();
            switchActionsSeigneur(choixS, caseCourante->getX(), caseCourante->getY());

            /* Aperçu */
            this->getPlateau()->affiche();
            InterfaceJoueur();
            break;
        default:
            break;
        }
    }
    return;
}

void Jeu::switchActionsGuerrier(int choix, int x, int y)
{
    Case *caseDest;
    Case *caseCourante = m_plateau->getTabCase()[x][y];
    switch (choix)
    {
    case 1: // ! DEPLACEMENT GUERRIER
        /* Calcul des déplacements possible */
        vecCasesDeplacement3(x, y, vecCasesAdj, vecCasesMvts);

        /* Aperçu */
        this->getPlateau()->affiche();
        InterfaceJoueur();

        /* Affiche les cases de déplacements possibles du Paysan*/
        dynamic_cast<Guerrier *>(caseCourante->getPion())->dplPossible(vecCasesMvts);
        /* Choix de la case de destination */
        int choixG1;
        choixG1 = choixCase(vecCasesMvts);
        if (choixG1 >= (int)vecCasesMvts.size() || choixG1 == -1)
        {
            break;
        }

        /* Sélection des cases de mvts */
        caseDest = selectionCase(choixG1, vecCasesMvts);

        /* Set du pion dans la nouvelle case */
        caseDest->setPion(caseCourante->getPion());
        caseDest->getPion()->setDeplacer(false);

        cleanCasesMvt(vecCasesMvts);
        caseCourante->setPion(new Pion(caseCourante->getX(), caseCourante->getY()));
        /* Remplacer l'ancienne case par la nouvelle dans vecCasesJoueurs */
        updateCasesJoueurs(vecCasesJoueur1, m_j1);
        updateCasesJoueurs(vecCasesJoueur2, m_j2);
        return;
    case 2: // ! attaquer sur le plateau
        /* Calcul des cases d'attaques possibles */
        vecCasesAdjEnnemis(x, y, vecCasesAdj, vecCasesEnnemis);

        /* Aperçu */
        this->getPlateau()->affiche();
        InterfaceJoueur();

        dynamic_cast<Guerrier *>(caseCourante->getPion())->attaquePossible(vecCasesEnnemis);

        /* Choix de la case de destination */
        int choixG2;
        choixG2 = choixCase(vecCasesEnnemis);
        if (choixG2 >= (int)vecCasesMvts.size() || choixG2 == -1)
        {
            break;
        }
        /* Sélection des cases d'attaques */
        caseDest = selectionCase(choixG2, vecCasesEnnemis);

        dynamic_cast<Guerrier *>(caseCourante->getPion())->attaque(caseDest->getPion());

        if (caseDest->getPion()->pionEstMort())
        {
            caseDest->setPion(new Pion(caseDest->getX(), caseDest->getY()));
        }
        else
        {
            cout << caseDest->getPion()->affichetype()
                 << " "
                 << caseDest->getPion()->getM_Joueur()->getCouleur()
                 << " a pris "
                 << caseCourante->getPion()->getPow()
                 << " de dégats !" << endl;
        }

        caseCourante->getPion()->setAction(false);
        /* Remplacer l'ancienne case par la nouvelle dans vecCasesJoueurs */
        updateCasesJoueurs(vecCasesJoueur1, m_j1);
        updateCasesJoueurs(vecCasesJoueur2, m_j2);
        break;
    case 3:
        cout << "Retour " << endl;
        break;
    default:
        break;
    }
}

// ! SWITCH SEIGNEUR
void Jeu::switchActionsSeigneur(int choix, int x, int y)
{
    Case *caseDest = nullptr;
    Case *caseCourante = m_plateau->getTabCase()[x][y];
    switch (choix)
    {
    case 1: // ! DEPLACEMENT SEIGNEUR
        if (!caseCourante->getPion()->getDeplacer())
        {
            cout << "Ce Pion ne peut plus se déplacer" << endl;
            break;
        }
        /* Calcul des déplacements possible */
        vecCasesDeplacement5(x, y, vecCasesAdj, vecCasesMvts);

        /* Aperçu */
        this->getPlateau()->affiche();
        InterfaceJoueur();

        /* Affiche les cases de déplacements possibles du Seigneur*/
        dynamic_cast<Seigneur *>(caseCourante->getPion())->dplSPossible(vecCasesMvts);
        /* Choix de la case de destination */
        int choixS1;
        choixS1 = choixCase(vecCasesMvts);
        if (choixS1 >= (int)vecCasesMvts.size() || choixS1 == -1)
        {
            break;
        }

        /* Sélection des cases de mvts */
        caseDest = selectionCase(choixS1, vecCasesMvts);

        /* Set du pion dans la nouvelle case */
        caseDest->setPion(caseCourante->getPion());
        caseDest->getPion()->setDeplacer(false);

        cleanCasesMvt(vecCasesMvts);
        caseCourante->setPion(new Pion(caseCourante->getX(), caseCourante->getY()));
        /* Remplacer l'ancienne case par la nouvelle dans vecCasesJoueurs */
        updateCasesJoueurs(vecCasesJoueur1, m_j1);
        updateCasesJoueurs(vecCasesJoueur2, m_j2);
        break;
    case 2: // ! ATTAQUE SEIGNEUR
        /* Calcul des cases d'attaques possibles */
        vecCasesAdjEnnemis(x, y, vecCasesAdj, vecCasesEnnemis);

        if (vecCasesEnnemis.empty())
            break;

        /* Aperçu */
        this->getPlateau()->affiche();
        InterfaceJoueur();

        dynamic_cast<Seigneur *>(caseCourante->getPion())->attaquePossible(vecCasesEnnemis);

        /* Choix de la case de destination */
        int choixS2;
        choixS2 = choixCase(vecCasesEnnemis);
        if (choixS2 >= (int)vecCasesEnnemis.size() || choixS2 == -1)
        {
            break;
        }

        /* Sélection des cases d'attaques */
        caseDest = selectionCase(choixS2, vecCasesEnnemis);

        /* Attaque le Pion en paramètre */
        dynamic_cast<Seigneur *>(caseCourante->getPion())->attaque(caseDest->getPion());

        /* si le pion est mort */
        if (caseDest->getPion()->pionEstMort())
        {
            caseDest->setPion(new Pion(caseDest->getX(), caseDest->getY()));
            // cout << caseDest->getPion()->getM_Joueur()->getNom() << endl;
        }
        /* Si il n'est pas mort (message de dégats) */
        else
        {
            cout << caseDest->getPion()->affichetype()
                 << " "
                 << caseDest->getPion()->getM_Joueur()->getCouleur()
                 << " a pris "
                 << caseCourante->getPion()->getPow()
                 << " de dégats !" << endl;
        }

        /* Action du seigneur à false */
        caseCourante->getPion()->setAction(false);

        updateCasesJoueurs(vecCasesJoueur1, m_j1);
        updateCasesJoueurs(vecCasesJoueur2, m_j2);
        break;
    case 3: // ! Transformer en Chateau

        /* Aperçu */
        this->getPlateau()->affiche();
        InterfaceJoueur();

        if (caseCourante->getPion()->peutRecruter(15))
        {
            caseCourante->setPion(new Chateau(caseCourante->getPion()->getM_Joueur(), caseCourante->getX(), caseCourante->getY()));
            cout << caseCourante->getPion()->getM_Joueur()->getNom() << endl;
            caseCourante->getPion()->getM_Joueur()->setNbChateau();
            caseCourante->getPion()->setAction(false);
            caseCourante->getPion()->getM_Joueur()->enleverOr(caseCourante->getPion()->getCout());
            updateCasesJoueurs(vecCasesJoueur1, m_j1);
            updateCasesJoueurs(vecCasesJoueur2, m_j2);
        }
        else
        {
            cout << "Vous n'avez pas assez d'OR" << endl;
        }
        break;
    case 4:
        cout << "Retour " << endl;
        break;
    default:
        break;
    }
}

void Jeu::switchActionsPaysan(int choix, int x, int y)
{
    Case *caseDest;
    Case *caseCourante = m_plateau->getTabCase()[x][y];
    switch (choix)
    {
    case 1: // ! Se déplacer sur le plateau
        /* Calcul des déplacements possible */
        vecCasesDeplacement2(x, y, vecCasesAdj, vecCasesMvts);

        /* Aperçu */
        this->getPlateau()->affiche();
        InterfaceJoueur();

        /* Affiche les cases de déplacements possibles du Paysan*/
        dynamic_cast<Paysan *>(caseCourante->getPion())->mvtPossible(vecCasesMvts);
        /* Choix de la case de destination */
        int choixP2;
        choixP2 = choixCase(vecCasesMvts);
        if (choixP2 >= (int)vecCasesMvts.size() || choixP2 == -1)
        {
            break;
        }

        /* Sélection des cases de mvts */
        caseDest = selectionCase(choixP2, vecCasesMvts);

        /* Set du pion dans la nouvelle case */
        caseDest->setPion(caseCourante->getPion());
        caseDest->getPion()->setAction(false);

        cleanCasesMvt(vecCasesMvts);
        caseCourante->setPion(new Pion(caseCourante->getX(), caseCourante->getY()));
        /* Remplacer l'ancienne case par la nouvelle dans vecCasesJoueurs */
        updateCasesJoueurs(vecCasesJoueur1, m_j1);
        updateCasesJoueurs(vecCasesJoueur2, m_j2);
        break;
    case 2: // ! Amasser des Ressources
        /* Produire de l'or */
        dynamic_cast<Paysan *>(caseCourante->getPion())->produireOrS();
        caseCourante->getPion()->setAction(false);
        cout << "Votre paysan a récolté : " << caseCourante->getPion()->getProd() << " pièces d'Or" << endl;
        break;
    case 3:
        cout << "Retour " << endl;
        break;
    default:
        break;
    }
}

void Jeu::switchActionsChateau(int choix, int x, int y)
{
    Case *caseDest;
    Case *caseCourante = m_plateau->getTabCase()[x][y];
    switch (choix)
    {
    /* Choix recrutement */
    case 1: // ! RECRUTEMENT PION
        /* Calcul des emplacements possible */
        vecCasesDeplacement1(x, y, vecCasesAdj, vecCasesMvts);

        /* Aperçu */
        this->getPlateau()->affiche();
        InterfaceJoueur();

        /* Affiche la liste des empl disponibles */
        dynamic_cast<Chateau *>(caseCourante->getPion())->afficheEmplPossible(vecCasesMvts);

        /* Choix de l'emplacement de recrutement */
        int choixC3;
        choixC3 = choixCase(vecCasesMvts);
        if (choixC3 >= (int)vecCasesMvts.size() || choixC3 == -1)
        {
            break;
        }
        /* Sélection de la case et la retourne */
        caseDest = selectionCase(choixC3, vecCasesMvts);

        /* Affiche la liste des pions recrutables */
        dynamic_cast<Chateau *>(caseCourante->getPion())->afficheRecruter();
        /* Sélection du type de pion */
        cout << "Selectionner le recrutement: ";
        int choixC2;
        choixC2 = choixMenu();

        /* Switch de recrutement Pion (ajouter si d'autres joueurs) */
        switch (choixC2)
        {
        case 1: // ! Recrute un Seigneur
            if (caseCourante->getPion()->peutRecruter(10))
            {
                caseDest->setPion(new Seigneur(caseCourante->getPion()->getM_Joueur(), caseDest->getX(), caseDest->getY()));
                caseDest->getPion()->setAction(false);
                caseCourante->getPion()->setAction(false);
                caseCourante->getPion()->getM_Joueur()->enleverOr(caseDest->getPion()->getCout());
                updateCasesJoueurs(vecCasesJoueur1, m_j1);
                updateCasesJoueurs(vecCasesJoueur2, m_j2);
            }
            break;
        case 2: // ! Recrute un Guerrier
            if (caseCourante->getPion()->peutRecruter(10))
            {
                caseDest->setPion(new Guerrier(caseCourante->getPion()->getM_Joueur(), caseDest->getX(), caseDest->getY()));
                caseDest->getPion()->setAction(false);
                caseCourante->getPion()->setAction(false);
                caseCourante->getPion()->getM_Joueur()->enleverOr(caseDest->getPion()->getCout());
                updateCasesJoueurs(vecCasesJoueur1, m_j1);
                updateCasesJoueurs(vecCasesJoueur2, m_j2);
            }
            break;
        case 3: // ! Recrute un Paysan
            if (caseCourante->getPion()->peutRecruter(20))
            {
                caseDest->setPion(new Paysan(caseCourante->getPion()->getM_Joueur(), caseDest->getX(), caseDest->getY()));
                caseDest->getPion()->setAction(false);
                caseCourante->getPion()->setAction(false);
                caseCourante->getPion()->getM_Joueur()->enleverOr(caseDest->getPion()->getCout());
                updateCasesJoueurs(vecCasesJoueur1, m_j1);
                updateCasesJoueurs(vecCasesJoueur2, m_j2);
            }
            break;
        case 4: // ! Retour annule le recrutement
            cout << "Retour (Recrutement annulé) " << endl;
            break;
        default:
            cout << "Erreur saisie (Recrutement annulé) !" << endl;
            break;
        }
        /* Nettoyage du marquage  */
        cleanCasesMvt(vecCasesMvts);
        break;
    /* Choix ne rien faire */
    case 2:
        cout << "Ne fait rien !" << endl;
        caseCourante->getPion()->setAction(false);
        break;
    default:
        break;
    }
}

/* Fonctions tests */
Case *Jeu::selectionPion(int num, vector<Case *> vecCases) const
{
    if (num > (int)vecCases.size() && (int)vecCases.size() == 0)
        exit(1);
    return vecCases[num];
}

/* Fonctions tests */
Case *Jeu::selectionCase(int num, vector<Case *> vecCases)
{
    if (num > (int)vecCases.size() && (int)vecCases.size() == 0)
    {
        exit(1);
    }
    return vecCases[num];
}

/**
 * TODO: Mieux commenter
 * Renvoi un Vecteur de cases adjacentes à la case sélectionnée
 */
void Jeu::vecCasesAdjEnnemis(int x, int y, vector<Case *> &vec, vector<Case *> &vecEnnemis)
{
    int nb_col = m_plateau->getNbCol();
    int posCase = x * nb_col + y; // 11
    vec.clear();
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

    vecEnnemis.clear();
    for (auto e : vec)
    {
        if (e->getPion()->getRef() != " " && e->getPion()->getRef() != " + " && m_plateau->getTabCase()[x][y]->getPion()->getM_Joueur() != e->getPion()->getM_Joueur())
            vecEnnemis.push_back(e);
    }
}

/**
 * TODO: Mieux commenter
 * Renvoi un Vecteur de cases adjacentes à la case sélectionnée
 */
void Jeu::vecCasesAdjacentes(int x, int y, vector<Case *> &vec)
{
    int nb_col = m_plateau->getNbCol();
    int posCase = x * nb_col + y; // 11
    vec.clear();
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
    /* Marquage des cases adjacentes vide */
    marqueCasesAdj(vec);

    /* if (posCase % nb_col != 0) // <-si  pas à la 1ere colonne
    {
        vec.push_back(m_plateau->getTabCase()[x][y - 1]);
    }
    if (posCase % nb_col != (nb_col - 1)) // <- si pas dernière colonne
    {
        vec.push_back(m_plateau->getTabCase()[x][y + 1]);
    } */
}

/* Marquage déplacement */
void Jeu::marqueCasesAdj(vector<Case *> &vec)
{
    for (auto e : vec)
    {
        if (e->getPion()->getRef() == " " || e->getPion()->getRef() == " + ")
        {
            e->setPion(new PionVide(e->getX(), e->getY()));
        }
    }
}

/* Clean du plateau */
void Jeu::cleanCasesMvt(vector<Case *> &vec)
{
    for (auto e : vec)
    {
        if (e->getPion()->getRef() == " + ")
            e->setPion(new Pion(e->getX(), e->getY()));
    }
}

/* Actualise les cases de pions disponibles pour Actions */
void Jeu::updateCasesActives(vector<Case *> &vecCases)
{
    vecCasesActives.clear();
    for (auto e : vecCases)
        if (e->getPion()->getAction())
            vecCasesActives.push_back(e);
}

/* Actualise les cases de pions disponibles pour Actions */
void Jeu::updateCasesJoueurs(vector<Case *> &vecCases, Joueur *joueur)
{
    vecCases.clear();
    for (int i = 0; i < m_plateau->getNbCol(); i++)
    {
        for (int j = 0; j < m_plateau->getNbCol(); j++)
        {
            if (m_plateau->getTabCase()[i][j]->getPion()->getM_Joueur() == joueur)
            {
                vecCases.push_back(m_plateau->getTabCase()[i][j]);
            }
        }
    }
}

/**
 * TODO: A Commenter !!!
 * Déplacement Paysan
 */
void Jeu::vecCasesDeplacement1(int x, int y, vector<Case *> &vecADJ, vector<Case *> &vecDPL)
{
    vecDPL.clear();
    vecCasesAdjacentes(x, y, vecADJ);
    for (int i = 0; i < m_plateau->getNbCol(); i++)
    {
        for (int j = 0; j < m_plateau->getNbCol(); j++)
        {
            if (m_plateau->getTabCase()[i][j]->getPion()->getRef() == " + ")
            {
                vecDPL.push_back(m_plateau->getTabCase()[i][j]);
            }
        }
    }
}

/**
 * TODO: A Commenter !!!
 * Déplacement Paysan
 */
void Jeu::vecCasesDeplacement2(int x, int y, vector<Case *> &vecADJ, vector<Case *> &vecDPL)
{
    vecCasesDeplacement1(x, y, vecADJ, vecDPL);

    int size = vecDPL.size();

    for (int i = 0; i < size; i++)
    {
        vecCasesAdjacentes(vecDPL[i]->getX(), vecDPL[i]->getY(), vecADJ);
    }

    vecCasesDeplacement1(x, y, vecADJ, vecDPL);
}

/**
 * TODO: A Commenter !!!
 * Déplacement Paysan
 */
void Jeu::vecCasesDeplacement3(int x, int y, vector<Case *> &vecADJ, vector<Case *> &vecDPL)
{
    vecCasesDeplacement1(x, y, vecADJ, vecDPL);
    int size = vecDPL.size();
    for (int i = 0; i < size; i++)
    {
        vecCasesAdjacentes(vecDPL[i]->getX(), vecDPL[i]->getY(), vecADJ);
    }
    vecCasesDeplacement1(x, y, vecADJ, vecDPL);

    int size2 = vecDPL.size();

    for (int i = 0; i < size2; i++)
    {
        vecCasesAdjacentes(vecDPL[i]->getX(), vecDPL[i]->getY(), vecADJ);
    }
    vecCasesDeplacement1(x, y, vecADJ, vecDPL);
}

void Jeu::vecCasesDeplacement5(int x, int y, vector<Case *> &vecADJ, vector<Case *> &vecDPL)
{
    vecCasesDeplacement1(x, y, vecADJ, vecDPL);
    int size = vecDPL.size();
    for (int i = 0; i < size; i++)
    {
        vecCasesAdjacentes(vecDPL[i]->getX(), vecDPL[i]->getY(), vecADJ);
    }
    vecCasesDeplacement1(x, y, vecADJ, vecDPL);

    int size2 = vecDPL.size();

    for (int i = 0; i < size2; i++)
    {
        vecCasesAdjacentes(vecDPL[i]->getX(), vecDPL[i]->getY(), vecADJ);
    }
    vecCasesDeplacement1(x, y, vecADJ, vecDPL);

    int size3 = vecDPL.size();

    for (int i = 0; i < size3; i++)
    {
        vecCasesAdjacentes(vecDPL[i]->getX(), vecDPL[i]->getY(), vecADJ);
    }

    vecCasesDeplacement1(x, y, vecADJ, vecDPL);
    int size4 = vecDPL.size();

    for (int i = 0; i < size4; i++)
    {
        vecCasesAdjacentes(vecDPL[i]->getX(), vecDPL[i]->getY(), vecADJ);
    }

    vecCasesDeplacement1(x, y, vecADJ, vecDPL);
}

void Jeu::estGameOver()
{
    if (m_j1->getNbChateau() < 1)
    {
        cout << m_j2->getNom() << " vous avez détruit le dernier chateau de " << m_j1->getNom() << ". Vous avez gagné !" << endl;
    }
    else
    {
        if (m_j2->getNbChateau() < 1)
        {
            cout << m_j1->getNom() << " vous avez détruit le dernier chateau de " << m_j2->getNom() << ". Vous avez gagné !" << endl;
        }
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

void Jeu::setNbTour()
{
    m_nb_tour += 1;
}
