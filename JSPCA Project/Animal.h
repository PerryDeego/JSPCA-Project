//
//  Animal.h
//  JSPCA Project
//
//  Created by Perry  on 08/03/2023.
//

#ifndef Animal_h
#define Animal_h
#include "Date.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <exception>
#include <stdexcept>

using namespace std;

class Animal
{
    private:
        string animalType;
        string breed;
        char gender;
        int age;
        string visitReason;
        string clinicVisit;
        Date intendedDateOfVisit;

    public:
        //-------------------------------- destructor reclaims memory ----------------------------------//
        ~Animal() {}

        //-------------------------------- default constructor ---------------------------------------------//
        Animal() : intendedDateOfVisit()
        {
            setAnimalType( "animal type" );
            setBreed( "breed" );
            setGender( 'M' );
            setAge( 1 );
            setVisitReason( "visit reason" ) ;
            setClinicVisit( "clinic visited" );
            setIntendedDateOfVisit( Date(3, 3, 2023) );
        }

        //--------------------------------- primary constructor ----------------------------------------//
        Animal( string animalType, string breed, char gender, int age, string visitReason, string clinicVisit, Date date )
            : intendedDateOfVisit( date )
        {
            setAnimalType( animalType );
            setBreed( breed );
            setGender( gender );
            setAge( age );
            setVisitReason( visitReason );
            setClinicVisit( clinicVisit );
        }

        //--------------------------------- copy constructor ----------------------------------------//
        Animal( const Animal &obj )
            : intendedDateOfVisit( obj.getIntendedDateOfVisit() )
        {
            setAnimalType( obj.animalType );
            setBreed( obj.breed );
            setGender( obj.gender );
            setAge( obj.age );
            setVisitReason( obj.visitReason );
            setClinicVisit( obj.clinicVisit );
        }


        //-------------------------------- mutators ---------------------------------------------//
        void setAnimalType( string aType )
        {
            animalType = aType;
        }
    
        void setBreed( string b )
        {
            breed = b;
        }
            
        void setGender( char g )
        {
            if (g != 'M' || g != 'm' || g != 'f' || g !='F')
                gender = g;
            else
                throw runtime_error( "\t\t Invalid gender! Valid gender: (m/f or M/F)." );
        }

        void setAge( int a )
        {
            if( a > 0 && a <= 100 )
                age = a;
            else
                throw ( "\t\t Invalid age! Valid age: (1 to 100)." );
        }

        void setVisitReason( string inVisitReason )
        {
            visitReason = inVisitReason;
        }

        void setClinicVisit( string inClinicVisit )
        {
            clinicVisit = inClinicVisit;
        }

        void setIntendedDateOfVisit( Date dt )
        {
            intendedDateOfVisit = dt;
        }

        
        //-------------------------------- accessors ---------------------------------------------//
        string getAnimalType() const
        {
            return    animalType;
        }
    
        string getBreed() const
        {
            return breed;
        }

        char getGender() const
        {
            return gender;
        }

        int getAge() const
        {
            return age;
        }

        string getVisitReason()const
        {
            return visitReason;
        }
        
        string getClinicVisit() const
        {
            return clinicVisit;
        }

        Date getIntendedDateOfVisit() const
        {
            return intendedDateOfVisit;
        }


        //-------------------------------- display method ------------------------------------------//
        void display() const
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~ ANIMAL INFORMATION ~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "ANIMAL TYPE : " << getAnimalType() << endl;
            cout << "GENDER (M/F) : " << getGender() <<endl;
            cout << "BREED : " << getBreed() << endl;
            cout << "APPROXIMATE AGE : " << getAge() << endl;
            cout << "REASON FOR VISITING : " << getVisitReason() << endl;
            cout << "CLINIC VISITED : " << getClinicVisit() << endl;
            cout << "INTENDED DATE OF VISIT : ";
            intendedDateOfVisit.display(); // evoke date display method for date of intended visit
        } // end method display
    
};

#endif /* Animal_h */
