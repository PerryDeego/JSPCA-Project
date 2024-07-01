//
//  TreatmentOfAnimals.h
//  JSPCA Project
//
//  Created by Perry  on 08/03/2023.
//

#ifndef TreatmentOfAnimals_h
#define TreatmentOfAnimals_h

#include "Intervention.h"
#include "Animal.h"
#include "Client.h"
#include "Date.h"

#include<string>
#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

class TreatmentOfAnimals : public Intervention
{
    private:
        // attribute declaration
        Animal animal;

    public:
        //-------------------------------- destructor reclaims memory ----------------------------------//
        ~ TreatmentOfAnimals() { }

        //-------------------------------- default constructors ---------------------------------------------//
        TreatmentOfAnimals() 
            : Intervention(), animal()
        {
            
        }

        //-------------------------------- primary constructor ---------------------------------------------//
        TreatmentOfAnimals( int interventionNumber, string dateTime, Client client, Date interventDate, Animal animal )
        : Intervention( interventionNumber, dateTime, client), animal( animal )
        {
        
        }

        //-------------------------------- copy constructor ---------------------------------------------//
        TreatmentOfAnimals( const TreatmentOfAnimals &obj ) // copy constructor
            : Intervention( obj ), animal( obj.getAnimal() )
        {
        
        }
    
        //----------------------------------- mutators --------------------------------//
        void setAnimal( Animal iAnimal)
        {
            animal = iAnimal;
        }
    
        //----------------------------------- accessors --------------------------------//
        Animal getAnimal() const
        {
            return animal;
        }
        
        //------------------------ display method -----------------------------//
        void display() const
        {
            Intervention::display(); // reuse abstract base-class display function
            animal.display(); // evoke display function for Animal class
        } //end dispaly method
    
}; // end TreamtmentOfAnimal class

#endif /* TreatmentOfAnimals_h */
