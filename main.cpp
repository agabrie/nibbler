#include <iostream>
#include "LinkedList.hpp"
using namespace std;


int main() {
LinkedList *a = new LinkedList();
   a->push(3);
   a->push(1);
   cout<<"The linked list is: ";
   a->display();
   a->pop();
   a->push(7);
   a->push(2);
   a->push(9);
   cout<<"The linked list is: ";
   a->display();
   delete a;
   return 0; 
} 

// class Player{
//     public:
//         Player(int x, int y,int level);
//         ~Player();
//     private:
//         int x;
//         int y;
//         int level;
// }

// int main(){

// }