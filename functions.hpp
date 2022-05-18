#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <vector>
#include "Case.hpp"

enum Alphabet
{
    A,B,C,D,E,F,G,H,I,J,K,L,M,
    N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
};

char enumToChar(int abc);
int choixMenu();

int choixCase(vector<Case *> vecCases);


#endif //FUNCTIONS_HPP