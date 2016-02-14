#include "Pharmacy.h"


#include <iostream>
using namespace std;


void Pharmacy::addMedicine(PatientAccount &pa){
    int choice;
    cout<<"Enter medicine choice(between 1-5): ";
    cin>>choice;

    pa.updateCharges(getMedPrice(choice-1));

    cout<<"Medcine added"<<endl;
}

