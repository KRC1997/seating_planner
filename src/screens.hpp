/*
    New File created as part of the refactoring project.
    Declares functions that draw different screens on the terminal window
*/

#ifndef SCREENS_HPP
#define SCREENS_HPP

#include <vector>
#include <string>

/*
    Functions for drawing different screens on the terminal window.
    Menus allow selecting options via a arrow-key movable pointer on the menu
    items
*/
namespace screens
{
    int draw_menu(std::vector<std::string> & menu_items, std::string & header);
    // New Screens will follow
}



#endif // SCREENS_HPP