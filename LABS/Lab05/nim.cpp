
#include "move.h"
#include "state.h"

#include <thread> 
#include <chrono>

enum player { user, computer };

int main( int arg, char* argv[] )
{
   player turn = user;
   srand( time( nullptr ));

#if 1
   state s( 1, 6 );
   //state s = {1,1,1,2,1,1,1};
   while( s. sum( ) > 1 )
   {
      std::cout << '\n';
      std::cout << s << '\n';

      if( turn == user )
      {
         std::cout << "hello, user, please make a move\n";
         auto mov = s. usermove( std::cout, std::cin );
         s. make( mov. value( )); 
         turn = computer; 
      }
      else
      {   
         std::cout << "now I will make a move\n"; 
         std::cout << "thinking\n"; 

         for( unsigned int r = 0; r != 15; ++ r )
         {
            std::cout << '.'; std::cout. flush( ); 
            std::this_thread::sleep_for( std::chrono::milliseconds(100) ); 
         }

         std::cout << '\n';

         std::optional<move> mov = s. removelastmorethantwo( );
         if( !mov )
         mov = s. makenimberzero( );
         if( !mov )
         mov = s. randommove( );
         if( !mov )
         std::abort( );
         s. make( mov. value( ));

         turn = user;
      } 
   }
      
   std::cout << '\n';
   std::cout << s << '\n';

   std::this_thread::sleep_for( std::chrono::milliseconds(500) );

   if( s. sum( ) == 0 )
   {
      if( turn == user )
         std::cout << "you won\n";
      else
         std::cout << "you lost (unnecessarily)\n";
   }
   else
   {
      if( turn == user )
      {
         for( unsigned int i = 0; i < 5; ++ i ) 
         {
            std::cout << "you lost\n";
            std::this_thread::sleep_for( std::chrono::milliseconds(200) );
         }
      }
      else 
         std::cout << "you won\n";
   }

   std::cout << "\n";
#endif 
   return 0;
}


