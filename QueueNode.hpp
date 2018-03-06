/**********************************************************************************************
** Program: Lab6 (Queue)
** Author: Jeremy Einhorn
** Date: August 4, 2017
** Description:  This is the header file for the QueueNode structure.  It holds an int value and
then 2 pointers to a QueueNode, next and previous.
***********************************************************************************************/

#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP

struct QueueNode
{
	int val;
	QueueNode *next;
	QueueNode *prev;
};

#endif