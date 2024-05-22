
#include "deque.h"
#include <utility>

void deque::check_invariant( ) const
{
   if( deq_size == 0 )
   {
      if( deq_front )
         throw std::logic_error( "size == 0, but front != nullptr" );
      if( deq_back )
         throw std::logic_error( "size == 0, but back != nullptr" );
   }
   else
   {
      size_t truesize = 0;

      if( deq_front -> prev )
         throw std::logic_error( "prev of front not nullptr " );
      if( deq_back -> next )
         throw std::logic_error( "next of back not nullptr" );

      for( auto p = deq_front; p; p = p -> next ) 
      {
         // If p has a next, its prev must be p.
         // If p has no next, p must be the back of the deque. 

         if( p -> next )
         {
            if( p -> next -> prev != p )
               throw std::logic_error( "prev or next is wrong" );
         }
         else
         {
            if( p != deq_back )
               throw std::logic_error( "deq_back is wrong" );
         } 
         ++ truesize;
      } 

      if( truesize != deq_size )
         throw std::logic_error( "deq_size is wrong" ); 
   }
}


deque::deque( ) noexcept //completed //works
:  deq_size(0),
   deq_front(nullptr),
   deq_back(nullptr)
{ }



void deque::push_back( const valtype& val ) //completed //works
{
   node* new_node = new node(val);
   if(deq_size == 0){
      deq_back = deq_front = new_node;
   } else {
      deq_back->next = new_node;
      new_node->prev = deq_back;
      deq_back = new_node;
   }
   deq_size++;
}

void deque::pop_back( ) //completed //works
{
   if(deq_size == 0){
      throw std::out_of_range("Deque is empty");
   } else if(deq_size == 1){
      delete (deq_back);
      deq_back = deq_front = nullptr;
      deq_size--;
   } else {
      node* NewBack = deq_back->prev;
      NewBack->next = nullptr;
      delete(deq_back);
      deq_back = NewBack;
      deq_size--;
   }
}

const deque::valtype& deque::back( ) const //completed //works
{
   return deq_back->val;
}

deque::valtype& deque::deque::back( ) //completed //works
{
   return deq_back->val;
}

// front methods:

void deque::push_front( const valtype& val ) //completed //works
{
   node* new_node = new node(val);
   if(deq_size == 0){
      deq_back = deq_front = new_node;
   } else {
      deq_front->prev = new_node;
      new_node->next = deq_front;
      deq_front = new_node;
   }
   deq_size++;  
}

void deque::pop_front( ) //completed //works
{
   if(deq_size == 0){
      throw std::out_of_range("Deque is empty");
   } else if(deq_size == 1){
      delete (deq_front);
      deq_back = deq_front = nullptr;
      deq_size--;     
   } else {
      node* NewFront = deq_front->next;
      NewFront->prev = nullptr;
      delete(deq_front);
      deq_front = NewFront;
      deq_size--;
   }  
}


const deque::valtype& deque::front( ) const //completed //works
{
   return deq_front->val;
}

deque::valtype& deque::deque::front( ) //completed //works
{
   return deq_front->val;
}

void deque::print( std::ostream& out ) const //completed //works //corrected
{  
   out << "[ ";
   node* current = deq_front;
   while (current != nullptr) {
      out << current->val;
      if (current->next != nullptr) {
         out << ", ";
      }
      current = current->next;
   }
   out << " ]";
}


deque::deque(const deque& q) //completed //works
:  deq_size(0),
   deq_front(nullptr), 
   deq_back(nullptr){
    node* current = q.deq_front;
    while (current != nullptr) {
         push_back(current->val);
         current = current->next;
    }
}


deque::deque(std::initializer_list<valtype> init) //completed //works
:  deq_size(0),
   deq_front(nullptr), 
   deq_back(nullptr){
      auto current = init.begin();
      while (current != init.end()) {
         push_back(*current);
         ++current;
    }
}


deque:: ~deque( ) //completed //works
{
    node* current = deq_front;
    while (current != nullptr) {
      node *next = current->next;
      delete (current);
      current = next;
    }
    deq_front = nullptr;
    deq_back = nullptr;
}


void deque::reset_front( size_t s ) //completed //works
{
   if(deq_size < s){
      return;
   } else {
   while(deq_size != s){
      pop_front();
   }      
   }
}

void deque::reset_back( size_t s ) //completed //works
{
   if(deq_size < s){
      return;
   } else {
   while(deq_size != s){
      pop_back();
   }
   }
}


const deque& deque::operator = ( const deque& q ) //completed //works //corrected
{
   if (this == &q) {
      return *this;
   }
   node* current = deq_front;
   while (current != nullptr) {
      node* next = current->next;
      delete current;
      current = next;
   }
   deq_front = nullptr;
   deq_back = nullptr;
   deq_size = 0;

   current = q.deq_front;
   while (current != nullptr) {
      push_back(current->val);
      current = current->next;
   }

   return *this;
}

size_t deque::size( ) const //completed //works
{
   return deq_size;
}

bool deque::empty( ) const //completed //works
{
   return (deq_size == 0);
}


deque::deque( deque&& q ) noexcept //completed //works
:  deq_size(q.deq_size), 
   deq_front(q.deq_front), 
   deq_back(q.deq_back)
{ 
   q.deq_size = 0;
   q.deq_front = nullptr;
   q.deq_back = nullptr;   
}


const deque& deque::operator = ( deque&& q ) noexcept //completed //works
{

      node* current = deq_front;
      while (current != nullptr)
      {
         node* next = current->next;
         delete current;
         current = next;
      }

      deq_size = q.deq_size;
      deq_front = q.deq_front;
      deq_back = q.deq_back;

      q.deq_size = 0;
      q.deq_front = nullptr;
      q.deq_back = nullptr;
   return *this;
}

