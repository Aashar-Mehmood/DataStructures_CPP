#include <cstdlib>
#include <iostream>
#define MAX_SIZE 101
using namespace std;
int stack[MAX_SIZE];
int top = -1;
void push(int number);
void pop();
void print();
bool isEmpty();

int main(){
  int option, number;
  do
  {
    cout<<"\nEnter 1 to push"
        <<"\nEnter 2 to pop"
        <<"\nEnter 3 to print All items in stack"
        <<"\nEnter 4 to check if stack is empty"
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
      cout<<"\nStack is empty ? "<<isEmpty()<<endl;
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

void push(int number){
  if(top==MAX_SIZE-1){
    cout<<"Error: Stack overflow\n";
    return;
  }
  else{
    stack[++top] = number;
  }
}

void pop(){
  if(top==-1){
    cout<<"\nNo Item in the stack\n";
  }
  else{
    int topNumber = stack[top];
    top--;
    cout<<"\n"<<topNumber<<" is removed from stack\n";
  }

}
void print(){
  cout<<"\nThe items in stack are \n";
  for(int i=top; i>-1; i--){
    cout<<stack[i]<<'\t';
  }
  cout<<endl;
}
bool isEmpty(){
  return top == -1;
}
