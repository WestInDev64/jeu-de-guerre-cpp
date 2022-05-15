#ifndef PION_HPP
#define PION_HPP

#include <string>
#include "Joueur.hpp"
class Pion
{
public:
    Pion(){};
    Pion(Joueur *j)
    {
        m_joueur = j;
    }
    // virtual std::string affichePion() = 0;
    const char *getRef() const;
    
    int getPdv()
    {
        return m_pdv;
    }

    void setPdv(int pdv)
    {
        m_pdv = pdv;
    }
    virtual string affichetype(){
        return "Pion";
    };

    bool getAction()
    {
        return m_action;
    }

    int getPdm()
    {
        return m_pdm;
    }

    void setPdm(int m)
    {
        m_pdm = m;
    }

    void reinitAction()
    {
        m_action = false;
    }

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
    char m_ref[2];
};

const char *Pion::getRef() const
{
    return m_ref;
}

class Guerrier : public Pion
{
private:
    bool seDeplace = false;

public:
    Guerrier(Joueur *j) : Pion(j)
    {
        m_pow = 5;
        m_pdv = 10;
        m_pdm = 3;
        m_prod = 0;
        m_cout = 10;
        m_ref[0] = 'G';
        m_ref[1] = j->getCouleur();
        m_joueur = j;
    }

    void attaque(Pion *p)
    {
        p->setPdv(p->getPdv() - this->m_pow);
    }

    string affichetype(){
        return "Guerrier";
    }
};

class Seigneur : public Pion
{
public:
    Seigneur(Joueur *j) : Pion(j)
    {
        m_pow = 3;
        m_pdv = 5;
        m_pdm = 1;
        m_prod = 0;
        m_cout = 10;
        m_ref[0] = 'S';
        m_ref[1] = j->getCouleur();
        m_joueur = j;
    }

    void attaque(Pion *p)
    {
        p->setPdv(p->getPdv() - this->m_pow);
    }

    string affichetype(){
        return "Seigneur";
    }

};

class Paysan : public Pion
{
public:
    Paysan(Joueur *j) : Pion(j)
    {
        m_pow = 0;
        m_pdv = 1;
        m_pdm = 2;
        m_prod = 5;
        m_cout = 20;
        m_ref[0] = 'P';
        m_ref[1] = j->getCouleur();
        m_joueur = j;
    }
    void produireOr(Joueur *j);

    string affichetype(){
        return "Paysan";
    }

};

void Paysan::produireOr(Joueur *j)
{
    j->setOr(Paysan::m_prod);
}

class Chateau : public Pion
{

private:
public:
    /* Méthodes */
    Chateau(Joueur *j) : Pion(j)
    {
        m_pow = 0;
        m_pdv = 20;
        m_pdm = 0;
        m_prod = 2;
        m_cout = 15;
        m_ref[0] = 'C';
        m_ref[1] = j->getCouleur();
        m_joueur = j;
    }

    void produireOr(Joueur *j)
    {
        j->setOr(Chateau::m_prod);
    }

    Pion *construirePion(char c)
    {
        Pion *p;
        switch (c)
        {
        case 'P':
            p = new Paysan(this->m_joueur);
            break;

        case 'S':
            p = new Seigneur(this->m_joueur);
            break;

        case 'G':
            p = new Guerrier(this->m_joueur);
            break;
        }
        m_action = true;
        return p;
    }

    string affichetype(){
        return "Chateau";
    }
};

#endif // PION_HPP
