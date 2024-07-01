//
//  Intervention.h
//  JSPCA Project
//
//  Created by Perry  on 08/03/2023.
//

#ifndef Intervention_h
#define Intervention_h

#include "Date.h"
#include "Client.h"

#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <exception>
#include <stdexcept>

using namespace std;

class Intervention
{
    protected:
        // attributes declaration
        int interventionNumber;
        string dateTime;
        Client client;

    public:
        //-------------------------------- destructor reclaims memory ----------------------------------//
        virtual ~Intervention() {}

        //-------------------------------- default constructor ---------------------------------------------//
        Intervention()
            : client()
        {
            setInterventionNumber( 0 );
            setDateTime( "Date Time" );
        }

        //-------------------------------- primary constructor ---------------------------------------------//
        Intervention( int interventionNumber, string dateTime, Client iClient )
            : client( iClient )
        {
            setInterventionNumber( interventionNumber );
            setDateTime( "dateTime" );
        }

        //-------------------------------- copy constructor ---------------------------------------------//
        Intervention( const Intervention  &i )
            : client( i.getClient() )
        {
            setInterventionNumber( interventionNumber );
            setDateTime( i.dateTime );
        }

        //----------------------------------- mutators --------------------------------//
        void setInterventionNumber( int iNumber )
        {
            interventionNumber = iNumber;
        }

        void setDateTime( string iDateTime )
        {
            dateTime = iDateTime;
        }

        void setClient( Client iClient )
        {
            client = iClient;
        }

        //----------------------------------- accessors --------------------------------//
        int getInterventionNumber() const
        {
            return interventionNumber;
        }

        string getDateTime() const
        {
            return dateTime;
        }
    
        Client getClient() const
        {
            return client;
        }

        //----------------------------------- display method --------------------------------//
        virtual void display() const // virtual tells the compiler it should not perform early binding.
        {
            std::cout << "INTERVENTION NUMBER : " << getInterventionNumber() << endl;
            std::cout << "DATE TIME : " << getDateTime() << endl;
            getClient().display(); // evoke client display method for time of invention
        } // end display method


        //--------------------------------------- virtual methods --------------------------------//
        virtual void initializeRecords( string fileName )
        {
    
            try
            {
                ofstream blankFile( fileName, ios::out | ios::binary ); // open file in write mode
            

                if ( blankFile.fail() ) // check if file opens
                {
                    cerr << "\t\t ERROR WHILE OPENING FILE!" << endl;
                    usleep(2000000); // will sleep for 1 s
                    

                    return; // exit function
                }

                for ( int indx = 0; indx < 1000; indx++ ) // initialized a thousand blank records.
                {
                    blankFile.seekp( ( indx ) *sizeof( *this ) ); // position cursor in file
                    blankFile.write( reinterpret_cast< const char * >( this ), sizeof( *this ) ) ; // write blank records
                }
            
                blankFile.close(); // close file

            } // end try
            catch (...) // handle exception
            {
                cerr << endl << endl << "\t\t ERROR WHILE INITIALIZING FILE!" << endl;
                usleep(1000000); // will sleep for 1 s
                
            } // end try
            
            cerr << endl << endl << "\t\t FILE LOAD SUCESSFULLY!" << endl;
            usleep(1000000); // will sleep for 1 s
            

        } // end initializeRecord


        virtual void addRecord( string fileName )
        {
            try
            {
                fstream writeFile( fileName, ios::out | ios::in | ios::binary ); // open file in read/write mode

                if ( writeFile.fail() ) // check whether the file is open
                {
                    cerr << "\t\t ERROR WHILE OPENING FILE!" << endl;
                    usleep(1000000); // will sleep for 1 s
                    

                    return; // exit function
                } //end if
                else
                {
                    writeFile.seekp( ( interventionNumber - 1 ) *sizeof( *this ) ); // position cursor in file
                    writeFile.write( reinterpret_cast< const char * >( this ), sizeof( *this ) ) ; // write object to file
                    
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "\t\t\t INTEVENTION RECORD : " << interventionNumber << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl ;
                 
                    writeFile.seekg( ( interventionNumber - 1 ) *sizeof( *this ) ); // position cursor in file
                    writeFile.read( reinterpret_cast< char * >( this ), sizeof( *this ) ); // read object from file
                    this->display(); // evoke display method
                    
                    cout << endl << "\t\t RECORD WITH INTERVENTION NUMBER"<< " " << interventionNumber << " " << "SAVED SUCCESSFULLY" << endl << endl;
                    usleep(2000000); // will sleep for 1 s
                }

                writeFile.close(); // close file

            }
            catch (...)
            {
                cerr << endl << endl << "\t\t ERROR WHILE ADDING RECORD TO FILE!" << endl;
                usleep(1000000); // will sleep for 1 s
                
            } // end catch

        } // end addRecord


        virtual void updateRecord( string fileName, int upNumber )
        {
            try
            {
                fstream writeFile( fileName, ios::out | ios::in | ios::binary ); // open file in read/write mode
            
                if ( writeFile.fail() ) // check if file opens
                {
                    cerr << "\t\t ERROR WHILE OPENING FILE!" << endl;
                    usleep(1000000); // will sleep for 1 s
                    

                    return;
                }
                
                if ( upNumber == interventionNumber ) // show record to be updated
                {
                    display();

                    writeFile.seekp( ( upNumber - 1 ) *sizeof( *this ) ); // position cursor in file
                    writeFile.write( reinterpret_cast< const char * >( this ), sizeof( *this ) ); // write object to file
                    
                    cout<< endl << "RECORD WITH : "<<  upNumber << " " << "UPDATED SUCCESSFULLY" << endl << endl;
                    
                    usleep(1000000); // will sleep for 1 s
                    
                }
                
                writeFile.close(); // close file
            }
            catch (...)
            {
                cout << endl << endl << "\t\t ERROR WHILE UPDATING RECORD!" << endl;
                usleep(1000000); // will sleep for 1 s
                
            } // end catch

        } //end updateRecord method


        virtual void readRecord( string fileName, int searchNumber )
        {
            try{
                ifstream readFile( fileName, ios::in | ios::binary ); // open file in read mode
                
                if ( readFile.fail() ) // check if file opens
                {
                    cerr << "\t\t ERROR WHILE OPENING FILE!" << endl;
                    usleep(1000000); // will sleep for 1 s
                    
                    
                    return;
                } // end if
                
                readFile.seekg( ( searchNumber - 1 ) *sizeof( *this ) ); // positon cursor in file
                readFile.read( reinterpret_cast< char * >( this ), sizeof( *this ) ); // read object from file
                
                if ( searchNumber != interventionNumber )
                {
                    cerr << "\t\t RECORD NOT FOUND!" << endl;
                    usleep(1000000); // will sleep for 1 s
                    
                    
                    return;
                } // end if
                else if ( searchNumber == interventionNumber ) // show record when found
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "\t\t\t RECORD" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl ;
                    this->display(); // evoke TreatmentOfAnimals display method
                    
                    cout << endl << endl;
                    system( "read -n 1 -s -p \"Press any key to continue...\"" );
                    
                } // end if
                
                readFile.close(); // close file
                
            } // end try
            catch (...)
            {
                cout << endl << endl << "\t\t ERROR WHILE UPDATING RECORD!" << endl;
                usleep(1000000); // will sleep for 1 s
                
            } // end catch

        } // end readRecord method


        virtual void viewAllRecords( string fileName )
        {
            ifstream readFile( fileName, ios::in | ios::binary ); // open file in read mode

            if ( readFile.fail() ) // check if file opens
            {
                cerr << "\t\t ERROR WHILE OPENING FILE!" << endl;
                usleep(1000000); // will sleep for 1 s
                
                
                return; // exit function
            } // end if
            
                while ( true )
                {
                    readFile.read( reinterpret_cast< char * >( this ), sizeof( *this ) ); // read object from file

                    if ( readFile.eof() || interventionNumber < 1 ) // check if file ends
                    {
                        cout << endl << "\t\t\t NO MORE INTEVENTION RECORD IN FILE." << endl << endl << endl;
                        usleep(2000000); // will sleep for 1 s
                        

                        break;
                    }  //end if
                    
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "\t\t\t INTEVENTION RECORD : " << interventionNumber << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl ;
                    this->display(); // evoke display method

                    cout << endl << endl;
                    system( "read -n 1 -s -p \"Press any key to continue...\"" );
                    cout << endl << endl;
                   
                
                } // end while
                
            readFile.close(); //close file

        } // end readAllRecords method
        

        virtual void deleteRecord( string fileName, int deleteNumber, Intervention s )
        {
    
            fstream deleteFile( fileName, ios::in | ios::out | ios::binary ); // open file in read/write mode
    

            if ( deleteFile.fail() ) // check if file opens
            {
                cerr << "\t\t ERROR WHILE OPENING FILE!" << endl;
                usleep(1000000); // will sleep for 1 s
                
                
                return; // exit function
            } // end if

            deleteFile.seekg( ( deleteNumber - 1 ) *sizeof( *this ) ); // positon cursor in file
            deleteFile.read( reinterpret_cast< char * >( this ), sizeof( *this ) ) ; // read object to file

            if ( deleteNumber == interventionNumber )
            {
                this->display();
                
                deleteFile.seekp( ( deleteNumber - 1 ) *sizeof( Intervention ) ); // positon cursor in file for record removal
                deleteFile.write( reinterpret_cast< const char * >( &s ), sizeof( Intervention ) ) ; // write object to file
                cout<< endl << "~~~ RECORD WITH INTERVENTION NUMBER : " << deleteNumber << " " << "DELETED SUCCESSFULLY ~~~" << endl << endl;
                usleep(1000000); // will sleep for 1 s
            } // end if
            else
            {
                cerr << "\t\t RECORD NOT FOUND!" << endl;
                usleep(1000000); // will sleep for 1 s
                
            } // end if
            
            deleteFile.close(); // close file

        } // end deleteRecord method


        virtual void generateReport( string fileName )
        {
    
            try
            {
                int countRecords = 0; // tracks existing records
                ifstream reportFile( fileName, ios::in | ios::binary ); // open file in read mode
        
                if ( reportFile.fail() ) // check if file opens
                {
                    cerr << "\t\t ERROR WHILE OPENING FILE!" << endl;
                    usleep(1000000); // will sleep for 1 s
                    
                    return; // exit function
                } //end if

                while (true)
                {
                    reportFile.read( reinterpret_cast< char * >( this ), sizeof( *this ) ); // read object from file
                    
                    if ( interventionNumber != 0 )
                    {
                        countRecords++; // record counter
                        cout << endl;
                    } //end if

                    if ( reportFile.eof() ) // check if file ends
                    {
                        break;
                    }  // end if
                
                } // end while
                
                if ( countRecords == 0 || interventionNumber == 0 ) // verify that no record exist
                {
                    cerr << endl << "\t\t NO RECORD FOUND!" << endl;
                    usleep(1000000); // will sleep for 1 s
                    
                }
                    
                reportFile.close(); // close file
                
            } // end try
            catch ( exception &i ) // handle exception
            {
                cerr << endl << endl << i.what() << endl;
                usleep(1000000); // will sleep for 1 s
                
            } // end catch

        } // end find report method

}; // end Intervention


#endif /* Intervention_h */
