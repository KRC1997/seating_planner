#include <iostream>
#include <fstream>

#include "help_about.hpp"


void help (){
/*
	system("cls");
	cout<<"\n\n\t\tUNDER DEVELOPMENT";
*/
	std::fstream file;
	file.open("help.txt", std::ios::in);
	if(!file){
		std::cout<<"help file not found";
		return;
	}
	char ch;
	while (!file.eof()){
		file.get(ch);
		std::cout<<ch;
	}
	std::cout<<"Press ANY key to return: ";
	file.close();
}

void about (){
/*
	system("cls");
	cout<<"\n\n\t\tUNDER DEVELOPMENT";
*/
	std::fstream file;
	file.open("about.txt", std::ios::in);
	if(!file){
		std::cout<<"about file not found";
		return;
	}
	char ch;
	while (!file.eof()){
		file.get(ch);
		std::cout<<ch;
	}
	std::cout<<"Press ANY key to return: ";
	file.close();
}