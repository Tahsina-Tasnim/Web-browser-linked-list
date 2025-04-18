/*
* LinkedList.hpp
* Written by : Tahsina TAsnim c3440184
* Modified   : 10/04/2024
*
* This class represents the template implementation for a LinkedList class.
* This file should be used in conjunction with Assignment 1 for SENG1120.
*/ 
#include "linked_list.h"
#include <iostream>


//a LinkedList class is made where head, tail and current are set as nullptr and count is default as 0
template <typename T>
LinkedList<T>::LinkedList()
{
  head = new Node<T>(); //creates new node
  tail = new Node<T>(); //creates new node

  head->set_next(tail); //points to tail
  head->set_prev(tail); //points to head

  tail->set_next(head); //points to head
  tail->set_prev(head); //points to head

  current = head; //current pointer is the head
  count = 0; //initial count is zero
}



// The class is destroyed and the nodes are deleted from memory freeing up space
template <typename T>
LinkedList<T>::~LinkedList() 
{

	clear(); //uses the clear function
	delete head; //deletes head as clear() doesnt remove it
	delete tail; //deletes tail as clear() doesnt remove it

	head = nullptr; //head nad tail are both set to nullptr
	tail = nullptr;
 
 }



// the first data is updated and current points to new node
template <typename T>
void LinkedList<T>::push_front(const T& data) 
{
	current = head->get_next(); //points to the node after head 
	insert(data); //uses the insert function
  
}




// the last data item is updated andcurrent points to the new node
template <typename T>
void LinkedList<T>::push_back(const T& data) 
{
	current = tail; //current points to tail
	insert(data);
  
}


// a new node has been added and current points to the new node
template <typename T>
void LinkedList<T>::insert(const T& data) 
{ 
		Node<T>* new_node = new Node<T>(data); //creates new node with the data provided
		
		new_node->set_next(current); //sets the next pointer of new node to current
		new_node->set_prev(current->get_prev()); //sets the previous pointer of new node to the node before current
		current->get_prev()->set_next(new_node); //sets the currents previous next pointer to the new node
		current->set_prev(new_node); // sets the previous pointer of current to new node
		current = new_node;
		
		count++; //adds to the count
	}



//the first data element has been removed, reducing the count of Nodes by 1. Current points to head
template <typename T>
T LinkedList<T>::pop_front()
{   
	if(empty())
  {
	throw std::out_of_range("Collection is empty"); //exception thrown if the list is empty
  }
    T node_data = head->get_data(); //stores new head data
	Node<T>* old_head = head; //stores the previous head
	if (head == tail) 
	{
		head = nullptr;
		tail = nullptr;	
	}
	else 
	{
		head = head-> get_next(); //gets the node after head
		head->set_prev(tail); //sets the previous pointer to tail
	}
	delete old_head; //frees up memory
	count--; //subtracts from count 
	current = head ; //current points to head
	return node_data; //returns the data from old head also check if this is needed
}


// the last data element has been removed,reducing the count of Nodes by 1.Current points to head
template <typename T>
T LinkedList<T>::pop_back()
{   if (empty())
{
	throw std::out_of_range("Collection is empty");

}   
    T pop_data = tail->get_data(); //stores new tail
	Node<T>* old_tail = tail; //stores old tail
	if (tail == head) 
	{
		head = nullptr;
		tail = nullptr;	
	}
	else 
	{
		tail = tail-> get_prev(); //gets the node before tail
		tail->set_next(nullptr); //sets next tail pointer to nullptr
	}
	delete old_tail; //frees up memory
	count--; //subtracts from count
	current = head; //current points to head
	return pop_data; //returns data from old tail
	
}

//the last data pointed to by current is removed, reducing node by 1 and current points to head
template <typename T>
T LinkedList<T>::remove()
{   if (empty() || current == head || current == tail) //checks if empty or current points to sentinel
  {
	throw std::out_of_range("Collection is empty or points to sentinal"); //check if the exception is correct 
  }
    
    T remove_data = current->get_data(); //stores the data 
	Node<T>* temp = current; //stores the current
	current->get_prev()->set_next(current->get_next()); //sets the next pointer of the node before current to point to the node thats after the current node
	current->get_next()->set_prev(current->get_prev()); //sets the previous pointer of the node after current to point to the node before the current node
	current = head; //current points to head
	delete temp; //deletes the node pointed by current
	count--; //subtracts from count
	return remove_data; //returns the data pointed to by current
	
}

//clears all data from list leaving the sentinels intact
template <typename T>
void LinkedList<T>::clear()
{
    while (!empty())  //continues until the list is empty 
	{
		T temp = pop_front();
	}
}

//returns a reference to the first data element in the list as in the data that is in the node after head
template <typename T>
T& LinkedList<T>::front() const
{
   if (empty()) 
   { 
	 throw std::out_of_range("Collection is empty");
   }
   else 
   {
     return head->get_next()->get_data(); //returns data from the node after the head
   }
}


//returns a reference to the last element in the list as inn the data that is in the node before tail
template <typename T>
T& LinkedList<T>::back() const
{
   if (empty())
   {
	throw std::out_of_range("Collection is empty");
   }
   else
   {
    return tail->get_prev()->get_data(); //returns data from the node before the tail
   }
}

//returns a reference to the last data elemt in the list
template <typename T>
T& LinkedList<T>::get_current() const
{
   if (empty() || current == head || current == tail) //checks if list is empty or current points to sentinel
   {
	throw std::out_of_range("Collection is empty"); //check if the error message is correct
   }
   else 
   {
    return current->get_data(); //returns the current data
   }
}

//sets the current pointer to the node after head even if its tail
template <typename T>
void LinkedList<T>::begin() 
{
   
    current = head->get_next();
   
}

//sets the current pointer to the node before tail even if its the head
template <typename T>
void LinkedList<T>::end() 
{
	
 current= tail->get_prev();
  
}


//moves the current pointer forward 
template <typename T>
void LinkedList<T>::forward() 
{ 
  if (current->get_next() != tail) 
  {
	current = current->get_next();
  }

}


//moves the current pointer backward
template <typename T>
void LinkedList<T>::backward() 
{ 
  if (current->get_prev() != head )
  {
	current = current->get_prev();
  }

}


//returns the size of ndoe
template <typename T>
int LinkedList<T>::size() const
{
	return count; 
}


//returns true if empty and false if otherwise
template <typename T>
bool LinkedList<T>::empty() const
{
	if (count==0)
	{
		return true;
	}
	else 
	{
		return false;
	}
}


//current points to the first node storing the target and true is returned
template <typename T>
bool LinkedList<T>::search(const T& target)
{
	Node<T>* sort = head->get_next(); //finds node after the head 
	while (sort != tail)
	{
		if (sort->get_data()==target) //checks if target 
		{
			current = sort; //sets current pointer to the node with target
			return true;
		}
		else
		{
		sort = sort->get_next(); //moves to next
		}
	}
	return false;
}