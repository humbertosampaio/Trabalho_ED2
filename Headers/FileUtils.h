//
// Created by edson on 28/03/18.
//

#ifndef TRABALHO_ED2_FILEUTILS_H
#define TRABALHO_ED2_FILEUTILS_H

#include <iostream>
#include <fstream>
#include <exception>
#include <vector>
#include <ctime>
#include "Question.h"
#include "Tag.h"
#include "Answer.h"

using namespace std;

class FileUtils {
private:
   // static clock_t tStart;
public:
    static void readFileQuestion(string path, vector<Question> &questionList);
    static void readFileTag (string path, vector<Tag> &tagList);
    static void readFileAnswer(string path, vector<Answer> &answerList);
    //static void timeStart();
    //static double timeEnd();
};

class runtime_error : public exception{
public:
    explicit runtime_error (const string& what_arg){};
};



#endif //TRABALHO_ED2_FILEUTILS_H
