//
//  RemovalService.h
//  JSPCA Project
//
//  Created by Perry  on 08/03/2023.
//

#ifndef RemovalService_h
#define RemovalService_h

#include "Intervention.h"
#include "Animal.h"

#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

class RemovalService : public Intervention
{
    private:
            //attributes declaration
            string animalAddress;
            string outcome;

    public:
        ~ RemovalService() {} // destructor provided to confirm destruction order

        //-------------------------------- default constructor ---------------------------------------------//
        RemovalService() // default constructor
            :Intervention()
        {
            setAnimalAddress( "animal address" );
            setOutcome( "outcome" );
        }
    
        //-------------------------------- primary constructor ---------------------------------------------//
        RemovalService( int interventionNumber, string dateTime, Client client, string animalAddress, string outcome ) // primay constructor
            :Intervention( interventionNumber, dateTime, client )
        {
            setAnimalAddress( animalAddress );
            setOutcome( outcome );
        }

        //-------------------------------- copy constructor ---------------------------------------------//
        RemovalService( const RemovalService &r )
            :Intervention( r )
        {
            this->outcome = r.outcome;
            this->animalAddress = r.animalAddress;

        }


        //------------------------ mutators -----------------------------//
        void setAnimalAddress( string inAnimalAddress )
        {
                animalAddress = inAnimalAddress;
        }

        void setOutcome( string oc )
        {
                outcome = oc;
        }

        //------------------------ accessor -----------------------------//
        string getOutcome() const
        {
            return outcome;
        }

        string getAnimalAddress() const
        {
            return animalAddress;
        }


        //------------------------ display method -----------------------------//
        void display() const
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~ REMOVAL SERVICE ~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            Intervention::display(); // override of intervention display method
            cout << "ANIMAL ADDRESS : " << getAnimalAddress() << endl;
            cout << "OUTCOME : " << getOutcome() << endl;
        } // end display method
    
};

#endif /* RemovalService_h */
