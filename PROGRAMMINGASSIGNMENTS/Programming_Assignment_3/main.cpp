
#include <random>
#include <algorithm>

#include "set.h"
#include "timetable.h"
#include "timer.h"


std::vector< int > randomvector( size_t sz ) 
{
   std::vector< int > res; 
   for( size_t i = 0; i != sz; ++ i )
   {
      res. push_back( rand( ) ); 
   } 
   return res;
}

   
int main( int argc, char* argv[ ] )
{

#if 0
   // A few simple tests with std::string.

   set small;    // A small test tree.

   std::cout << small. height( ) << "\n";
   small. insert( "if" ); 
   std::cout << small. height( ) << "\n"; 
   small. insert( "thE" ); 
   std::cout << small. height( ) << "\n";
   small. insert( "vaLue" );
   std::cout << small << "\n";
   std::cout << small. height( ) << "\n";
   // small. clear( );
   std::cout << "this is the tree: " << small << "\n";
   set small3 = small; 
   std::cout << small3 << "\n";

   std::cout << small. contains( "Xx" ) << "\n";
   std::cout << small. contains( "vAlUe" ) << "\n";

#endif

#if 0
   // Some more tests with std::string: 
   // Make sure that your set is case insensitive.
   small. insert( "oskemen" );
   std::cout << small. contains( "kostanay" ) << "\n";

   small. insert( "atyrau" );
   small. insert( "nursultan" );
   small. insert( "Almaty" );
   small. insert( "shymkent" ); 
   small. insert( "almaty" ); 
   small. insert( "pavlodar" );

   small. insert( "PavloDar" ); 
   small. insert( "sHYmKeNt" );  
   std::cout << small << "\n";
   return 0;
   small. remove( "PavLoDar" );
   small. remove( "almaty" );
   std::cout << small. remove( "if" );

   std::cout << small << "\n";

   small. checksorted( );
   std::cout << small << "\n"; 
   std::cout << small. size( ) << "\n";
   std::cout << "Height is " << small. height( );
   std::cout << " should be approximately " << 
     log_base2( small. size( )) << "\n";
      // If the numbers differ much, the tree is badly balanced. 

   auto small2 = small; // Copy constructor. 
   std::cout << small2 << "\n";
   std::cout << "size = " << small2. size( ) << "\n";
   std::cout << "height = " << small2. height( ) << "\n";
   small2 = small;      // Assignment.
   small = small;       // Self assignment.

#endif 

#if 1
   // Measurements using int.

   timetable tab( std::string( "BST-based set" ));

   for( size_t s = 1000; s < 4096 * 1000; s = 2 * s ) 
   {
      std::cout << "----------------------------------------\n";

      // Create random test set of size s:

      std::vector< int > values = randomvector(s);
      
      //  Turn on if you want to see the test vector.

      bool i_want_to_see_the_test_vector = false;
      if( i_want_to_see_the_test_vector )
      {
         std::cout << "values: ";
         for( const auto& s : values )
            std::cout << s << " ";
         std::cout << "\n";
      }

      // Uncomment to see the performance of a badly balanced tree:

      bool i_want_to_see_the_bad_performance_of_an_unbalanced_tree = false; 
      if( i_want_to_see_the_bad_performance_of_an_unbalanced_tree )
      { 
         std::sort( values. begin( ), values. end( ));
      }
      set someset1;

      timer tt; 
      size_t nr_insertions = 0;
      size_t nr_deletions = 0;

      for( size_t i = 0; i != values. size( ); ++ i ) 
      {
         nr_insertions += someset1. insert( values[i] );
      }

      // We do some deletions too:

      for( const auto& s : values )
      {
         // Remove the odd values:

         if( s & 1 )
            nr_deletions += someset1. remove( s );

         nr_deletions += someset1. remove( s + 2 );  // Probably not there.
      }
    
      // std::cout << someset1 << "\n";
      std::cout << nr_insertions << " " << nr_deletions << "\n";

      auto someset2 = someset1;

      if( nr_insertions - nr_deletions != someset2. size( )) 
      {
         std::cout << "nr = " << nr_insertions << "\n";
         std::cout << "size( ) = " << someset2. size( ) << "\n"; 
         throw std::runtime_error( 
                       "something went wrong with counting insertions" );
      }

      // Don't use size( )! It is O(n), and will mess up your performance. 

      tab. insert( s, tt. time( )); 

      std::cout << "number of insertions " << nr_insertions << "\n";
      std::cout << "number of deletions " << nr_deletions << "\n"; 
      std::cout << "tree-height = " << someset2. height( ) << ", " << "log_base2 = " << log_base2( someset2. size( )) << "\n";

      std::cout << "finished test for " << s << "\n";
   } 

   std::cout << tab << "\n"; 
   std::cout << "totaltime " << tab. totaltime( ) << "\n";
#endif

#if 0
// MyTest Start//
   //Log2
   std::cout << log_base2(0) << "\n"; // must print 0.
   std::cout << log_base2(1) << "\n"; // must print 0.
   std::cout << log_base2(2) << "\n"; // must print 1.
   std::cout << log_base2(15) << "\n"; // must print 3.
   std::cout << log_base2(16) << "\n"; // must print 4.


   set testSet;
   //Insert
   testSet.insert(10);
   testSet.insert(5);
   testSet.insert(15);
   testSet.insert(7);
   testSet.insert(4);
   testSet.insert(14);
   testSet.insert(16);
   testSet.checksorted();

   // Print the set after insertion
   std::cout << "Set after insertion: \n";
   testSet.print(std::cout);


   //Contains
   int valToCheck = 5;
   if (testSet.contains(valToCheck)) {
      std::cout << valToCheck << " is present in the set.\n";
   } else {
      std::cout << valToCheck << " is not present in the set.\n";
   }
   int valToCheck1 = 70;
   if (testSet.contains(valToCheck1)) {
      std::cout << valToCheck1 << " is present in the set.\n";
   } else {
      std::cout << valToCheck1 << " is not present in the set.\n";
   }


   //Size and height
   std::cout << "Size of the set: " << testSet.size() << std::endl;  // Expected: 7
   std::cout << "Height of the set: " << testSet.height() << std::endl;  // Expected: 3


   // Copy constructor
   set copiedSet(testSet);
   std::cout << "Copied set after using copy constructor:\n";
   copiedSet.print(std::cout);
   std::cout << "Size of copied set: " << copiedSet.size() << std::endl; 
   std::cout << "Height of copied set: " << copiedSet.height() << std::endl; 
   std::cout << std::endl;

   // Assignment operator
   set assignedSet;
   assignedSet = testSet;
   std::cout << "Set after using assignment operator:\n";
   assignedSet.print(std::cout);
   std::cout << "Size of assigned set: " << assignedSet.size() << std::endl; 
   std::cout << "Height of assigned set: " << assignedSet.height() << std::endl; 


   // Remove
   int valToRemove = 10;
   if (testSet.remove(valToRemove)) {
      std::cout << valToRemove << " was successfully removed from the set.\n";
   } else {
      std::cout << valToRemove << " was not found in the set.\n";
   }
   valToRemove = 70;
   if (testSet.remove(valToRemove)) {
      std::cout << valToRemove << " was successfully removed from the set.\n";
   } else {
      std::cout << valToRemove << " was not found in the set.\n";
   }

   // Print the set after removal
   std::cout << "Set after removal: \n";
   testSet.print(std::cout);
   testSet.checksorted();


   // Empty 
   std::cout << "Is testSet empty? " << (testSet.empty() ? "Yes" : "No") << std::endl; 

   // Clear 
   copiedSet.clear();
   std::cout << "Is copiedSet empty after clear? " << (copiedSet.empty() ? "Yes" : "No") << std::endl;
   #endif
}

//Balansed Tree
// Performance table of BST-based set (inputsize/runtime in seconds):
//      1000/8.0955e-04     2000/1.6728e-03     4000/3.9862e-03     8000/8.7107e-03     16000/1.4108e-02     32000/1.8624e-02     64000/3.3383e-02     
//      128000/1.0312e-01     256000/1.4101e-01     512000/3.6639e-01     1024000/1.0240e+00     2048000/2.4484e+00

// totaltime 4.1642e+00



//Unbalanced Tree
// Performance table of BST-based set (inputsize/runtime in seconds):
//      1000/2.4641e-03     2000/6.6870e-03     4000/3.0060e-02     8000/1.1398e-01     
//      16000/4.5719e-01     32000/1.9309e+00     64000/7.4963e+00     128000/3.0119e+01

// totaltime 4.0156e+01