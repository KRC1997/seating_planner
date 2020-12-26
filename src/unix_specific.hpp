/*
    New File created as part of the refactoring project.
    Declares functions that are used in a unix environment
*/

#ifndef UNIX_SPECIFIC_HPP
#define UNIX_SPECIFIC_HPP


#include <termios.h>
#include <stdio.h>

namespace unix_specific
{
    /* Initialize new terminal i/o settings */
    void initTermios(int echo);

    /* Restore old terminal i/o settings */
    void resetTermios(void);

    /* Read 1 character - echo defines echo mode */
    char getch_(int echo);

    /* Read 1 character without echo */
    char getch(void);

    /* Read 1 character with echo */
    char getche(void);
}

#endif // UNIX_SPECIFIC_HPP