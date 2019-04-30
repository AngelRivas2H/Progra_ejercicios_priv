#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main(){
  /*
  *
  * formas de iniciar un fstream:
  *   ifstrean -> lectura de archivos -> ios::in
  *   ofstream -> escritura de archivos -> ios::out
  *   fstream  -> i/o file -> ios::in | ios::out
  *
  *   flags:
  *     ios::app -> Todos los uotput al archivo van al final
  *     ios::ate -> Se abre el archivo para output y el control de lectura y escritra se va al final del mismo
  *     ios::in  -> lectura
  *     ios::out  -> escritura
  *     ios::trunc  -> si ya existe el archivo, borra su contenido antes de abrirlo
  *
  * Public memeber functions:
  *   .open() -> abre el archivo
  *   .is_open() -> verifica que el archivo haya sido correctamente abierto
  *   .close() -> cierra el archivo
  *   .seekg() -> setea la posicion en secuencia de lectura
  *
  * Si se quiere escribir y leer el mismo archivo, se necesita esta linea.
  *   <archivo>.seekg(0, ios::beg);
  */



  // FORMAS DE LEER UN ARCHIVO DE TEXTO
  ifstream file; // se abre archivo para lectura
  file.open("test.txt");
  string line; // se crea una variable donde se va a almacenar las lineas del archivo una por una
  if (file.is_open()) { // se verifica que el archivo este abierto
    while (getline(file, line)) { //mientras haya una linea en al archivo se sigue el bucle
      cout << line << endl; // se imprimen las lineas del archivo
    }
    file.close();// se cierra el archivo
  }


  // FORMA DE ESCRIBIR EN UN ARCHIVO
  ofstream archivo; // se abre archivo para escritura, por defecto se elimina el contenido anterior del archivo
  archivo.open("escritura.txt");
  string linea;
  while (archivo.is_open()) { // se comprueba que el archivo haya sido abierto con exito
    getline(cin, linea); // aqui se captura la entrada de datos del usuario
    if (linea == "-1") { //control del fin de entrada de datos
      break;
    }
    archivo << linea << endl; //se ingresan las lineas al archivo, una por una
  }
  archivo.close();


  //BUSCAR PALABRAS EN UN ARCHIVO
  fstream fichero; // se abre archivo para input y output
  int cont = 0; // contador de coincidencias
  char lineaArchivo[20], lineaBusqueda[20]; //ambos char donde se almacena la busqueda y el archivo mismo
  fichero.open("test.txt"); // se abre el archivo
  cout << "Escribe la palabra que quieres buscar: ";
  cin >> lineaBusqueda; // peticion de palabra a buscar
  while (fichero) { //mientras el archivo este abierto se repite el bucle
    fichero >> lineaArchivo; // se almacenan las lineas del archivo en el char
    if (strcmp(lineaArchivo, lineaBusqueda) == 0) { // se compara la busqueda con la linea del archivo
      cont++; // se incrementa el contador en funcion de las coincidencias dentre la busqueda y el archivo
    }
  }
  cout << "La palabra se repide " << cont-1 << " veces." << endl;
  fichero.close(); // se cierra el archivo
}
