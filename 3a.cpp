#include <cstdio>
#include <iostream>

using namespace std;

void combinations(int id, int *a, int maxNumber) {
  if (id == maxNumber) {
    for(int i = 0; i < maxNumber; i++) cout << a[i] << " ";
    cout<<endl;
    return;
  }
  for(int j = id; j < maxNumber; j++) {
    swap(a[id], a[j]);
    combinations(id + 1, a, maxNumber);
    swap(a[id], a[j]);
  }
}
void combinations(int maxNumber) {
  int a[maxNumber];
  for(int i = 0; i < maxNumber; i++)
    a[i] = i + 1;
  combinations(0, a, maxNumber);
}

int main() {
  combinations(2);
}
