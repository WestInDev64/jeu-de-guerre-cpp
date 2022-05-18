#ifndef PION_HPP
#define PION_HPP

#include <string>
#include "Joueur.hpp"
#include <iostream>


using namespace std;

class Pion
{
protected:
    /*Référence Joueur appartenant au pion  */
    Joueur *m_joueur;

    /* Compétences des Pions */
    int m_pow;
    int m_pdv;
    int m_pdm;
    int m_cout;
    int m_prod;

    /* 1 action par Pion (sauf pour le Guerrier qui peut se déplacer puis attaquer) */
    bool m_action = true;

    /* positions */
    int m_posx;
    int m_posy;

    /* Référence nom du pion */
    string m_ref;

public:
    Pion(int x, int y)
    {
        m_joueur = nullptr;
        m_ref = " ";
        m_posx = x;
        m_posy = y;
    };

    Pion(Joueur *j, int x, int y)
    {
        m_joueur = j;
        m_ref = " " + j->getCouleur();
        m_posx = x;
        m_posy = y;
    }

    virtual ~Pion()
    {
        delete this;
    }

    bool pionEstMort()
    {
        if (this->m_pdv < 1)
        {
            cout << "*Slurp* pion détruit !" << endl;
            return true;
        }
        return false;
    }

    

    // virtual std::string affichePion() = 0;

    /********************************************************
     *                      Accesseurs                      *
     ********************************************************/
    Joueur *getM_Joueur() { return m_joueur; }

    string getRef() const { return m_ref; }

    int getPdv() { return m_pdv; }

    bool getAction() { return m_action; }

    int getPdm() { return m_pdm; }

    int getCout() const { return m_cout; }

    int getProd() const { return m_prod; }

    int getX() const { return m_posx; }

    int getY() const { return m_posy; }

    int getPow() const { return m_pow; }

    /********************************************************
     *                      Mutateurs                       *
     ********************************************************/

    void setPdv(int pdv)
    {
        m_pdv = pdv;
    }
    virtual string affichetype()
    {
        return "Pion";
    }

    virtual void afficheActions() {}

    virtual void selectActions() {}

    bool peutRecruter(int price)
    {
        if (m_joueur->getOr() >= price)
        {
            return true;
        }
        return false;
    }

    // void mvtPossible(vector<Case *> &vecCases){}
    /**
     * Peut servir dans le cas ou un chateau recrute un Pion,
     * Et que ce Pion qui vient d'être créer ne pourra faire ses actions que le prochain tour
     *
     * Exemple, un Chateau recrute un Paysan,
     *  ce paysan ne pourra se deplacer ou récolter que le prochain tour
     *
     */
    void setAction(bool a)
    {
        m_action = a;
    }

    void setPdm(int m)
    {
        m_pdm = m;
    }

    void reinitAction()
    {
        m_action = false;
    }
};

class PionVide : public Pion
{

public:
    PionVide(int x, int y) : Pion(x, y)
    {   
        m_joueur = nullptr;
        m_ref = " + ";
    }
    string affichetype()
    {
        return "Pion vide";
    }
};



#endif // PION_HPP
