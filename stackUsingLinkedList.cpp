// Stack is an abstract data type which can be implemented using
// arrays or linked list with the restriction that insertion and deletion of items
// can only be performed at one end called the top of stack
// it is also called last in first out (LIFO) data strcutre
// when we use linked list to implement the stack
// we do not have to worry about the overflow (unlike array implementation)
// push an pop function takes constant time (O(1))
// printing all items of stack takes linear time (O(n)) 

#include <cstdlib>
#include <iostream>
using namespace std;

void push(int number);
void pop();
void print();
void isEmpty();
void printTop();

struct Node{
  int data;
  Node *next;
};

Node *top;

int main(){
  top = NULL;
  int option, number;
  do
  {
    cout<<"\nEnter 1 to push"
        <<"\nEnter 2 to pop"
        <<"\nEnter 3 to print All items in stack"
        <<"\nEnter 4 to check if stack is empty"
        <<"\nEnter 5 to print top element in stack"
        <<"\nEnter 0 to exit : ";
    cin >> option;
    switch (option)
    {
    case 1:
      cout<<"\nEnter the number you want to push : ";
      cin>>number;
      push(number);
      cout<<"\n"<<number<<" is pushed to stack\n";
      break;
    case 2:
      pop();
      break;
    case 3:
      print();
      break;
    case 4:
      isEmpty();
      break;
    case 5:
      printTop();
      break;
    case 0:
      exit(0);
      break;
    default:
      cout<<"Invalid choice! Enter a valid number";
      break;
    }
  } while (option!=0);
  
}

void push(int data){
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;
  if(top==NULL){
    top = newNode;

  }
  else{
    newNode->next = top;
    top = newNode;
  }
}

void pop(){
  if(top==NULL){
    cout<<"\n Stack is empty\n";
    return;
  }
  Node *cuurentTop = top;
  int topNum = top->data;
  top = top->next; //assign the top to next 
  delete cuurentTop; //delete the current top
  cout << "\n"<<topNum<<" is removed from stack\n";
}

void print(){
  Node *current = top;
  if(current == NULL){
    cout<<"\nStack is empty\n ";
    return;
  }
  cout<<"\nItems in Stack are \n";
  while(current!=NULL){
    cout<<current->data<<'\t';
    current = current->next;
  }
  cout<<'\n';
}

void isEmpty(){
  if(top==NULL){
    cout<<"\nStack is empty\n";
  }
  else{
    cout<<"\nStack is not empty\n";
  }
}
void printTop(){
  cout<<"\nItem at top of stack is " <<top->data<<"\n";
}
