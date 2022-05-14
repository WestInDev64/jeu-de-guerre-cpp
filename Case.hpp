#ifndef CASE_HPP
#define CASE_HPP

#include "Pion.hpp"
class Case
{
private:
    int m_etat;
    Pion *m_pion;

public:
    int getEtat();
    Case();
    //Case(Pion *p);
    //void setCase(/* int etat, */ Pion *P);
    //Pion* getCase();
};

Case::Case()
{
    m_etat = 0;
    m_pion = nullptr;
}

int Case::getEtat()
{
    return m_etat;
}

#endif //CASE_HPP