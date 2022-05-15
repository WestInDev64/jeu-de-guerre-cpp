#ifndef CASE_HPP
#define CASE_HPP

#include "Pion.hpp"
class Case
{
private:
    /**
     * 
     * 
     * TODO: getPosition() retourne un (x,y) du plateau
     */ 
    Pion *m_pion;

public:
    Case();
    Pion* getPion();
    void setPion( Pion * p);
    //Case(Pion *p);
    //void setCase(/* int etat, */ Pion *P);
    //Pion* getCase();
};

Case::Case()
{
    m_pion = new Pion();
}

Pion* Case::getPion(){
    return m_pion;
}

void Case::setPion(Pion * p){
    m_pion = p;
}

#endif //CASE_HPP