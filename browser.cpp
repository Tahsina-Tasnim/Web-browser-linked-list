/*
-browser.cpp
-written by : Tahsina Tasnim c3440184
-modified : 10/04/24
*/


#include "browser.h"

//everything is initialised with the homepage added to the history
Browser::Browser(const std::string& homepage, int history_limit)
{
  history = new LinkedList<std::string>(); //makes a new linked list
  history->push_front(homepage); //homepage is added to the history
  bookmarks = new LinkedList<std::string>(); //makes a new linked list
 
}

//destructor destroys the browser and associated memory is freed
Browser::~Browser()
{
  delete history; //deletes hisotry freeing up memory
  delete bookmarks; //deletes bookmarks freeing up memory
}

//returns a reference to the current site as a string
const std::string& Browser::get_current_site()
{
   return history->get_current();
}

//current site is updated to the url with no forward history and oldest element is deleted if history limit is reached
void Browser::visit(const std::string& url)
{
    history->push_back(url);
   
    if (history->size() > history_limit) //deletes the oldest history entry if limit is exceeded
    {
        history->pop_front();
    }

    history->end();
}

//moves back in history
void Browser::back(int steps)
{
    for (int i = 0; i<steps; ++i)
    {
        history->backward();
    }


}

//moves forward in history
void Browser::forward(int steps)
{
    for (int i = 0; i<steps; ++i)
    {
        history->forward();
    }


}

//removes all entries for a specific url, current points to the last element and number of deleted elements is returned
int Browser::remove(std::string url)
{
    int count = 0; //initial count of deleted elements is zero
    while (!history->empty()) //goes on until the list is not empty
    {
        if (history->get_current()==url) //checks if current points to the url
        {
            history->remove(); //removed
            ++count; //adds to count
        }
        else
        {
            history->forward(); //moves forward
        }
    }
    return count; //count of deleted elements is returned
}

//the current page is bookmared and if its already bookmarked it is removed from bookmarks
void Browser::bookmark_current()
{
    std::string current_site = get_current_site(); //holds the current site

    if (!bookmarks->search(current_site)) //checks if the current_site is in bookmarks
    {
        bookmarks->push_back(current_site); //adds to bookmarks
        std::cout << current_site << " added to bookmarks" << std::endl; //prints it out
    }

    else
    {
        bookmarks->remove(); //removed from bookmarks
        std::cout << current_site << " removed from bookmarks" <<std::endl; //prints it out
    }

}

//history is cleared and current/history is updated to the homepage
void Browser::clear_history()
{
    history->clear(); //all data elements are removed leaving the sentinels intact

}

//prints the bookmarks list in the order they were added
void Browser::print_bookmarks()
{
    bookmarks->begin(); //sets the current to the node after head
    for(int i =0; i< bookmarks->size(); i++)
    {
        std::cout<<bookmarks->get_current() << std::endl; //prints it out

        bookmarks->forward(); //moves forward
    }
   
    
}


//returns the number of elements in the history list
int Browser::count_history() const
{
    return history->size();
}


//returns the number of elements in the bookmarks list
int Browser::count_bookmarks() const
{
    return bookmarks->size();
}


//the element at the specific index is visited otherwise theres an error
void Browser::visit_bookmark(int index)
{
    bookmarks->begin(); //current points to node after head
    for (int i = 0; i<index && !bookmarks->empty(); ++i)
    {
        bookmarks->forward(); //moves forward
    }
    if (!bookmarks->empty()) ///checks if empty
    {
        visit (bookmarks->get_current()); //goes to the current site

    }
    else 
    {
        std::cout << "Invalid index. Site not updated" << std::endl; //prints out a generic error message
    }
}