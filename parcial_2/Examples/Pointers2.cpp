////
////  Pointers2.cpp
////  PlayGround
////
////  Created by Angel Brambila on 3/28/19.
////  Copyright © 2019 Angel Brambila. All rights reserved.
////
//
//#include <iostream>
//using namespace std;
//
//void ptrWithFor(int *);
//int * createArray(int);
//
//int main()
//{
//    //Declare an array
//    int val[3] = { 5, 10, 20 };
//
//    //declare pointer variable
//    int *ptr;
//
//    //Assign the address of val[0] to ptr
//    // We can use ptr=&val[0];(both are same)
//    ptr = val ;
//
////    cout << "Elements of the array are: " << endl;
////    cout << ptr[0] << " " << ptr[1] << " " << ptr[2] << endl;
////    cout << &ptr[0] << " " << &ptr[1] << " " << &ptr[2] << endl;
////
////    ptrWithFor(ptr);
//    int *pt = createArray(5);
//    ptrWithFor(pt);
//    return 0;
//}
//
//void ptrWithFor(int * ptr)
//{
//
//    for (int i = 0; i < 5; i++)
//    {
//        cout << "Value at ptr = " << ptr << "\n";
//        cout << "Value at *ptr = " << *ptr << "\n";
//
//        // Increment pointer ptr by 1
//        ptr++;
//    }
//}
//
//int * createArray(int n)
//{
//    //Create Array
//        int* arr = (int*)(malloc(n * sizeof(int)));
//        return arr;
//}
