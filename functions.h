/*Convert a word into a linked list, and allow user to change the individual letters
  and add letters as need be*/






#include <stdlib.h>
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


int getLength(Node* fp) //get length of the linked list
{
    int c = 0;
    while (fp != NULL) 
    {
        c++; 
        fp = fp->n; 
    }
    return c;
}


Node* removeNode(int i,Node* p) //removes i-th node(zero-based w/ negative indexing)
{                                  //and returns new first node(if applicable,else NULL)
    int n = 0;
    int len = getLength(p);
    Node *prev,*next;
    next = p->n;

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
        p = next; //current pointer
        next = next->n; //next pointer
        n++;
    }

    delete p; //bye bye

    //edge cases that require no stiching of pointers
    if (i == 0) //first node
    {
        return next; //next is now your new first node
    }
    

    //predecessor now points to successor instead of our now-deleted current pointer p
    prev->n = next; 
    return NULL;

}

Node* addNode(int i,char c, Node* p)
{
    //i > len - 1(last index) : do nothing
    //i == len - 1(last index) : prev->n = newnode 
    //i == 0: fp = newnode, newnocde->n = fp
    //else : prev->n = newnode, newnode->n = next


    int n = 0;
    int len = getLength(p);
    Node* nn = new Node;
    nn->c = c;
    Node *prev,*next;
    next = p->n; 

    if ((i > len - 1) || (-i > len)) 
    {
        return NULL; 
    }

    if (i < 0)
    {
        i = len + i; 
    }



    while (n < i)
    {
        prev = p; //predecessor pointer
        p = next; //current pointer
        next = next->n; //next pointer
        n++;
    }

    if (i == 0)
    {
        nn->n = p;
        return nn;
    }

    
    prev->n = nn;
    nn->n = p;

    

    return NULL;
}

