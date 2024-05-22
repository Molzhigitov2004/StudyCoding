
#include <iostream>
#include <string>
#include "queue.h"

#include <list> 


int main( int argc, char* argv [ ] )
{

#if 1
   queue q;
   q. push(1);
   q. push(2);

   q. push(3);
   q. pop( );

   q. push(4);
   q. push(5);

   q. push(100);
   q. pop( );
   q. printstate( std::cout );

   queue myQueue = {1, 2, 3, 4};

   myQueue.printstate(std::cout);

   myQueue.push(5);
   myQueue.printstate(std::cout);

   myQueue.pop();
   myQueue.printstate(std::cout);
   myQueue.print(std::cout);
   std::cout << std::endl;

   std::cout << "Peek: " << myQueue.peek() << std::endl;
   std::cout << "Size: " << myQueue.size() << std::endl;
   std::cout << "IsEmpty?: " << (myQueue.empty() ? "true" : "false") << std::endl;

   myQueue = myQueue;
   myQueue.printstate(std::cout);

   myQueue.clear();
   myQueue.printstate(std::cout);
   myQueue.pop();

   myQueue = myQueue;
#else
   // Try this with string

   queue q3 = { "this", "is", "a", "queue" };
   std::cout << q3 << "\n";
   q3. pop( ); 
   q3. push( "round" ); 
   std::cout << q3. peek( ) << "\n";
   q3. pop( ); 
   q3. printstate( std::cout ); 
   auto q4 = q3; 

   q4.print(std::cout);

   return 0;
#endif
}
