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

class FileUtils
{
	public:
	static void clearFileContent(string path);
	static vector<int> readInputFile(string path);
	static void readFileQuestion(string path, vector<Question> &questionList);
	static void readFileTag(string path, vector<Tag> &tagList);
	static void readFileAnswer(string path, vector<Answer> &answerList);
	static void writeToOutputFile(string text);
};

#endif //TRABALHO_ED2_FILEUTILS_H
