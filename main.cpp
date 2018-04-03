#include <iostream>
#include "Headers/FileUtils.h"
#include <ctime>

using namespace std;
int main(int argc, char** argv)
{
    string path = "/home/edson/pythonquestions/Questions.csv";
    vector<Question*>* list = FileUtils::readFileQuestion(path);
    return 0;
}