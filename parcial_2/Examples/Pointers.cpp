////
////  Pointers.cpp
////  PlayGround
////
////  Created by Angel Brambila on 3/28/19.
////  Copyright © 2019 Angel Brambila. All rights reserved.
//
//#include <iostream>
//using namespace std;
//
//void pointersBasics();
//int square1 (int);
//void square2 (int *);
//void square3 (int &);
//
//int main()
//{
//     //Basics
////    pointersBasics();
//
////    //Pass Parameters
////    //Call-by-Value
////    int n1=8;
////    cout << "address of n1 in main(): " << &n1 << endl;
////    cout << "Square of n1: " << square1(n1) << endl;
////    cout << "No change in n1: " << n1 << endl;
//
//    //Call-by-Reference with Pointer Arguments
//    int n2=8;
//    cout << "address of n2 in main(): " << &n2 << endl;
//    square2(&n2);
//    cout << "Square of n2: " << n2 << endl;
//    cout << "Change reflected in n2: " << n2 << endl;
//
//    //Call-by-Reference with Reference Arguments
//    int n3=8;
//    cout << "address of n3 in main(): " << &n3 << endl;
//    square3(n3);
//    cout << "Square of n3: " << n3 << endl;
//    cout << "Change reflected in n3: " << n3 << endl;
//
//    return 0;
//}
//
//void pointersBasics()
//{
//    int var = 50;
//    int *ptr; // Declaration of Pointer
//
//    //NOTE data type of var and ptr must be THE SAME
//    // Assigning the addres of variables to a pointer
//    ptr = &var;
////
//    cout << "Value at ptr: " << ptr << endl;
//    cout << "Value at var: " << var << endl;
//    cout << "Value at *ptr: " << *ptr << endl;
//}
//
//// There are 3 ways to pass arguments in C++
//// Value
//int square1(int n)
//{
//    //Address of n in square1() is not the same as n1 in main()
//    cout << "address of n1 in square1(): " << &n << endl;
//
//    // clone modified inside the function
//    n *= n;
//    return n;
//}
//
////Pass-by-Reference with Pointer Arguments
//void square2(int *n)
//{
//    //Address of n in square2() is the same as n2 in main()
//    cout << "address of n2 in square2(): " << n << endl;
//
//    // Explicit de-referencing to get the value pointed-to
//    *n *= *n;
//}
//
////Pass-by-Reference with Reference Arguments
//void square3(int &n)
//{
//    //Address of n in square3() is the same as n3 in main()
//    cout << "address of n3 in square3(): " << &n << endl;
//
//    // Implicit de-referencing (without '*')
//    n *= n;
//}
