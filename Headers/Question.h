//
// Created by edson on 31/03/18.
//

#ifndef TRABALHO_ED2_QUESTION_H
#define TRABALHO_ED2_QUESTION_H

#include <iostream>

using namespace std;

class Question {
private:
    int questionId;
    int userId;
    int score;
    string date;
    string title;
public:
    Question(string* question);
    ~Question();
    void printComponents ();
};


#endif //TRABALHO_ED2_QUESTION_H
