/**********************************************************************************************
** Program: Lab6 (Queue)
** Author: Jeremy Einhorn
** Date: August 4, 2017
** Description:  This is the header file for the Queue class.  
***********************************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP
#include"QueueNode.hpp"

class Queue
{
private:
	QueueNode *front;
	QueueNode *back;

public:
	Queue();
	~Queue();
	bool isEmpty();
	void addBack(int);
	int getFront();
	void removeFront();
	void display();
};

#endif