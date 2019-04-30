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
  archivo.open("TipoB.txt");
  if (archivo.is_open()) { // se verifica que el archivo este abierto
    while (getline(archivo, line)) { //mientras haya una linea en al archivo se sigue el bucle
      char convertido[line.size()+1];
      strcpy(convertido, line.c_str());
      contCapital = 0;
      contLowerA = 0;
      contWarn = 0;
      contLet = 0;
      contSpaces = 0;
      lineCount++;
      for (i = 0; i <= sizeof(convertido)-1; i++) {
        // cout << convertido[i];
        // cout << "ascii test: " << "opci\u00E1n" << endl;
        // cout << "ascii test: " << "opci\u00E9n" << endl;
        // cout << "ascii test: " << "opci\u00EDn" << endl;
        // cout << "ascii test: " << "opci\u00F3n" << endl;
        // cout << "ascii test: " << "opci\u00FAn" << endl;
        if (convertido[i] == 'a') {
          contLowerA++;
        }
        if(isalpha(convertido[i]) || (convertido[i] == '\u00E1' || convertido[i] == '\u00E9' || convertido[i] == '\u00ED' || convertido[i] == '\u00F3' || convertido[i] == '\u00FA')){
          contLet++;
        }
        if(isspace(convertido[i])){
          contSpaces++;
        }
        if(convertido[i] == 33){
          contWarn++;
        }
        if (isupper(convertido[i])) {
          contCapital++;
        }
      }
      cout << "La linea " << lineCount << " contiene " << contLowerA << " letras mayúscula, " << contLowerA << " a's, " << contWarn << " ! ," << contLet << " letras, " << contSpaces << " espacios.\n\n";
    }
    archivo.close();// se cierra el archivo
  }
  archivo.close(); // se cierra el archivo
}
