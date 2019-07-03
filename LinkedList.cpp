#include "LinkedList.hpp"
using namespace std;
void LinkedList::push(int new_data) { 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    // struct Node* new_node; 
    new_node->data = new_data; 
    new_node->next = this->head; 
    this->head = new_node;
    this->len++;
}
void LinkedList::pop(){
    struct Node* n;
    n = this->head;
    this->head = (this->head)->next;
    cout << "popped : ("<< n->data << ")\n";
    free(n);
    this->len--;
}

LinkedList::LinkedList(){
    this->head = NULL;
}
LinkedList::~LinkedList(){
    // this->head = NULL;
    while(this->len > 0){
        this->pop();
    }
    this->display();
}
void LinkedList::display() {
   struct Node* ptr;
   ptr = this->head;
   cout << this->len<< endl;
   while (ptr != NULL) { 
      cout<< ptr->data <<" "; 
      ptr = ptr->next; 
   }
   cout << endl;
}