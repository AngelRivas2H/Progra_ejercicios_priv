#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
  ifstream file;
  string line;
// abrimos el archivo de texto con el preset de lectura
  file.open("Test.txt");

  file.seekg(0, ios::beg);

  while (file) {
    getline(file, line);
    cout << line << endl;
  }

  file.close();

  return 0;
}
