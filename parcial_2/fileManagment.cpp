#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
  // ofstream fout;
  // string line;
  //
  // // fout.open("Test.txt", ios::app);
  // fout.open("Test.txt");
  //
  // while (fout) {
  //   getline(cin, line);
  //   if (line == "-1"){
  //     break;
  //   }
  //   fout << line << endl;
  // }
  //
  // fout.close();





  fstream fio;
  string line;

  fio.open("Test.txt", ios::trunc | ios::out | ios::in);

  while (fio) {
    getline(cin, line);
    if (line == "-1") {
      break;
    }
    fio << line << endl;
  }

  fio.seekg(0, ios::beg);

  while (fio) {
    getline(fio, line);
    cout << line << endl;
  }

  fio.close();

  return 0;
}
