#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

void insertAtHead(int data);
void print();
void reverseList();

struct Node{
  int data;
  Node *next;
};

Node *head;

int main(){
 head = NULL;
 int choice, num;
 cout<<"How many items : ";
 cin>>choice; 
 for(int i=0; i<choice; i++){
   cout<<"Enter the number : ";
   cin>>num;
   insertAtHead(num);
 }
 cout<<"\nThe original list is \n";
 print();
 cout<<"\nThe reverse list is \n";
 reverseList();
}

void insertAtHead(int insertedData)
{

  Node *temp;
  temp = new Node();
  temp->data = insertedData;
  // insert at the beginning of the list
  temp->next = head;
  head = temp;
}

void print()
{
  Node *temp;
  temp = head;
  while (temp != NULL)
  {
    cout << temp->data << "\t";
    temp = temp->next;
  }
}

void reverseList(){
  stack <struct Node*> S;
  Node* temp = head;
  while(temp!=NULL){
    S.push(temp);
    temp = temp->next;
  }
  temp = S.top();
  head = temp;
  S.pop();
  while (!S.empty())
  {
    cout<<temp->data<<"\t";
    temp->next = S.top();
    S.pop();
    temp = temp->next;
  }
  cout<<temp->data;
  temp->next = NULL;
}