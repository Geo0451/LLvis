/*Convert a word into a linked list, and allow user to change the individual letters
  and add letters as need be*/






#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class Node {
    public:
        Node *next;
        char c;
};



Node* convertWord(string w) //convert given word w into a LL with each letter as a node
    {
    Node* head = new Node; // The very first node of our linked list
    Node* p = head;
    
    for (int i = 0; i < w.length(); i++ )
    {
        p->c = w[i]; //assign the letter
        if (i != w.length() - 1) // not the very last letter?
        {
            p->next = new Node; // address to next node is created
            p = p->next; // traverse to next node
        }
        else
        {
            p->next = NULL; //last node's next node address points to NULL
        }
        
    }
    return head;
    }

void displayLL(Node* head) //displays an entire linked list given the first pointer head
{
    int index = 0;
    while (head != NULL) //until last node is reached
    {
        cout << index << " - " << head->c << endl; //print node's character
        head = head->next; //traverse to next node
        index++;
    }
}


int getLength(Node* head) //get length of the linked list
{
    int c = 0;
    while (head != NULL) 
    {
        c++; 
        head = head->next; 
    }
    return c;
}

int menuInput(Node* head)
{
    while (true)
        {
        system("clear");
        displayLL(head);

        string choice;
        int mode;
        cout << "\nChoose MODE:\n1. Add\n2. Remove\n3. Exit " << endl;
        cin >> choice;
        try 
        {
            return stoi(choice); //string to integer
            
        }

        catch (...)
        {
            cout << "INVALID CHOICE" << endl;
            continue;
        }
        

        }
}




Node* removeNode(int i,Node* p) //removes i-th node(zero-based w/ negative indexing)
{                                  //and returns new first node(if applicable,else NULL)
    int n = 0;
    int len = getLength(p);
    Node *prev,*np;
    np = p->next;

    if ((i > len - 1) || (-i > len)) //is mod i greater than last index position
    {                                // -ve i doesnt have to begin from 0 so no need of -1
        return NULL; //eat 5-star, do nothing
    }

    if (i < 0) //to support negative indexing,
    {
        i = len + i; //we convert i into a positive index position
        //cout << " THIS IS I = " << i << endl;
    }

    while (n < i)
    {
        prev = p; //predecessor pointer
        p = np; //current pointer
        np = np->next; //next pointer
        n++;
    }

    delete p; //bye bye

    //edge cases that require no stiching of pointers
    if (i == 0) //first node
    {
        return np; //next is now your new first node
    }
    

    //predecessor now points to successor instead of our now-deleted current pointer p
    prev->next = np; 
    return NULL;

}

Node* addNode(int i,char c, Node* head)
{
    int n = 0;
    int len = getLength(head);
    Node* nn = new Node;
    nn->c = c;

    if ((i > len - 1) || (-i > len)) 
    {
        return NULL; 
    }

    if (i < 0)
    {
        i = len + i; 
    }
    else
    {
        i -= 1;
    }

    if (i <= 0)
    {
        nn->next = head;
        return nn;
    }


    while (n < i)
    {
        head = head->next;
        n++;
    }

    
    cout << "i = " << i << "n = " << n << "len = " << len << endl;
    
    nn->next = head->next;
    head->next = nn;

    

    return NULL;
}

