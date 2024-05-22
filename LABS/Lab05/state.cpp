
#include "state.h"
#include <string>

state::state( std::initializer_list< unsigned int > init )
{ 
   for(size_t val : init){
      sticks.push_back(val);
   }
}

state::state( unsigned int i1, unsigned int i2 )
{ 
   for (size_t i = i1; i <= i2; ++i) {
      sticks.push_back(i);
   }   
}

unsigned int state::sum( ) const 
{ 
   int sum = 0;
   for(unsigned int i = 0; i < sticks.size(); i++){
      sum = sum + sticks[i];
   }
   return sum;
}

std::optional< move > state::randommove( ) const 
{ 
   if (sum()>0){
      int RowChosen = rand() % sticks.size();
      while(sticks[RowChosen] == 0){
         RowChosen = rand() % sticks.size();
      }
      unsigned int SticksLeft = rand() % sticks[RowChosen];
      while(SticksLeft == sticks[RowChosen]){
         SticksLeft = rand() % sticks[RowChosen];
      }
      return move(RowChosen, SticksLeft);
   } else {
      return std::nullopt;
   }
}

std::optional< move > state::removelastmorethantwo( ) const{ //works
   int counter1 = 0;
   for(size_t i = 0; i < sticks.size(); i++){
      if(sticks[i] >= 2){
         counter1++;
      }
   }

   if(counter1 != 1){
      return std::nullopt;
   }

   int OneStickRows = 0;

   for(size_t i = 0; i < sticks.size(); i++){
      if(sticks[i] == 1){
         OneStickRows++;
      }
   }

   int targetBit = (OneStickRows % 2 == 0) ? 1 : 0;

   for(size_t i = 0; i < sticks.size(); i++){
    if(sticks[i] > 1){
        return move(i, targetBit);
    }     
   }
   
   return std::nullopt;

}

unsigned int state::nimber( ) const{ //works
   unsigned int result = 0;

   for(size_t i = 0; i < sticks.size(); i++){
      result = result^sticks[i];
   }

   return result;
}

std::optional<move> state::makenimberzero() const {
    while (nimber() != 0) {

      size_t RowChosen = rand() % sticks.size();
      while (sticks[RowChosen] == 0) {
         RowChosen = rand() % sticks.size();
      }

      unsigned int nimberBeforeMove = 0;
      for(size_t i = 0; i < sticks.size(); i++){
         if(i != RowChosen){
            nimberBeforeMove = nimberBeforeMove^sticks[i];
         }
      }

      for (size_t i = 0; i < sticks[RowChosen]; i++) {
               if((nimberBeforeMove^i) == 0){
                  return move(RowChosen, i);
               }
      }
   }

   return std::nullopt;
}


std::optional< move >
state::usermove( std::ostream& out, std::istream& in ) const
{
   // It seems to me that usermove( ) is the same as randommove( ),
   // with the only difference that rand( ) should be replaced by
   // user( ). We could make it into a template. 

   if( sum( ))
   {
      while( true )
      {
         std::string inp;
         try
         {
            out << "row? "; out. flush( );
            in >> inp; 

            unsigned int row = std::stoul( inp ); inp. clear( );

            if( row > 0 && row <= sticks. size( )) 
            {
               unsigned int row1 = row - 1;  // This is a type conversion! 
               if( sticks[ row1 ] )
               {
                  out << "how many remaining? "; out. flush( );
                  in >> inp; 
                  unsigned int remain = std::stoul( inp ); inp. clear( ); 

                  if( remain < sticks[ row1 ] )
                     return move( row1, remain );
                  else
                  {
                     out << "having " << remain 
                         << " remaining is not possible, "
                         << "you have to remove at least one stick\n";
                  }
               }
               else 
               {
                  out << "row " << row << " is already empty\n";
               }
            }
            else
            {
               out << "row " << row << " is not a valid row, ";
               out << "rows are between 1 and " << sticks. size( ) << "\n";
            }
            
         }
         catch( std::invalid_argument& inv )
         {
            out << inp << " is not a number\n";
         }
         catch( std::out_of_range& r )
         {
            out << inp << " is too big\n";
         }
      }
   }
   else
      return std::optional< move > ( );
}


void state::make(move m) {
    if (m.row < 0 || m.row >= sticks.size()) {
        std::cerr << "Error: Invalid row in the move.\n";
        std::abort();
    }

    if (m.remaining < 0 || m.remaining >= sticks[m.row]) {
        std::cerr << "Error: Invalid number of sticks in the move.\n";
        std::abort();
    }

    if (sticks[m.row] == 0) {
        std::cerr << "Error: Chosen row is empty.\n";
        std::abort();
    }

    sticks[m.row] = m.remaining;
}


void state::print( std::ostream& out ) const
{ 
   for(size_t i = 0; i < sticks.size(); i++ ){
      out << i + 1 << "   : ";
      for(size_t j = 0; j < sticks[i]; j++){
         out << " 1";
      }
   out <<"\n";
   }
}


