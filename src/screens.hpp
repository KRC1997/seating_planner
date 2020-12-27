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
    static std::string empty_str = std::string();

    int draw_menu(
        const std::vector<std::string> & menu_items, 
        const std::string & header = empty_str,
        const std::string & footer = empty_str
    );
    // New Screens will follow

    void draw_about();

    void draw_help();

    void draw_settings();

    void draw_create_arrangement();
}



#endif // SCREENS_HPP