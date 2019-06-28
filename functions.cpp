#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include "linkedListClass.h"
#include "functionClass.h"
using namespace std;

LinkedList a;
LinkedList b;
LinkedList c;
LinkedList d;
LinkedList e;
LinkedList f;
LinkedList g;
LinkedList h;
LinkedList i;
LinkedList j;
LinkedList k;
LinkedList l;
LinkedList m;
LinkedList n;
LinkedList o;
LinkedList p;
LinkedList q;
LinkedList r;
LinkedList s;
LinkedList t;
LinkedList u;
LinkedList v;
LinkedList w;
LinkedList x;
LinkedList y;
LinkedList z;
LinkedList allWords;

Function func1;

void Function::readFile(){
    ifstream file("/Users/Gadiza/Desktop/Data Structures and Algorithms/Final Project/Final Project/Final Project/words");
    string word, pOS, definition;
    
    if (file.is_open()){
        while(file >> word >> pOS >> definition){
            replaceChar(word,"_"," ");
            replaceChar(pOS,"_"," ");
            replaceChar(definition, "_", " ");
            allWords.insertWord(word, pOS, definition);
            if(word[0]=='a'){
                a.insertWord(word, pOS, definition);
            }
            else if(word[0] == 'b'){
                b.insertWord(word, pOS, definition);
            }
            else if(word[0] == 'c'){
                c.insertWord(word, pOS, definition);
            }
            else if(word[0] == 'd'){
                d.insertWord(word, pOS, definition);
            }
            else if(word[0] == 'e'){
                e.insertWord(word, pOS, definition);
            }
            else if(word[0] == 'f'){
                f.insertWord(word, pOS, definition);
            }
            else if(word[0] == 'g'){
                g.insertWord(word, pOS, definition);
            }
            else if(word[0] == 'h'){
                h.insertWord(word, pOS, definition);
            }
            else if(word[0] == 'i'){
                i.insertWord(word, pOS, definition);
            }
            else if(word[0] == 'j'){
                j.insertWord(word, pOS, definition);
            }
            else if(word[0] == 'k'){
                k.insertWord(word, pOS, definition);
            }
            else if(word[0] == 'l'){
                l.insertWord(word, pOS, definition);
            }
            else if(word[0] == 'm'){
                m.insertWord(word, pOS, definition);
            }
            else if(word[0] == 'n'){
                n.insertWord(word, pOS, definition);
            }
            else if(word[0] == 'o'){
                o.insertWord(word, pOS, definition);
            }
            else if(word[0] == 'p'){
                p.insertWord(word, pOS, definition);
            }
            else if(word[0] == 'q'){
                q.insertWord(word, pOS, definition);
            }
            else if(word[0] == 'r'){
                r.insertWord(word, pOS, definition);
            }
            else if(word[0] == 's'){
                s.insertWord(word, pOS, definition);
            }
            else if(word[0] == 't'){
                t.insertWord(word, pOS, definition);
            }
            else if(word[0] == 'u'){
                u.insertWord(word, pOS, definition);
            }
            else if(word[0] == 'v'){
                v.insertWord(word, pOS, definition);
            }
            else if(word[0] == 'w'){
                w.insertWord(word, pOS, definition);
            }
            else if(word[0] == 'x'){
                x.insertWord(word, pOS, definition);
            }
            else if(word[0] == 'y'){
                y.insertWord(word, pOS, definition);
            }
            else if(word[0] == 'z'){
                z.insertWord(word, pOS, definition);
            }
            
        }
        file.close();
    }
    else{
        cout << "Unable to read file! \n";
        exit(EXIT_FAILURE);
    }
}

void LinkedList::writeFile(){
    string word, pOS, definition;
    string newWord, newPOS, newDefinition;
    ofstream file("/Users/Gadiza/Desktop/Data Structures and Algorithms/Final Project/Final Project/Final Project/words");
    if(!file.is_open()){
        exit(EXIT_FAILURE);
    }
    while(file.good()){
        node *curr = head;
        while(curr != NULL){
            word = curr->word;
            pOS = curr->pOS;
            definition = curr->definition;
            func1.replaceChar(word, " ", "_");
            func1.replaceChar(pOS, " ", "_");
            func1.replaceChar(definition, " ", "_");
            file << word << " " << pOS << " " << definition << endl;
            curr = curr->next;
        }
        file.close();
    }
}

void Function::closeFile(){
    allWords.writeFile();
}

void Function::replaceChar(string& str, const string& oldStr, const string& newStr){
    string::size_type pos = 0;
    while((pos = str.find(oldStr, pos)) != string::npos){
        str.replace(pos, oldStr.length(), newStr);
        pos += newStr.length();
    }
}

string Function::inputWord(){
    string word;
    cout << "Input word: ";
    cin >> ws;
    getline(cin, word);
    return word;
}

string Function::inputLetter(){
    string letter;
    cout << "Input letter: ";
    cin >> letter;
    return letter;
}

void LinkedList::sentence(string word){
    bool check = false;
    node* curr = head;
    while(curr != tail){
        if(curr->word == word){
            cout << "The word is: " << word << "\nHere is the sample sentence: \n";
            if(curr->pOS == "noun"){
                cout << "That " << curr->word << " belongs to me!\n";
            }
            else if (curr->pOS == "countable noun"){
                cout << "Oh my gosh, look at the " << curr->word << "!\n";
            }
            else if (curr->pOS == "common noun"){
                cout << "I kind of like this " << curr->word << ".\n";
            }
            else if(curr->pOS == "collective noun"){
                cout << "The " << curr->word << " is a mess!\n";
            }
            else if(curr->pOS == "verb"){
                cout << "I like to " << curr->word << ".\n";
            }
            else if(curr->pOS == "transitive verb"){
                cout << "Why don't you " << curr->word << " me?\n";
            }
            else if(curr->pOS == "irregular verb"){
                cout << "I want to " << curr->word << " some fish.\n";
            }
            else if(curr->pOS == "action verb"){
                cout << "I like to " << curr->word << ".\n";
            }
            else if(curr->pOS == "adjective"){
                cout << "I think that sheep is " << curr->word << "!\n";
            }
            else if(curr->pOS == "subject pronoun"){
                cout << "Did " << curr->word << " do this?\n";
            }
            else if(curr->pOS == "object pronoun"){
                cout << "They didn't give " << curr->word << " a choice.\n";
            }
            else if(curr->pOS == "possessive pronoun"){
                cout << "A thief broke into " << curr->word << " house!\n";
            }
            else if(curr->pOS == "independent possessive pronoun"){
                cout << "Isn't that shirt " << curr->word << ".\n";
            }
            else{
                cout << "Sorry, no sentence found.\n";
            }
            check = true;
        }
        curr = curr->next;
    }
    if(check == false){
        cout << "Word not found!\n";
    }
    
}

bool LinkedList::isWordExist(string word){
    node *curr = head;
    while(curr != NULL){
        if(curr->word == word){
            return true;
        }
        curr = curr->next;
    }
    return false;
}

void Function::adminMenu(){
    string username = "user123";
    string password = "smartass123";
    bool check1 = false;
    bool check2 = false;
    bool check3 = false;
    
    string inputUser;
    string inputPass;
    
    cout << "Please input username: ";
    cin >> inputUser;
    cout << "Please input password: ";
    cin >> inputPass;
    
    if(inputUser == username){
        check1 = true;
    }
    if(inputPass == password){
        check2 = true;
    }
    if(check1 == true && check2 == true){
        check3 = true;
    }
    else{
        cout << "Please enter the correct username and password!\n";
    }
    
    if(check3 == true){
        string choice;
        bool run = true;
        bool check;
        string word;
        string definition;
        cout << "\nHello Admin! \n";
        while(run){
            cout << "Here is what you can do: \n[1] Add a new word \n[2] Delete a word \n[3] Change definition of a word \n[4] Back to main menu \n[5] Exit \nInput your choice: ";
            cin >> choice;
            if(choice == "1"){
                    word = inputWord();
                    if(word[0] == 'a'){
                        addWord(word, a, allWords);
                    }
                    else if(word[0] == 'b'){
                        addWord(word, b, allWords);
                    }
                    else if(word[0] == 'c'){
                        addWord(word, c, allWords);
                    }
                    else if(word[0] == 'd'){
                        addWord(word, d, allWords);
                    }
                    else if(word[0] == 'e'){
                        addWord(word, e, allWords);
                    }
                    else if(word[0] == 'f'){
                        addWord(word, f, allWords);
                    }
                    else if(word[0] == 'g'){
                        addWord(word, g, allWords);
                    }
                    else if(word[0] == 'h'){
                        addWord(word, h, allWords);
                    }
                    else if(word[0] == 'i'){
                        addWord(word, i, allWords);
                    }
                    else if(word[0] == 'j'){
                        addWord(word, j, allWords);
                    }
                    else if(word[0] == 'k'){
                        addWord(word, k, allWords);
                    }
                    else if(word[0] == 'l'){
                        addWord(word, l, allWords);
                    }
                    else if(word[0] == 'm'){
                        addWord(word, m, allWords);
                    }
                    else if(word[0] == 'n'){
                        addWord(word, n, allWords);
                    }
                    else if(word[0] == 'o'){
                        addWord(word, o, allWords);
                    }
                    else if(word[0] == 'p'){
                        addWord(word, p, allWords);
                    }
                    else if(word[0] == 'q'){
                        addWord(word, q, allWords);
                    }
                    else if(word[0] == 'r'){
                        addWord(word, r, allWords);
                    }
                    else if(word[0] == 's'){
                        addWord(word, s, allWords);
                    }
                    else if(word[0] == 't'){
                        addWord(word, t, allWords);
                    }
                    else if(word[0] == 'u'){
                        addWord(word, u, allWords);
                    }
                    else if(word[0] == 'v'){
                        addWord(word, v, allWords);
                    }
                    else if(word[0] == 'w'){
                        addWord(word, w, allWords);
                    }
                    else if(word[0] == 'x'){
                        addWord(word, x, allWords);
                    }
                    else if(word[0] == 'y'){
                        addWord(word, y, allWords);
                    }
                    else if(word[0] == 'z'){
                        addWord(word, z, allWords);
                    }
                    else{
                        cout << "Please make sure your input is valid!\n";
                    }
            }
            else if(choice == "2"){
                    word = inputWord();
                    check = allWords.isWordExist(word);
                    if(word[0] == 'a'){
                        a.deleteWord(word, a);
                    }
                    else if(word[0] == 'b'){
                        b.deleteWord(word, b);
                    }
                    else if(word[0] == 'c'){
                        c.deleteWord(word, c);
                    }
                    else if(word[0] == 'd'){
                        d.deleteWord(word, d);
                    }
                    else if(word[0] == 'e'){
                        e.deleteWord(word, e);
                    }
                    else if(word[0] == 'f'){
                        f.deleteWord(word, f);
                    }
                    else if(word[0] == 'g'){
                        g.deleteWord(word, g);
                    }
                    else if(word[0] == 'h'){
                        h.deleteWord(word, h);
                    }
                    else if(word[0] == 'i'){
                        i.deleteWord(word, i);
                    }
                    else if(word[0] == 'j'){
                        j.deleteWord(word, j);
                    }
                    else if(word[0] == 'k'){
                        k.deleteWord(word, k);
                    }
                    else if(word[0] == 'l'){
                        l.deleteWord(word, l);
                    }
                    else if(word[0] == 'm'){
                        m.deleteWord(word, m);
                    }
                    else if(word[0] == 'n'){
                        n.deleteWord(word, n);
                    }
                    else if(word[0] == 'o'){
                        o.deleteWord(word, o);
                    }
                    else if(word[0] == 'p'){
                        p.deleteWord(word, p);
                    }
                    else if(word[0] == 'q'){
                        q.deleteWord(word, q);
                    }
                    else if(word[0] == 'r'){
                        r.deleteWord(word, r);
                    }
                    else if(word[0] == 's'){
                        s.deleteWord(word, s);
                    }
                    else if(word[0] == 't'){
                        t.deleteWord(word, t);
                    }
                    else if(word[0] == 'u'){
                        u.deleteWord(word, u);
                    }
                    else if(word[0] == 'v'){
                        v.deleteWord(word, v);
                    }
                    else if(word[0] == 'w'){
                        w.deleteWord(word, w);
                    }
                    else if(word[0] == 'x'){
                        x.deleteWord(word, x);
                    }
                    else if(word[0] == 'y'){
                        y.deleteWord(word, y);
                    }
                    else if(word[0] == 'z'){
                        z.deleteWord(word, z);
                    }
                    else{
                        cout << "Please make sure your input is valid!\n";
                    }
                    allWords.deleteWord(word, allWords);
                if(check == true){
                    cout << word << " has been successfully removed!\n";
                }
                else if(check == false){
                    cout << "Word not found!\n";
                }
            }
            else if(choice == "3"){
                    word = inputWord();
                    definition = inputDefinition();
                    if(word[0] == 'a'){
                        a.changeDef(word, definition);
                    }
                    else if(word[0] == 'b'){
                        b.changeDef(word, definition);
                    }
                    else if(word[0] == 'c'){
                        c.changeDef(word, definition);
                    }
                    else if(word[0] == 'd'){
                        d.changeDef(word, definition);
                    }
                    else if(word[0] == 'e'){
                        e.changeDef(word, definition);
                    }
                    else if(word[0] == 'f'){
                        f.changeDef(word, definition);
                    }
                    else if(word[0] == 'g'){
                        g.changeDef(word, definition);
                    }
                    else if(word[0] == 'h'){
                        h.changeDef(word, definition);
                    }
                    else if(word[0] == 'i'){
                        i.changeDef(word, definition);
                    }
                    else if(word[0] == 'j'){
                        j.changeDef(word, definition);
                    }
                    else if(word[0] == 'k'){
                        k.changeDef(word, definition);
                    }
                    else if(word[0] == 'l'){
                        l.changeDef(word, definition);
                    }
                    else if(word[0] == 'm'){
                        m.changeDef(word, definition);
                    }
                    else if(word[0] == 'n'){
                        n.changeDef(word, definition);
                    }
                    else if(word[0] == 'o'){
                        o.changeDef(word, definition);
                    }
                    else if(word[0] == 'p'){
                        p.changeDef(word, definition);
                    }
                    else if(word[0] == 'q'){
                        q.changeDef(word, definition);
                    }
                    else if(word[0] == 'r'){
                        r.changeDef(word, definition);
                    }
                    else if(word[0] == 's'){
                        s.changeDef(word, definition);
                    }
                    else if(word[0] == 't'){
                        t.changeDef(word, definition);
                    }
                    else if(word[0] == 'u'){
                        u.changeDef(word, definition);
                    }
                    else if(word[0] == 'v'){
                        v.changeDef(word, definition);
                    }
                    else if(word[0] == 'w'){
                        w.changeDef(word, definition);
                    }
                    else if(word[0] == 'x'){
                        x.changeDef(word, definition);
                    }
                    else if(word[0] == 'y'){
                        y.changeDef(word, definition);
                    }
                    else if(word[0] == 'z'){
                        z.changeDef(word, definition);
                    }
                    allWords.changeDefAll(word, definition);
            }
            else if(choice == "4"){
                    cout << "Goodbye Admin! \n";
                    run = false;
            }
            else if(choice == "5"){
                    closeFile();
                    cout << "See you next time!\n";
                    exit(1);
            }
                    
            else{
                    cout << "Please choose from the options!\n";
            }
            }
        }
}


void Function::userMenu(){
    string choice;
    bool run = true;
    string word;
    cout << "\nHello User! \n";
    while(run){
        cout << "Here is what you can do: \n[1] Find a word \n[2] View All Words of a Letter [a-z] \n[3] See sample sentence of a word \n[4] Back to main menu \n[5] Exit \nInput your choice: ";
        cin >> choice;
            if(choice == "1"){
                word = inputWord();
                if(word[0] == 'a'){
                    a.searchWord(word);
                }
                else if(word[0] == 'b'){
                    b.searchWord(word);
                }
                else if(word[0] == 'c'){
                    c.searchWord(word);
                }
                else if(word[0] == 'd'){
                    d.searchWord(word);
                }
                else if(word[0] == 'e'){
                    e.searchWord(word);
                }
                else if(word[0] == 'f'){
                    f.searchWord(word);
                }
                else if(word[0] == 'g'){
                    g.searchWord(word);
                }
                else if(word[0] == 'h'){
                    h.searchWord(word);
                }
                else if(word[0] == 'i'){
                    i.searchWord(word);
                }
                else if(word[0] == 'j'){
                    j.searchWord(word);
                }
                else if(word[0] == 'k'){
                    k.searchWord(word);
                }
                else if(word[0] == 'l'){
                    l.searchWord(word);
                }
                else if(word[0] == 'm'){
                    m.searchWord(word);
                }
                else if(word[0] == 'n'){
                    n.searchWord(word);
                }
                else if(word[0] == 'o'){
                    o.searchWord(word);
                }
                else if(word[0] == 'p'){
                    p.searchWord(word);
                }
                else if(word[0] == 'q'){
                    q.searchWord(word);
                }
                else if(word[0] == 'r'){
                    r.searchWord(word);
                }
                else if(word[0] == 's'){
                    s.searchWord(word);
                }
                else if(word[0] == 't'){
                    t.searchWord(word);
                }
                else if(word[0] == 'u'){
                    u.searchWord(word);
                }
                else if(word[0] == 'v'){
                    v.searchWord(word);
                }
                else if(word[0] == 'w'){
                    w.searchWord(word);
                }
                else if(word[0] == 'x'){
                    x.searchWord(word);
                }
                else if(word[0] == 'y'){
                    y.searchWord(word);
                }
                else if(word[0] == 'z'){
                    z.searchWord(word);
                }
                else{
                    cout << "Please make sure your input is valid!\n";
                }
            }
                
            else if(choice == "2"){
                string letter;
                letter = inputLetter();
                if(letter == "a"){
                    a.viewWord(letter);
                }
                else if(letter == "b"){
                    b.viewWord(letter);
                }
                else if(letter == "c"){
                    c.viewWord(letter);
                }
                else if(letter == "d"){
                    d.viewWord(letter);
                }
                else if(letter == "e"){
                    e.viewWord(letter);
                }
                else if(letter == "f"){
                    f.viewWord(letter);
                }
                else if(letter == "g"){
                    g.viewWord(letter);
                }
                else if(letter == "h"){
                    h.viewWord(letter);
                }
                else if(letter == "i"){
                    i.viewWord(letter);
                }
                else if(letter == "j"){
                    j.viewWord(letter);
                }
                else if(letter == "k"){
                    k.viewWord(letter);
                }
                else if(letter == "l"){
                    l.viewWord(letter);
                }
                else if(letter == "m"){
                    m.viewWord(letter);
                }
                else if(letter == "n"){
                    n.viewWord(letter);
                }
                else if(letter == "o"){
                    o.viewWord(letter);
                }
                else if(letter == "p"){
                    p.viewWord(letter);
                }
                else if(letter == "q"){
                    q.viewWord(letter);
                }
                else if(letter == "r"){
                    r.viewWord(letter);
                }
                else if(letter == "s"){
                    s.viewWord(letter);
                }
                else if(letter == "t"){
                    t.viewWord(letter);
                }
                else if(letter == "u"){
                    u.viewWord(letter);
                }
                else if(letter == "v"){
                    v.viewWord(letter);
                }
                else if(letter == "w"){
                    w.viewWord(letter);
                }
                else if(letter == "x"){
                    x.viewWord(letter);
                }
                else if(letter == "y"){
                    y.viewWord(letter);
                }
                else if(letter == "z"){
                    z.viewWord(letter);
                }
                else{
                    cout << "Please make sure your input is valid!\n";
                }
            }
                
            else if(choice == "3"){
                word = inputWord();
                if(word[0] == 'a'){
                    a.sentence(word);
                }
                else if(word[0] == 'b'){
                    b.sentence(word);
                }
                else if(word[0] == 'c'){
                    c.sentence(word);
                }
                else if(word[0] == 'd'){
                    d.sentence(word);
                }
                else if(word[0] == 'e'){
                    e.sentence(word);
                }
                else if(word[0] == 'f'){
                    f.sentence(word);
                }
                else if(word[0] == 'g'){
                    g.sentence(word);
                }
                else if(word[0] == 'h'){
                    h.sentence(word);
                }
                else if(word[0] == 'i'){
                    i.sentence(word);
                }
                else if(word[0] == 'j'){
                    j.sentence(word);
                }
                else if(word[0] == 'k'){
                    k.sentence(word);
                }
                else if(word[0] == 'l'){
                    l.sentence(word);
                }
                else if(word[0] == 'm'){
                    m.sentence(word);
                }
                else if(word[0] == 'n'){
                    n.sentence(word);
                }
                else if(word[0] == 'o'){
                    o.sentence(word);
                }
                else if(word[0] == 'p'){
                    p.sentence(word);
                }
                else if(word[0] == 'q'){
                    q.sentence(word);
                }
                else if(word[0] == 'r'){
                    r.sentence(word);
                }
                else if(word[0] == 's'){
                    s.sentence(word);
                }
                else if(word[0] == 't'){
                    t.sentence(word);
                }
                else if(word[0] == 'u'){
                    u.sentence(word);
                }
                else if(word[0] == 'v'){
                    v.sentence(word);
                }
                else if(word[0] == 'w'){
                    w.sentence(word);
                }
                else if(word[0] == 'x'){
                    x.sentence(word);
                }
                else if(word[0] == 'y'){
                    y.sentence(word);
                }
                else if(word[0] == 'z'){
                    z.sentence(word);
                }
                else{
                    cout << "Please make sure your input is valid!\n";
                }
            }
            else if(choice == "4"){
                closeFile();
                cout << "Goodbye User! \n";
                run = false;
            }
            else if(choice == "5"){
                cout << "See you next time!\n";
                exit(1);
            }
                
            else{
                cout << "Please choose from the options!\n";
            }
    }
}
