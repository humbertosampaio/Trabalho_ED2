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
    void insert (unsigned int value)override ;
    void find (unsigned int value)override ;

HashDouble(unsigned int size):Hash(size, true){
    elementCounter = 0;
    //4 contador de elementos, 10% de size para o espaço extra
    extraMemory += 4 + 0.1*size*4;
    };
private:
    unsigned int elementCounter;
    unsigned int secondaryFunction (unsigned int value);
};


#endif //TRABALHO_ED2_DOUBLEHASH_H
