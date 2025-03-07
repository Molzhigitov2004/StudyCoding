
// Written by Hans de Nivelle, March 2021.
// Changed namespace from 'maph' to 'lexing' in March 2023.

#ifndef LEXING_FILEREADER_ 
#define LEXING_FILEREADER_  1

#include <iostream>
#include <string>
#include <string_view>

namespace lexing
{

   class filereader
   {
      std::istream* in;
      std::string buffer;

   public: 
      std::string filename; 

      long unsigned int line;     // We count like computer scientists, 
      long unsigned int column;   // because that's what we are. 

      // Note that default constructor constructs an unusable state.

      filereader( ) :
         in( nullptr ),
         line(0), column(0)
      { }


      filereader( std::istream* in, const std::string& filename ) 
         : in( in ),
           filename( filename ),
           line(0), column(0) 
      { }

      // The moves are transfers of responsability:

      filereader( filereader&& );
      filereader( const filereader & ) = delete;

      filereader& operator = ( const filereader& ) = delete;
      filereader& operator = ( filereader&& );

      bool has( size_t len );
         // True if we have least i characters. If we have less, 
         // we try to read from the file. Therefore we are not const.  
         // After successful has(i), it is guaranteed that we 
         // we have all characters get(i') with i' < i.

      char peek( size_t i ) const;
         // See i-th character in the buffer. It must be in the buffer
         // already, because we won't try to extend the buffer. 
         // This means that has(i') with i' > i must have succeeded before. 

      std::string_view view( size_t i ) const;
         // get a string_view of the initial segment up to, but not 
         // including i.
         // Any non-const operation will spoil this view. 

      void commit( size_t len ); 
         // irreversably move forward. There must be at least len 
         // characters in the buffer, which means that
         // has( len' ) with len' >= len must have succeeded before. 

      bool good( ) const { return in -> good( ); } 
      bool bad( ) const { return in -> bad( ); } 
      bool eof( ) const { return in -> eof( ); }

      void print( std::ostream& ) const; 
   };

   inline 
   std::ostream& operator << ( std::ostream& out, const filereader& read )
   {
      read. print( out );
      return out;
   }

}

#endif

