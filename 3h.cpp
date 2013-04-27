#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;


struct Node {
  int value;
  Node *next;
  Node(int v) {
    value = v;
    next = 0;
  }
};


Node* reverse_linkedlist(Node *head) {
  if (head == 0) return 0;
  Node* prev = 0;
  while (head != 0) {
    Node *next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }
  return prev;
}

void print_out(Node* nd) {
  while(nd != 0) {
    cout << nd->value << " ";
    nd = nd->next;
  }
  cout << endl;
}

int main() {
  Node* m1 = new Node(1);
  Node* m2 = new Node(2);
  Node* m3 = new Node(3);
  Node* m4 = new Node(4);
  m1->next = m2;
  m2->next = m3;
  m3->next = m4;
  Node* res = reverse_linkedlist(m1);

  print_out(res);
  return 0;
}
