
#include "queue.h"
#include <algorithm>

void queue::checkinvariant( ) const
{
   if( current_capacity < 2 )
   {
      std::cout << "current capacity < 2\n";
      printstate( std::cout );
      std::abort( );
   }

   if( current_size > current_capacity )
   {
      std::cout << "current_size > current_capacity\n";
      printstate( std::cout );
      std::abort( );
   }

   if( current_front >= current_capacity )
   {
      std::cout << "current_front >= current_capacity\n";
      printstate( std::cout );
      std::abort( );
   }
}


void queue::printstate( std::ostream& out ) const
{
   size_t current_end = current_front + current_size;
   if( current_end >= current_capacity )
      current_end -= current_capacity;
   
   if( current_front + current_size < current_capacity )
   {
      for( size_t i = 0; i != current_front; ++ i )
         out << ".   ";
      out << "(front)   ";
      for( size_t i = current_front; i != current_end; ++ i )
         out << data[i] << "   ";
      for( size_t i = current_end; i != current_capacity; ++ i )
         out << ".   ";
   }
   else
   {
      for( size_t i = 0; i != current_end; ++ i )
         out << data[i] << "   ";
      for( size_t i = current_end; i != current_front; ++ i )
         out << "X   ";
      out << "(front)   ";
      for( size_t i = current_front; i != current_capacity; ++ i )
         out << data[i] << "   ";
   }
   out << "\n";
}


queue::queue( ): //works
   current_capacity(4),
   data(new valtype[4]),
   current_size(0),
   current_front(0)
{ }

queue::valtype* queue::makecopy( size_t c ) const //works
{
   if( c < current_size ){
      throw std::logic_error( "makecopy: c is too small" );
   }
   valtype* new_data(new valtype[c]);
   if (current_front + current_size <= current_capacity) {
      std::copy(data + current_front, data + current_front + current_size, new_data);
   } else {
      std::copy(data + current_front, data + current_capacity, new_data);
      std::copy(data, data + (current_size - (current_capacity - current_front)), new_data + (current_capacity - current_front));
   }
   return new_data;
}


void queue::ensure_capacity( size_t c ) //works
{ 
   if(c <= current_capacity){
      return;
   } else {
      size_t new_cap = current_capacity;
      while(new_cap < c){
      new_cap = 2 * new_cap;
      }
      valtype* new_data = makecopy(new_cap);
      delete[] data;
      data = new_data;
      current_capacity = new_cap;
      current_front = 0;
   }
}
 

void queue::push( const valtype& val ) //works
{ 
   ensure_capacity(current_size+1);
   data[((current_front + current_size) % current_capacity)] = val;
   current_size++;
}


void queue::pop( ) //works
{ 
   if (current_size == 0) {
      throw std::out_of_range("pop: queue is empty");
   }
   current_size--;
   current_front = (current_front + 1) % current_capacity;
}

const queue::valtype& queue::peek( ) const //works
{ 
   if (current_size == 0) {
      throw std::out_of_range("peek: queue is empty");
   }
   return data[current_front];
}

queue::~queue( )
{ 
   delete[] data;
}

queue::queue(const queue& q) //works
   : current_capacity(q.current_capacity),
     data(q.makecopy(q.current_capacity)),
     current_size(q.current_size),
     current_front(0)
{ }

const queue& queue::operator = ( const queue& q ) //works
{ 
   if (this == &q) {
      return *this;
   }
   delete[] data;
   data = q.makecopy(q.current_capacity);
   current_capacity = q.current_capacity;
   current_size = q.current_size;
   current_front = 0;   

   return *this;
}

void queue::print(std::ostream& out) const //works
{
   if (current_size == 0) {
      out << "Queue is empty.\n";
      return;
   }

   out << "[";
   size_t count = 0;

   for (size_t i = current_front; count < current_size; i = (i + 1) % current_capacity) {
      if (count > 0) {
         out << ",";
      }
      out << data[i];
      ++count;
   }

   out << "]";
}

void queue::clear( )//works
{ 
   current_size = 0;
   current_front = 0;   
}

size_t queue::size( ) const//works
{ 
   return current_size;
}


bool queue::empty( ) const//works
{ 
   return (current_size == 0);
}


queue::queue(std::initializer_list<valtype> values)
   : current_capacity(values.size() >= 4 ? values.size() : 4),
   data(new valtype[current_capacity]),
   current_size(values.size()),
   current_front(0)
{
   std::copy(values.begin(), values.end(), data);
}

