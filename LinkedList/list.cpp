#include <string>
#include "list.h"
#include <iostream>

using namespace std;

Node::Node(string element)
{
   data = element;
   previous = 0;
   next = 0;
}

List::List()
{
   first = 0;
   last = 0;
}

List::List(List& ListtobeCopied){
   
   // Assign an iterator to the begging of the of the list
   Iterator pos = ListtobeCopied.begin();

   
   // check to see if the list is empty(if the begging of the list is equal to 
   // the end of the list, = empty list)
   if(pos.equals(ListtobeCopied.end())){
      first = nullptr;
      last = nullptr; 
   }
   else{    // create a copy of the original list
      // while loop to go through each posistion of the list till you reach the end
      while(!pos.equals(ListtobeCopied.end())){
         push_back(pos.get());      // creates a new node to store the data of the old list in
         pos.next();
      }
   }
}

void List::push_back(string element)
{
   // cout << element;
   Node *new_node = new Node(element);
   if (last == 0) // List is empty
   {
      first = new_node;
      last = new_node;
   }
   else
   {
      new_node->previous = last;
      last->next = new_node;
      last = new_node;
   }
}

void List::insert(Iterator iter, string element)
{
   if (iter.position == 0)
   {
      push_back(element);
      return;
   }

   Node *after = iter.position;
   Node *before = after->previous;
   Node *new_node = new Node(element);
   new_node->previous = before;
   new_node->next = after;
   after->previous = new_node;
   if (before == 0) // Insert at beginning
   {
      first = new_node;
   }
   else
   {
      before->next = new_node;
   }
}

Iterator List::erase(Iterator iter)
{
   Node *remove = iter.position;
   Node *before = remove->previous;
   Node *after = remove->next;
   if (remove == first)
   {
      first = after;
   }
   else
   {
      before->next = after;
   }
   if (remove == last)
   {
      last = before;
   }
   else
   {
      after->previous = before;
   }
   delete remove;
   Iterator r;
   r.position = after;
   r.container = this;
   return r;
}

Iterator List::begin()
{
   Iterator iter;
   iter.position = first;
   iter.container = this;
   return iter;
}

Iterator List::end()
{
   Iterator iter;
   iter.position = 0;
   iter.container = this;
   return iter;
}

Iterator::Iterator()
{
   position = 0;
   container = 0;
}

string Iterator::get() const
{
   return position->data;
}

void Iterator::next()
{
   position = position->next;
}

void Iterator::previous()
{
   if (position == 0)
   {
      position = container->last;
   }
   else
   {
      position = position->previous;
   }
}

bool Iterator::equals(Iterator other) const
{
   return position == other.position;
}
