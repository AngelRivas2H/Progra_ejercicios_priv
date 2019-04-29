#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sstream>
#include <cstring>

using namespace std;


void mostrarCartasActuales(string [][3], int);

string cartaAleatoria(string [][2]);

int jugadores();

void resetTime();

int calcularValor(string);

int calcularValor(string carta){
  char cstr[carta.size() + 1];
  strcpy(cstr, carta.c_str());
  int valor = 999, i = 0;
  char posiblesValores[10] = "AJQK";
  for (i = 0; i < sizeof(posiblesValores)-1; i++) {
    if (strcmp(&posiblesValores[strlen(posiblesValores)-i], cstr) == 0) {
      valor = 10;
    }
  }
  return valor;
}

int jugadores(){
  int noJugadores;
  do {
    cout << "Elije la cantidad de jugadores (4-7): ";
    cin >> noJugadores;
  } while(!(noJugadores >= 4 && noJugadores <= 7)); //fin de la seleccion de cantidad de jugadores
  return noJugadores;
}

void resetTime(){
  usleep(1000000/2);
  srand(time(0));
}

// string cartaAleatoria(string cartas[][2]){
//   resetTime();
//   int x = (rand()%52) + 1;
//   int y = (rand() % 52) + 1;
//   stringstream ss;
//   string respuesta;
//   if (x <= 12) {
//     resetTime();
//     ss << cartas[x][1] << " de " << cartas[y][0];
//   }else if(x <= 25 && x >= 13){
//     resetTime();
//     ss << cartas[x][1] << " de " << cartas[y][0];
//   }else if(x <= 38 && x >= 26){
//     resetTime();
//     ss << cartas[x][1] << " de " << cartas[y][0];
//   }else if(x <= 51 && x >= 39){
//     resetTime();
//     ss << cartas[x][1] << " de " << cartas[y][0];
//   }
//   respuesta = ss.str();
//   return (respuesta);
// }

string cartaAleatoria(string cartas[][2]){
  resetTime();
  int x = (rand()%52) + 1;
  int y = (rand() % 52) + 1;
  stringstream ss;
  string respuesta;
  if (x <= 12) {
    resetTime();
    ss << cartas[x][1] << " de " << cartas[y][0];
  }else if(x <= 25 && x >= 13){
    resetTime();
    ss << cartas[x][1] << " de " << cartas[y][0];
  }else if(x <= 38 && x >= 26){
    resetTime();
    ss << cartas[x][1] << " de " << cartas[y][0];
  }else if(x <= 51 && x >= 39){
    resetTime();
    ss << cartas[x][1] << " de " << cartas[y][0];
  }
  respuesta = ss.str();
  return respuesta;
}

void mostrarCartasActuales(string arreglo[][3], int numero){
  int i = 0;
  for (i = 0; i <= numero ; i++) {
    cout << "Cartas del jugador " << i+1 << "\n Carta 1: " << arreglo[i][1] << "\n Carta 2: " << arreglo[i][2] <<endl;
  }
}

/*
Reglas para asignamiento de valores en la tabla:

     Corazones siempre color rojo.(del 0 al 12)
      Diamantes siempre color rojo. (del 13 al 25)

      Trebol siempre color negro.(del 26 al 38)
      Picas siempre color negro.(del 39 al 51)

      Orden de valor:
       A, 2, 3, 4 , 5, 6, 7, 8, 9, 10, J, Q y K

      Valores de las cartas en black jack:
        A = 1 o 11
        J, Q y K = 10
        El resto de cartas posee su valor natural.
*/


int main(){
  //variables contadores
  int i,j = 0;
  int valorCarta;
  //variables para las cartas
  string baraja[52][2];
  string valCartas[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
  //variables para el funcionamiendo del juego
  int cantJugadores;
  //fin de la declaracion de variables
  //inicio de la creacion de la baraja
  for (i = 0; i <= 51; i++) {
    if (i <= 12) {
      baraja[i][0] = "Corazones";
      baraja[i][1] = valCartas[j];
      j++;
    }else if(i <= 25 && i >= 13){
      i == 13 ? j = 0 : j++;
      baraja[i][0] = "Diamantes";
      baraja[i][1] = valCartas[j];
    }else if(i <= 38 && i >= 26){
      i == 26 ? j = 0 : j++;
      baraja[i][0] = "Treboles";
      baraja[i][1] = valCartas[j];
    }else if(i <= 51 && i >= 39){
      i == 39 ? j = 0 : j++;
      baraja[i][0] = "Picas";
      baraja[i][1] = valCartas[j];
    }
  }// fin de la creacion de la baraja
  cantJugadores = jugadores();
  string jugadores[cantJugadores][3];
  for (i = 0; i <= cantJugadores-1; i++)
        jugadores[i][0] = to_string(i+1);
  for (j = 0; j <= cantJugadores-1; j++) {
    // system("clear");
    cout << "\n\nTurno de jugador " << jugadores[j][0] << endl;
    cout << "Se reparte primera carta..." << "\n";
    jugadores[j][1] = cartaAleatoria(baraja);
    valorCarta  = calcularValor(jugadores[j][1]); // aqui se manda el string con la carta
    cout << "Valor de la carta: " << valorCarta << endl;
    cout << jugadores[j][1];
    cout << "\n\n" ;
    mostrarCartasActuales(jugadores, cantJugadores-1);
  }
  return 0;
}
