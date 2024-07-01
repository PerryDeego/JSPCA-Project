//
//  Client.h
//  JSPCA Project
//
//  Created by Perry  on 08/03/2023.
//

#ifndef Client_h
#define Client_h

#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Client
{
    private:
        //attributes declaration
        std::string firstName;
        std::string lastName;
        std::string contactNumber;
        std::string paymentType;

    public:
        ~Client() { } //destructor


        //-------------------------------- constructors ---------------------------------------------//
        Client() //default constructor
        {
            firstName = "First Name";
            lastName = "Last Name";
            contactNumber = "876-929-5555";
            paymentType = "Payment Type";
        }

        //-------------------------------- primary constructor ---------------------------------------------//
        Client( std::string firstName, std::string lastName, std::string contactNumber, std::string paymentType )
        {
            this->firstName = firstName;
            this->lastName = lastName;
            this->contactNumber = contactNumber;
            this->paymentType = paymentType;
        }

        Client( const Client &c )
        {
            this->firstName = c.firstName;
            this->lastName = c.lastName;
            this->contactNumber = c.contactNumber;
            this->paymentType = c.paymentType;
        }


        //----------------------------------- mutators --------------------------------//
        void setFirstName( string fName )
        {
            firstName = fName;
        }

        void setLastName( string lName )
        {
            lastName = lName;
        }

        void setContactNumber( string contNum )
        {
            contactNumber = contNum;
        }

        void setPaymentType( string pType )
        {
            if( pType == "F" || pType == "f" )
            {
                paymentType = "FULL PAYMENT";
            }
            else if ( pType == "C" || pType == "c" )
            {
                paymentType = "CONTRIBUTION";
            }
            else if ( pType == "N" || pType == "n" )
            {
                paymentType = "CAN NOT PAY";
            }
            else {
                cout << "INVALID PAYMENT METHOD.";
            }
            
        }


        //----------------------------------- accessors --------------------------------//
        string getFirstName() const
        {
            return firstName;
        }

        string getLastName() const
        {
            return lastName;
        }

        string getContactNumber() const
        {
            return contactNumber;
        }

        string getPaymentType() const
        {
            return paymentType;
        }

        bool isValidContact(string& number)
        {
             // Regex to check valid phonenumber.
             regex pattern("[[:digit:]]{3}-[[:digit:]]{3}-[[:digit:]]{4}");

            if (number.size() == 12)
            {
                if ((number[3] == '-') && (number[7] == '-'))
                {
                    // Return true if the phone number matched the ReGex
                    if (regex_match(number, pattern)) {

                        return true;
                    }
                }
                else
                 return false;
            }
            else
                 return false;

            return true;
        }

        //----------------------------------- accessors --------------------------------//
        void display() const
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~ CLIENT INFORMATION ~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout <<"FIRST NAME : "<< getFirstName() << endl;
            cout <<"LAST NAME : "<< getLastName() << endl;
            cout <<"CONTACT INFORMATION : " << getContactNumber() << endl;
            cout <<"PAYMENT TYPE : " << getPaymentType() << endl;
        }
};


#endif /* Client_h */
