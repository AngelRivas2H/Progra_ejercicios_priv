#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;


int main(){
  fstream Files;
  Files.open("Files.txt", ios::app | ios::out | ios::in);
  // Files.open("Files.txt");
  string words;
  string lines;
  while (Files.is_open()){
    getline(cin, words);
    if(words=="cerrar"){
      break;
    }
    Files << words << endl;
  }

  Files.seekg(0, ios::beg);

  while (Files) {

        // Read a Line from File
        getline(Files, lines);

        // Print line in Console
        cout << lines << endl;
    }
  Files.close();


}
