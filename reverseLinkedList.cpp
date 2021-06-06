// reversing a linked list using recurrsion
#include <cstdlib>
#include <iostream>
using namespace std;

void insertAtFirst(int data);
void reverseList();
void print();

struct Node
{
  int data;
  Node *next;
};

Node *head;

int main()
{
  head = NULL;
  int choice;
  do
  {
    cout << "\nEnter 1 to insert numbers in list"
         << "\nEnter 2 to reverse List"
         << "\nEnter 3 to print List"
         << "\nEnter 0 to exit";
    cin >> choice;
    switch (choice)
    {
    case 1:
      int count, data;
      cout << "How many numbers : ";
      cin >> count;
      cout << endl;
      for (int i = 0; i < count; i++)
      {
        cout << "Enter the number : ";
        cin >> data;
        cout << endl;
        insertAtFirst(data);
      }
      break;
    case 2:
      Node *temp = head;
      reverseList(temp);
      break;
    case 3:
      print();
      break;
    case 0:
      exit(0);
      break;
    default:
      cout << "Invalid Choice, enter a valid number." << endl;
      break;
    }

  } while (choice != 0);
}

void insertAtFirst(int insertedData)
{
  Node *temp;
  temp = new Node();
  temp->data = insertedData;
  // insert at the beginning of the list
  temp->next = head;
  head = temp;
}

void reverseList(Node *headPtr)
{ 
  if(headPtr->next==NULL){
    head = headPtr;
    return;
  }
  reverseList(headPtr->next);
  Node* nextNode = headPtr->next;
  nextNode->next = headPtr;
  headPtr->next  = NULL; 
}

void print()
{
  Node *temp;
  temp = head;
  cout << "The list is \n\n";
  while (temp != NULL)
  {
    cout << temp->data << "\t";
    temp = temp->next;
  }
  cout << "\n";
}