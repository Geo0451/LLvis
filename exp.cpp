/*Convert a word into a linked list, and allow user to change the individual letters
  and add letters as need be*/






#include <stdlib.h>
#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

int main()
{
    string word;

    system("clear");
        
    cout << "Enter your word:\n" << endl;
    //cin >> word; //use getline because cin stops at first whitespace
    getline(cin,word);
    Node* myp = convertWord(word);

    int ind;
    Node* t; //test
    while (true)
    {
        displayLL(myp);
        cout << "Enter which letter to remove starting from 0: " << endl;
        cin >> ind;

        t = removeNthNode(ind, myp);
        if (t != NULL)
        {
            myp = t;
        }        
        
        cin.get();
        //system("clear");
    }

    

    return 0;
}    