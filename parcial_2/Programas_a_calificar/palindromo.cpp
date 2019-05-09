#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void removeSpaces(char *str);

int main(){
  char cadena[100];
  string noSpaceString;
  int i = 0, j = 0, success = 0, failure = 0;

  cout << "********** Palindrome detector **********\n\n";

  cin.getline(cadena, sizeof(cadena)); //get string with empty spaces
  removeSpaces(cadena);// function that removes white spaces
  noSpaceString = cadena;
  char palindrome[noSpaceString.length()];
  char palindrome_mirror[noSpaceString.length()];
  strcpy(palindrome, noSpaceString.c_str());

  for (i = 0, j=sizeof(palindrome)-1; i <= sizeof(palindrome)-1; i++, j--){
    palindrome_mirror[j] = palindrome[i];
    if (palindrome_mirror[i] == palindrome[i]) {
      success++;
    }else{
      failure++;
    }
  }
  if(success == failure+1){
    cout << "\n\nsi es palindromo" << endl;
  }else{
    cout << "\n\nno es palindromo" << endl;
  }
  cout << "\n\nPalabra original invertida: " <<palindrome_mirror << endl;
  cout << "Palabra original sin invertir: " <<palindrome << endl;
}


void removeSpaces(char *str){
  int count = 0;
  for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i];
    str[count] = '\0';
}
