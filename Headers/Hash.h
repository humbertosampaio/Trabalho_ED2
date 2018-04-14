//
// Created by edson on 13/04/18.
//

#ifndef TRABALHO_ED2_HASH_H
#define TRABALHO_ED2_HASH_H


class Hash {
protected:
    unsigned int size;
    unsigned int collisionCounter;
    int* hashTable;

public:
    static unsigned int keyFunction (int value);
    Hash(unsigned int size);
    //virtual void insert(int value);
};


#endif //TRABALHO_ED2_HASH_H
