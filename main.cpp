#include <iostream>
#include "Headers/FileUtils.h"

using namespace std;
int main(int argc, char** argv)
{
    //string path = "/home/edson/pythonquestions/Questions.csv"; //edson
    string path = "/media/viniman/Files/Google Drive/UFJF/2018/1/ED2/Trabalho/pythonquestions/Questions.csv";
    vector<Question*>* list = FileUtils::readFileQuestion(path);

    for(unsigned int i = 0; i < 10; i++)
        list->at(i)->printComponents();

    return 0;
}