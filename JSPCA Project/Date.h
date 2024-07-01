//
//  Date.h
//  JSPCA Project
//
//  Created by Perry  on 08/03/2023.
//

#ifndef Date_h
#define Date_h

#include <unistd.h>
#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

class Date{
    private:
        int day;
        int month;
        int year;

    public:
        ~Date() {} //destructor


        //-------------------------------- constructors ---------------------------------------------//
        Date()
        {
            setDay( 01 );
            setMonth( 01 );
            setYear( 2020 );
        }

        Date( int day, int month, int year )
        {
            setDay( day );
            setMonth( month );
            setYear( year );
        }

        Date( const Date &dt )

        {
            setDay( dt.getDay() );
            setMonth( dt.getMonth() );
            setYear( dt.getYear() );
        }

        //----------------------------------- mutators --------------------------------//
        void setDay(int inDay)
        {
            inDay >= 1 && inDay <= 31 ? day = inDay : throw invalid_argument( "\t\t Please check Valid days [ 1-31 ]..." ); 
        }

        void setMonth( int inMonth )
        {
            inMonth >= 1 && inMonth <= 12 ? month = inMonth : throw invalid_argument( "\t\t Please check valid months [ 1-12 ]..." );
        }

            
        void setYear( int inYear )
        {
            inYear >= 2020 && inYear <= 9999 ? year = inYear  :  throw invalid_argument( "\t\t Please check valid years [ 2020 to 9999 ]" );
        }

        
        //----------------------------------- accessors --------------------------------//
        int getDay() const
        {
            return day;
        }

        int getMonth() const
        {
            return month;
        }

            
        int getYear() const
        {
            return year;
        }


        // Returns true if given year is valid.
        bool isLeap(short year)
        {
            // Return true if year - is a multiple of 4 and - not multiple of 100.
            // Or year is multiple of 400.
            return (((year % 4 == 0) &&
                (year % 100 != 0)) ||
                (year % 400 == 0));
        }

        // Checks that the date entered is valid.
        bool isValidDate(short day, short month, short year)
        {
            short leapyear = 0;

            if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
            {
                leapyear = 1;
            }
            
            if (month < 13)
            {
                if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                {
                    if (day <= 31)
                    {
                        return true;
                    }
                }
                else if (month == 4 || month == 6 || month == 9 || month == 11)
                {
                    if (day <= 30)
                    {
                        return true;
                    }
                }
                else
                {
                    // Check if Feburary is a leap year.
                    if (leapyear == 1)
                    {
                        if (day <= 29)
                        {
                            return true;
                        }
                    }
                    if (leapyear == 0)
                    {
                        {if (day <= 28)
                            return true; }
                    }
                }
            }

            return true;
        }


        void display() const
        {
            std::cout<<getDay()<<"/"<<getMonth()<<"/"<<getYear()<<std::endl;
        }

};

#endif /* Date_h */
