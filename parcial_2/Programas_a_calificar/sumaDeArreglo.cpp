#include <iostream>

using namespace std;

int main(){
  int sum[10], i, res;

  for (i = 0; i <= 9; i++) {
    cout << "Valor del elemento: " << i+1 << ": ";
    cin >> sum[i];
    res += sum[i];
  }
  cout << "Suma de los elementos del array: "<< res << endl;
}
