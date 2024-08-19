/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 *  SumofDigits.cpp
 *
 *  Created on: August 19, 2024
 *  Author: Souroosh Memarian
 *////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int sum_of_digits(int n) {
    int size = 0;
    int temp = n;
    // Handle the case when n is 0 separately
    if (temp == 0)
        return 0; // 0 has one digit (i.e., 0 itself)

    // Count digits by continuously dividing by 10
    while (temp != 0) {
        temp /= 10;
        size++;
    }
    int p = n/pow(10,size-1);
    return p+sum_of_digits(n- pow(10,size-1)*p);
    //;
    //
}

int main()
{
    int m{0},S{0};
    cin>>m;
    S = sum_of_digits(m);
    cout << S<< endl;

    return 0;

}

