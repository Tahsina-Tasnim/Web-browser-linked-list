/*
* Node.hpp
* Written by : Tahsina Tasnim c3440184
* Modified   : 10/04/2024
*
* This class represents the template implementation for a Node class.
* This file should be used in conjunction with Assignment 1 for SENG1120.
*/ 


//constructor creates a new node where next and previous are set to null pointers
template <typename T>
Node<T>::Node() 
{ 
   next = nullptr;
   prev = nullptr;
}


//constructor initialises new data and next and previous pointers are set to null pointers
template <typename T>
Node<T>::Node(const T& new_data) 
{ 
    data = new_data;
    next = nullptr;
    prev = nullptr;

}


//destructor sets next and prev as nullptr 
template <typename T>
Node<T>::~Node() 
{
    next = nullptr;
    prev = nullptr;

}

// ---- Mutators --------
//sets the data to the new supplied data
template <typename T>
void Node<T>::set_data(T& new_data) 
{
   data = new_data; 
}


//the next pointer has been set to the supplied Node
template <typename T>
void Node<T>::set_next(Node<T>* const new_next) 
{
    next = new_next;
}


//the dprev pointer has been set to the supplied Node
template <typename T>
void Node<T>::set_prev(Node<T>* const new_prev) 
{
    prev = new_prev;
}


// ---- Accessors --------
//the value of the next pointer is returned 
template <typename T>
Node<T>* Node<T>::get_next() 
{
    return next;
}


//the value of the previous pointer is returned
template <typename T>
Node<T>* Node<T>::get_prev() 
{
    return prev;
}


//a reference to the data item is returned 
template <typename T>
T& Node<T>::get_data() 
{
    return data;
}


//the value of the next pointer is returned as a const
template <typename T>
const Node<T>* Node<T>::get_next() const 
{
    return next;
}


//the value of the previous pointer is returned as a const
template <typename T>
const Node<T>* Node<T>::get_prev() const 
{
    return prev;
}


//a const reference to the data item is returned 
template <typename T>
const T& Node<T>::get_data() const 
{
    return data;
}