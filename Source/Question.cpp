//
// Created by edson on 31/03/18.
//

#include "../Headers/Question.h"

Question::Question(string *question)
{
    this->questionId = stoi(question[0], nullptr, 10);
    this->userId = (question[1] != "NA" ? stoi(question[1], nullptr, 10) : -1);
    this->score = stoi(question[3], nullptr, 10);
    this->date = question[2];
    this->title = question[4];
}

Question::~Question()
{

}

void Question::printComponents()
{
    cout << "questionId: " << questionId << endl;
    cout << "userId: " << userId << endl;
    cout << "date: " << date << endl;
    cout << "score: " << score << endl;
    cout << "title: " << title << endl;
}

int Question::getQuestionId() const {
    return questionId;
}

