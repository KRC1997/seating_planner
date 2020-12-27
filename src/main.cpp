#include <iostream>
#include <vector>
#include <string>

#include "screens.hpp"

int main ()
{
	std::vector<std::string> main_menu = {
		"CREATE ARRANGEMENT", "HELP", "ABOUT", "SETTINGS", "EXIT"
	};
	std::string header = "SEAT ARRANGER 2.0";
	std::string footer = "PLEASE POINT TO CHOICE";
	int main_menu_choice = -1;
	do
	{
		// Draw the main menu of the program
		main_menu_choice = screens::draw_menu(main_menu, header);
		switch (main_menu_choice)
		{
			case 0:
			{
				screens::draw_create_arrangement();
				break;
			}
			case 1:
			{
				screens::draw_help();
				break;
			}
			case 2:
			{
				screens::draw_about();
				break;
			}
			case 3:
			{
				screens::draw_settings();
				break;
			}
			default:
			{
				break;
			}
		}
	}
	while (main_menu_choice != main_menu.size() - 1);
	std::cout << "\n\t\t\t        " << header << std::endl;
	std::cout << "\n\t\t\tThank you for using our services!!";
	std::cout << "\n\t\t\t      Hope to see you again!\n\n\n";
	return 0;
}
