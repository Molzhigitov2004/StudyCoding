
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


unsigned int date::daysinyear( unsigned int y ) //works
{
   if(isleapyear(y) == true){
      return 366;
   } else {
      return 365;
   }
}

unsigned int date::daysinmonth( unsigned int y, unsigned int m ) //works
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

void date::setdays1jan(unsigned int nrdays)
{
    if (nrdays < leapyear[1]) //Used to handle case when its January
    {
        month = 1;
        day = nrdays + 1;
        return;
    }

    const unsigned int *yearArray = isleapyear(year) ? leapyear : normalyear;
    int i = 1;

    while (nrdays >= yearArray[i])
    {
        nrdays -= yearArray[i];
        i++;

        if (i > 12) 
        {
            if (nrdays == 0)
            {
                month = 12;
                day = 1;
            }
            else
            {
                month = 12;
                day = nrdays;
            }
            return;
        }
    }

    month = i;
    day = nrdays + 1;
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

   return difference;
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
