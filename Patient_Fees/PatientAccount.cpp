#include "PatientAccount.h"

using namespace std;

#include <iostream>

 PatientAccount::PatientAccount(){
    // cout<<"default constructor called!!!"<<endl;
            patientName="";
            charges=0.0;
            daysInHospital=0;
            dailyRate=0.0;
}



void PatientAccount::setPatientName(string name){
    patientName=name;
}

void PatientAccount::updateCharges(double amt){
    charges+=amt;
}
