#include "Case.hpp"
#include <vector>
#include "Plateau.hpp"

Case::Case()
{
}

Case::Case(int x, int y)
{
    m_pion = new Pion(x,y);
    posx = x;
    posy = y;
}

Case::Case(int x, int y, Joueur *j)
{
    m_pion = new Pion(j,x,y);
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

