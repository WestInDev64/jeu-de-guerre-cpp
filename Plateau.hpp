#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <iostream>
#include <array>
#include "Case.hpp"

using namespace std;

class Plateau
{
private:
    std::array<Case,20*20> m_plateau;

public:
    Plateau();
    void affiche();
};

Plateau::Plateau(){
}

void Plateau::affiche(){
    /* for(Case c : m_plateau ){
        cout << c.getEtat() << endl; 
    } */
    cout << endl;
    cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = " << endl;
    for(int i = 0 ; i < 20 ; i++){
        for(int j = 0 ; j < 20 ; j++){
            cout <<  m_plateau[i].getEtat() << ", "; 
        }
        cout << endl;
    }
    cout << endl;
}

#endif //PLATEAU_HPP