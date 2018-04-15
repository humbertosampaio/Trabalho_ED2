//
// Created by edson on 15/04/18.
//

#ifndef TRABALHO_ED2_DOUBLEHASH_H
#define TRABALHO_ED2_DOUBLEHASH_H

#include <iostream>
#include "Hash.h"

using namespace std;

class DoubleHash : public Hash{
public:
    void insert (int value);
DoubleHash(unsigned int size):Hash(size){
    elementCounter = 0;
    this->size = 1.1*size;
    };
private:
    unsigned int elementCounter;
    unsigned int secondaryFunction (unsigned int value);
};


#endif //TRABALHO_ED2_DOUBLEHASH_H
