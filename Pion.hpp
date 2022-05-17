#ifndef PION_HPP
#define PION_HPP

#include <string>
#include "Joueur.hpp"

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
    bool m_action = false;

    /* positions */
    int m_posx;
    int m_posy;

    /* Référence nom du pion */
    string m_ref;

public:
    Pion(){
        m_ref = " ";
    };

    Pion(Joueur *j)
    {
        m_joueur = j;
        m_ref = " " + j->getCouleur() ;
    }

    virtual ~Pion()
    {
        delete this;
    }

    // virtual std::string affichePion() = 0;

    /********************************************************
     *                      Accesseurs                      *
     ********************************************************/
    string getRef() const { return m_ref; }

    int getPdv() { return m_pdv; }

    bool getAction() { return m_action; }

    int getPdm() { return m_pdm; }

    Joueur *getM_Joueur() { return m_joueur; }

    int getCout() { return m_cout; }

    void setPdv(int pdv)
    {
        m_pdv = pdv;
    }
    virtual string affichetype()
    {
        return "Pion";
    }

    virtual void afficheActions(){}

    virtual void selectActions(){}
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

    int getX() const{
        return m_posx;
    }

    int getY() const{
        return m_posy;
    }

};

class PionVide : public Pion
{

public:
    PionVide()
    {
        m_ref = " + ";
    }
    string affichetype()
    {
        return "Pion vide";
    }
};

class Guerrier : public Pion
{
private:
    /* Pour que le Guerrier puisse se déplacer puis attaquer */
    bool m_seDeplace = false;

public:
    Guerrier(Joueur *j) : Pion(j)
    {
        m_pow = 5;
        m_pdv = 10;
        m_pdm = 3;
        m_prod = 0;
        m_cout = 10;
        m_ref = "G" + j->getCouleur();
        m_joueur = j;
    }

    void attaque(Pion *p)
    {
        p->setPdv(p->getPdv() - this->m_pow);
    }

    string affichetype()
    {
        return "Guerrier";
    }

    bool getSeDeplace()
    {
        return m_seDeplace;
    }

    void s_estDeplacer()
    {
        m_seDeplace = true;
    }
    /*   static int getCout()
      {
          return m_cout;
      } */
};

class Seigneur : public Pion
{
private:
    bool m_seDeplace = false;

public:
    Seigneur(Joueur *j) : Pion(j)
    {
        m_pow = 3;
        m_pdv = 5;
        m_pdm = 1;
        m_prod = 0;
        m_cout = 10;
        m_ref = "S" + j->getCouleur();
        m_joueur = j;
    }

    /* Un Seigneur peut se Transformer si le joueur à assez d'or */
    bool peutSeTransformer(Joueur *j)
    {
        if (j->getOr() >= 15)
        {
            return true;
        }
        return false;
    }

    void attaque(Pion *p)
    {
        p->setPdv(p->getPdv() - this->m_pow);
    }

    bool getSeDeplace()
    {
        return m_seDeplace;
    }

    void s_estDeplacer()
    {
        m_seDeplace = true;
    }

    string affichetype()
    {
        return "Seigneur";
    }

};


#endif // PION_HPP
