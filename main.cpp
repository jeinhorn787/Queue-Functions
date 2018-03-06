/**********************************************************************************************
** Program: Lab6 (Queue)
** Author: Jeremy Einhorn
** Date: August 4, 2017
** Description:  This is the main file.  It allows the user to choose from the menu of Queue
options.
***********************************************************************************************/

#include"Queue.hpp"
#include"input_validation.hpp"
#include"menu.hpp"
#include<iostream>
using std::cout;
using std::endl;

int main()
{
	//int variable to hold the users choice
	int choice = menu();
	//creates a queue
	Queue q;

	//while the user chooses not to exit
	while (choice != 5)
	{
		//if the user wants to add a new node to the back
		if (choice == 1)
		{
			//int variable to hold the value user wants to add
			int value;

			cout << "Please enter a value to be entered in the queue." << endl;
			//input validation for an integer
			value = getInt();

			//adds that integer to the queue from the back
			q.addBack(value);
		}

		//if the user wants to print the front's value
		else if (choice == 2)
		{
			//if the queue is empty, getFront will not be called and 
			//the user will be told the queue is empty
			if (q.isEmpty())
				cout << "Queue is empty." << endl;

			else
				cout << q.getFront() << endl;
		}

		//if the user wants to remove the front value
		else if (choice == 3)
		{
			//if the queue is empty, removeFront will not be called and
			//the user will be told the queue is empty
			if (q.isEmpty())
				cout << "Queue is empty." << endl;

			else
				q.removeFront();
		}

		//if the user wants to display the whole queue
		else if (choice == 4)
		{
			//if the queue is empty, display will not be called and
			//the user will be told the queue is empty
			if (q.isEmpty())
				cout << "Queue is empty." << endl;

			else
				q.display();
		}

		//the menu pops up again for the user to choose from
		choice = menu();
	}

	//if the user chooses 5 to quit, program exits
	return 0;
}