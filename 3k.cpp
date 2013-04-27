#include <cstdio>
#include <iostream>
#include <queue>
#include <cctype>

using namespace std;


void my_reverse(char *head, char* tail) {
  while(head < tail)
    swap(*head++, *tail--);
}

void reverse_sentence(char *str) {
  int len = strlen(str);
  int first = -1, last;
  for(int i = 0; i < len; i++)
    if (isalpha(str[i])) {
      if (first == -1) first = i;
      last = i;
    } else {
      if (first >= 0) my_reverse(str + first, str + last);
      first = -1;
    }
  if (first >= 0) my_reverse(str + first, str + last);
}

int main() {
  char str[100];
  strcpy(str, "The quick brown fox jumped over lazy old dog.");
  cout << str << endl;
  reverse_sentence(str);
  cout << str << endl;
  cout << "ehT kciuk nworb xof depmuj revo yzal dlo god." << endl;
  return 0;
}
