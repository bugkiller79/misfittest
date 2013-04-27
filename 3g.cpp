#include <iostream>
#include <algorithm>

using namespace std;

void firstK(int *a, int n, int *b, int m, int K) {
  if(m+n < K) {
    cout << "wrong input";
    return;
  }
  int ia = 0, ib = 0;
  while (K && ia < n && ib < m) {
    if (a[ia] < b[ib]) cout << a[ia++] << endl;
    else cout << b[ib++] << endl;
    K--;
  }
  while (K && ia < n) cout << a[ia++] << endl;
  while (K && ib < m) cout << b[ib++] << endl;
}

int main() {
  int a[] = {130,142,143,153,154,155,166};
  int b[] = {130,142,143,153,154,155,166,177};
  firstK(a, 7, b, 8, 4);
}
