
#include "deque.h"
#include <utility>

int main( int argc, char* argv [] )
{
   // Examples with exchange:

   std::string s = "hallo"; 
   std::cout << std::exchange( s, "goodbye" ) << "\n";
   std::cout << std::exchange( s, "hello again" ) << "\n";
   std::cout << s << "\n";

#if 1
   //Here my own testing starts
   std::cout <<"\n\nMyTestStart\n\n";


   deque a1;
   std::cout << "Default Constructor: " << a1 << "\n";

   // Test push_back and push_front
   a1.push_back(1);
   a1.push_front(2);
   a1.push_back(3);
   std::cout << "After push operations: " << a1 << "\n";

   // Test pop_back and pop_front
   a1.pop_back();
   a1.pop_front();
   std::cout << "After pop operations: " << a1 << "\n";

   // Test front and back
   std::cout << "Front: " << a1.front() << ", Back: " << a1.back() << "\n";


   // Test accessing and changing front and back values
   a1.front() = 10;
   std::cout << "After changing front value: " << a1 << "\n";
   a1.back() = 20;
   std::cout << "After changing back value: " << a1 << "\n";

   // Test size and empty
   std::cout << "Size: " << a1.size() << ", Empty: " << (a1.empty() ? "true" : "false") << "\n";


   // Test Copy Constructor
   deque a2(a1);
   std::cout << "Copy Constructor: " << a2 << "\n";


   // Test Initializer List Constructor
   deque a3 = {4, 5, 6};
   std::cout << "Initializer List Constructor: " << a3 << "\n";


   // Test reset_front and reset_back
   a3.reset_front(1);
   a3.reset_back(2);
   std::cout << "After reset operations: " << a3 << "\n";


   // Test Copy Assignment
   a2 = a3;
   std::cout << "Copy Assignment: " << a2 << "\n";


   // Test self-assignment
   deque a4 = {1, 2, 3};
   a4 = a4;
   std::cout <<"\n\nMyTestEnd\n\n";

   
   //Here my own testing ends


   deque q;
   std::cout << q. deq_size << "\n";

   q. push_back( 1 );
   q. push_front( 2 );
   q. push_front( 3 );
   q. push_front( 4 );

   q. check_invariant( );

   while( q && false )
   {
      std::cout << q. back( ) << "\n"; 
      std::cout << q << "\n";
      q. pop_back( );
      q. check_invariant( ); 
   }
   q. check_invariant( );
   std::cout << q << "\n";

   deque q2 = { 3.16, 2.718, 3.16 };

   std::cout << q << "\n";
   std::cout << q2 << "\n\n";

   q = std::move(q2); 
   std::cout << q << "\n";
   std::cout << q2 << "\n";

   // Open this when you have rvalue-reference CC and assignment:

   // Exchanges q and q2:

   q2 = std::exchange( q, std::move(q2) );
   std::cout << q << "\n";
   std::cout << q2 << "\n";
 
#else
   std::cout << price(1000) << " " << 1000_kzt << " " << 1000_tt << "\n";

   std::cout << 5 * 500_kzt << "\n";
   std::cout << 300_tt + 400_kzt << "\n";
   std::cout << ( 250_tt == 200_tt + 50_tt ) << "\n";
   std::cout << order( "tiramisu", 1790_tt ) << "\n";
   std::cout << order( "medowik", 1590_tt, 3 ) << "\n";

   deque q;
   q. push_back( { "espresso", 750_tt } );
   std::cout << q << "\n";
   q. push_back( { "esterhazy", 1690_kzt } );
   std::cout << q << "\n"; 
   q. push_back( { "latte macchiato", 1170_tt, 2 } );
   std::cout << q << "\n";

   while( q. size( ) > 3 )
   {
      auto s = std::move( q. front( ));
      std::cout << s << "\n";
      q. pop_front( );
   }

   deque many_orders = 
      {  { "cake", 500_tt }, { "cappuccino", 1170_tt }, 
         { "pavlova", 1990_tt }} ;

   q = many_orders;

   while( q. size( ))
   {
      std::cout << q. front( ) << "\n";
      q. pop_front( );
   }
#endif

   return 0;
}

