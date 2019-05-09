#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int dado();

using namespace std;

int main(){
  int i, valor, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0;
  for (i = 0; i < 6001; i++) {
    /* code */
    valor = dado();
    // cout << valor << endl;
    switch (valor) {
      case 1:
        c1++;
      break;
      case 2:
        c2++;
      break;
      case 3:
        c3++;
      break;
      case 4:
        c4++;
      break;
      case 5:
        c5++;
      break;
      case 6:
        c6++;
      break;
      default:
        cout << "Valor no valido" << endl;
    }
  }
  cout << "El dado cayó " << c1 << " veces en 1." << endl;
  cout << "El dado cayó " << c2 << " veces en 2." << endl;
  cout << "El dado cayó " << c3 << " veces en 3." << endl;
  cout << "El dado cayó " << c4 << " veces en 4." << endl;
  cout << "El dado cayó " << c5 << " veces en 5." << endl;
  cout << "El dado cayó " << c6 << " veces en 6." << endl;
}



int dado(){
  int valorDado;
  usleep(1000);
  srand(time(0));

  valorDado = (rand()%6)+1;

  return valorDado;
}
