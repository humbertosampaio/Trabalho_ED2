//
// Created by edson on 28/03/18.
//

#ifndef TRABALHO_ED2_FILEUTILS_H
#define TRABALHO_ED2_FILEUTILS_H

#include <iostream>
#include <fstream>
#include "Question.h"
#include <exception>
#include <vector>
#include <ctime>

using namespace std;

class FileUtils {
public:
    static Question* readFileQuestion(string path);
};


#endif //TRABALHO_ED2_FILEUTILS_H
