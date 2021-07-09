#include <iostream>
#include <cstdlib>
using namespace std;
struct Node
{
  int data;
  Node *left;
  Node *right;
};

Node *insertNode(int number, Node *root);
Node *removeNode(int number, Node *root);
bool searchNumber(int number, Node *root);
void printAll(Node *root);
Node *findMin(Node *root);

int main()
{
  Node *root = NULL;
  int choice = 0;
  Node *temp = root;

  do
  {
    int number = 0;

    cout << "\nEnter 1 to add element\n"
         << "Enter 2 to remove element\n"
         << "Enter 3 to search element\n"
         << "Enter 4 to print elements\n";
    cin >> choice;
    switch (choice)
    {
    case 0:
      exit(0);
      break;
    case 1:
    {
      int count = 0;
      cout << "\n How many numbers ? ";
      cin >> count;
      for (int i = 0; i < count; i++)
      {
        cout << "\nEnter the number you want to insert : ";
        cin >> number;
        temp = insertNode(number, temp);
        cout << "\n";
      }
    }
    break;
    case 2:
    {
      int number = 0;
      cout << "\nEnter the number you want to remove : ";
      cin >> number;
      temp = removeNode(number, temp);
    }
    break;
    case 3:
    {
      int number = 0;
      cout << "\nEnter the number you want to search : ";
      cin >> number;
      bool result = searchNumber(number, temp);
      if (result)
        cout << "\n Number is present\n";
      else
        cout << "\n Number not found\n";
      break;
    }
    case 4:
    {
      printAll(temp);
    }
    break;
    default:
      cout << "\nInvalid choice ! Enter a valid number\n";
    }
  } while (choice != 0);
}

Node *insertNode(int number, Node *root)
{
  Node *newNode = new Node;
  newNode->data = number;
  if (root == NULL)
  {
    newNode->left = newNode->right = NULL;
    root = newNode;
  }
  else if (number <= root->data)
  {
    root->left = insertNode(number, root->left);
  }
  else
  {
    root->right = insertNode(number, root->right);
  }
  return root;
}

Node *removeNode(int number, Node *root)
{
  if (root == NULL)
  {
    return root;
  }
  else if (number > root->data)
  {
    root->right = removeNode(number, root->right);
  }
  else if (number < root->data)
  {
    root->left = removeNode(number, root->left);
  }
  else
  {
    if (root->left == NULL && root->right == NULL)
    {
      delete root;
      root = NULL;
    }
    else if (root->left = NULL)
    {
      Node *temp = root;
      root = root->right;
      delete temp;
    }
    else if (root->right = NULL)
    {
      Node *temp = root;
      root = root->left;
      delete temp;
    }
    else
    {
      Node *temp = findMin(root->right);
      root->data = temp->data;
      root->right = removeNode(temp->data, root->right);
    }
  }
  return root;
}

Node *findMin(Node *root)
{
  while (root->left != NULL)
  {
    root = root->left;
  }
  return root;
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

void printAll(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  else
  {
    printAll(root->left);
    cout << root->data << "\t";
    printAll(root->right);
  }
}
