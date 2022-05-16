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



#endif //CASE_HPPPP