#include "Case.hpp"

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