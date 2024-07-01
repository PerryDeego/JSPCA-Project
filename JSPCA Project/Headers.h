//
//  Headers.h
//  JSPCA Project
//
//  Created by Perry  on 20/03/2023.
//

#ifndef Headers_h
#define Headers_h

#include "Date.h"
#include "Client.h"
#include "Animal.h"
#include "Intervention.h"
#include "RemovalService.h"
#include "TreatmentOfAnimals.h"
#include "CreateFunctions.h"

/* ------ preprocessor directives ------ */
#include <ctime>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <string>

#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include <stdexcept>

using namespace std;

/* ------------------ function prototypes for menu ----------------- */
void mainMenu();
void treatmentMenu();
void removalMenu();
void reportsMenu();
/* --------------------- menu functions ------------------- */
/* ----------------- input data functions ---------------- */
Date createDate();
Client createClient();
Animal createAnimal();
TreatmentOfAnimals createTreatmentOfAnimals( int );
TreatmentOfAnimals modifyTreatmentOfAnimals( int );
RemovalService createRemoveAnimal( int );
RemovalService modifyRemoveAnimal( int );
/* ---------------- input data functions ------------- */
/* ----------- generate report funtion -------------- */
void veterinaryClinicReport();
void removalRequestReport();
/* ---------- generate report funtion ------------ */

#endif /* Headers_h */
