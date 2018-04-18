//
// Created by edson on 31/03/18.
//

#include "../Headers/Answer.h"
#include <string>

Answer::Answer(string *answer)
{
    this->answerId = stoi(answer[0], nullptr, 10);
    this->userId = (answer[1] != "NA" ? stoi(answer[1], nullptr, 10) : -1);
    this->date = answer[2];
    this->questionId = stoi(answer[3], nullptr, 10);
    this->questionId = stoi(answer[4], nullptr, 10);
}