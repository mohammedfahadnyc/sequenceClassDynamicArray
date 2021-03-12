
/*                              MOHAMMED FAHAD , ID: 24006611
“The work in this assignment is my own. Any outside sources have been properly cited.”
 */


//Provided by:   MOHAMMED FAHAD
// Email Address: mfahad001@citymail.cuny.edu

#include <cassert> // Provides assert

#include <iostream>

#include "sequence2.hpp"

using namespace std;

namespace main_savitch_4
{

// sequence(size_t initial_capacity = DEFAULT_CAPACITY)

// Postcondition: The sequence has been initialized as an empty sequence.

// The insert/attach functions will work efficiently (without allocating

// new memory) until this capacity is reached.

sequence::sequence(size_type initial_capacity)
{
    capacity = initial_capacity;
    data = new value_type[capacity];
    used = 0;
    current_index = 0;
}

// sequence(const sequence& source)

// Postcondition: The sequence has capacity set to the sequence source parameter.

// The sequence object is filled with data members given by the sequence source

// parameter.

//

sequence::sequence(const sequence& source)
{
    data = new value_type[source.capacity];
    capacity = source.capacity;
    used = source.used;
    current_index = source.current_index;
    copy(source.data, source.data+used, data);
}

// ~sequence()

// Postcondition: dynamically allocated memory for data member has been released

sequence::~sequence()
{
    //release memory
    delete [] data;
}

// size_type count(const value_type& target) const

// Postcondition: Return value is number of times target is in the sequence

sequence::size_type sequence::size() const
{
    return used;
}

// bool is_item( ) const

// Postcondition: A true return value indicates that there is a valid

// "current" item that may be retrieved by activating the current

// member function (listed below). A false return value indicates that

// there is no valid current item.

bool sequence::is_item() const
{
    //see if current index is valid
    return (current_index < used);
}

// value_type current( ) const

// Precondition: is_item( ) returns true.

// Postcondition: The item returned is the current item in the sequence.

sequence::value_type sequence::current() const

{
    // ensure that current_index is valid before returning value
    assert(is_item());
    return data[current_index];
}

// void resize(size_type new_capacity)

// Postcondition: The sequence's current capacity is changed to the

// new_capacity (but not less that the number of items already on the

// list). The insert/attach functions will work efficiently (without

// allocating new memory) until this new capacity is reached.

//
void sequence::resize(size_type new_capacity) {
    
    try{
        
        if(new_capacity > used)
            
        {
            
            capacity = new_capacity;
            
            value_type *temp_data = new value_type[capacity];
            
            for(int i=0;i<used;i++)
            
            temp_data[i] = data[i];
            
            delete[] data;
            
            data = temp_data;
            
        }
        
    }catch(bad_alloc &b)
    
    {
        
        cout<<"Insufficient memory"<<endl;
        
    }
    
}
// void start( )

// Postcondition: The first item on the sequence becomes the current item

// (but if the sequence is empty, then there is no current item).

void sequence::start()
{
    current_index = 0;
}

// void advance( )

// Precondition: is_item returns true.

// Postcondition: If the current item was already the last item in the

// sequence, then there is no longer any current item. Otherwise, the new

// current item is the item immediately after the original current item.
void sequence::advance()
{
    // ensure that current_index is valid
    //assert(is_item());
    if((is_item()) && (current_index < used))
        current_index++;
}

// void insert(const value_type& entry)

// Postcondition: A new copy of entry has been inserted in the sequence

// before the current item. If there was no current item, then the new entry

// has been inserted at the front of the sequence. In either case, the newly

// inserted item is now the current item of the sequence.
void sequence::insert(const value_type& entry)
{
    // add additional memory if at capacity
    if(capacity <= used)
        resize(used+1);
    if(!(is_item()))
    {
        if(used == 0)
        {
            data[0] = entry;
            used++;
        }
        else
        {
            start();
            for(size_type i = used; i > current_index; i--)
            data[i] = data[i-1];
            ++current_index;
            data[0] = entry;
            used++;
        }
    }
    else
    {
        for(size_type i = used; i > current_index; i--)
        data[i] = data[i-1];
        data[current_index] = entry;
        used++;
    }
}



// void attach(const value_type& entry)

// Postcondition: A new copy of entry has been inserted in the sequence after

// the current item. If there was no current item, then the new entry has

// been attached to the end of the sequence. In either case, the newly

// inserted item is now the current item of the sequence.

//

void sequence::attach(const value_type& entry)
{
    if(capacity <= used)
        resize(used+1);
    if(!(is_item()))
    {
        data[current_index] = entry;
        used++;
    }
    else
    {
        for(size_type i = used; i > current_index; i--)
        data[i] = data[i-1];
        ++current_index;
        data[current_index] = entry;
        used++;
    }
}
// void remove_current( )

// Precondition: is_item returns true.

// Postcondition: The current item has been removed from the sequence, and the

// item after this (if there is one) is now the new current item.

//

void sequence::remove_current()
{
    assert(is_item());
    if(is_item())
    {
        for(size_type k = current_index; k < used; k++)
        data[k] = data[k+1];
    }
    used--;
}

// Overloaded = operator (as member function)

void sequence::operator=(const sequence& source) {
    
    try{
        
        if(this != &source){
            
            capacity =source.capacity;
            
            delete[] data;
            
            data = new value_type[capacity];
            
            used = source.used;
            
            current_index = source.current_index;
            
            for(int i=0;i<used;i++)
            
            data[i] = source.data[i];
            
        }
        
    }catch(bad_alloc &b)
    
    {
        
        cout<<"Insufficient memory"<<endl;
        
    }
    
}

}

//end of mySequence.cpp

