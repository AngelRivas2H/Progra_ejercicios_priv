//
//  Pointers3.cpp
//  PlayGround
//
//  Created by Angel Brambila on 3/28/19.
//  Copyright © 2019 Angel Brambila. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

void reverseString(char *);
bool compare ( char * , char *);

int main ()
{
    // Get the string
    char str[100] = "StringTheory1234";
    cout<<"String : " << str << endl;

    // Reverse the string
    reverseString(str);

    // Print the result
    cout << "Reversed String: " << str << endl;

//    char str1[100] = "anitalavalatina";
//    char str2[100] = "anitalavalatina";
//
//    if (compare(str1, str2) == 1)
//        cout << str1 << endl << str2 << endl << "Are Equal" << endl;
//    else
//        cout << str1 << endl << str2 << endl << "Are not Equal" << endl;
    return 0;
}

void reverseString(char * str)
{
    int l, i;
    char *begin_ptr, *end_ptr, ch;

    // Get the length of the string
    l = strlen(str);

    // Set the begin_ptr and end_ptr
    // initially to start of string
    begin_ptr = str;
    end_ptr = str;

    // Move the end_ptr to the last character
    for (i = 0; i < l - 1; i++)
        end_ptr++;

    // Swap the char from start and end
    // index using begin_ptr and end_ptr
    for (i = 0; i < l / 2; i++) {

        // swap character
        ch = *end_ptr;
        *end_ptr = *begin_ptr;
        *begin_ptr = ch;

        // update pointers positions
        begin_ptr++;
        end_ptr--;
    }
}

bool compare(char *str1, char *str2)
{
    while (*str1 == *str2)
    {
        if (*str1 == '\0' && *str2 == '\0')
            return true;
        str1++;
        str2++;
    }

    return false;
}
