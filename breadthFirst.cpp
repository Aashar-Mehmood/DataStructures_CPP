#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;
struct Node
{
  int data;
  Node *left;
  Node *right;
};
void breadthFirst(Node *root);
int main()
{

  return 0;
}
void breadthFirst(Node *root)
{

  if (root == NULL) return;
  else
  {
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
      Node *current = Q.front();
      cout << current->data << "\t";
      if (current->left != NULL)
      {
        Q.push(current->left);
      }
      if (current->right != NULL)
      {
        Q.push(current->right);
      }
      Q.pop();
    }
  }
}
