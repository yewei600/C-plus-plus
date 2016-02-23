#include "Surgery.h"

#include <iostream>
using namespace std;



void Surgery::addSurgery(PatientAccount &pa){
    int choice;
    cout<<"Enter surgery choice(between 1-5): ";
    cin>>choice;

    pa.updateCharges(getSurgeryPrice(choice-1));

    cout<<"Surgery added"<<endl;
}
