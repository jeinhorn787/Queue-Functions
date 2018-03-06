/**********************************************************************************************
** Program: Lab6 (Queue)
** Author: Jeremy Einhorn
** Date: August 4, 2017
** Description:  This is the implementation file for my menu function.  The user has 5 options.
***********************************************************************************************/

#include"menu.hpp"
#include"input_validation.hpp"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int menu()
{
	//local variable to hold user choice
	int choice;

	cout << "		The Queue" << endl;
	cout << "1: Add a Value to the Back of the Queue" << endl;
	cout << "2: Display First Value" << endl;
	cout << "3: Remove First Value" << endl;
	cout << "4: Display the Queue" << endl;
	cout << "5: Quit" << endl;

	cout << "Please enter a number, from 1 to 5, for you choice." << endl;
	//input validation for a positive integer
	choice = getUnsignedInt();

	//while the user enters lower than 1 or higher than 5, they must re-enter
	while (choice < 1 || choice > 5)
	{
		cout << "Error.  Please enter 1 to 5 for your choice." << endl;
		choice = getUnsignedInt();
	}


	switch (choice)
	{
	case 1:
		return 1;

	case 2:
		return 2;

	case 3:
		return 3;

	case 4:
		return 4;

	case 5:
		return 5;

	}

	return 5;
}