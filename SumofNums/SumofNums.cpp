// Write a program to count the sum of numbers in a string.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int sum {0};
    string target;
    getline(cin,target);
    vector <int> numbers(target.size());
    for(int i {0};i<target.size();i++)
    {
        if (target.at(i)>='0' && target.at(i)<='9')
            numbers.at(i)=target.at(i)-48;
    }
    for(int j {0};j<numbers.size();j++)
        sum+=numbers.at(j);
    cout<<sum<<endl;
    return 0;
}