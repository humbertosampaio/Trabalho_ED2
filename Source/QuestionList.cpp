//
// Created by edson on 13/04/18.
//

#include "QuestionList.h"

QuestionList::QuestionList(string path)
{
    FileUtils::readFileQuestion(path, questionList);
}