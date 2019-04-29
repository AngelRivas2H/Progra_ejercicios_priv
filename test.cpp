#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cstring>

using namespace std;

int main(){
 ifstream file;; //opening text file
 int count=0;
 char ch[20],c[20];
 file.open("test.txt");

 cout<<"Palabra a buscar: ";
 cin >> c;

 while(file){
  file>>ch;
  if(strcmp(ch,c)==0)
   count++;
 }
 cout<<"La palabra sale: "<<count<<" veces.";
 file.close(); //closing file

 return 0;

}
