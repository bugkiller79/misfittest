#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
  Node* parent;
  Node* left, *right;
  char value;
  Node(int v) {
    value = v;
    left = right = parent = 0;
  }
};

void print_nodes(Node *prev, Node *cur, int diff) {
  if (cur == 0) return;
  if (diff == 0) {
    cout << cur->value << endl;
    return;
  }
  if (prev != cur->left) print_nodes(cur, cur->left, diff - 1);
  if (prev != cur->right) print_nodes(cur, cur->right, diff - 1);
  if (prev != cur->parent) print_nodes(cur, cur->parent, diff - 1);
}

int main() {
  Node* a = new Node('a');
  Node* b = new Node('b');
  Node* c = new Node('c');
  Node* f = new Node('f');
  Node* z = new Node('z');
  a->left = b; b->parent = a;
  a->right = c; c->parent = a;
  c->left = f; f->parent = c;
  c->right= z; z->parent = c;
  print_nodes(0, b, 2);
  print_nodes(0, c, 2);
  print_nodes(0, c, 1);

  return 0;
}
