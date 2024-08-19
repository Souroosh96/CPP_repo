/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 *  Reversing_Array.c
 *
 *  Created on: August 18, 2024
 *  Author: Souroosh Memarian
 *////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Write a program that reverse an array using pointers.
#include <iostream>
#include <string>

using namespace std;

void reverse_array(int* arr, int size) {
    for (int i{0}; i < size/2 ;i++)
    {
        *(arr+i) += *(arr+size-i-1);
        *(arr+size-i-1) = *(arr+i) - *(arr+size-i-1);
        *(arr+i) -= *(arr+size-i-1);
    }
    cout <<"\n"<<"[";
    for (int i{0}; i < size ; ++i ){
         cout << *(arr + i);
         if(i == size -1)
            cout <<"]";
         else
            cout <<'\t';
        }      
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    reverse_array(arr, size);
    return 0;
}