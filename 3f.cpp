#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

vector<vector <int> > rotate(const vector<vector <int> >& a){
  int m = a.size();
  int n = a[0].size();

  vector<vector <int> > tmp(n, vector<int>(m, 0));
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      tmp[i][j] = a[n-j-1][i];
  return tmp;
}

int main() {
  int n = 3, k = 0;
  vector<vector <int > > a(n, vector<int> (n, 0));
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) a[i][j] = ++k;
  vector<vector <int> > res = rotate(a);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++) cout << res[i][j] << " ";
    cout << endl;
  }

}
