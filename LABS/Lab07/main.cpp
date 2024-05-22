
#include <iostream>
#include <vector>

#include "timetable.h"
#include "sorting.h"
#include "string.h"
#include "timer.h"
 
int main( int argc, char* argv[] )
{
 
#if 0
   timetable heap_times( "heapsort" );
   timetable quick_times( "quicksort from library" );
   timetable bubble_times( "bubblesort" );
   timetable insertion_times( "insertion sort" );

   // My experience from earlier, similar tasks is that doubling
   // is much more informative than adding a fixed step.

   for( size_t s = 4000; s < 160000; s *= 2 ) 
   { 
      std::vector<int> test = randomvector(s); 

      { 
         auto v = test; timer t; heap_sort(v); 
         heap_times. insert( s, t. time( )); 
         std::cout << v << "\n";
      }

      {
         auto v = test; timer t; quick_sort(v); 
         quick_times. insert( s, t. time( ));
         std::cout << v << "\n";
      }

      {
         auto v = test; timer t; bubble_sort(v); 
         bubble_times. insert( s, t. time( ));
         std::cout << v << "\n";
      }
 
      {
         auto v = test; timer t; insertion_sort(v); 
         insertion_times. insert( s, t. time( ));
         std::cout << v << "\n";
      }
   }

   std::cout << heap_times << "\n";
   std::cout << quick_times << "\n";
   std::cout << bubble_times << "\n";
   std::cout << insertion_times << "\n";
   std::cout << "this is the total time: ";
   std::cout << heap_times.totaltime( ) + quick_times.totaltime( ) + 
                bubble_times.totaltime( ) + 
                insertion_times.totaltime( ) << "\n";
   // Performance table of heapsort (inputsize/runtime in seconds):
   //      4000/1.2893e-03     8000/7.0888e-04     16000/1.5485e-03     32000/3.3512e-03     64000/5.2444e-03     128000/1.1506e-02

   // Performance table of quicksort from library (inputsize/runtime in seconds):
   //      4000/1.3647e-04     8000/2.8770e-04     16000/7.3985e-04     32000/1.3964e-03     64000/2.8604e-03     128000/6.7542e-03

   // Performance table of bubblesort (inputsize/runtime in seconds):
   //      4000/9.3227e-03     8000/4.1138e-02     16000/1.9700e-01     32000/1.0264e+00     64000/4.7369e+00     128000/1.9421e+01

   // Performance table of insertion sort (inputsize/runtime in seconds):
   //      4000/4.0268e-03     8000/1.6731e-02     16000/7.8231e-02     32000/2.4729e-01     64000/9.5864e-01     128000/3.7347e+00

   // this is the total time: 3.0507e+01

   // Input size of vector was from 4000 to 128000, time taken 30.507 seconds.

   // Based on the data that i got from the testing i can conclude that 
   // Sorting algorithms with O(n^2): Bubblesort, Insertion sort
   // Sorting algorithms with O(n log n): Heapsort, Quicksort
   // But in reality the only algorythm with O(n log n) is Heapsort, and what we got here as a result is actually
   // a Theta θ() time complexety of sorting, and data supports this because in average 
   // Sorting algorithms with θ(n^2): Bubblesort, Insertion sort
   // Sorting algorithms with θ(n log n): Heapsort, Quicksort

#endif

#if 1
   std::cout << "\n";
   std::cout << "measuring performance of string operations\n";

   timetable string_times( "string with multiplying/adding ensure_capacity" );
  
   unsigned int start = 1000000; 
   for( size_t s = start; s < 32 * start; s *= 2 )
   {
      timer t;
      csci152::string str; 
      for( size_t i = 0; i != s; ++ i )  
         str. push_back( 'a' + ( i % 26 ));

      while( str. size( ))
         str. pop_back( ); 
      
      string_times. insert( s, t. time( )); 
   }

   std::cout << string_times << "\n";
// measuring performance of string operations "size_t new_cap = c * 2;"
// Performance table of string with multiplying/adding ensure_capacity (inputsize/runtime in seconds):
// 1000000/2.7707e-03     2000000/3.6470e-03     4000000/7.2549e-03     8000000/1.6723e-02     16000000/3.6047e-02

// measuring performance of string operations "size_t new_cap = c + 1000;"
// Performance table of string with multiplying/adding ensure_capacity (inputsize/runtime in seconds):
// 1000000/1.4482e-01     2000000/4.9416e-01     4000000/2.1199e+00     8000000/9.6759e+00     16000000/3.6203e+01

// measuring performance of string operations "size_t new_cap = c * 3;"
// Performance table of string with multiplying/adding ensure_capacity (inputsize/runtime in seconds):
// 1000000/3.2536e-03     2000000/2.9720e-03     4000000/7.1210e-03     8000000/1.4492e-02     16000000/2.2774e-02

// By analising data from the test I conclude that estimated k values for each case are:
// "size_t new_cap = c * 2;" k = 2
// "size_t new_cap = c + 1000;" k = 1
// "size_t new_cap = c * 3;" k = 2
// However, it is worth noting that the algorithm with 
// с+1000 will take the most time, since we will copy the 
// values every 1000 new elements, but this is more 
// economical in terms of memory. Algorithms with c* 2 
// and c *3 are more efficient, although they can 
// potentially use much more of the necessary computer memory
#endif

   return 0; 
}

 
