#include <iostream>

using namespace std;

int main(){
  int x1 = 0, x2 = 0, y1 = 0, y2 = 0, i = 0, j = 0;
  int Mx1 = 0, Mx2 = 0, My1 = 0, My2 = 0;
  cout << "Suma de matrices..." << endl;
  cout << "Selecciona las dimenciones de tu matriz uno: \n\tX: ";
  cin >> x1;
  cout << "\ty: ";
  cin >> y1;
  // int matriz1[x1][y1];
  cout << "Slecciona las dimenciones de tu matriz dos: \n\tX: ";
  cin >> x2;
  cout << "\ty: ";
  cin >> y2;
  // int matriz2[x2][y2];

  int matriz1[x1][y1];
  int matriz2[x2][y2];
  cout << "Rellena tu matriz uno: " << endl;
  for (i = 0; i <= (x1-1); i++) {
    for (j = 0; j <= (y1-1); j++) {
      cout << "Rellena la posicion x: " << i+1 << " y: " << j+1 << ": ";
      cin >> matriz1[i][j];
    }
  }

  // cout << "Rellena tu matriz dos: " << endl;
  // for (i = 0; i <= (x2-1); i++) {
  //   for (j = 0; j <= (y2-1); j++) {
  //     cout << "Rellena la posicion x: " << i+1 << " y: " << j+1 << ": ";
  //     cin >> matriz2[i][j];
  //   }
  // }

  if (x1 > x2 && y1 > y2) {

    int matriz3[x1][y1];
    cout << "x1: " << x1 << " y1: " << y1 << endl;
    // ESTO RELLENA LA NUEVA MATRIZ CON 0's
    for (i = 0; i <= (x1); i++) {
      for (j = 0; j <= (y1); j++) {
        matriz3[i][j] = 0;
      }
    }
    cout << "Rellena tu matriz dos: " << endl;
    for (i = 0; i <= (x2-1); i++) {
      for (j = 0; j <= (y2-1); j++) {
        cout << "Rellena la posicion x: " << i+1 << " y: " << j+1 << ": ";
        cin >> matriz3[i][j];
      }
    }
    /* ESTO MUESTRA LAS MATRICES 1 Y 2(3) */
    for (i = 0; i <= (x1-1); i++) {
      for (j = 0; j <= (y1-1); j++) {
        cout << "\n" << matriz3[i][j] << "\t ";
      }
    }
    for (i = 0; i <= (x1-1); i++) {
      for (j = 0; j <= (y1-1); j++) {
        cout << "\n" << matriz1[i][j] << "\t ";
      }
    }
    
  }else if (x1 < x2 && y1 < y2) {
    int matriz3[x2][y2];
    cout << "x2: " << x2 << " y2: " << y2 << endl;
  }else if (x1 < x2 && y1 > y2) {
    int matriz3[x2][y1];
    cout << "x2: " << x2 << " y1: " << y1 << endl;
  }else if (x1 > x2 && y1 < y2) {
    int matriz3[x1][y2];
    cout << "x1: " << x1 << " y2: " << y2 << endl;
  }

}
