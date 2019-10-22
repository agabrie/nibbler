#ifndef LINKEDLIST_HPP
# define LINKEDLIST_HPP
#include <iostream>
struct Node { 
   int data; 
   struct Node *next; 
};
class LinkedList{
    private :
        struct Node* head;
        int len;
    public:
        LinkedList();
        ~LinkedList();  
        void push(int new_data);
        void pop();
        void display();
};
#endif