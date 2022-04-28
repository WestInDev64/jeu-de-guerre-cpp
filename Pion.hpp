#ifndef PION_HPP
#define PION_HPP

#include <string>
#include "Joueur.hpp"
class Pion
{
public:
    Pion(const Joueur& j);
    //~Pion();
    //int getPuissance();
    //int getPdv();
    //int getPdm();
    //int getCout();
    //int getProd();
    virtual std::string affichePion() = 0;

protected:
    int m_puissance;
    int m_pdv;
    int m_pdm;
    int m_cout;
    int m_prod;
    const Joueur & m_joueur;
};

class Guerrier : public Pion
{
public:
    Guerrier(const Joueur& j);
    //~Guerrier();
    std::string affichePion();
};

class Seigneur : public Pion
{
public:
    Seigneur(const Joueur& j);
    //~Seigneur();
    std::string affichePion();
};

class Chateau : public Pion
{
public:
    Chateau(const Joueur& j);
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
    Paysan(const Joueur& j);
    //~Paysan();
    std::string affichePion();
};

#endif // PION_HPP
