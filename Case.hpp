#ifndef CASE_HPP
#define CASE_HPP

class Case
{
private:
    int m_etat;
    //Pion *m_pion;

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
}

int Case::getEtat()
{
    return m_etat;
}

#endif //CASE_HPP