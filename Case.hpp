#ifndef CASE_HPP
#define CASE_HPP

#include "Pion.hpp"
class Case
{
private:
    /**
     * TODO: getPosition() retourne un (x,y) du plateau
     */ 
    Pion *m_pion;
    int posx;
    int posy;

public:
    Case();
    Case(int x, int y);
    void setPion( Pion * p);

    /* Accesseurs */
    Pion* getPion() const;
    int getX() const;
    int getY() const;
    //void setCase(/* int etat, */ Pion *P);
};

Case::Case()
{
    m_pion = new Pion();
}

Case::Case(int x, int y)
{
    m_pion = new Pion();
    posx = x;
    posy = y;
}

/********************************************************
 *                      Accesseurs                      *
 ********************************************************/ 

Pion* Case::getPion() const{
    return m_pion;
}
int Case::getX() const {
    return posx;
}
int Case::getY() const {
    return posy;
}



void Case::setPion(Pion * p){
    m_pion = p;
}

#endif //CASE_HPP