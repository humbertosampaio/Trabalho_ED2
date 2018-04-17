//
// Created by edson on 31/03/18.
//

#ifndef TRABALHO_ED2_TAG_H
#define TRABALHO_ED2_TAG_H

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Tag {

private:
    unsigned int questionId;
    list<string> tagList;
public:
    Tag(unsigned int questionId, list<string> tagList);
    void printTags();
};


#endif //TRABALHO_ED2_TAG_H
