//g++ ../tests/terminal_arrow_key_test2.cpp ../src/unix_specific.cpp -o test2.out

#include <iostream>
#include <termios.h>

#include "../src/unix_specific.hpp"

#define STDIN_FILENO 0
using namespace std;
int main()
{
// Once the buffering is turned off, the rest is simple.
    cout << "Enter a character: ";
    char c,d,e;
    c = unix_specific::getche();
    cout << int(c) << endl;
    d = unix_specific::getche();
    cout << int(d) << endl;
    e = unix_specific::getche();
    cout << int(e) << endl;
    
    cout << "\nYour character was ";
// Using 3 char type, Cause up down right left consist with 3 character
    if ((c==27)&&(d=91)) {
        if (e==65) { cout << "UP";}
        if (e==66) { cout << "DOWN";}
        if (e==67) { cout << "RIGHT";}
        if (e==68) { cout << "LEFT";}
    }
    return 0;
}