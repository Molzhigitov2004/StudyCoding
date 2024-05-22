
#include <random>
#include <algorithm>
#include <sstream>

#include "map.h"
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
   {
      map deutsch;
      deutsch[ "null" ] = 0;
      deutsch[ "eins" ] = 1;
      deutsch[ "zwei" ] = 2;
      deutsch[ "drei" ] = 3;
      deutsch[ "vier" ] = 4;
      deutsch[ "fuenf" ] = 5;
      deutsch[ "sechs" ] = deutsch[ "fuenf" ];
      deutsch[ "sechs" ] ++; 
      deutsch[ "sieben" ] = 7;
      deutsch[ "acht" ] = deutsch[ "sieben" ] + 1;
      deutsch[ "neun" ] = 9;
      deutsch[ "zehn" ] = deutsch. at( "neun" ) + 1;
      std::cout << deutsch << "\n";
      std::cout << deutsch. size( ) << "\n";
   }
#endif

#if 0
   {
      map kazakh;
      kazakh[0] = "nol";
      kazakh[1] = "bir";
      kazakh[2] = "eki";
      kazakh[3] = "ush";
      kazakh[4] = "tort";
      kazakh[5] = "bes";
      kazakh[6] = "alty";
      kazakh[7] = "zheti";   
      kazakh[8] = "segiz";
      kazakh[9] = "toryz";
      kazakh[10] = "on";

      std::cout << kazakh << "\n";
      return 0;
   }
#endif

#if 0 
   { 
      // Tests for case insensitive map:

      map small;    // A small test map.

      small[ "the" ] = 4;
      std::cout << small[ "The" ] << "\n";

      small[ "notthere" ] ++ ;

      small. insert( "if", 2 ); 
      small[ "the" ] = 3;
      small[ "value" ] = 5;
      small. insert( "aaa", 4 );
      small. insert( "aAa", 4 );
      small. insert( "ccc", 2 );
      small. insert( "xyz", 2 );
      small. insert( "XYZ", 2 );
      small. insert( "ssss", 4 );

      std::cout << small. at( "xYZ" ) << "\n";
      small. at( "ssss" ) = 55;

      std::cout << small << "\n";
      std::cout << small. size( ) << "\n";

      map small3 = small; 
      small. clear( );
      std::cout << "this is the hash map after clear:\n" << small << "\n";
      std::cout << small3 << "\n";

      small = std::move( small3 );
      std::cout << "small3\n";
      std::cout << small3 << "\n";

      std::cout << small << "\n";
      std::cout << small. contains( "xx" ) << "\n";
      std::cout << small. at( "CCC" ) << "\n";
         // To contain or not to contain, that's the question. 

      return 0;
   }
#endif

#if 1
   // Measurements using int -> int.

   timetable tab( std::string( "map" ));

   for( size_t s = 1000; s < 4096 * 1000; s = 2 * s )
   {
      std::cout << "----------------------------------------\n";

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

      map somemap1;

      timer tt;
      size_t nr_insertions = 0;
      size_t nr_deletions = 0;

      for( size_t i = 0; i != values. size( ); ++ i )
      {
         nr_insertions += somemap1. insert(
                              std::to_string( values[i] ), values[i] );
      }

      // We do some deletions too:

      for( const auto& s : values )
      {
         // Remove the odd values:

         if( s & 1 )
            nr_deletions += somemap1. erase( std::to_string(s));

         nr_deletions += somemap1. erase( std::to_string( s + 2 ));  
                                     // Probably not there.
      }

      // std::cout << somemap1 << "\n";

      std::cout << nr_insertions << " " << nr_deletions << "\n";

      auto somemap2 = somemap1;

      if( nr_insertions - nr_deletions != somemap2. size( ))
      {
         std::cout << "nr = " << nr_insertions << "\n";
         std::cout << "size( ) = " << somemap2. size( ) << "\n";
         throw std::runtime_error(
                       "something went wrong with counting insertions" );
      }

      tab. insert( s, tt. time( ));

      std::cout << "number of insertions " << nr_insertions << "\n";
      std::cout << "number of deletions " << nr_deletions << "\n";
  
      somemap1. printstatistics( std::cout ); 
   }

   std::cout << tab << "\n"; 
   std::cout << "totaltime " << tab. totaltime( ) << "\n";
   //Performance table of map (inputsize/runtime in seconds): //Here is my test result, seems to me like O(n)
   //1000/6.7615e-04     2000/6.9739e-04     4000/1.5622e-03     8000/3.6592e-03     
   //16000/6.2704e-03     32000/2.4238e-02     64000/6.3273e-02     128000/7.8314e-02     
   //256000/1.8990e-01     512000/3.6829e-01     1024000/8.1808e-01     2048000/1.8989e+00
#endif

#if 0
// MyTest Starts here

   map MyTest;
   MyTest[ "nol" ] = 0;
   MyTest[ "odin" ] = 1;
   MyTest[ "dva" ] = 2;
   MyTest[ "tree" ] = 3;
   MyTest[ "chetire" ] = 4;

// Test case-insensitive hash
   case_insensitive_hash hash;
   std::cout << "Hash value for 'CheTirE': " << hash("CheTirE") << std::endl;
   std::cout << "Hash value for 'chetire': " << hash("chetire") << std::endl;
   std::cout << MyTest << "\n";


   std::cout << "Number of buckets needed for size 10: " << MyTest.nrbuckets_needed(10) << std::endl;

   std::cout << "Map contains key 'chetire': " << MyTest.contains("chetire") << std::endl;

   std::cout << "Inserting key 'pyat': " << MyTest.insert("pyat", 5) << std::endl;
   std::cout << "Inserting key 'pyat' again: " << MyTest.insert("pyat", 5) << std::endl;
   std::cout << MyTest << "\n";

   std::cout << "Value at key 'odin': " << MyTest.at("odin") << std::endl;

   std::cout << "Value at key 'shest': " << MyTest["shest"] << std::endl;

   std::cout << "Erasing key 'dva': " << MyTest.erase("dva") << std::endl;
   std::cout << MyTest << "\n";

   std::cout << "Map size: " << MyTest.size() << std::endl;
   std::cout << "Map empty: " << MyTest.empty() << std::endl;
   std::cout << MyTest << "\n";

   MyTest.clear();
   std::cout << "Map size after clear: " << MyTest.size() << std::endl;
   std::cout << "Map empty after clear: " << MyTest.empty() << std::endl;
   std::cout << MyTest << "\n";

// MyTest Ends here
#endif
}

