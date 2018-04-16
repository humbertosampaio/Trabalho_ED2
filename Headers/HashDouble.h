//
// Created by edson on 15/04/18.
//

#ifndef TRABALHO_ED2_DOUBLEHASH_H
#define TRABALHO_ED2_DOUBLEHASH_H

#include <iostream>
#include "Hash.h"

using namespace std;

class HashDouble : public Hash{
public:
    void insert (int value);

HashDouble(unsigned int size):Hash(size){
    elementCounter = 0;
    this->size = 1.1*size;
    extraMemory += 4 + 1.1*size*4;
    };
private:
    unsigned int elementCounter;
    unsigned int secondaryFunction (unsigned int value);
};


#endif //TRABALHO_ED2_DOUBLEHASH_H
