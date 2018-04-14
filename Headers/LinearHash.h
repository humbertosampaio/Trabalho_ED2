//
// Created by edson on 13/04/18.
//

#ifndef TRABALHO_ED2_LINEARHASH_H
#define TRABALHO_ED2_LINEARHASH_H

#include <iostream>
#include "Hash.h"

using namespace std;

class LinearHash : public Hash{

public:
    LinearHash(unsigned int size):Hash(size)
    {
        elementCounter = 0;
    };
    //metodos
    void insert (int value);
    void printElements();

private:
    int elementCounter;
};


#endif //TRABALHO_ED2_LINEARHASH_H
