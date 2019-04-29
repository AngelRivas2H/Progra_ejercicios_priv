#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <assert.h>

using namespace std;

int main() {
  string str;
  int pivote;
  char temp;
  int i, j;
  cout << "Please enter a  word: ";
  cin >> str;
  char p[str.length()];
  for (i = 0; i < sizeof(p); i++) {
    p[i] = str[i];
    cout << p[i];
  }
  for (i = 0; i < str.size(); i++) {
    pivote = i;
    for (j = i + 1; j < str.size(); j++) {
      if (str[j] < str[pivote]) {
        pivote = j;
      }
    }
    temp = str[pivote];
    str[pivote] = str[i];
    str[i] = temp;
  }
  do {
    cout << str << endl;
  } while (next_permutation(str.begin(), str.end()));
  return 0;
}
