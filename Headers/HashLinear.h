//
// Created by edson on 13/04/18.
//

#ifndef TRABALHO_ED2_LINEARHASH_H
#define TRABALHO_ED2_LINEARHASH_H

#include <iostream>
#include "Hash.h"

using namespace std;

class HashLinear : public Hash{

public:
    HashLinear(unsigned int size, bool quadratic):Hash(size, quadratic)
    {
        elementCounter = 0;
        this->quadratic = quadratic;
        //4 do contador de elementos
        extraMemory += 4;
    };
    //metodos
    void insert (unsigned int value)override ;
    void find (unsigned int value)override ;

private:
    int elementCounter;
    //true para sondagem quadratica e false para sondagem linear
    bool quadratic;
    //funcoes auxiliares
    void insertLinear(int value);
    void insertQuadratic(int value);
    void findLinear (int value);
    void findQuadratic (int value);

};


#endif //TRABALHO_ED2_LINEARHASH_H
