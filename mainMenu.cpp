#include <iostream>
#include <stdio.h>
#include "functionClass.h"

void Function::mainMenu(){
    readFile();
    bool run = true;
    while(run){
        cout << "WELCOME TO THE DICTIONARY! \nPlease choose: \n[1] Admin \n[2] User \n[3] Exit \nInput your choice: ";
        string choice;
        cin >> choice;
        if(choice == "1"){
            adminMenu();
        }
        else if(choice == "2"){
            userMenu();
        }
        else if(choice == "3"){
            closeFile();
            cout << "See you next time!\n";
            run = false;
        }
        else{
            cout << "Please choose from the options!\n";
        }
    }
}
