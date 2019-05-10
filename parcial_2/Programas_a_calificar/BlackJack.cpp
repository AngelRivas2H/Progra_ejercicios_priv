#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;


void mostrarCartasActuales(string [][4], int);

string cartaAleatoria(string [][2]);

int jugadores();

void resetTime();

int calcularValor(string);

void calcularPuntuacion(string [][4]);

void printMatrix(vector< vector<string> > &matrix, int);

void printMatrix(vector< vector<string> > &matrix, int numero){
  // cout << "ENTRADA A LA FUNCION PRINT MATRIX" << endl;
  int i, j;
  cout << "EL JUGADOR UNO ES EL DEALER DE LAS CARTAS..." << endl;
  // cout << "numero de rows pasados a la funcion " << matrix.size() << endl;
  // cout << "numero de columnas pasados a la funcion " << matrix[0].size() << endl;
  for (j = 0; j <= numero; j++) {
    cout << "\n\nCartas del jugador " << j+1;
    for (i = 1; i <= (matrix[0].size()); i++) {
      cout << "\n\t Carta " << i << ": "<< matrix[j][i] << endl;
      // cout << "Cartas del jugador " << i+1 << "\n Carta 1: " << arreglo[i][1] << "\n Carta 2: " << arreglo[i][2] << "\n Puntos: " << arreglo[i][3] << endl;
  }
}

// void calcularPuntuacion(string arreglo[][4]){
//   int limite = 21;
//   int valorJuego = stoi(arreglo[][4]);
}

int calcularValor(string carta){
  int valor = 0, i = 0;
  char posiblesValores[10] = "JQK";
  for (i = 0; i <= sizeof(posiblesValores); i++) {
    size_t found = carta.find(posiblesValores[i]);
    if (found != string::npos) {
      valor = 10;
    }else if(carta.find("A") != string::npos){
      valor = 11;
    }else if(carta.find("2") != string::npos){
      valor = 2;
    }else if(carta.find("3") != string::npos){
      valor = 3;
    }else if(carta.find("4") != string::npos){
      valor = 4;
    }else if(carta.find("5") != string::npos){
      valor = 5;
    }else if(carta.find("6") != string::npos){
      valor = 6;
    }else if(carta.find("7") != string::npos){
      valor = 7;
    }else if(carta.find("8") != string::npos){
      valor = 8;
    }else if(carta.find("9") != string::npos){
      valor = 9;
    }else if(carta.find("10") != string::npos){
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

string cartaAleatoria(string cartas[][2]){
  resetTime();
  int x = (rand()%51) + 1;
  int y = (rand() % 51) + 1;
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

void mostrarCartasActuales(string arreglo[][4], int numero){
  int i = 0;
  for (i = 0; i <= numero ; i++) {
    cout << "Cartas del jugador " << i+1 << "\n Carta 1: " << arreglo[i][1] << "\n Carta 2: " << arreglo[i][2] << "\n Puntos: " << arreglo[i][3] << endl;
  }
}
/*
*
* Reglas para asignamiento de valores en la tabla:
*
*   Corazones siempre color rojo.(del 0 al 12)j
*   Diamantes siempre color rojo. (del 13 al 25)
*
*   Trebol siempre color negro.(del 26 al 38)
*   Picas siempre color negro.(del 39 al 51)
*
*   Orden de valor:
*      A, 2, 3, 4 , 5, 6, 7, 8, 9, 10, J, Q y K
*
*/


int main(){
  string respuesta = "s";
  //variables contadores
  int i,j = 0, control = 0;
  int valorCarta = 0;
  stringstream ss;
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
  int contador = 0;
  string controlCarta;
  string jugadores[cantJugadores][4];
  vector<vector<string> > jugadoresDinamico; // ARREGLO DINAMICO
  vector<string> expander; // creador de dos dimensiones
  vector<int> estadoDeJuego;
  vector<int> puntos;
  string JugadorAEliminar;
  jugadoresDinamico.push_back(expander); // Se le agrega el expander para transformarlo en un vector de dos dimensiones
  jugadoresDinamico.resize(cantJugadores);//aqui se incrementa el numero de rows segun la cantidad de iteraciones del for
  for (i = 0; i <= cantJugadores-1; i++){
    puntos.resize(i);
    jugadoresDinamico.at(i).push_back(to_string(i+1));
    estadoDeJuego.push_back(1); // El numero 1 es equivalente a "Jugando", y el 0 a "Perdió"
  }
  cout << "JUGADORES AÑADIDOS: " << jugadoresDinamico.size() << endl;



  cout << "Nota: hay que tomar en cuenta que el jugador numero 1 es el dealer del juego, es decir, que se compite contra el." << endl;
  int estado = 0;
  do{
    contador++;
    cout << "Despues del while" << endl;
    for (j = 0; j <= jugadoresDinamico.size()-1; j++) {
      valorCarta = 0; // se reinicia el valorCarta para no sobreescribir valores
      cout << "Turno del jugador " << jugadoresDinamico[j][0] << endl;
      if (jugadoresDinamico[j][0] == "1") { // SI ES EL TURNO DEL DEALER SOLO SE DA UNA CARTA
        jugadoresDinamico.at(j).push_back(cartaAleatoria(baraja)); //esta es una copia de la linea de abajo
        cout << "Carta repartida esta vez " << jugadoresDinamico.at(j).back() << "\n\n";
        valorCarta  += calcularValor(jugadoresDinamico[j].back()); // aqui se manda el string con la carta para calcular el valor
        // jugadoresDinamico.at(j).push_back(to_string(valorCarta)); //aqui se inserta el valor da las cartas al final del row de jugador
        puntos[j] += (valorCarta);
        cout << "Valor de las cartas adquiridas " << puntos[j] << endl;
      }else{
        if (contador > 1) {
          cout << "Deseas pedir una carta[s/n]: ";
          cin >> controlCarta;
          if (controlCarta == "s") {
            /* PETICION DE LA CARTA CON UNA FUNCION */
            jugadoresDinamico.at(j).push_back(cartaAleatoria(baraja));  //aqui se inserta el string con la carta generada de forma aletoria
            cout << "Carta repartida esta vez " << jugadoresDinamico.at(j).back() << "\n\n"; // display del string de la carta repartida
            valorCarta  += calcularValor(jugadoresDinamico[j].back()); // aqui se manda el string con la carta para calcular el valor
            puntos[j] += (valorCarta);
            cout << "Valor de las cartas adquiridas " << puntos[j] << endl;


            if (puntos[j] == 21) {
              cout << "El jugador " << j+1 << " ganó." << endl;
              break;
            }else if(puntos[j] > 21){
              cout << "El jugador " << j+1 << " perdió el juego." << endl;

              jugadoresDinamico.erase(jugadoresDinamico.begin() + j);



              // break;
            }


          }
        }else{
          // jugadoresDinamico.at(j).push_back(cartaAleatoria(baraja));  //aqui se inserta el string con la carta generada de forma aletoria
          if (contador == 1) {
            jugadoresDinamico.at(j).push_back(cartaAleatoria(baraja));  //aqui se inserta el string con la carta generada de forma aletoria
            cout << "Carta repartida esta vez " << jugadoresDinamico.at(j).back() << "\n\n"; // display del string de la carta repartida
            valorCarta  += calcularValor(jugadoresDinamico[j].back()); // aqui se manda el string con la carta para calcular el valor

            jugadoresDinamico.at(j).push_back(cartaAleatoria(baraja));  //aqui se inserta el string con la carta generada de forma aletoria
            cout << "Carta repartida esta vez " << jugadoresDinamico.at(j).back() << "\n\n"; // display del string de la carta repartida
            valorCarta  += calcularValor(jugadoresDinamico[j].back()); // aqui se manda el string con la carta para calcular el valor

            puntos[j] += (valorCarta);
            cout << "Valor de las cartas adquiridas " << puntos[j] << endl;


            if (puntos[j] == 21) {
              cout << "El jugador " << j+1 << " ganó." << endl;
              break;
            }else if(puntos[j] > 21){
              cout << "El jugador " << j+1 << " perdió el juego." << endl;
              jugadoresDinamico.erase(jugadoresDinamico.begin()+(j));
            }


          }else{
            cout << "Se suman los puntos al total." << endl;
            // juqgadoresDinamico.at(j).push_back(to_string(valorCarta)); // se inserta al final del row del jugador el valor de la carta
          }
        }/* SALIR DEL TURNO DE ESTE JUGADOR */
        // cout << "SALIR DEL TURNO DE ESTE JUGADOR" << endl;
      } // fin de los turnos de los jugadores
      // cout << "fin de los turnos de los jugadores" << endl;
    } // fin del for
    // cout << "fin del for." << endl;
    estado++;
    printMatrix(jugadoresDinamico, jugadoresDinamico.size()-1);
  }while (estado != 5); // fin del while


//   for (j = 0; j <= jugadoresDinamico.size(); j++) {
//     valorCarta = 0;
//     // system("clear");
//     // cout << "Row del arreglo dinamico: " << jugadoresDinamico.size() << endl;
//
//
//      cout << "\n\nTurno de jugador " << jugadoresDinamico[j][0] << endl;
//     // cout << "\n\nTurno de jugador " << jugadores[j][0] << endl;
//
//     // respuesta = "s";
//     // while (respuesta == "s") {
//       jugadoresDinamico.at(j).push_back(cartaAleatoria(baraja)); //esta es una copia de la linea de abajo
//       cout << "Carta repartida esta vez " << jugadoresDinamico.at(j).back() << endl;
//       valorCarta  += calcularValor(jugadoresDinamico[j].back()); // aqui se manda el string con la carta para calcular el valor
//       // cout << "Valor de la carta: " << valorCarta << "\n\n";
//     //   cout << "Desea pedir una carta extra[s/n]: ";
//     //   cin >> respuesta;
//     // }
//
//
//     jugadoresDinamico.at(j).push_back(cartaAleatoria(baraja));
//     cout << "Carta repartida esta vez " << jugadoresDinamico.at(j).back() << endl;
//     // jugadores[j][1] = cartaAleatoria(baraja);
//     valorCarta  += calcularValor(jugadoresDinamico[j].back()); // aqui se manda el string con la carta para calcular el valor
//
//     jugadoresDinamico.at(j).push_back(cartaAleatoria(baraja));
//     cout << "Carta repartida esta vez " << jugadoresDinamico.at(j).back() << endl;
//     // jugadores[j][1] = cartaAleatoria(baraja);
//     valorCarta  += calcularValor(jugadoresDinamico[j].back()); // aqui se manda el string con la carta para calcular el valor
//
//     cout << "Antes del filtro: " <<jugadoresDinamico.size() << endl;
//     jugadoresDinamico.at(j).push_back(to_string(valorCarta)); //esta es una copia de la linea de abajo
//     if (valorCarta == 21) {
//       cout << "\n\nJugador " << jugadoresDinamico[j][0] << "gano el juego."<< endl;
//       break;
//     }else if(valorCarta > 21){
//       cout << "\n\nJugador " << jugadoresDinamico[j][0] << "perdio el juego."<< endl;
//       jugadoresDinamico.erase(jugadoresDinamico.begin()+(j));
//     }
//     cout << "despues del filtro: " <<jugadoresDinamico.size() << endl;
//     // cout << "jugadoresDinamico.begin(): " << jugadoresDinamico.begin() << endl;
//     // jugadores[j][3] = to_string(valorCarta);
// }
    // cout << "Foor loop ended" << endl;
    // // system("clear");
    // printMatrix(jugadoresDinamico, jugadoresDinamico.size());
    // cout << "After function line." << endl;
    /*
    * Estructura del vector multidimensional
    *
    *  jugador 1 | carta 1 | carta 2 | carta n |
    *-------------------------------------------
    *  jugador 2 | carta 1 | carta 2 | carta n |
    *-------------------------------------------
    *  jugador n | carta 1 | carta 2 | carta n |
    *
    *   El .at(n) apunta siempre a row numero n
    *   La manera de incrementar las columnas de manera dinamica es haciendo un push_back en el row que deseas incrementar la columna
    *
    *
    *
    */
  // }
}
