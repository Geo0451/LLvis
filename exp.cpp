/*Convert a word into a linked list, and allow user to change the individual letters
  and add letters as need be*/







#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

class Node {
    public:
        Node *n;
        char c;
};

Node* convertWord(string w) //convert given word w into a LL with each letter as a node
    {
    Node* fp = new Node; // The very first node of our linked list
    Node* p = fp;
    
    for (int i = 0; i < w.length(); i++ )
    {
        p->c = w[i]; //assign the letter
        cout << w[i];
        if (i != w.length() - 1) // not the very last letter?
        {
            p->n = new Node; // address to next node is created
            p = p->n; // traverse to next node
        }
        else
        {
            p->n = NULL; //last node's next node address points to NULL
        }
        
    }
    return fp;
    }

void displayLL(Node* fp) //displays an entire linked list given the first pointer fp
{
    while (fp != NULL) //until last node is reached
    {
        cout << fp->c << endl; //print node's character
        fp = fp->n; //traverse to next node
    }
}

int main()
{
    string word;
    cout << "Enter your word:\n" << endl;
    //cin >> word; //use getline because cin stops at first whitespace
    getline(cin,word);

    displayLL(convertWord(word));

    

    cout << "Done" << endl;
    return 0;
}    