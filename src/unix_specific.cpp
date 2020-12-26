/*
    New File created as part of the refactoring project.
    Declares functions that are used in a unix environment
*/

#include "unix_specific.hpp"

static struct termios old, current;

/* Initialize new terminal i/o settings */
void unix_specific::initTermios(int echo) 
{
    tcgetattr(0, &old); /* grab old terminal i/o settings */
    current = old; /* make new settings same as old settings */
    current.c_lflag &= ~ICANON; /* disable buffered i/o */
    if (echo) {
        current.c_lflag |= ECHO; /* set echo mode */
    } else {
        current.c_lflag &= ~ECHO; /* set no echo mode */
    }
    tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void unix_specific::resetTermios(void) 
{
    tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char unix_specific::getch_(int echo) 
{
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

/* Read 1 character without echo */
char unix_specific::getch(void) 
{
    return unix_specific::getch_(0);
}

/* Read 1 character with echo */
char unix_specific::getche(void) 
{
    return unix_specific::getch_(1);
}