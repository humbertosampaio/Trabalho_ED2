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
public:
    static vector<Question*>* readFileQuestion(string path);
    static vector<Tag*>* readFileTag (string path);
    static vector<Answer*>* readFileAnswer(string path);
};

class runtime_error : public exception{
public:
    explicit runtime_error (const string& what_arg){};
};

#endif //TRABALHO_ED2_FILEUTILS_H
