
#include <iostream>

#include "date.h"

int main( int argc, char* argv [ ] )
{
   date d1 = date( 1995, 3, 8 );
   date d2 = date( 1995, 3, 8 );
   std::cout << (d1 == d2) << " " << (d1 <= d2) << " " << (d2 <= d1) << "\n";
   // Must print 1 1 1

   d1 = date( 2000, 5, 12 );
   d2 = date( 2000, 3, 7 );
   std::cout << (d1 == d2) << " " << (d1 <= d2) << " " << (d2 <= d1) << "\n";
   // Must print 0 0 1

   d1 = date( 1991, 3, 8 );
   d2 = date( 1990, 5, 12 );
   std::cout << (d1 == d2) << " " << (d1 <= d2) << " " << (d2 <= d1) << "\n";
   // Must print 0 0 1

   std::cout << "\n";
   std::cout << ( d1 == d2 ) << " " << ( d1 != d2 ) << "\n";
   std::cout << ( d1 < d2 ) << " " << ( d1 > d2 ) << "\n";
   std::cout << "\n";

   std::cout << date( 2024,12,31 ). days1jan( ) << "\n";
   std::cout << date( 2024,1,1 ). days1jan( ) << "\n";
   std::cout << date( 2021,3,8 ). days1jan( ) << "\n";
   std::cout << "\n";

   for( unsigned int i = 0; i < 365; ++ i )
   {
      date d1 = { 1992, 1, 1 };
      date d2 = d1; 
      d2. setdays1jan(i);
      if( d2. days1jan( ) != i )
         throw std::logic_error( "something went wrong with day counting" );
   }

   unsigned int totaldays = 0;
   for( unsigned int i = 0; i < 10000; ++ i )
   {
      totaldays += date::daysinyear(i);
   }
   std::cout << "average length of year = " << totaldays / 10000.0;
   // Astronomically correct is 365.2422 

   std::cout << "\n\n";

   std::cout << "Astana has been called Nursultan for ";
   std::cout << date( 2022, 9, 17 ) - date( 2019, 3, 23 ) << " days\n";

   std::cout << "The DDR has existed for ";
   std::cout << date( 1990, 10, 3 ) - date( 1949, 10, 7 ) << " days\n";

   // Turn this on for thorough testing: 

   if constexpr( true )
   {
      date startdate = { 1991, 12, 16 };
      for( int i1 = -1000; i1 != 1000; ++ i1 )
      {
         for( int i2 = -1000; i2 != 1000; ++ i2 ) 
         {
            auto d1 = startdate + i1;
            auto d2 = startdate + i2;
        
            if( d1 - startdate != i1 || startdate - d1 != -i1 )
               throw std::logic_error( "problem with d1" );
            if( d2 - startdate != i2 || startdate - d2 != -i2 )
               throw std::logic_error( "problem with d2" );
            if( d2 - d1 != i2 - i1 )
               throw std::logic_error( "difference is wrong" );
         } 
      }
   }

   std::cout << date( 1900, 1, 1 ). getweekday( ) << "\n";
      // Monday. 
   std::cout << date( 2024, 2, 1 ). getweekday( ) << "\n";
      // Deadline of thie exercise, Thursday.
   std::cout << date( 1959, 2, 3 ). getweekday( ) << "\n";
      // the day the music died, Tuesday. 

   std::cout << date( 1969, 7, 20 ). getweekday( ) << "\n";
      // First moon landing, Sunday. 
   std::cout << date( 1991, 12, 16 ). getweekday( ) << "\n";
      // Independence of Kazakhstan, Monday. 
   std::cout << date( 1961, 4, 12 ). getweekday( ) << "\n";
      // Space flight of Yuri Gagarin, Wednesday. 

   return 0;
}

#include "date.h"

bool date::isleapyear( unsigned int y )
{
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

// This is called 'anonymous namespace'. It prevents that 
// the names are passed to the linker.
// All the tables start with an unused element, because we don't
// use 0 for counting months.

namespace
{
   // Tables start with an unused 0, because we start counting months at 1.

   const unsigned int normalyear[] = 
      { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

   const unsigned int leapyear[] = 
      { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

   // Table starts with an empty string, because we start counting months at 1.

   const char* const monthnames[] = 
      { "", "january", "february", "march", "april",
        "may", "june", "july", "august", "september",
        "october", "november", "december" };
}

bool date::ispossible(unsigned int year, unsigned int month, unsigned int day)
{
    if (isleapyear(year)) {
        if (year > 0 && 0 < month && month < 13 && 0 < day && day <= leapyear[month]) {
            return true;
        }
    } else {
        if (year > 0 && 0 < month && month < 13 && 0 < day && day <= normalyear[month]) {
            return true;
        }
    }
    return false;
}


void date::print_usa(std::ostream& out) const
{
    out << monthnames[month] << " " << day << " " << year << '\n';
}

void date::print_euro(std::ostream& out) const
{
    out << day << " " << monthnames[month] << " " << year << '\n';
}


bool date::operator == ( date other ) const
{
   if(year == other.year && month == other.month && day == other.day){
      return true;
   } else {
      return false;
   }
}

bool date::operator<=(date other) const
{
    if (year < other.year) {
        return true;
    } else if (year > other.year) {
        return false;
    }

    if (month < other.month) {
        return true;
    } else if (month > other.month) {
        return false;
    }

    if(day <= other.day){
      return true;
    } else {
      return false;
    }
}


unsigned int date::daysinyear( unsigned int y )
{
   if(isleapyear(y) == true){
      return 366;
   } else {
      return 365;
   }
}

unsigned int date::daysinmonth( unsigned int y, unsigned int m )
{
   if(isleapyear(y) == true){
      return leapyear[m];
   } else {
      return normalyear[m];
   }
}

unsigned int date::days1jan( ) const //works
{  
   int dayscount = -1;
   if(isleapyear(year) == true){
      for(int i = 1; i < month; i++){
         dayscount = dayscount + leapyear[i];
      }
      return dayscount + day;
   } else {
      for(int i = 1; i < month; i++){
         dayscount = dayscount + normalyear[i];
      }
      return dayscount + day;
   }
}

void date::setdays1jan( unsigned int nrdays ) 
{
   if (nrdays < leapyear[1]) {
      month = 1;
      day = nrdays+1;
      return;
   }
   int i = 1;
   int dayscount = 0;
   int daysleft = 0;
   if(isleapyear(year) == true){
      while( dayscount < nrdays){
         dayscount = dayscount + leapyear[i];
         i++;
      }
   daysleft = nrdays - dayscount;
   month = i;
   i = 1;
   day = daysleft+1;
   } else {
      while( dayscount < nrdays){
         dayscount = dayscount + normalyear[i];
         i++;
      }
   daysleft = nrdays - dayscount;
   month = i;
   i = 1;
   day = daysleft+1;
   } 
}



 
date& date::operator+=(int diff)
{  
    diff += days1jan();
    while (diff < 0){
        year--;
        diff += daysinyear(year); 
    }
    while (diff >= daysinyear(year)){
        diff -= daysinyear(year);
        year++;
    }
    setdays1jan(diff); 

    return *this;
}



int date::operator - (const date& other) const
{
   int daysThis = days1jan();
   int daysOther = other.days1jan();
   int difference = daysThis - daysOther;

   unsigned int y1 = year;
   unsigned int y2 = other.year;

   while (y1 != y2) {
      if (y1 > y2) {
         difference += daysinyear(y2);
         y2++;
      } else {
         difference -= daysinyear(y1);
         y1++;
      }
   }

   return difference; //can return negative value
}

namespace
{
   const char *weekdays[] =
      { "sunday", "monday", "tuesday", "wednesday",
        "thursday", "friday", "saturday" };
}

const char* date::getweekday() const //works
{
    int daysSinceReference = -1;
    daysSinceReference += days1jan();

    if (year >= 2000)
    {
        for (int i = 2000; i < year; i++)
        {
            daysSinceReference += daysinyear(i);
        }
    }
    else
    {
        for (int i = 1999; i >= year; i--)
        {
            daysSinceReference -= daysinyear(i);
        }
    }

    int remainder = daysSinceReference % 7;
    remainder = (remainder < 0) ? remainder + 7 : remainder;

    const char* weekday = weekdays[remainder];
    return weekday;
}

#ifndef DATE_
#define DATE_

#include <iostream>
#include <stdexcept>

struct date
{
   unsigned int year;
   unsigned int month;
   unsigned int day;

   static bool isleapyear( unsigned int y );

   static bool 
   ispossible( unsigned int year, unsigned int month, unsigned int day ); 

   // We have to decide what to do, when 
   // the user is attempting to construct an ill-defined date.

   date( unsigned int year,
         unsigned int month,
         unsigned int day )
      : year( year ), month( month ), day( day )
   { 
         if( !ispossible( year, month, day )){
         throw std::range_error( "tried to construct impossible date" ); 
         }
   }

   void print_usa( std::ostream& out ) const;
   void print_euro( std::ostream& out ) const;

   static unsigned int daysinyear( unsigned int year );
   static unsigned int daysinmonth( unsigned int year, unsigned int month );

   unsigned int days1jan( ) const; 
      // Number of days since 1st of January in our year.

   void setdays1jan( unsigned int nrdays );
      // Set month and day to the nrdays-th day of our year.

   bool operator == ( date other ) const;
   bool operator <= ( date other ) const; 

   date& operator += ( int diff );
   int operator - ( const date& other ) const; 

   const char* getweekday( ) const; 

};

inline bool operator != ( const date& d1, const date& d2 )
   { 
      return !(d1==d2);
   }

inline bool operator < ( const date& d1, const date& d2 )
   { 
      return ((d1 <= d2) && !(d1 == d2));
   }

inline bool operator > ( const date& d1, const date& d2 )
   { 
      return !(d1 <= d2);
   }

inline bool operator >= ( const date& d1, const date& d2 )
   { 
      return !((d1 <= d2) && !(d1 == d2));
   }

inline std::ostream& operator << ( std::ostream& out, const date& d )
   { 
      d.print_euro(out);
      return out;
   }

inline date& operator -= ( date& d, int x ) { return d += -x; }  
inline date operator + ( date d, int x ) { d += x; return d; }
inline date operator - ( date d, int x ) { d += -x; return d; }

#endif
