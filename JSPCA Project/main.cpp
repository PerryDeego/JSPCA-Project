//
//  main.cpp
//  JSPCA Project
//
//  Created by Perry  on 08/03/2023.
//
#include "Headers.h"

int main(int argc, const char * argv[]) {
    mainMenu(); // Application
    cout << endl << endl << "\t\t APPLICATION CLOSED" << endl;
    usleep(2000000); // will sleep for 1 s
    
    return 0; // Application terminate successfully
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//------------------------------ TreatmentOfAnimals main menu ------------------------------//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void treatmentMenu() //main menu ption
{
    
    char option = '\0'; // sets the string to null
    
    Intervention *interventionPtr = NULL;
    TreatmentOfAnimals viewAllTreatment, addTreamtment, readTreatment, initializeTreatment;
    
    // file name declaration
    string fileName = "animal_treatment.dat";
    
    // open file in write mode
    ofstream fileExist( fileName, ios::in | ios::binary );
    
    if( !fileExist ) // check if file exist or create it.
        initializeTreatment.initializeRecords( fileName ); // intitialize file for storing recirds
    
    fileExist.close(); // file close
    
    do
    {
        try
        {
            cout<< endl << endl << endl << endl << endl << endl << endl << endl << endl;
            cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            cout << "\n\t\t~~                 VETERINARY CLINIC VISITS               ~~";
            cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            cout << "\n\t\t~~                                                        ~~";
            cout << "\n\t\t~~                                                        ~~";
            cout << "\n\t\t~~          ->1. ADD A NEW RECORD                         ~~";
            cout << "\n\t\t~~          ->2. UPDATE AN EXISTING                       ~~";
            cout << "\n\t\t~~          ->3. VIEW A SINGLE RECORD                     ~~";
            cout << "\n\t\t~~          ->4. VIEW ALL RECORDS                         ~~";
            cout << "\n\t\t~~          ->5. DELETE RECORD                            ~~";
            cout << "\n\t\t~~          ->0. RETURN TO MAIN MENU                      ~~";
            cout << "\n\t\t~~                                                        ~~";
            cout << "\n\t\t~~                                                        ~~";
            cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            
            cout << endl << endl << endl << "SELECT OPTION: ";
            cin >> option; // option input stream
            
            if( cin.fail() )
            {
                cin.clear();
                
                cerr << endl << endl << "\t\t SORRY THERE WAS A PROBLEM WITH YOUR OPTION!";
                usleep(1000000); // will sleep for 1 s
                
            } //end if
            
            switch( option )
            {
                case '0':
                    break; // exit case 0
                    
                /* ----------------------- .1 add a single record option ----------------------- */
                case '1':
                    
                    while ( true )
                    {
                        
                        
                        try
                        {
                            int interventionNumber; // declaration of intervention record number to add record to file
                            
                            cout << "~~~~~~~~~~~~~~~~~~~~~ " << __TIMESTAMP__ << " ~~~~~~~~~~~~~~~~~~~" << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            cout << "ENTER INTERVENTION NUMBER TO ADD RECORD OR [-1] TO RETURN -> ";
                            cin >> interventionNumber; //number use to look intervenion record
                            cout << endl;
                            
                            if ( interventionNumber == -1 ) // use to exit loop
                                break; // exit loop
                            
                            if ( cin.fail() ) // input stream encountered something unexpected
                            {
                                cin.clear();
                                cerr << endl << endl << "\t\t SORRY SOMETHING UNEXEPECTED OCCURRED WITH INPUT!";
                                usleep(1000000); // will sleep for 1 s
                                
                            } //end if
                            
                            if( interventionNumber > 0 )
                            {
                                cin.ignore(); // ignore function is used to skip(discard/throw away) characters in the input stream
                                addTreamtment =  createTreatmentOfAnimals( interventionNumber ); // assign CreateTreatmentOfAnimals function instance "addTreatment" to createTreatmentOfAnimal function values
                                
                                addTreamtment.addRecord( fileName ); // save instance of TreatmentOfAnimals to file
                            }
                            else{
                                cerr << endl << endl << "\t\t ERROR PLEASE CHECK INTERVENTION NUMBER!" << endl;
                                usleep(1000000); // will sleep for 1 s
                                
                            }
                            
                        }
                        catch(...)
                        {
                            cout << endl << endl << "\t\t ERROR WHILE PROCESSING COMMAND!" << endl;
                            usleep(1000000); // will sleep for 1 s
                            
                        }
                        
                    } // end while
                    
                    break; // exit case 1
                    
                /* ----------------------- .2 update a single record option ----------------------- */
                case '2':
                    
                    while( true )
                    {
                        
                        try
                        {
                            TreatmentOfAnimals updateTreatment;
                            int updateNumber; //declaration of intervention record look up number
                            
                            cout << "ENTER INTERVENTION NUMBER TO UPDATE RECORD OR [-1] TO RETURN -> ";
                            cin >> updateNumber; // number use to look intervenion record
                            cout << endl;
                            
                            if ( updateNumber == -1 ) // use to exit loop
                                break; // exit loop
                            
                            if ( cin.fail() )
                            {
                                cin.clear();
                                
                                cerr << endl << endl << "\t\t SORRY SOMETHING UNEXEPECTED OCCURRED WITH INPUT!";
                                usleep(1000000); // will sleep for 1 s
                                
                            } //end if
                            
                            
                            if ( updateNumber > 0 )
                            {
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                cout << "ENTER VETERINARY TREATMENT OF ANIMAL INFORMATION TO BE UPDATED" << endl;
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl ;
                                
                                updateTreatment.readRecord( fileName, updateNumber ); // search for record to update
                                
                                if ( updateTreatment.getInterventionNumber() == updateNumber ) // validate that record exist to be updated
                                {
                                    interventionPtr = new TreatmentOfAnimals ( modifyTreatmentOfAnimals( updateNumber ) );
                                    interventionPtr->updateRecord( fileName, updateNumber );
                                }
                                
                            }
                            else{
                                
                                cerr << endl << endl << "\t\t ERROR INVALID INTERVENTION NUMBER TO UPDATE RECORD !" << endl;
                                usleep(1000000); // will sleep for 1 s
                                
                            }
                            
                        } //end try
                        catch(...)
                        {
                            cerr << endl << endl << "\t\t ERROR WHILE PROCESSING COMMAND!" << endl;
                            usleep(1000000); // will sleep for 1 s
                            
                        } // end catch
                        
                    } //end while
                    
                    break; // exit case 2
                    
                /* ----------------------- .3 view a single record option ------------------ */
                case '3':
                    
                    while( 1 )
                    {
                        
                        try
                        {
                            int searchId; //declaration of intervention record look up number
                            
                            cout<< "ENTER INTERVENTION NUMBER TO RETRIEVE RECORD OR [-1] TO RETURN -> ";
                            cin >> searchId; //number use to look intervenion record
                            cout << endl << endl;
                            
                            if ( searchId == -1 ) //exit search loop
                                break;
                            
                            if ( cin.fail() ) // check if interventionNumber valid to add record
                            {
                                cin.clear();
                                cerr << endl << endl << "\t\t SORRY SOMETHING UNEXEPECTED OCCURRED WITH INPUT!";
                                usleep(1000000); // will sleep for 1 s
                                
                            } // end if
                            
                            readTreatment.readRecord( fileName, searchId ); // evoke readRecord method to locate record in file
                            
                        } // end try
                        catch(...)
                        {
                            cout << endl << endl << "\t\t ERROR WHILE PROCESSING COMMAND!" << endl;
                            usleep(1000000); // will sleep for 1 s
                            
                        } // end catch
                        
                    } //end while
                    
                    break;  // exit case
                    
                /* ----------------------- .4 view all record option -----------------------  */
                case '4':
                    viewAllTreatment.viewAllRecords( fileName );
                    
                    break; // exit case
                    
                /* ----------------------- .5 delete a single record option ----------------------- */
                case '5':
                    
                    while( 1 )
                    {
                        try {
                            TreatmentOfAnimals deleteTreatment, treatmentOjb;
                            //Intervention interventionOjb;
                            int deleletNumber; // declaration of intervention record look up number
                            
                            cout<<"ENTER INTERVENTION NUMBER TO DELETE RECORD OR [-1] TO RETURN -> ";
                            cin >> deleletNumber; // number use to look intervenion record
                            cout << endl << endl;
                            
                            if ( deleletNumber == -1 )
                                break; // exit loop
                            
                            if ( cin.fail() )
                            {
                                cin.clear();
                                cerr << endl << endl << "\t\t SORRY SOMETHING UNEXEPECTED OCCURRED WITH INPUT!";
                                usleep(1000000); // will sleep for 1 s
                                
                            } //end if
                            
                            treatmentOjb.deleteRecord( fileName, deleletNumber, deleteTreatment );
                            
                        } // end try
                        catch(...)
                        {
                            cout << endl << endl << "\t\t ERROR WHILE PROCESSING COMMAND!" << endl;
                            usleep(1000000); // will sleep for 1 s
                            
                        } // end catch
                        
                        
                    } // end while
                    
                    break;  // exit case 5
                    
                // Invalid input option .default
                default:
                    cerr << "\n\n\n\n\t\t>>> [ INVALID OPTION, PLEASE TRY AGAIN. ] <<<";
                    cout<<endl<<endl;
                    usleep(1000000); // will sleep for 1 s
                    cin.clear();
                    
            } // end switch
            
        }
        catch (...)
        {
            cerr << "EEXCEPTION : " << "...SOMETHING WENT WRONG WITH THE APPLICATION!"<< endl << endl;
            usleep(1000000); // will sleep for 1 s
            
        }
        
    } while( option != '0' ); //end while
    
} // end treatmentMenu method


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//-------------------------------- RemovalService main menu --------------------------------//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void removalMenu() // main menu option
{
    char option = '\0';
    
    Intervention *interventionPtr = NULL;
    Intervention viewAllRemovalService, RemovalServiceOjb, readRemovalService, initializeRemovalService;
    
    // file name declaration
    string fileName = "removal_service.dat";
    
    //open file in write mode
    ofstream fileExist( fileName, ios::in | ios::binary );
    
    if( !fileExist ) // check if file exist
        initializeRemovalService.initializeRecords( fileName ); //intitialize record for storing files
   
    fileExist.close(); // file close
    
    do {
        try
        {
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            cout << "\n\t\t~~                 ANIMAL REMOVAL SERVICES                ~~";
            cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            cout << "\n\t\t~~                                                        ~~";
            cout << "\n\t\t~~                                                        ~~";
            cout << "\n\t\t~~          ->1. ADD A NEW RECORD                         ~~";
            cout << "\n\t\t~~          ->2. UPDATE AN EXISTING                       ~~";
            cout << "\n\t\t~~          ->3. VIEW A SINGLE RECORD                     ~~";
            cout << "\n\t\t~~          ->4. VIEW ALL RECORDS                         ~~";
            cout << "\n\t\t~~          ->5. DELETE RECORD                            ~~";
            cout << "\n\t\t~~          ->0. RETURN TO MAIN MENU                      ~~";
            cout << "\n\t\t~~                                                        ~~";
            cout << "\n\t\t~~                                                        ~~";
            cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            
            cout << endl << endl << endl << "SELECT OPTION: ";
            cin >> option; // option input stream
            
            if( cin.fail() )
            {
                cin.clear();
                
                cerr << endl << endl << "\t\t SORRY THERE WAS A PROBLEM WITH YOUR OPTION!";
                usleep(1000000); // will sleep for 1 s
                
            } //end if
            
            switch( option )
            {
                case '0':
                    break; // exit case .0
                    
                /* ----------------------- 1. add a single record option ----------------------- */
                case '1':
                    
                    while ( true )
                    {
                        try
                        {
                            int interventionNumber; // declaration of intervention record number to add record to file
                            
                            cout << "[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ REMOVAL SERVICE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            cout << "[~~~~~~~~~~~~~~~~~~~~~~~~~~ " << __TIMESTAMP__ << " ~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            
                            
                            cout << "ENTER INTERVENTION NUMBER TO ADD RECORD OR [-1] TO RETURN -> ";
                            cin >> interventionNumber; //number use to look intervenion record
                            cout << endl;
                            
                            if ( interventionNumber == -1 ) // use to exit loop
                                break; // exit loop
                            
                            if ( cin.fail() ) // input stream encountered something unexpected
                            {
                                cin.clear();
                                cerr << endl << endl << "\t\t SORRY SOMETHING UNEXEPECTED OCCURRED WITH INPUT!";
                                usleep(1000000); // will sleep for 1 s
                                
                            } //end if
                            
                            if( interventionNumber > 0 )
                            {
                                interventionPtr = new RemovalService( createRemoveAnimal( interventionNumber ) ); // assign CreateTreatmentOfAnimals function instance "addTreatment" to createTreatmentOfAnimal function values
                                
                                interventionPtr->addRecord( fileName ); // save instance of TreatmentOfAnimals to file
                            }
                            else{
                                cerr << endl << endl << "\t\t ERROR PLEASE CHECK INTERVENTION NUMBER!" << endl;
                                usleep(1000000); // will sleep for 1 s
                            }
                            
                        }
                        catch(...)
                        {
                            cout << endl << endl << "\t\t ERROR WHILE PROCESSING COMMAND!" << endl;
                            usleep(1000000); // will sleep for 1 s
                        }
                        
                    } // end while
                    
                    break;    // exit case 1
                    
                /* ----------------------- 2. update a single record option ----------------------- */
                case '2':
                    
                    while( true )
                    {
                        try
                        {
                            TreatmentOfAnimals updateTreatment;
                            int updateNumber; //declaration of intervention record look up number
                            
                            cout << "ENTER INTERVENTION NUMBER TO UPDATE RECORD OR [-1] TO RETURN -> ";
                            cin >> updateNumber; // number use to look intervenion record
                            cout << endl;
                            
                            if ( updateNumber == -1 ) // use to exit loop
                                break; // exit loop
                            
                            if ( cin.fail() )
                            {
                                cin.clear();
                                
                                cerr << endl << endl << "\t\t SORRY SOMETHING UNEXEPECTED OCCURRED WITH INPUT!";
                                usleep(1000000); // will sleep for 1 s
                                
                            } //end if
                            
                            
                            if ( updateNumber > 0 )
                            {
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                cout << "ENTER VETERINARY TREATMENT OF ANIMAL INFORMATION TO BE UPDATED" << endl;
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl ;
                                
                                updateTreatment.readRecord( fileName, updateNumber ); // search for record to update
                                
                                if ( updateTreatment.getInterventionNumber() == updateNumber ) // validate that record exist to be updated
                                {
                                    interventionPtr = new TreatmentOfAnimals ( modifyTreatmentOfAnimals( updateNumber ) );
                                    interventionPtr->updateRecord( fileName, updateNumber );
                                }
                                
                            }
                            else{
                                
                                cerr << endl << endl << "\t\t ERROR INVALID INTERVENTION NUMBER TO UPDATE RECORD !" << endl;
                                usleep(1000000); // will sleep for 1 s
                                
                            }
                            
                        } //end try
                        catch(...)
                        {
                            cerr << endl << endl << "\t\t ERROR WHILE PROCESSING COMMAND!" << endl;
                            usleep(1000000); // will sleep for 1 s
                            
                        } // end catch
                        
                        // cout << endl << endl;
                        // system( "read -n 1 -s -p \"Press any key to continue...\"" );
                        
                    } //end while
                    
                    break; // exit case 2
                    
                /* ----------------------- 3. view a single record option ------------------ */
                case '3':
                    
                    while( 1 )
                    {
                        
                        try
                        {
                            int searchId; //declaration of intervention record look up number
                            
                            cout<< "ENTER INTERVENTION NUMBER TO RETRIEVE RECORD OR [-1] TO RETURN -> ";
                            cin >> searchId; //number use to look intervenion record
                            cout << endl << endl;
                            
                            if ( searchId == -1 ) //exit search loop
                                break;
                            
                            if ( cin.fail() ) // check if interventionNumber valid to add record
                            {
                                cin.clear();
                                cerr << endl << endl << "\t\t SORRY SOMETHING UNEXEPECTED OCCURRED WITH INPUT!";
                                usleep(1000000); // will sleep for 1 s
                                
                            } // end if
                            
                            readRemovalService.readRecord( fileName, searchId ); // evoke readRecord method to locate record in file
                            
                        } // end try
                        catch(...)
                        {
                            cout << endl << endl << "\t\t ERROR WHILE PROCESSING COMMAND!" << endl;
                            usleep(1000000); // will sleep for 1 s
                            
                        } // end catch
                        
                    } //end while
                    
                    break;  // exit case .3
                    
                /* ----------------------- 4. view all record option -----------------------  */
                case '4':
                    viewAllRemovalService.viewAllRecords( fileName );
                    
                    break; // exit case .4
                    
                /* ----------------------- .5 delete a single record option ----------------------- */
                case '5':
                    
                    while( 1 )
                    {
                        
                        try {
                            TreatmentOfAnimals deleteTreatment, treatmentOjb;
                            //Intervention interventionOjb;
                            int deleletNumber; // declaration of intervention record look up number
                            
                            cout<<"ENTER INTERVENTION NUMBER TO DELETE RECORD OR [-1] TO RETURN -> ";
                            cin >> deleletNumber; // number use to look intervenion record
                            cout << endl << endl;
                            
                            if ( deleletNumber == -1 )
                                break; // exit loop
                            
                            if ( cin.fail() )
                            {
                                cin.clear();
                                cerr << endl << endl << "\t\t SORRY SOMETHING UNEXEPECTED OCCURRED WITH INPUT!";
                                usleep(1000000); // will sleep for 1 s
                                
                            } //end if
                            
                            treatmentOjb.deleteRecord( fileName, deleletNumber, deleteTreatment );
                            
                        } // end try
                        catch(...)
                        {
                            cout << endl << endl << "\t\t ERROR WHILE PROCESSING COMMAND!" << endl;
                            usleep(1000000); // will sleep for 1 s
                            
                        } // end catch
                        
                    } // end while
                    
                    break;  // exit case .5
                
                // Invalid input option .default
                default:
                    cerr << "\n\n\n\n\t\t>>> [ INVALID OPTION ] <<<";
                    cout<<endl<<endl;
                    usleep(1000000); // will sleep for 1 s
                    cin.clear();
                    
            } // end switch
            
        }
        catch (...)
        {
            cerr << "EEXCEPTION : " << "...SOMETHING WENT WRONG WITH THE APPLICATION!"<< endl << endl;
            usleep(1000000); // will sleep for 1 s
            
        }
        
    } while( option != '0' ); //end while
    
} // end treatmentMenu method


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//---------------------------------- Veterinary Clinic Reports function -------------------------------------------- //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void veterinaryClinicReport()
{
    
    // file name declaration
    string fileName = "animal_treatment.dat";
    TreatmentOfAnimals reportObject;
    
    char option = '\0';
    
    do
    {
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~   SOCIETY FOR THE PREVENTION OF CRUELTY TO ANIMALS     ~~";
        cout << "\n\t\t~~                      (J.S.P.C.A)                       ~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~                <TREATMENT OF ANIMALS>                  ~~";
        cout << "\n\t\t~~    <GENERATE REPORT BASED ON THE OPTIONS PROVIDED>     ~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~          ->1. LOCATION REPORTS                         ~~";
        cout << "\n\t\t~~          ->2. VISIT DATE REPORTS                       ~~";
        cout << "\n\t\t~~          ->3. ANIMAL TYPE REPORTS                      ~~";
        cout << "\n\t\t~~          ->0. RETURN TO REPORTS MAIN MENU              ~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        
        
        cout << "\n\n\n\n SELECT OPTION: ";
        cin >> option;
        cout << endl << endl;
        usleep(1000);
        
        switch ( option )
        {
            case '0':
                
                
                break;
                
            case '1':
                //location reports
                try {
                    string visitLocation; //declaration of location to lookup
                    
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "\t\t\tLOCATION REPORT" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl ;
                    
                    cout<<"ENTER LOCATION VISITED TO RETRIEVE RECORD : ";
                    cin >> visitLocation; //location use to look intervenion record
                    cout << endl << endl;
                    
                    if ( cin.fail() )
                    {
                        cin.clear();
                        throw invalid_argument( "\t\tNOT A VALID LOCATION!" );
                    } //end if
                    
                    reportObject.generateReport( fileName ); //evoke display method if record found
                    
                    if ( reportObject.getAnimal().getClinicVisit() == visitLocation )
                    {
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "\t\t\tREPORT FOUND" << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl ;
                        reportObject.display(); //evoke TreatmentOfAnimals display method
                    } //end if
                    else{
                        cout << "\t\tRECORD WITH LOCATION : " << visitLocation << " " << "DOES NOT EXIST." << endl;
                    } //end else
                    
                } // end try
                catch (invalid_argument &e) {
                    cerr << e.what() << endl;
                } //end catch
                
                cout << endl << endl;
                system( "read -n 1 -s -p \"Press any key to continue...\"" );
                
                
                break;
                
            case '2':
                //visit date reports
                try {
                    int day,  year, month;
                    
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "\t\t\tVISIT DATE REPORT" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl ;
                    cout << "ENTER DATAE TO RETRIEVE RECORD [FORMAT - dd/mm/yyyy] : ";
                    cin >> day;
                    cin >> month;
                    cin >> year;
                    
                    //number use to look intervenion record
                    cout << endl << endl;
                    if ( cin.fail() )
                    {
                        cin.clear();
                        throw invalid_argument( "\t\tNOT A VALID DATE VISITED!" );
                    } //end if
                    
                    reportObject.generateReport( fileName ); // evoke display method if record found
                    
                    if ( reportObject.getAnimal().getIntendedDateOfVisit().getDay() == day && reportObject.getAnimal().getIntendedDateOfVisit().getMonth() == month &&
                        reportObject.getAnimal().getIntendedDateOfVisit().getYear() == year )
                    {
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "\t\t\tREPORT FOUND" << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl ;
                        reportObject.display(); //evoke TreatmentOfAnimals display method
                    } //end if
                    else{
                        cout << "\t\tRECORD WITH DATE VISITED DOES NOT EXIST." << endl;
                    } //end else
                    
                } // end try
                catch (invalid_argument &e) {
                    cerr << e.what() << endl;
                } //end catch
                
                cout << endl << endl;
                system( "read -n 1 -s -p \"Press any key to continue...\"" );
                
                
                break;
                
            case '3':
                //outcome reports
                try {
                    string type; //declaration of outcome to lookup
                    
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "\t\t\tTYPE REPORT" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl ;
                    
                    cout<<"ENTER ANIMAL TYPE TO RETRIEVE RECORD : ";
                    cin >> type;
                    cout << endl << endl;
                    
                    if ( cin.fail() )
                    {
                        cin.clear();
                        throw invalid_argument( "\t\tNOT A VALID OUTCOME!" );
                    } //end if
                    
                    reportObject.generateReport( fileName ); //evoke display method if record found
                    
                    if ( reportObject.getAnimal().getAnimalType() == type )
                    {
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "\t\t\tREPORT FOUND" << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl ;
                        reportObject.display(); //evoke TreatmentOfAnimals display method
                    } //end if
                    else{
                        cout << "\t\tRECORD WITH ANIMAL TYPE : " << type << " " << "DOES NOT EXIST." << endl;
                    } //end else
                    
                } // end try
                catch (invalid_argument &e) {
                    cerr << e.what() << endl;
                } //end catch
                
                cout << endl << endl;
                system( "read -n 1 -s -p \"Press any key to continue...\"" );
                
                break;
                
            // Invalid input option .default
            default:
                cerr << "\n\n\n\n\t\t>>> [ INVALID OPTION ] <<<";
                cout<<endl<<endl;
                usleep(1000000); // will sleep for 1 s
                cin.clear();
                
        } //end switch
        
    } while( option != '0' ); // end while
    
} // end veterinaryClinicReport method


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//----------------------------------------- RemovalRequestReport function ------------------------------------------ //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void  removalRequestReport()
{
    
    // file name declaration
    string fileName = "removal_service.dat";
    RemovalService reportObject;
    
    char option = '\0'; // variable to select option.
    
    do
    {
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~   SOCIETY FOR THE PREVENTION OF CRUELTY TO ANIMALS     ~~";
        cout << "\n\t\t~~                      (J.S.P.C.A)                       ~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~                  <REMOVAL SERVICES>                    ~~";
        cout << "\n\t\t~~    <GENERATE REPORT BASED ON THE OPTIONS PROVIDED>     ~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~          ->1. LOCATION REPORTS                         ~~";
        cout << "\n\t\t~~          ->2. REMOVAL DATE REPORTS                     ~~";
        cout << "\n\t\t~~          ->3. ANIMAL OUTCOME REPORTS                   ~~";
        cout << "\n\t\t~~          ->0. RETURN TO REPORTS MAIN MENU              ~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        
        
        cout << "\n\n\n\n SELECT OPTION: ";
        cin >> option;
        cout<<endl<<endl;
        usleep(1000);
        
        
        switch ( option )
        {
            case '0':
                break;
                
            case '1':
                //location reports
                try {
                    string address; //declaration of location to lookup
                    
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "\t\t\tLOCATION/ADDRESS REPORT" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl ;
                    
                    cout<<"ENTER LOCATION FROM WHERE ANIMAL WAS REMOVED TO RETRIEVE RECORD : ";
                    cin >> address; //location use to look intervenion record
                    cout << endl << endl;
                    
                    if ( cin.fail() )
                    {
                        cin.clear();
                        throw invalid_argument( "\t\tNOT A VALID LOCATION!" );
                    } //end if
                    
                    reportObject.generateReport( fileName ); // evoke display method if record found
                    
                    if( reportObject.getAnimalAddress() == address )
                    {
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "\t\t\tREPORT FOUND" << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl ;
                        reportObject.display(); //evoke TreatmentOfAnimals display method
                    } //end if
                    else{
                        cout << "\t\tRECORD WITH LOCATION : " << address << " " << "DOES NOT EXIST." << endl;
                    } //end else
                    
                } // end try
                catch (invalid_argument &e) {
                    cerr << e.what() << endl;
                } //end catch
                
                cout << endl << endl;
                system( "read -n 1 -s -p \"Press any key to continue...\"" );
                
                break;
                
            case '2':
                // visit date reports
                try {
                    string dateTime;
                    
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "\t\t\tREMOVAL DATE REPORT" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl ;
                    cout << "ENTER DATE OF REMOVAL TO RETRIEVE RECORD [FORMAT - dd/mm/yyyy] : ";
                    cin >> dateTime;
                    
                    //number use to look intervenion record
                    cout << endl << endl;
                    if ( cin.fail() )
                    {
                        cin.clear();
                        throw invalid_argument( "\t\tNOT A VALID DATE OF REMOVAL!" );
                    } //end if
                    
                    reportObject.generateReport( fileName ); //evoke display method if record found
                    
                    if( reportObject.getDateTime() == dateTime )
                        
                    {
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "\t\t\tREPORT FOUND" << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl ;
                        reportObject.display(); //evoke TreatmentOfAnimals display method
                    } //end if
                    else{
                        cout << "\t\tRECORD WITH DATE OF REMOVAL DOES NOT EXIST." << endl;
                    } //end else
                    
                } // end try
                catch (invalid_argument &e) {
                    cerr << e.what() << endl;
                } //end catch
                
                cout << endl << endl;
                system( "read -n 1 -s -p \"Press any key to continue...\"" );
                
                break;
                
            case '3':
                //outcome reports
                try {
                    string outcome; //declaration of outcome to lookup
                    
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "\t\t\tANIMAL OUTCOME REPORT" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl ;
                    
                    cout<<"ENTER ANIMAL OUTCOME TO RETRIEVE RECORD : ";
                    cin >> outcome;
                    cout << endl << endl;
                    
                    if ( cin.fail() )
                    {
                        cin.clear();
                        throw invalid_argument( "\t\tNOT A VALID OUTCOME!" );
                    } //end if
                    
                    reportObject.generateReport( fileName ); //evoke display method if record found
                    
                    if( reportObject.getOutcome() == outcome )
                    {
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "\t\t\tREPORT FOUND" << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl ;
                        reportObject.display(); //evoke TreatmentOfAnimals display method
                    } //end if
                    else{
                        cout << "\t\tRECORD WITH ANIMAL OUTCOME : " << outcome << " " << "DOES NOT EXIST." << endl;
                    } //end else
                    
                } // end try
                catch (invalid_argument &e) {
                    cerr << e.what() << endl;
                } //end catch
                
                cout << endl << endl;
                system( "read -n 1 -s -p \"Press any key to continue...\"" );
                
                break;
                
            // Invalid input option .default
            default:
                cerr << "\n\n\n\n\t\t>>> [ INVALID OPTION ] <<<";
                cout<<endl<<endl;
                usleep(1000000); // will sleep for 1 s
                cin.clear();
                
        } // end switch
        
    } while( option != '0' ); // end while
    
} // removalRequestReport


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//----------------------------------------- reports menu function -------------------------------------------------- //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void reportsMenu() // menu option
{
    char option = '\0';
    
    do
    {
        
        
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~   SOCIETY FOR THE PREVENTION OF CRUELTY TO ANIMALS     ~~";
        cout << "\n\t\t~~                      (J.S.P.C.A)                       ~~";
        cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~          ->1. VETERIANARY CLINIC VISIT REPORTS         ~~";
        cout << "\n\t\t~~          ->2. REMOVAL SERVICE REPORTS                  ~~";
        cout << "\n\t\t~~          ->0. RETURN TO MAIN                           ~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        
        cout << "\n\n\n\n SELECT OPTION -> ";
        cin >>  option;
        cout << endl << endl;
        usleep(1000);
        
        switch ( option )
        {
            case '0':
                break;
                
            case '1':
                //TreatmentOfAnimal reports
                veterinaryClinicReport();
                
                cout << endl << endl;
                system( "read -n 1 -s -p \"Press any key to continue...\"" );
                
                break;
                
            case '2':
                //RemovalService reports
                removalRequestReport();
                
                cout << endl << endl;
                system( "read -n 1 -s -p \"Press any key to continue...\"" );
                
                break;
                
            // Invalid input option .default
            default:
                cerr << "\n\n\n\n\t\t>>> [ INVALID OPTION ] <<<";
                cout<<endl<<endl;
                usleep(1000000); // will sleep for 1 s
                cin.clear();
                
        } //end switch
        
    } while( option != '0' ); // end while
    
} // end reportMenu method


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//---------------------------------------------- main function ------------------------------------------------------//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void mainMenu() // menu option
{
    
    char option = '\0';
    
    do
    {
        cout<< endl << endl << endl;
        cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~   SOCIETY FOR THE PREVENTION OF CRUELTY TO ANIMALS     ~~";
        cout << "\n\t\t~~                      (J.S.P.C.A)                       ~~";
        cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~          ->1. VETERIANARY CLINIC VISIT RECORDS         ~~";
        cout << "\n\t\t~~          ->2. REMOVAL SERVICE RECORDS                  ~~";
        cout << "\n\t\t~~          ->3. REPORTS                                  ~~";
        cout << "\n\t\t~~          ->0. EXIT                                     ~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~                                                        ~~";
        cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        
        cout << "\n\n\n\n SELECT OPTION: ";
        cin >> option;
        cout<< endl << endl;
        
        switch (option)
        {
            case '0':
                break; // exit switch loop
                
            case '1':
                // TreatmentOfAnimal menu
                treatmentMenu();
                
                break; // exit case
                
            case '2':
                //RemovalService menu
                removalMenu();
                
                break;// exit case
                
            case '3':
                reportsMenu();
                
                break; // exit case
                
            // Invalid input option .default
            default:
                
                cerr << "\n\n\n\n\t\t>>> [ INVALID OPTION ] <<<";
                cout<< endl << endl;
                usleep(1000000); // will sleep for 1 s
                cin.clear();
                
        } // end switch
        
    } while( option != '0' ); // end while
    
} // end mainMenu method









