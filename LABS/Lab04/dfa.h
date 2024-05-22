
// This code was generated automatically.
// Generator written by Hans de Nivelle and Dina Muktubayeva.

namespace
{
   template< typename S >
   std::pair< inputtype, size_t > readandclassify( int triv, S& inp )
   {
      auto latest = std::make_pair< inputtype, size_t > ( inp_scanerror, 0 );
      if( !inp. has(1))
         return latest;
      char c = inp. peek(0);
      size_t i = 0;

   Q00:
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      switch( c )
      {
      case 13:
      case 32:
         ++ i; goto Q01;
      case 37:
         ++ i; goto Q02;
      case 42:
         ++ i; goto Q03;
      case 43:
         ++ i; goto Q04;
      case 45:
         ++ i; goto Q05;
      case 47:
         ++ i; goto Q06;
      case 48:
         ++ i; goto Q07;
      case 59:
      case 61:
         ++ i; goto Q09;
      case 95:
      case 98:
      case 100:
         ++ i; goto Q10;
      case 94:
         ++ i; goto Q11;
      case 97:
         ++ i; goto Q12;
      case 99:
         ++ i; goto Q13;
      case 101:
         ++ i; goto Q14;
      case 108:
         ++ i; goto Q15;
      case 112:
         ++ i; goto Q16;
      case 115:
         ++ i; goto Q17;
      case 116:
         ++ i; goto Q18;
      case 44:
      case 46:
      case 58:
      case 60:
      case 96:
         return latest;
      }
      if( c >= 62 )
      {
         if( c >= 91 )
         {
            if( c >= 123 ) return latest;
            if( c >= 102 ) { ++ i; goto Q10; }
            if constexpr( true ) return latest;
         }
         else
         {
            if( c >= 65 ) { ++ i; goto Q10; }
            if constexpr( true ) return latest;
         }
      }
      else
      {
         if( c >= 49 ) { ++ i; goto Q08; }
         if( c >= 11 ) return latest;
         if( c >= 9 ) { ++ i; goto Q01; }
         if constexpr( true ) return latest;
      }
   Q01:
      latest. first = inp_whitespace; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 13 || c == 32 ) { ++ i; goto Q01; }
      if( c >= 11 ) return latest;
      if( c >= 9 ) { ++ i; goto Q01; }
      if constexpr( true ) return latest;
   Q02:
      latest. first = inp_mod; latest. second = i;
      return latest;
   Q03:
      latest. first = inp_times; latest. second = i;
      return latest;
   Q04:
      latest. first = inp_plus; latest. second = i;
      return latest;
   Q05:
      latest. first = inp_minus; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 48 ) { ++ i; goto Q07; }
      if( c >= 58 ) return latest;
      if( c >= 49 ) { ++ i; goto Q08; }
      if constexpr( true ) return latest;
   Q06:
      latest. first = inp_div; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 42 ) { ++ i; goto Q19; }
      if( c == 47 ) { ++ i; goto Q20; }
      if constexpr( true ) return latest;
   Q07:
      latest. first = inp_num; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 46 ) { ++ i; goto Q21; }
      if( c == 69 || c == 101 ) { ++ i; goto Q22; }
      if constexpr( true ) return latest;
   Q08:
      latest. first = inp_num; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      switch( c )
      {
      case 46:
         ++ i; goto Q21;
      case 69:
      case 101:
         ++ i; goto Q22;
      case 47:
         return latest;
      }
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q08; }
      if constexpr( true ) return latest;
   Q09:
      latest. first = inp_end; latest. second = i;
      return latest;
   Q10:
      latest. first = inp_ident; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q10; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q11:
      latest. first = inp_pow; latest. second = i;
      return latest;
   Q12:
      latest. first = inp_ident; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      switch( c )
      {
      case 95:
      case 97:
         ++ i; goto Q10;
      case 98:
         ++ i; goto Q23;
      case 96:
         return latest;
      }
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 99 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q13:
      latest. first = inp_ident; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q10; }
      if( c == 111 ) { ++ i; goto Q24; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q14:
      latest. first = inp_e; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q10; }
      if( c == 120 ) { ++ i; goto Q25; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q15:
      latest. first = inp_ident; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q10; }
      if( c == 111 ) { ++ i; goto Q26; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q16:
      latest. first = inp_ident; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q10; }
      if( c == 105 ) { ++ i; goto Q27; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q17:
      latest. first = inp_ident; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      switch( c )
      {
      case 95:
         ++ i; goto Q10;
      case 105:
         ++ i; goto Q28;
      case 113:
         ++ i; goto Q29;
      case 96:
         return latest;
      }
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q18:
      latest. first = inp_ident; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q10; }
      if( c == 97 ) { ++ i; goto Q30; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 98 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q19:
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 42 ) { ++ i; goto Q31; }
      if constexpr( true ) { ++ i; goto Q19; }
   Q20:
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 10 ) { ++ i; goto Q32; }
      if constexpr( true ) { ++ i; goto Q20; }
   Q21:
      latest. first = inp_num; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 69 || c == 101 ) { ++ i; goto Q22; }
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q21; }
      if constexpr( true ) return latest;
   Q22:
      latest. first = inp_num; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 43 || c == 45 ) { ++ i; goto Q33; }
      if( c == 44 ) return latest;
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q34; }
      if constexpr( true ) return latest;
   Q23:
      latest. first = inp_ident; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q10; }
      if( c == 115 ) { ++ i; goto Q35; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q24:
      latest. first = inp_ident; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q10; }
      if( c == 115 ) { ++ i; goto Q36; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q25:
      latest. first = inp_ident; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q10; }
      if( c == 112 ) { ++ i; goto Q37; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q26:
      latest. first = inp_ident; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q10; }
      if( c == 103 ) { ++ i; goto Q38; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q27:
      latest. first = inp_pi; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q10; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q28:
      latest. first = inp_ident; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q10; }
      if( c == 110 ) { ++ i; goto Q39; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q29:
      latest. first = inp_ident; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q10; }
      if( c == 114 ) { ++ i; goto Q40; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q30:
      latest. first = inp_ident; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q10; }
      if( c == 110 ) { ++ i; goto Q41; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q31:
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 42 ) { ++ i; goto Q31; }
      if( c == 47 ) { ++ i; goto Q32; }
      if constexpr( true ) { ++ i; goto Q19; }
   Q32:
      latest. first = inp_comment; latest. second = i;
      return latest;
   Q33:
      latest. first = inp_num; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q34; }
      if constexpr( true ) return latest;
   Q34:
      latest. first = inp_num; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q42; }
      if constexpr( true ) return latest;
   Q35:
      latest. first = inp_abs; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q10; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q36:
      latest. first = inp_cos; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q10; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q37:
      latest. first = inp_exp; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q10; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q38:
      latest. first = inp_log; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q10; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q39:
      latest. first = inp_sin; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q10; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q40:
      latest. first = inp_ident; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q10; }
      if( c == 116 ) { ++ i; goto Q43; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q41:
      latest. first = inp_tan; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q10; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q42:
      latest. first = inp_num; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q44; }
      if constexpr( true ) return latest;
   Q43:
      latest. first = inp_sqrt; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q10; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q10; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q10; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      }
   Q44:
      latest. first = inp_num; latest. second = i;
      return latest;
   }
}

