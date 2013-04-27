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
/*
 function partition(list, left, right, pivotIndex)
     pivotValue := list[pivotIndex]
     swap list[pivotIndex] and list[right]  // Move pivot to end
     storeIndex := left
     for i from left to right-1
         if list[i] < pivotValue
             swap list[storeIndex] and list[i]
             increment storeIndex
     swap list[right] and list[storeIndex]  // Move pivot to its final place
     return storeIndex
*/

int partition(int *a, int l, int r, int pivotIndex) {
  int pivotValue = a[pivotIndex];
  swap(a[pivotIndex], a[r]);
  int idx = l;
  for(int i = l; i < r; i++)
    if (a[i] < pivotValue) swap(a[i], a[idx++]);
  swap(a[r], a[idx]);
  return idx;
}

void select(int *a, int l, int r, int K) {
  if (l == r) {
    cout << a[l] << endl;
    return;
  }
  int idx = partition(a, l, r, (l+r)/2);
  int pivotDist = idx - l + 1;
  if (pivotDist > K)
    select(a, l, idx, K);
  else {
    for(int i = l; i <= idx; i++) cout << a[i] << endl;
    if (pivotDist < K)
      select(a, idx + 1, r, K - pivotDist);
  }
}

void select(int *a, int n, int K) {
  select(a, 0, n - 1, K);
}
int main() {
  int a[] = {2,1,6,7,4,5,7,8};
  select(a, 8, 1);
}
