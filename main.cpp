#include <iostream>
#include "Headers/FileUtils.h"
#include <ctime>

using namespace std;
int main(int argc, char** argv)
{
    FileUtils::readFileQuestion("/home/edson/pythonquestions/Questions.csv");
    /*
    char* c;
    fstream f;
    f.open("teste.txt");
    f.seekg(0, f.end);
    int length = f.tellg();
    c = new char[length];
    f.seekg(0, f.beg);
    f.read(c,length);
    cout << c;
    */
    return 0;
}