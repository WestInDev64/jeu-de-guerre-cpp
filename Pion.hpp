#ifndef PION_HPP
#define PION_HPP

#include <string>
#include "Joueur.hpp"

using namespace std;

class Pion
{
public:
    Pion(){};
    Pion(Joueur *j)
    {
        m_joueur = j;
    }
    // virtual std::string affichePion() = 0;
    const char *getRef() const
    {
        return m_ref;
    }

    int getPdv()
    {
        return m_pdv;
    }

    void setPdv(int pdv)
    {
        m_pdv = pdv;
    }
    virtual string affichetype()
    {
        return "Pion";
    }

    virtual void afficheActions(){
        
    }

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
        m_ref[0] = 'G';
        m_ref[1] = j->getCouleur();
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
        m_ref[0] = 'S';
        m_ref[1] = j->getCouleur();
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

class Paysan : public Pion
{
private:
    bool m_seDeplace = false;

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
    void produireOrS(Joueur *j)
    {
        j->setOr(m_prod);
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
        return "Paysan";
    }
};

#endif // PION_HPP
