/**********************************************************************************************
** Program: Lab6 (Queue)
** Author: Jeremy Einhorn
** Date: August 4, 2017
** Description:  This is the implementation file for the Queue class.  It can add a QueueNode to
the back, display the front's value, remove the front's value, and display's the entire Queue.
The destructor properly destroys any allocation made.
***********************************************************************************************/

#include"Queue.hpp"
#include<iostream>
using std::cout;
using std::endl;

//constructor sets front and back to nullptr to start out
Queue::Queue()
{
	back = nullptr;
	front = nullptr;
}

//destructor deletes all QueuNodes.  When there is only 1 node left in the queue
//it handles that in a different way because the next and prev pointers are all pointing
//to the same thing
Queue::~Queue()
{
	//if the queue is not empty
	if (!isEmpty())
	{
		//while the front does not equal the back, meaning there are 2 or more
		//elements in the queue
		while (this->front != this->back)
		{
			//create local pointer to point to the front
			//set the prev and next pointers to point to the next element
			//which will be the front after deletion
			QueueNode *remove = this->front;
			this->front = remove->next;
			this->front->prev = remove->prev;
			remove->prev->next = this->front;
			delete remove;
		}

		//if the front equals the back, meaning there is only 1 element because
		//1 element in the queue will be the back AND the front
		if (this->front == this->back)
		{
			//this also properly deletes the back
			//which is the same element
			delete front;
		}
	}
}

//checks if the queue is empty
bool Queue::isEmpty()
{
	//if front and back are both pointing to nothing
	if (this->front == nullptr && this->back == nullptr)
		return true;

	else
		return false;
}

//adds QueueNode to the back of the queue
void Queue::addBack(int a)
{
	//dynamic allocation of a new QueueNode to
	//add to back
	QueueNode *newBack;

	newBack = new QueueNode;
	newBack->val = a;
	
	//if the queue is empty
	if (this->back == nullptr)
	{
		//the new node is now the front and back
		this->back = newBack;
		this->front = newBack;
	
		//creates circular structure by having the back and next pointers
		//point to the same node
		this->front->prev = this->back;
		this->back->next = this->front;	
	}

	//if the queue is not empty
	else
	{
		
		//set back and next pointers to correct elements
		//sets back to new back node
		this->back->next = newBack;
		newBack->prev = this->back;
		this->back = newBack;
		//keep circular structure
		this->front->prev = this->back;
		this->back->next = this->front;
	}
}

//returns value at the front
int Queue::getFront()
{
	return front->val;
}

//removes the node at the front
void Queue::removeFront()
{
	//if there is only 1 element in the queue
	if (this->front == this->back)
	{
		//delete the front and set front and back to nullptr
		delete front;
		front = back = nullptr;
		return;
	}

	//new node pointer to point to current front
	QueueNode *newFront = this->front;

	//set the current back and prev pointers to point to ther right element
	//after deletion, then delete the current element
	this->back->next = newFront->next;
	newFront->next->prev = this->back;
	this->front = newFront->next;
	delete newFront;
}

//prints the entire queue starting from the front node
void Queue::display()
{
	//queue node pointer to traverse queue
	QueueNode *list = this->front;

	//print the value list is pointing to, then move on to
	//the next element and print that until it points back to front
	do
	{
		cout << list->val << endl;
		list = list->next;
	} while (list != this->front);
}