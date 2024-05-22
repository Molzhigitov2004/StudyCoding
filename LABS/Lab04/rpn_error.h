
#ifndef RPN_ERROR_
#define RPN_ERROR_  1

#include <string>
#include <iostream>

struct rpn_error 
{
   std::string cause;
   long unsigned int line;
   long unsigned int column;

   rpn_error( const std::string& cause,
              long unsigned int line, long unsigned int column )
      : cause( cause ),
        line( line ),
        column( column )
   { }

};

inline std::ostream& operator << ( std::ostream& out, const rpn_error& e )
{
   out << e.cause << " at position " << e.line+1 << "/" << e.column+1;
   return out;
}

#endif

