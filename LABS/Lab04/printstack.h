
#ifndef PRINTSTACK_
#define PRINTSTACK_

#include <iostream>
#include <stack>

// prints [ ...,  .... 

template< typename T >
void printtop( std::ostream& out, std::stack<T> & s, size_t n )
{
   if( s. empty( ))
      out << "[";
   else
   {
      if( n == 0 )
         out << " [ ...";
      else
      {
         auto t = std::move( s. top( ));
         s. pop( ); 
         bool empty = s. empty( );
         printtop( out, s, n - 1 );

         if( empty )
            out << ' ' << t;
         else
            out << ", " << t; 
      }
   } 

}

template< typename T >
std::ostream& operator << ( std::ostream& out, std::stack<T> s )
{
   printtop( out, s, 10 );
   out << " ]";
   return out;
}


#endif

