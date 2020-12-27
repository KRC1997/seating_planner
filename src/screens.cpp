/*
    New File created as part of the refactoring project.
    Defines functions that draw different screens on the terminal window
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "screens.hpp"
#include "unix_specific.hpp"

#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_LEFT 67
#define KEY_RIGHT 68
#define CARIAGE_RETURN 10
#define CLEAR_SCREEN "clear"


int take_char_input()
{
    char ch1, ch2, ch3;
    ch1 = unix_specific::getch();
    if ((ch1==27)) 
    {
        ch2 = unix_specific::getch();
        ch3 = unix_specific::getch();
        return ch3;
    }
    else 
    {
        return ch1;
    }
}

int screens::draw_menu(
    const std::vector<std::string> & menu_items, 
    const std::string & header,
    const std::string & footer
)
{
    int pointer = 0;
	char ch;
	while (true){
        system(CLEAR_SCREEN); // To clear the terminal window
        if (header.size() > 0)
            std::cout << "\n\t" << header << "\n\t";
		std::cout<<"\n\tPress Enter to choose\n";
		for (int i = 0; i < menu_items.size(); i++){
			if (pointer == i){
				std::cout<<"             ->\t|"<<menu_items[i]<<"\n";
			}
			else{
				std::cout<<"\t\t|"<<menu_items[i]<<"\n";
			}
		}
        if (footer.size() > 0)
            std::cout << "\n\t" << footer << "\n";
		ch = take_char_input();
        switch(ch)
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
                return pointer;
            }
            default:
            {
                break;
            }
        }
	}
}

void screens::draw_about()
{
    system(CLEAR_SCREEN); // To clear the terminal window
    std::fstream file;
	file.open("about.txt", std::ios::in);
    char ch;
	if( !file )
    {
		std::cout << "about file not found";
	}
    else 
    {
        while ( !file.eof() ){
            file.get(ch);
            std::cout << ch;
        }
        file.close();
    }
    std::cout << "Press ANY key to return... ";
    ch = unix_specific::getch();
	return;
}

void screens::draw_help()
{
    system(CLEAR_SCREEN); // To clear the terminal window
    std::fstream file;
	file.open("help.txt", std::ios::in);
	char ch;
	if( !file )
    {
		std::cout << "help file not found";
	}
	else 
    {
        while ( !file.eof() ){
            file.get(ch);
            std::cout << ch;
        }
        file.close();
    }
    std::cout << "Press ANY key to return... ";
    ch = unix_specific::getch();
	return;
}

void screens::draw_settings() 
{
    std::vector<std::string> settings_menu = {
        "NUMBER OF CLASSES",
		"NUMBER OF SECTIONS",
		"COLUMNS PER CLASS",
		"ROWS PER CLASS",
		"SEATS PER TABLE",
		"NUMBER OF STUDENTS",
		"RESET DEFAULT SETTINGS",
		"EXIT SAVING CHANGES"
    };
	std::string header = "SETTINGS";
	std::string footer = "PLEASE POINT TO CHOICE";

	int settings_menu_choice = 0;
    do
    {
        settings_menu_choice = screens::draw_menu(
            settings_menu, header, footer
        );
    }
    while(settings_menu_choice != settings_menu.size() - 1);
    return;
}

void screens::draw_create_arrangement()
{
    std::vector<std::string> create_arrangement_menu = {
        "NUMBER OF CLASSES",
		"EXIT SAVING CHANGES"
    };
	std::string header = "CREATE ARRANGEMENT";
	std::string footer = "PLEASE POINT TO CHOICE";

	int create_arrangement_menu_choice = 0;
    do
    {
        create_arrangement_menu_choice = screens::draw_menu(
            create_arrangement_menu, header, footer
        );
    }
    while(create_arrangement_menu_choice != create_arrangement_menu.size() - 1);
    return;
}