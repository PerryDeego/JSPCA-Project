//
//  Time.h
//  JSPCA Project
//
//  Created by Perry  on 08/03/2023.
//

#ifndef Time_h
#define Time_h

#include <iomanip>
#include <iostream>
#include <exception>
#include <stdexcept>

class Time
{
    private:
        // attributes declaration
        int hour;
        int minute;
        int second;

    public:
        ~Time()    { } // destructor

    
        //-------------------------------- constructors ---------------------------------------------//
        Time() //default constructor
        {
            setHour( 00 );
            setMinute( 59 );
            setSecond( 59 );
        }

        Time( int hour, int minute, int second ) // primary constructor
        {
            setHour( hour );
            setMinute( minute );
            setSecond( second );
        }

        Time( const Time &t ) // copy constructor
        {
            setHour( t.getHour() );
            setMinute( t.getMinute() );
            setSecond( t.getSecond() );
        }


        //----------------------------------- mutators --------------------------------//
        void setHour( int h )
        {
            if ( h >= 00 && h <= 23 ) {
                hour = h;
             } //end if
            else {
             throw invalid_argument( "\t\tInvalid hour! Hour format should be [00-23]." );
            } //end else1
        }

        void setMinute( int m )
        {
            if ( m >= 00 && m <= 59 ) {
                minute = m;
            } //end if
            else {
                throw invalid_argument( "\t\tInvalid minute! Minute valid [0-59]" );
            } //end else
        }

        void setSecond( int s )
        {
            if ( s >= 00 && s <= 59 ) {
                second = s;
             } //end if
            else {
             throw invalid_argument( "\t\t Please check second format [00-59]." );
            } //end else1
        }
    
        //----------------------------------- accessors --------------------------------//
        int getHour() const
        {
            return hour;
        }

        int getMinute() const
        {
            return minute;
        }

        int getSecond() const
        {
            return second;
        }


        //----------------------------------- display method --------------------------------//
        void display() const
        {
            std::cout << getHour() << ':' << getMinute() << ':' << getSecond() << std::endl;
        } // end display method
};

#endif /* Time_h */
