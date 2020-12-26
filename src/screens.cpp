/*
    New File created as part of the refactoring project.
    Defines functions that draw different screens on the terminal window
*/

#include <iostream>

#include "screens.hpp"
#include "unix_specific.hpp"

#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_LEFT 67
#define KEY_RIGHT 68
#define CARIAGE_RETURN 10


int screens::draw_menu(std::vector<std::string> & menu_items, std::string & header)
{
    int pointer = 0;
	char ch1 = '0', ch2 = '0', ch3 = '0';
	while (true){
        system("clear"); // To clear the terminal window
        if (header.size() > 0)
        {
            std::cout << "\n\t" << header << "\n\t";
        }
		std::cout<<"\n\tPress Enter to choose\n";
		for (int i = 0; i < menu_items.size(); i++){
			if (pointer == i){
				std::cout<<"             ->\t|"<<menu_items[i]<<"\n";
			}
			else{
				std::cout<<"\t\t|"<<menu_items[i]<<"\n";
			}
		}
		ch1 = unix_specific::getch();
        if (ch1 == CARIAGE_RETURN) {
            system("clear");
            return pointer;
        }
        ch2 = unix_specific::getch();
        ch3 = unix_specific::getch();
        
		if (!(ch1==27)&&(ch2=91))
        {
            continue;
        }
        switch(ch3)
        {
            case KEY_UP:
            {
                if(pointer == 0)
                    pointer = menu_items.size()-1;
                else
                    --pointer;
                break;
            }
            case KEY_DOWN:
            {
                if(pointer != menu_items.size()-1)
                    ++pointer;
                else
                    pointer = 0;
                break;
            }
            case CARIAGE_RETURN:
            {
                system("clear");
                return pointer;
            }
            default:
            {
                system("clear");
                break;
            }
        }
	}
}