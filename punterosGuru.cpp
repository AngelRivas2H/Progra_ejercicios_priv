#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){

  /*
  *
  * El ampersand (&) nos sirve para obtener una direccion de memoria de una variable cualquiera.
  * El asterisco (*) nos permite, que, si el valor de dicho apuntador corresponde a una direccion de memoria con un valor, podemos acceder a el.
  *
  */


  // PUNTEROS 1
  int x = 5, y = 10;
  int *ip; //ip es un puntero a un int
  ip = &x; // ip apunta a x
  y = *ip; // a la variable y se le asigna lo apuntado por ip
  *ip = *ip + 3; // incrementa lo apuntado por ip, es decir, x
  cout << y << endl; // "5"
  ip = NULL;

  // PUNTEROS 2
  char *apuntador = NULL; // declaramos un puntero con NULL, facil para detectar errores.
  char letra; // se declara un char de manera primitiva
  apuntador = &letra; //asignamos al apuntador la direccion de memoria de char letra
  *apuntador = 'x'; // modificamos "letra" a travez del apuntador
  cout << letra << endl;




}
