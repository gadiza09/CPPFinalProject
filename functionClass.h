#ifndef functionClass_h
#define functionClass_h

#include <stdio.h>
#include <string>
#include "linkedListClass.h"

using namespace std;

class Function{
    
public:
    void replaceChar(string& str, const string& oldStr, const string& newStr);
    void mainMenu();
    void readFile();
    void addWord(string word, LinkedList letter, LinkedList all);
    string inputWord();
    string inputLetter();
    string inputDefinition();
    void adminMenu();
    void userMenu();
    void closeFile();
};

#endif
