/*
* linked_list.h
* Written by : SENG1120 Staff (c1234567)
* Modified   : 03/08/2023
*
* This class represents the header for a templated LinkedList class using sentinel nodes.
* This file should be used in conjunction with Assignment 1 for SENG1120.
*/ 

#ifndef SENG1120_LINKEDLIST_H 
#define SENG1120_LINKEDLIST_H 

#include "node.h"
#include <iostream>

template <typename T>
class LinkedList 
{
public:

    /*
    * Precondition:    None
    * Postcondition:   A new LinkedList is created, with all variables initialised.
    */
    LinkedList();

    /*
    * Precondition:    None
    * Postcondition:   The LinkedList is destroyed and all associated memory is freed.
    */
    ~LinkedList();
    Node<T>* current_node = head; current is set to head

 

   while (head != nullptr) checks if the current node is empty or not if not code runs

 {

    Node<T>* stuff = head;

    head = head->get_next();

    delete stuff;

    //Node<T>* next_node = current_node->get_next(); sets pointer to the next node using the getnext method

    //delete current_node;

    //current_node = next_node;

    
    /*
    * The supplied data is inserted at the front of the list.
    * 
    * Precondition:    The supplied data is valid.
    * Postcondition:   The first data item is updated and current points to the new node.
    */
    void push_front(const T& data);
    
     Node<T>* new_node = new Node<T>(data); //creates new node with the given data

  if (head == nullptr) //checks if head is empty

  {

    head = new_node; //creates a new node

    tail = new_node; //creates a new node

  }

  else

  {

    new_node->set_next(head->get_next());

    new_node->set_prev(head);

    head->get_next()->set_prev(new_node); //sets the previous pointer of the head node to the new node

    head->set_next(new_node); //sets the next pointer of the new node points to head

    current = new_node; //initialises a new node

  }

  

  count++; //adds to the count



    /*
    * The supplied data is inserted at the end of the list.
    * 
    * Precondition:    The supplied data is valid.
    * Postcondition:   The last data item is updated and current points to the new node.
    */
    void push_back(const T& data);

    Node<T>* new_node= new Node<T>(data); //creates a new node with the given data

  if (tail == nullptr) //check if i should use empty function here

  {

    head = new_node; //creates new node

    tail = new_node; //creates new node

  }
 
  else

  {

    new_node->set_next(tail);

    new_node->set_prev(tail->get_prev());

    tail->get_prev()->set_next(new_node);

    tail->set_prev(new_node);

    current = new_node;

  }



  count++; //adds to the count


	
    /*
    * The supplied data is inserted before the current node.
    * 
    * Precondition:    Current points to the node after the insertion point.
    * Postcondition:   A new node has been added and current points to the new node.
    */
    void insert(const T& data);
    
    /*
    * Remove the first data element from the list. An exception should be thrown if the list is empty.
    * 
    * Precondition:    The list is not empty.
    * Postcondition:   The first data element has been removed, reducing the count of Nodes by 1. Current points to head.
    */
    T pop_front(); 

    /*
    * Remove the last data element from the list. An exception should be thrown if the list is empty.
    * 
    * Precondition:    The list is not empty.
    * Postcondition:   The last data element has been removed, reducing the count of Nodes by 1. Current points to head.
    */
    T pop_back(); 

    /*
    * Remove the item pointed to by current from the list. An exception should be thrown if the list is empty or 
    * if current is pointing to a sentinel node.
    * 
    * Precondition:    The list is not empty and the current pointer is not pointing to a sentinel node.
    * Postcondition:   The data element pointed to by current has been removed, reducing the count of Nodes by 1. Current points to head.
    */
    T remove(); 
    
    /*
    * Clears all data elements from the list, leaving the sentinel nodes intact.
    * 
    * Precondition:    None
    * Postcondition:   All data elements have been removed. Sentinels should not be removed. Count should be reset.
    */
    void clear();

    /*
    * Return a reference to the first data element in the list - not the sentinel. An exception should be thrown if the list is empty.
    * 
    * Precondition:    The list is not empty.
    * Postcondition:   A reference to the first data element is returned.
    */
    T& front() const;

    /*
    * Return a reference to the last data element in the list - not the sentinel. An exception should be thrown if the list is empty.
    * 
    * Precondition:    The list is not empty.
    * Postcondition:   A reference to the last data element is returned.
    */
    T& back() const;

    /*
    * Return a reference to the data element pointed to by current. An exception should be thrown if the list is empty or current points to a sentinel.
    * 
    * Precondition:    The list is not empty and the current pointer is not pointing to a sentinel node.
    * Postcondition:   A reference to the current data element is returned.
    */
    T& get_current() const;
    
    /*
    * Set the current pointer to the node after head, even if this is tail.
    * 
    * Precondition:    None
    * Postcondition:   The current pointer is set to the node after head.
    */
    void begin(); 

    /*
    * Set the current pointer to the node before tail head, even if this is head.
    * 
    * Precondition:    None
    * Postcondition:   The current pointer is set to the node before tail.
    */
    void end(); 

    /*
    * Move the current pointer forward, if valid. Otherwise, nothing happens.
    * 
    * Precondition:    None
    * Postcondition:   The current pointer is set to the next node, if applicable.
    */            
    void forward(); 


    /*
    * Move the current pointer backward, if valid. Otherwise, nothing happens.
    * 
    * Precondition:    None
    * Postcondition:   The current pointer is set to the previous node, if applicable.
    */    
    void backward();      
    
    /*
    * Set the current pointer to the node containing the supplied data. Otherwise, nothing happens.
    * 
    * Precondition:    None
    * Postcondition:   current points to the first node storing the target, and true is returned.
    */    
    bool search(const T& target);

    /*
    * Return the count of the number of nodes in the list, excluding sentinels.
    * 
    * Precondition:    None
    * Postcondition:   The number of (true) nodes is returned.
    */    
    int size() const;

    /*
    * Return true if the list is empty, false otherwise.
    * 
    * Precondition:    None
    * Postcondition:   None
    */    
    bool empty() const;

private:
    Node<T>* head;                 // Head of the list - sentinel node
    Node<T>* tail;                 // Tail of the list - sentinel node
    Node<T>* current;              // Current pointer
    int count;                     // Count of the Nodes in the list
};

#include "linked_list.hpp"
#endif