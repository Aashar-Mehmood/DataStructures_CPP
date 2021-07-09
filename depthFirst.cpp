#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
};
Node *root = NULL;
void preOrder(Node *root);
void inOrder(Node *root);
void postOrder(Node *root);
int main()
{
  return 0;
}

void preOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  else
  {
    cout << root->data << "\t";
    preOrder(root->left);
    preOrder(root->right);
  }
}

void inOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  else
  {

    inOrder(root->left);
    cout << root->data << "\t";
    inOrder(root->right);
  }
}

void postOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  else
  {
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << "\t";
  }
}