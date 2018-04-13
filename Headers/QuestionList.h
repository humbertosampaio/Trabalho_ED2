//
// Created by edson on 13/04/18.
//

#ifndef TRABALHO_ED2_QUESTIONLIST_H
#define TRABALHO_ED2_QUESTIONLIST_H

#include <iostream>
#include <vector>
#include "Question.h"
#include "FileUtils.h"

#define TAM 606709

using namespace std;

class QuestionList
{
public:
    QuestionList(string path);
private:
    vector<Question> questionList;
};


#endif //TRABALHO_ED2_QUESTIONLIST_H
