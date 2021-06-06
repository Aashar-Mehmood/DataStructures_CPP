#include <cstdlib>
#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

Node *head;
void insertAtFirst(int data);
void insertAtNth(int pos, int data);
void deleteFrom(int index);
void reverseList();
void print();

int main()
{
  head = NULL; //Empty list
  int choice;
  do
  {
    cout << "\nEnter 1 to insert at beginning"
         << "\nEnter 2 to insert at nth position"
         << "\nEnter 3 to reverse and print the List"
         << "\nEnter 4 to print List"
         << "\nEnter 5 to exit\n";
    cin  >>choice;
    cout << endl;
    switch (choice)
    {
    case 1:
      int count, i, data;
      cout << "How many numbers ?" << endl;
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
      int position, data2;
      cout << "Enter the position where you want to insert : ";
      cin >> position;
      cout << endl;
      cout << "Enter the data you want to insert : ";
      cin >> data2;
      cout << endl;
      insertAtNth(position, data2);
      break;
    case 3:
      reverseList();
      break;
    case 4:
      print();
      break;
    case 5:
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

void insertAtNth(int pos, int data)
{
  Node *temp = new Node;

  temp->data = data;
  temp->next = NULL;

  Node *traverse = head;
  if (pos == 1)
  {
    temp->next = head;
    head = temp;
  }
  else
  {
    for (int i = 1; i < pos - 1; i++)
    {
      traverse = traverse->next;
    }

    temp->next = traverse->next;
    // traverse->next = NULL;
    traverse->next = temp;
  }
}

void deleteFrom(int index)
{
  Node *temp = head;
  if (index == 1)
  {
    head = temp->next;
    delete temp;
  }
  else
  {
    for (int i = 1; i < index - 1; i++)
    {
      temp = temp->next;
    }
    Node *temp2 = temp->next; //points to index (nth node)
    temp->next = temp2->next; //points to index.next
    delete temp2;
  }
}

void reverseList()
{
  Node *current = head;
  Node *prevNode = NULL;
  Node *nextNode = NULL;
  while (current != NULL)
  {
    // make link to next node of current node
    // if we directly pint the current->next to prevNode,
    // we will lose the next part of list
    nextNode = current->next;

    // fixt link (current.next points to previous node instead next)
    current->next = prevNode;

    // now previous node becomes current (for next iteration)
    prevNode = current;

    // and current becomes next (for next iteration)
    current = nextNode;
  }
  head = prevNode;
  print();
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