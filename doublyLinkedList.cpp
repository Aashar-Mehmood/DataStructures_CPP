#include <iostream>
#include <cstdlib>
using namespace std;

void insertAtFirst(int data);
void insertAtEnd(int data);
void printAll();
void reversePrint();

struct Node
{
  int data;
  Node *next;
  Node *prev;
};

Node *head;

int main()
{
  head = NULL;
  int options;
  int choice, number;
  do
  {
    cout << "\nEnter 1 to insert numbers at begining"
         << "\nEnter 2 to insert numbers at end"
         << "\nEnter 3 to print list"
         << "\nEnter 4 to print reverse list"
         << "\nEnter 0 to exit : ";
    cin  >> options;
    cout << endl;
    switch (options)
    {
    case 1:
      cout << "How many numbers : ";
      cin >> choice;
      for (int i = 0; i < choice; i++)
      {
        cout << "Enter the number : ";
        cin >> number;
        insertAtFirst(number);
      }
      break;
    case 2:
      cout << "How many numbers : ";
      cin >> choice;
      for (int i = 0; i < choice; i++)
      {
        cout << "Enter the number : ";
        cin >> number;
        insertAtEnd(number);
      }
      break;
    case 3:
      printAll();
      break;
    case 4:
      reversePrint();
      break;
    case 0:
      exit(0);
      break;
    default:
      cout << "Invalid choice, inter a valid number\n";
      break;
    }
  } while (options != 0);
}

void insertAtFirst(int data)
{
  Node* newNode = new Node;
  newNode->data = data;
  if (head == NULL)
  {
    newNode->prev = NULL;
    newNode->next = NULL;
    head = newNode;
  }
  else
  {
    head->prev = newNode;
    newNode->prev = NULL;
    newNode->next = head;
    head = newNode;
  }
  
}

void insertAtEnd(int data)
{
  Node* newNode = new Node;
  newNode->data = data;
  Node* temp = head;
  
  if (temp==NULL)
  {
    newNode->next =NULL;
    newNode->prev = NULL;
    head = newNode;
  }

  else
  {
    while (temp->next!=NULL)
    {
      temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = NULL;
  }
}

void printAll()
{
  Node* cuurrent = head;
  while (cuurrent)
  {
    cout << cuurrent->data << "\t";
    cuurrent = cuurrent->next;
  }
  cout<<endl;
}

void reversePrint()
{
  Node* temp = head;
  if(temp == NULL) return;
  
  while (temp->next!=NULL)
  {
    temp = temp->next;
  }

  while (temp!=NULL)
  {
    cout<<temp->data<<"\t";
    temp = temp->prev;
  }
  cout<<"\n";
  
}