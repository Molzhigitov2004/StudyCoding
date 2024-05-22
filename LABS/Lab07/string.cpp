
#include "string.h"
#include <utility>


csci152::string::string( ) noexcept
:  cap(0), 
   sz(0), 
   data( nullptr )
{ }


csci152::string::string( string&& s ) noexcept
:  cap(s.cap),
   sz(s.sz),
   data(s.data)
{ 
   s.data = nullptr;
   s.sz = 0;
   s.cap = 0;
}


csci152::string&
csci152::string::operator = ( csci152::string&& s ) noexcept
{
   delete[] data;
   data = s.data;
   sz = s.sz;
   cap = s.cap;
   s.data = nullptr;
   s.sz = 0;
   s.cap = 0;
   return *this;
}

void csci152::string::ensure_capacity( size_t c ) 
{
   if( cap < c )
   {
      if( cap == 0 )
      {
         size_t new_cap = 4;
         char* new_data = new char[new_cap];
         delete[] data;
         data = new_data;
         cap = new_cap;
      }
      else
      {
         // size_t new_cap = c + 1000;
         size_t new_cap = c * 2;
         // size_t new_cap = c * 3;
         char* new_data = new char[new_cap];
         std::copy(data, data + sz, new_data);
         delete[] data;
         data = new_data;
         cap = new_cap;
      }
   }
}


csci152::string::~string( ) noexcept
{
   delete[] data;
   data = nullptr;
}


void csci152::string::push_back( char c )
{
   ensure_capacity(sz+1);
   data[sz++] = c;
}

void csci152::string::pop_back( )
{
   if (sz == 0) {
      return;
   }
   sz--;
}

void csci152::string::clear( )
{
   sz = 0;
}


size_t csci152::string::size( ) const
{
   return sz;
}

bool csci152::string::empty( ) const
{
   return sz == 0;
}


void csci152::string::push_back( const char* s )
{
   if(s){
   for (size_t i = 0; s[i] != '\0'; i++) {
      push_back(s[i]);
   }
   }
}


