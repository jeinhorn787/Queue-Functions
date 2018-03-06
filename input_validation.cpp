/**********************************************************************************************
** Program: Lab6 (Queue)
** Author: Jeremy Einhorn
** Date: August 4, 2017
** Description:  This is the implementation file for my input validation.  It can get check for
a positive integer and for any integer.
***********************************************************************************************/

#include "input_validation.hpp"
#include <iostream>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::remove;
using std::atoi;

//properly gathers a positive integer from the user
int getUnsignedInt()
{
	//user input is stored as string
	string input;
	//integer variable to store the returned unsigned integer
	int uint;

	do 
	{
		//getline will get every character from the string
		getline(cin, input);

		//the following code taken from 
		//https://stackoverflow.com/questions/16329358/remove-spaces-from-a-string-in-c
		input.erase(remove(input.begin(), input.end(), ' '), input.end());
		//end of copied code. this code will remove
		//all whitespace from the string

		//if the string is found NOT to be an unsigned integer
		if (!(isUnsignedInt(input)))
			cout << "Error.  Please enter a postitive integer." << endl;

	} while (!(isUnsignedInt(input)));

	//converts string to integer
	uint = atoi(input.c_str());

	return uint;
}

//checks to see if the string that holds the user input is in fact 
//an unsigned int
bool isUnsignedInt(string input)
{	
	bool status;

	if (input == "")
		return false;
	
	for (int index = 0; index < input.size(); index++)
	{
		if (isdigit(input[index]))
			status = true;
		//if any element in the string is anything but number
		//it automatically returns false
		else
			return false;
	}

	return status;
}

int getInt()
{
	//user input is stored as string
	string input;
	//integer variable to store the returned unsigned integer
	int any;

	do
	{
		//getline will get every character from the string
		getline(cin, input);

		//the following code taken from 
		//https://stackoverflow.com/questions/16329358/remove-spaces-from-a-string-in-c
		input.erase(remove(input.begin(), input.end(), ' '), input.end());
		//end of copied code. this code will remove
		//all whitespace from the string

		//if the string is found NOT to be an unsigned integer
		if (!(isInt(input)))
			cout << "Error.  Please enter an integer." << endl;

	} while (!(isInt(input)));

	//converts string to integer
	any = atoi(input.c_str());

	return any;
}

bool isInt(string input)
{
	bool status;

	if (input == "")
		return false;

	//if the first element is a negative sign, the rest of the string
	//can be checked
	if (input[0] == '-')
	{
		for (int index = 1; index < input.size(); index++)
		{
			if (isdigit(input[index]))
				status = true;

			//if anything other than a number is encountered
			else
				return false;
		}
	}

	//if the first element is not a negative sign
	else
	{
		for (int index = 0; index < input.size(); index++)
		{
			if (isdigit(input[index]))
				status = true;

			//if anything other than a number is encountered
			else
				return false;
		}
	}

	return status;
}