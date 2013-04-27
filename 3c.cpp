/*
# 3b find k min numbers of n given numbers. this can be solved by selection algorithm.
# first solution:
# basically, partition the array into 2 parts (first part elems less than equal to elems of second parts ),
# if the # of elems of first part less than K, then go on the small problem (first part)
# otherwise print out all elems of first part, then work on the second part with another K = K - # of second parts
# the average complexity is O(n)
#
# second solution:
# another solution is use a max heap with capacity k.
# Iterate all elements of the array. If size of heap less K, just add to the max heap else compare the top elem with the
# the current element, if greater then remove that top elem and add the current element. the complexity is O(nlogk)
*/
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

int isloop(Node* head) {
  Node *p1 = head;
  Node *p2 = head;
  do {
    if (p1 == 0) return 0;
    p1 = p1->next;
    if (p2 == 0) return 0;
    p2 = p2->next;
    if (p2 == 0) return 0;
    p2 = p2->next;
  } while(p1 != p2);
  return 1;
}

int main() {
  Node *head = new Node(1);
  Node *cur = head;
  Node *tmp = new Node(2); cur->next = tmp; cur = cur->next;
  Node *second = tmp;
  tmp = new Node(3); cur->next = tmp; cur = cur->next;
  tmp = new Node(4); cur->next = tmp; cur = cur->next;
  cur->next = second;
  cout << isloop(head) << endl;
}
