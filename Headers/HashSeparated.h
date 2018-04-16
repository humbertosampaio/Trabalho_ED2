//
// Created by edson on 13/04/18.
//

#ifndef TRABALHO_ED2_HASHING_H
#define TRABALHO_ED2_HASHING_H

#include <iostream>
#include <vector>
#include "Hash.h"

using namespace std;

class HashSeparated : public Hash{
public:
    //construtor e destrutor
    HashSeparated(unsigned int size):Hash(size)
    {
        collisionTable = new Vertex[size];
        //2*4*size para os ponteiros e variaveis de armazenamento de vertex, + 4 do ponteiro para
        //o inicio da lista
        extraMemory = 2*(4*size) + 4;
    };
    ~HashSeparated();

    //metodos
    void insert (unsigned int value);
    void find (unsigned int value);
    void printElements();
    void churos();

    //classe auxiliar para a lista de colisoes
    class Vertex
    {
    public:
        Vertex() {value = 0; next = nullptr;};
        Vertex(int value, Vertex* next)
        {
            this->value = value;
            this->next = next;
        };
        int value;
        Vertex* next;
    };
private:
    Vertex* collisionTable;
};

#endif //TRABALHO_ED2_HASHING_H
