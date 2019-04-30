// #include <cstdlib>
// #include <iostream>
// #include <vector>
//
// using namespace std;
//
// int main(int argc, char *argv[])
// {
//     vector<char> v;
//
//     for (int x = 'A'; x <= 'Z'; x++)
//         v.push_back(x);
//
//     // obtenemos un iterator del tipo char
//     vector<char>::iterator it;
//
//     // lectura y despliegue de datos
//     cout << "\ndesplegando datos" << endl;
//     for( it = v.begin(); it != v.end(); it++ )
//         cout << *it << endl;
//
//     // system("PAUSE");
//     return EXIT_SUCCESS;
// }

#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector< vector<int> > &matrix);

void printMatrix(vector< vector<int> > &matrix){
  cout << "Dentro de la funcion " << endl;
  cout << "number of rows in vector " << matrix.size() << endl;
  cout << "number of columns in vector " << matrix[0].size() << endl;
}

int main()
{
    vector< vector<int> > g1;
    vector<int> expander;

// for (size_t i = 0; i < 10; i++) {
  /* code */
  cout << "incrementa" << endl;
  g1.push_back(expander); // incrementa las columnas
// }
    // g1.at(3).push_back(expander);
    // g1.push_back(expander);
    for (int i = 0; i < 8; i++)
      g1.resize(i+1); //incrementa los rows

    g1.at(0).push_back(111);
    g1.at(0).push_back(222);
    g1.at(0).push_back(333);
    g1.at(0).push_back(444);
    //GRACIAS A QUE SE HACE UN PUSH_BACK EN EL MISMO ROW (0) SE HACEN MAS COLUMNAS DE MANERA AUTOMATICA
    g1.at(1).push_back(666);
    g1.at(1).push_back(666);
    g1.at(1).push_back(666);
    g1.at(2).push_back(777);
    cout << "Fuera de la funcion; " << endl;
    cout << "number of rows in vector " << g1.size() << endl;
    cout << "number of columns in vector " << g1[1].size() << endl;
    printMatrix(g1);

    return 0;
}
