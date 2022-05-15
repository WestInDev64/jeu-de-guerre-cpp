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

protected:
    int m_puissance;
    int m_pdv;
    int m_pdm;
    int m_cout;
    int m_prod;
    int m_posx;
    int m_posy;
    /**
     * TODO:
     *
     */
    char m_ref[2];
    Joueur *m_joueur;
};

const char *Pion::getRef() const
{
    return m_ref;
}

class Guerrier : public Pion
{
public:
    Guerrier(Joueur *j);
    // std::string affichePion();
    void attaque(Pion *p)
    {
        p->setPdv(p->getPdv() - this->m_puissance);
    }
};

Guerrier::Guerrier(Joueur *j) : Pion(j)
{
    m_puissance = 5;
    m_pdv = 10;
    m_pdm = 3;
    m_prod = 0;
    m_cout = 10;
    m_ref[0] = 'G';
    m_ref[1] = j->getCouleur();
    m_joueur = j;
}

class Seigneur : public Pion
{
public:
    Seigneur(Joueur *j) : Pion(j)
    {
        m_puissance = 3;
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
        p->setPdv(p->getPdv() - this->m_puissance);
    }
    // void transformeEnChateau();
    // std::string affichePion();
};

class Chateau : public Pion
{

private:
    bool m_action = false;

public:
    Chateau(Joueur *j) : Pion(j)
    {
        m_puissance = 0;
        m_pdv = 20;
        m_pdm = 0;
        m_prod = 2;
        m_cout = 15;
        m_ref[0] = 'C';
        m_ref[1] = j->getCouleur();
        m_joueur = j;
    }
    //~Chateau();
    // std::string affichePion();
    void produireOr(Joueur *j)
    {
        j->setOr(Chateau::m_prod);
    }
    Pion *construirePion(char c);
    bool getAction()
    {
        return m_action;
    }
};

Pion *Chateau::construirePion(char c)
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

class Paysan : public Pion
{
public:
    Paysan(Joueur *j) : Pion(j)
    {
        m_puissance = 0;
        m_pdv = 1;
        m_pdm = 2;
        m_prod = 5;
        m_cout = 20;
        m_ref[0] = 'P';
        m_ref[1] = j->getCouleur();
        m_joueur = j;
    }
    void produireOr(Joueur *j);
};

void Paysan::produireOr(Joueur *j)
{
    j->setOr(Paysan::m_prod);
}

#endif // PION_HPP
