//
//  CreateFunctions.h
//  JSPCA Project
//
//  Created by Perry  on 27/03/2023.
//

#ifndef CreateFunctions_h
#define CreateFunctions_h

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//----------------------------------- object functions ----------------------------------//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

Date createDate() // Date template
{
    Date date;
    unsigned short day, month, year;
    
    try
    {
        cout << "ENTER DATAE [ DD/MM/YYYY ] ->  ";
        cin >> day >> month >> year;
        
        if( cin.fail() )
        {
            cin.clear();
            throw invalid_argument( "\t\t INVALID DATE, FORMAT [ DD/MM/YY ]!" );
        } // end if
        
        if( date.isValidDate(day, month, year) ) // validates date format is correct
        {
            // assign setter values for Date object
            date.setDay(day);
            date.setMonth(month);
            date.setYear(year);
        }
        else
        {
            throw invalid_argument( "\t\t THIS DATE IS NOT VALID. FORMAT [ DD/MM/YY ]!" );
        }
        
    } // End try
    catch( invalid_argument &i )
    {
        cerr << endl << endl << i.what() << endl;
    } // end catch
    catch(...)
    {
        cout << endl << endl << "\t\t ERROR WHILE PROCESSING DATA!" << endl;
        usleep(1000000); // will sleep for 1 s
        
    } // end catch
    
    return date; // Date instance initialized
    
} // end method createDate


Client createClient() // Client template
{
    // instantiation of cleint object
    Client client;
    
    // local varibles declaration
    string firstName;
    string lastName;
    string contactNumber;
    string paymentType;
    
    try{
        cout << "~~~~~~~~~~~~~~~~~~ CLIENT INFORMATION ~~~~~~~~~~~~~~~~~~" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        
        cout << "ENTER FIRST NAME -> ";
        getline ( cin, firstName ); // get the input line from cin and store into firstName
        
        cout << endl <<  "ENTER LAST NAME -> ";
        getline ( cin, lastName ); // get the input line from cin and store into lastName
        
        cout << endl <<  "ENTER CONTACT NUMBER -> ";
        cin >> contactNumber;
        
        cout << endl <<  "ENTER PAYMENT TYPE [ F - FULL PAYMENT | C - CONTRIBUTION | N - CAN NOT PAY ] -> ";
        cin >> paymentType;
        
        if( cin.fail() )
        {
            cin.clear();
            throw invalid_argument( "\t\t ERROR: INVALID INPUT!" );
        } // end if
        
        // Assign setter values for Client object.
        client.setFirstName( firstName );
        client.setLastName ( lastName );
        client.setPaymentType ( paymentType );
        client.isValidContact(contactNumber)? client.setContactNumber( contactNumber ): throw ( "\t\t Format [ ###-###-#### ], this phone number is not valid!" );
        
    } //end try
    catch( invalid_argument &i)
    {
        cerr << i.what() << endl;
        usleep(1000000); // will sleep for 1 s
        
    } //end catch
    catch(...)
    {
        cout << endl << endl << "\t\t ERROR WHILE PROCESSING DATA!" << endl;
        usleep(1000000); // will sleep for 1 s
        
    } // end catch
    
    return client;
} //end method createClient


Animal createAnimal() //Animal template
{
    Animal animal; //instantiation of animal object
    
    // local varibles declaration
    string animalType;
    string breed;
    char gender;
    int age;
    string visitReason;
    string clinicVisit;
    Date intendedDateOfVisit;
    
    cout << "~~~~~~~~~~~~~~ ANIMAL INFORMATION ~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    
    try
    {
        cout << "ENTER ANIMAL TYPE -> ";
        getline ( cin, animalType ); // get the input line from cin and store into animalType
        
        cout << endl << "ENTER BREED -> ";
        getline ( cin, breed ); // get the input line from cin and store into breed
        
        cout << endl <<  "ENTER GENDER (M/F) -> ";
        cin >> gender;
        
        cout << endl << "ENTER APPROXIMATE AGE -> ";
        cin >> age;
        cin.ignore(); // ignore function is used to skip(discard/throw away) characters in the input stream
        
        cout << endl <<  "ENTER REASON FOR VISITING -> ";
        getline ( cin, visitReason ); // get the input line from cin and store into visitReason
        
        cout << endl <<  "ENTER CLINIC VISITING -> " ;
        getline ( cin, clinicVisit ); // get the input line from cin and store into clinicVisit
        
        if( cin.fail() ) //validate age input
        {
            cin.clear();
            throw invalid_argument( "NOT A VALID NUMBER FOR AGE!" );
        } //end if
        
        cout << endl << "INTENDED DATE OF VISIT";
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
        intendedDateOfVisit = (createDate());
        
        // Assign setter values for animal object
        animal.setAnimalType( animalType );
        animal.setBreed( breed );
        animal.setGender( gender );
        animal.setAge( age );
        animal.setVisitReason( visitReason );
        animal.setClinicVisit( clinicVisit );
        animal.setIntendedDateOfVisit( intendedDateOfVisit );
        
    } //end try
    catch( invalid_argument &i)
    {
        cerr << i.what() << endl;
        usleep(1000000); // will sleep for 1 s
        
    } //end catch
    catch(...)
    {
        cout << endl << endl << "\t\t ERROR WHILE PROCESSING DATA!" << endl;
        usleep(1000000); // will sleep for 1 s
        
    } // end catch
    
    return animal; //return an Animail object
    
} //end createAniaml


/* -------------------------------------------------- TreatmentOfAnimals method ------------------------------------------ */

TreatmentOfAnimals createTreatmentOfAnimals( int interventionNumber ) // TreatmentOfAnimals new instance template
{
    // instantiate TreatmentOfAnimal object
    TreatmentOfAnimals treatment;
    
    // local varibles declaration
    string dateTime;
    Client client;
    Animal animal;
    
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    
    time ( &rawtime );
    timeinfo = localtime( &rawtime );
    
    strftime( buffer,sizeof( buffer ),"%d-%m-%Y %H:%M:%S", timeinfo );
    string str( buffer );
    
    try
    {
        cout << endl;
        dateTime = str; // assign current date time
        cout << endl;
        
        client = createClient();
        cin.ignore(); // ignore function is used to skip(discard/throw away) characters in the input stream
        animal = createAnimal(); // create Treament object
        cout << endl;
        
        // assign setter values for Intervention veterinary clinic visit "TreatmentOfAnimals" object
        treatment.setInterventionNumber( interventionNumber );
        treatment.setDateTime( dateTime );
        treatment.setClient( client );
        treatment.setAnimal( animal );
        
    } // end try
    catch(...)
    {
        cout << endl << endl << "\t\t ERROR WHILE PROCESSING DATA!" << endl;
        usleep(1000000); // will sleep for 1 s
        
    }
    
    return treatment; // return a TreatmentOfAnimal instance
    
} // end TreatmentOfAnimals method


TreatmentOfAnimals modifyTreatmentOfAnimals( int updateNumber ) // TreatmentOfAnimals updaate instance template
{
    //instantiate TreatmentOfAnimal objec
    TreatmentOfAnimals treatment;
    
    // local varibles declaration
    string dateTime;
    Client client;
    Animal animal;
    
    // current date time formating
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    
    time ( &rawtime );
    timeinfo = localtime( &rawtime );
    
    strftime( buffer,sizeof( buffer ),"%d-%m-%Y %H:%M:%S", timeinfo );
    string str( buffer );
    
    try
    {
        cout << endl;
        dateTime = str; // assign current date time
        cout << endl;
        
        client = createClient();
        cin.ignore(); // ignore function is used to skip(discard/throw away) characters in the input stream
        animal = createAnimal(); // create Treament object
        cout << endl;
        
        // assign setter values for Intervention veterinary clinic visit "TreatmentOfAnimals" object
        treatment.setInterventionNumber( updateNumber );
        treatment.setDateTime( dateTime );
        treatment.setClient( client );
        treatment.setAnimal( animal );
        
    } // end try
    catch(...)
    {
        cout << endl << endl << "\t\t ERROR WHILE PROCESSING DATA!" << endl;
        usleep(1000000); // will sleep for 1 s
        
    } // end catch
    
    return treatment; // return a TreatmentOfAnimal object
    
} // end modifyTreatmentOfAnimals method


//-------------------------------------------------- RemovalService method ------------------------------------------//
RemovalService createRemoveAnimal( int interventionNumber ) // TreatmentOfAnimals template
{
    //instantiate TreatmentOfAnimal objec
    RemovalService removeAnimal;
    
    // local varibles declaration
    string dateTime;
    Client client;
    string address;
    string outcome;
    
    // current date time formating
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    
    time ( &rawtime );
    timeinfo = localtime( &rawtime );
    
    strftime( buffer,sizeof( buffer ),"%d-%m-%Y %H:%M:%S", timeinfo );
    string str( buffer );
    
    try
    {
        dateTime = str;
        
        cin.ignore(); // ignore function is used to skip(discard/throw away) characters in the input stream
        cout << endl;
        client = createClient(); // create Client object
        cin.ignore(); // ignore function is used to skip(discard/throw away) characters in the input stream
        
        cout << endl;
        cout << "~~~~~~~~~~~~~~~~ ANIMAL INFORMATION ~~~~~~~~~~~~~~~~~" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "ENTER ANIMAL ADDRESS -> " ;
        getline(cin, address);
        cin.ignore(); // ignore function is used to skip(discard/throw away) characters in the input stream
        
        cout << endl << "CHOOSE ANIMAL OUTCOME [ A OR E ]  FOR ADOPTION OR EUTHANIZED -> ";
        cin >> outcome;
        
        if( cin.fail() )
        {
            cin.clear();
            throw invalid_argument( "\t\tNot a valid input!" );
        } // end if
        
        if( outcome == "A" || outcome == "a")
        {
            outcome = "ADOPTION";
        } // end if
        else if ( outcome == "E" || outcome == "E")
        {
            outcome = "EUTHANIZED";
        } // end else
        
        // set value to intervention treatment object
        removeAnimal.setInterventionNumber( interventionNumber );
        removeAnimal.setDateTime( dateTime );
        removeAnimal.setClient( client );
        removeAnimal.setAnimalAddress( address );
        removeAnimal.setOutcome( outcome );
        
        
    } // end try
    catch (invalid_argument& t)
    {  // need <stdexcept>
        cerr << "Exception: " << t.what() << endl<<endl;
        // Continue to the next statement after try-catch
    } // end catch
    
    return removeAnimal; //return a TreatmentOfAnimal object
    
} // end method TreatmentOfAnimals


RemovalService modifyRemoveAnimal( int updateNumber ) //TreatmentOfAnimals template
{
    //instantiate TreatmentOfAnimal objec
    RemovalService removeAnimal;
    
    //local varibles declaration
    string dateTime;
    Client client;
    string address;
    string outcome;
    
    // current date time formating
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    
    time ( &rawtime );
    timeinfo = localtime( &rawtime );
    
    strftime( buffer,sizeof( buffer ),"%d-%m-%Y %H:%M:%S", timeinfo );
    string str( buffer );
    
    try {
        cout << "[~~~~~~~~~~~~~~ UPDATE REMOVAL SERVICE RECORD ~~~~~~~~~~~~~]" << endl;
        cout << "[**************** " << __TIMESTAMP__ << " *****************]" << endl<<endl<<endl;
        dateTime = str; // create dateTime with current date and time
        cout << endl;
        
        client = createClient(); // create Client object
        cout << endl;
        
        cout << "~~~~~~~~~~~~~~~~~~ ANIMAL INFORMATION ~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "ENTER ANIMAL ADDRESS : " ;
        getline(cin, address);
        cin.ignore(); // ignore function is used to skip(discard/throw away) characters in the input stream
        
        cout << endl << "CHOOSE ANIMAL OUTCOME [ A OR E ]  FOR ADOPTION OR EUTHANIZED -> ";
        cin >> outcome;
        
        if( cin.fail() )
        {
            cin.clear();
            throw invalid_argument( "Not a valid animal outcome!" );
        } //end if
        
        if( outcome == "A" || outcome == "a")
        {
            outcome = "ADOPTION";
        } //end if
        else if ( outcome == "E" || outcome == "E")
        {
            outcome = "EUTHANIZED";
        } //end else
        
        //set value to intervention treatment object
        removeAnimal.setInterventionNumber( updateNumber );
        removeAnimal.setDateTime( dateTime );
        removeAnimal.setClient( client );
        removeAnimal.setAnimalAddress( address );
        removeAnimal.setOutcome( outcome );
        
    } //end try
    catch (invalid_argument& o)
    {  // need <stdexcept>
        cout << "Exception: " << o.what() << endl<<endl;
        // Continue to the next statement after try-catch
    } //end catch
    
    return removeAnimal; //return a TreatmentOfAnimal object
    
} //end method TreatmentOfAnimals


#endif /* CreateFunctions_h */
