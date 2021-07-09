#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
};

void insertNode(int data);
void findMinMax();
bool searchNumber(int number, Node *root);
int getHeight(Node *top);

Node *head = NULL;

int main()
{
  int choice = 0;
  do
  {
    int number = 0;
    cout << "\nEnter 1 to insert elements\n"
         << "Enter 2 to print minimum and maximum elements\n"
         << "Enter 3 to search element\n"
         << "Enter 4 to get height of tree\n"
         << "Enter 0 to exit\n";
    cin >> choice;
    switch (choice)
    {
    case 0:
      exit(0);
      break;
    case 1:
      int count;
      cout << "\n How many numbers ? ";
      cin >> count;
      for (int i = 0; i < count; i++)
      {
        cout << "\nEnter the number you want to insert : ";
        cin >> number;
        insertNode(number);
      }
      break;
    case 2:
      findMinMax();
      break;
    case 3:
      Node *root = head;
      cout << "\nEnter the number you want to search : ";
      cin >> number;
      bool result = searchNumber(number, root);
      if (result)
      {
        cout << "\n Number is present\n";
      }
      else
      {
        cout << "\n Number not found\n";
      }
      break;
    case 4:
      Node *top = head;
      cout << "The height of tree is : " << getHeight(top) << "\n";
      break;
    default:
      cout << "Invalid Choice !\n";
      break;
    }

  } while (choice != 0);
}

void insertNode(int data)
{
  Node *newNode = new Node;
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  Node *tempHead = head;
  Node *prev = NULL;

  if (tempHead == NULL)
  {
    head = newNode;
    return;
  }
  while (tempHead != NULL)
  {
    prev = tempHead; //keep track of tempHead
    if (tempHead->data > data)
    {
      tempHead = tempHead->left;
    }
    else
    {
      tempHead = tempHead->right;
    }
  }
  if (prev->data > data)
  {
    prev->left = newNode;
  }
  else
  {
    prev->right = newNode;
  }
}
void findMinMax()
{
  Node *temp1 = head;
  Node *temp2 = head;

  int min = 0;
  int max = 0;
  if (temp1 == NULL)
  {
    cout << "Tree is empty\n";
  }
  else
  {
    while (temp1->left != NULL)
    {
      temp1 = temp1->left;
    }
    min = temp1->data;

    while (temp2->right != NULL)
    {
      temp2 = temp2->right;
    }
    max = temp2->data;
    cout << "The minimum number in tree is " << min << "\n";
    cout << "The maximum number in tree is " << max << "\n";
  }
}

bool searchNumber(int number, Node *root)
{
  if (root == NULL)
  {
    return false;
  }
  else if (root->data == number)
  {
    return true;
  }
  else if (number <= root->data)
  {
    searchNumber(number, root->left);
  }
  else
  {
    searchNumber(number, root->right);
  }
}
int getHeight(Node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  int heightOfLeft = getHeight(root->left);
  int heightOfRight = getHeight(root->right);
  return max(heightOfLeft, heightOfRight) + 1;
}