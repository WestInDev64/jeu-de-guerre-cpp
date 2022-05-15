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

protected:
    int m_puissance;
    int m_pdv;
    int m_pdm;
    int m_cout;
    int m_prod;
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
    /**
     */
    Guerrier(Joueur *j);
    std::string affichePion();
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
    Seigneur(Joueur *j)
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
    std::string affichePion();
};

class Chateau : public Pion
{
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
    std::string affichePion();
    /*   void ProduireOr();
      void RecruterSeigneur();
      void RecruterGuerrier();
      void RecruterPaysan();
      bool PeutRecruter();
      bool CaseDisponible(); // A voir si elle reste */
};

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
    std::string affichePion();
};

#endif // PION_HPP
