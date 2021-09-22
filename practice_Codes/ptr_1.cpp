#include <iostream>
using namespace std;

int main()
{
    // pointer review
    int x = 25;
    // int  *ptr;
    // ptr = &x;
    int *ptr = &x;


    // address of x
    cout << &x << endl;

    // address of x 
    cout << ptr << endl;
    
    // prints out the values of 25 where its store in the address  
    cout << *ptr << endl;

    // address of ptr 
    cout << &ptr << endl;

    return 0;
}