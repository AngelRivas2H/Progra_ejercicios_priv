#include <iostream>

using namespace std;
int funcion();

int main(){
  int arreglo[10];
  int i, suma = 0;

  for (i = 0; i <= 9; i++) {
    cout << "Introduce el valor del arreglo en la posicion numero " << i+1 << " : ";
    cin >> arreglo[i];
    suma+=arreglo[i];
  }
  cout << "Valor de la suma de los items del arreglo: " << suma;
}

int funcion (){
	
}