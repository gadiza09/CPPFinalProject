#ifndef linkedListClass_h
#define linkedListClass_h
#include <stdio.h>
#include <string>

using namespace std;

class LinkedList{
    
    struct node{
        string word;
        string pOS;
        string definition;
        node *next, *prev;
    };
    
    private:
        node *head = NULL;
        node *tail = NULL;
    
    public:
        void insertHead(string word, string pOS, string definition);
        void insertTail(string word, string pOS, string definition);
        void insertWord(string word, string pOS, string definition);
        void deleteHead();
        void deleteTail();
        void deleteWord(string word, LinkedList letter);
        void searchWord(string word);
        bool isWordExist(string word);
        void changeDef(string word, string definition);
        void sentence(string word);
        void viewWord(string letter);
        void changeDefAll(string word, string definition);
        void writeFile();
    
};

#endif
