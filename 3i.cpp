#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int is_permutation(int *a, int na, int *b, int nb) {
  if (na < 0 || na != nb) return 0;
  map<int, int> cnt;
  for(int i = 0; i < na; i++) cnt[a[i]]++;
  for(int j = 0; j < nb; j++) {
    cnt[b[j]]--;
    if (cnt[b[j]] < 0) return 0;
  }
  return 1;
}

int main() {
  int a[] = {1,2,3,4,5};
  int b[] = {3,4,2,5,0};
  cout << is_permutation(a, 5, b, 5) << endl;
}
