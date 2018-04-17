//
// Created by edson on 31/03/18.
//

#ifndef TRABALHO_ED2_ANSWER_H
#define TRABALHO_ED2_ANSWER_H

#include <iostream>

using namespace std;

class Answer {
private:
    int answerId;
    int userId;
    string date;
    unsigned int questionId;
    int score;
public:
    Answer(string* answer);
};


#endif //TRABALHO_ED2_ANSWER_H
