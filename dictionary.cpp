#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include "functionClass.h"
#include "linkedListClass.h"

using namespace std;

Function func;

void LinkedList::insertHead(string word, string pOS, string definition){
    node *curr = new(node);
    curr->word = word;
    curr->pOS = pOS;
    curr->definition = definition;
    
    if(head == NULL){
        head = tail = curr;
        curr->next = curr->prev = NULL;
    }
    else{
        curr->next = head;
        head->prev = curr;
        head = curr;
        curr->prev = NULL;
    }
}

void LinkedList::insertTail(string word, string pOS, string definition){
    node *curr = new(node);
    curr->word = word;
    curr->pOS = pOS;
    curr->definition = definition;
    
    if(head == NULL){
        head = tail = curr;
        curr->next = NULL;
        curr->prev = NULL;
    }
    else{
        tail->next = curr;
        curr->prev = tail;
        curr->next = NULL;
        tail = curr;
    }
}

void LinkedList::insertWord(string word, string pOS, string definition){
    node *curr = new(node);
    curr->word = word;
    curr->pOS = pOS;
    curr->definition = definition;
    
    if(head == NULL){
        head = tail = curr;
        curr->next = curr->prev = NULL;
    }
    else{
        if(curr->word <= head->word){
            insertHead(word, pOS, definition);
        }
        else if (curr->word >= tail->word){
            insertTail(word, pOS, definition);
        }
        else{
            node *temp = new(node);
            temp = head;
            while(temp != NULL){
                if(temp->word > curr->word){
                    curr->next = temp;
                    curr->prev = temp->prev;
                    temp->prev->next = curr;
                    temp->prev = curr;
                    break;
                }
                temp = temp->next;
            }
        }
    }
}

void LinkedList::deleteHead(){
    node *curr = head;
    
    if(head!=NULL){
        if(head ==tail){
            head = tail = NULL;
            delete(curr);
        }
        else{
            head = head->next;
            head->prev = NULL;
            delete(curr);
        }
    }
}

void LinkedList::deleteTail(){
    node *curr = tail;
    
    if(head!=NULL){
        if(head ==tail){
            head = tail = NULL;
            delete(curr);
        }
        else{
            tail = tail->prev;
            tail->next = NULL;
            delete(curr);
        }
    }
}

void LinkedList::deleteWord(string word, LinkedList letter){
    bool check = letter.isWordExist(word);
    
    if(check == true){
        node *curr = head;
        if(head != NULL){
            if(head->word == word){
                deleteHead();
            }
            else if (tail->word == word){
                deleteTail();
            }
            else{
                node *temp = head;
                curr = head->next;
                while(temp!=NULL){
                    if(curr->word == word){
                        temp = curr->prev;
                        temp->next = curr->next;
                        curr->next->prev = curr->prev;
                        delete(curr);
                        break;
                    }
                    temp = temp->next;
                    curr = curr->next;
                }
            }
        }

    }

}

void LinkedList::searchWord(string word){
    bool check = false;
    node* curr = head;
    
    while(curr != tail){
        if(curr->word == word){
            cout <<  "Word: " << curr->word << "\nPart of Speech: " << curr->pOS << "\nDefinition: " << curr->definition << endl;
            check = true;
            break;
        }
        curr = curr->next;
    }
    if(check == false){
        cout << "Word not found! \n";
    }
}

void Function::addWord(string word, LinkedList letter, LinkedList all){
    bool check = letter.isWordExist(word);
    
    if(check == true){
        cout << "The word already exists!\n";
    }
    else{
        string pOS;
        string definition;
        cout << "Input part of speech: ";
        cin >> ws;
        getline(cin, pOS);
        cout << "Input definition: ";
        cin >> ws;
        getline(cin, definition);
        letter.insertWord(word, pOS, definition);
        all.insertWord(word, pOS, definition);
        cout << word << " has been successfully added to the dictionary!\n";
    }
}

string Function::inputDefinition(){
    string definition;
    cout << "Input new definition: ";
    cin >> ws;
    getline(cin, definition);
    return definition;
}

void LinkedList::changeDef(string word, string definition){
    bool check = false;
    node *curr = head;
    while(curr != tail){
        if(curr->word == word){
            curr->definition = definition;
            check = true;
            cout << "The definition of " << word << " has successfully been changed!\n";
            break;
        }
        curr = curr->next;
    }
    if(check == false){
        cout << "Word not found! \n";
    }
}

void LinkedList::changeDefAll(string word, string definition){
    node *curr = head;
    while(curr != tail){
        if(curr->word == word){
            curr->definition = definition;
            break;
        }
        curr = curr->next;
    }
}


void LinkedList::viewWord(string letter){
    bool check1 = false;
    bool check2 = false;
    if(letter.length() == 1){
        check2 = true;
    }
    node *curr = head;
    while(check2 == true){
        while (curr != NULL) {
            if (curr->word[0] == letter[0]) {
                cout << curr->word << endl;
                check1 = true;
            }
            curr = curr->next;
        }
        break;
    }
    if(check2 == false){
        cout << "Please input a letter!\n";
    }
    if(check1 == false){
        cout << "No words starting with " << letter << " found!\n";
    }
}
