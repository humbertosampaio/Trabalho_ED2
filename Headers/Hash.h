//
// Created by edson on 13/04/18.
//

#ifndef TRABALHO_ED2_HASH_H
#define TRABALHO_ED2_HASH_H

#include <cmath>
#include <iostream>
using namespace std;

class Hash {
protected:
    unsigned int size;
    unsigned int collisionCounter;
    int* hashTable;

public:
    unsigned int keyFunction (unsigned int value);
    void printElements();
    Hash(unsigned int size);

    unsigned int getCollisionCounter() const;
    //virtual void insert(int value);
};


#endif //TRABALHO_ED2_HASH_H
