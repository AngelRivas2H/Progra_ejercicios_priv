#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <cctype>
using namespace std;
int main(){

  /*
  *
  * Letras mayusculas por linea,  done
  * a's minisculas por linea.     done
  * ! por linea.                  done
  * Letras por linea.             done
  * Espacios por linea.           done
  *
  * Ejemplo:
  *
  * La línea 1 contiene 1 letra mayúscula, 12 a’s, 0 ! , 62 letras, 16 espacios.
  *
  */
  int contCapital = 0, contLowerA = 0, contWarn = 0, contLet = 0 , contSpaces = 0, i = 0, j;
  fstream archivo;
  string line;
  int lineCount;
  char lineaArchivo[20], lineaBusqueda[20];
  char acentoA = 'á';
  char acentoE = 'é';
  char acentoI = 'í';
  char acentoO = 'ó';
  char acentoU = 'ú';
  archivo.open("TipoB.txt");
  if (archivo.is_open()) { // se verifica que el archivo este abierto
    while (getline(archivo, line)) { //mientras haya una linea en al archivo se sigue el bucle
      char convertido[line.size()+1]; // creacion del char en funcion del tamaño del string
      strcpy(convertido, line.c_str()); //conversion de string a char
      // Reinicio de las variables
      contCapital = 0;
      contLowerA = 0;
      contWarn = 0;
      contLet = 0;
      contSpaces = 0;
      lineCount++;
      for (i = 0; i <= sizeof(convertido)-1; i++) {
        // cout << convertido[i]; //impresion del archivo caracter por caracter
        // cout << "ascii test: " << "opci\u00E1n" << endl; // á
        // cout << "ascii test: " << "opci\u00E9n" << endl; // é
        // cout << "ascii test: " << "opci\u00EDn" << endl; // í
        // cout << "ascii test: " << "opci\u00F3n" << endl; // ó
        // cout << "ascii test: " << "opci\u00FAn" << endl; // ú
        if (convertido[i] == 'a') { //conteo de letas a
          contLowerA++;
        }
        if(isalpha(convertido[i]) || convertido[i] == acentoA || convertido[i] == acentoE || convertido[i] == acentoI || convertido[i] == acentoO || convertido[i] == acentoU) {
          contLet++;
        }
        if(isspace(convertido[i])){ // conteo de espacios
          contSpaces++;
        }
        if(convertido[i] == 33){ // conteo de signos de admiracion
          contWarn++;
        }
        if (isupper(convertido[i])) { //conteo de mayusculas
          contCapital++;
        }
      }
      cout << "La linea " << lineCount << " contiene " << contLowerA << " letras mayúscula, " << contLowerA << " a's, " << contWarn << " ! ," << contLet << " letras, " << contSpaces << " espacios.\n\n";
    }
  }
  archivo.close(); // se cierra el archivo
}
