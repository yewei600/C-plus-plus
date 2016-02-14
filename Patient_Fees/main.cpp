#include <iostream>
#include <vector>
#include "PatientAccount.h"
#include "Pharmacy.h"
#include "Surgery.h"


using namespace std;

void displayMenu(){
    cout << "\n                MENU\n";
    cout << "-----------------------------------------\n";
    cout << "A) Display patient account\n";
    cout << "B) Add medicine for patient\n";
    cout << "C) Add surgery for patient\n";
    cout << "D) Set daily hospital rate for patient\n";
    cout << "E) Add patient account\n";
    cout << "F) Delete patient account\n";
    cout << "G) Exit the program\n\n";
    cout << "Enter your choice: ";

}

//choose the patient for which to display the Menu for.
int choosePatient(vector<PatientAccount> &pArray){
    int patientNum;
    PatientAccount p;
    cout<<"Please choose a patient number:\n";
    for(int i=0;i<pArray.size();i++){
        p=pArray.at(i);
        cout<<i<<"  "<<p.getPatientName()<<endl;
    }
    cout<<"number: ";
    cin>>patientNum;

    return patientNum;

}

//Options of displaying a particular patient's account
void displayPatientAccount(PatientAccount chosen){
    cout<<"Account info for "<<chosen.getPatientName()<<":"<<endl;
    cout<<"charges: "<<chosen.getPatientCharges()<<endl;
    cout<<"days in hospital: "<<chosen.getDaysInHospital()<<endl;
    cout<<"daily rate: "<<chosen.getDailyRate()<<endl;

    //return patient;
}

//add a single patient
void addPatientAccount(vector<PatientAccount> &pArray){
    string name;
    cout<<"Enter patient name: ";
    cin>>name;

    PatientAccount p;
    p.setPatientName(name);

    pArray.push_back(p);

    cout<<"Added patient "<<p.getPatientName()<<endl;

}

void deletePatientAccount(vector<PatientAccount> &pArray){
    PatientAccount p;
    int index;
    cout<<"Please choose a patient to delete:\n";
    for(int i=0;i<pArray.size();i++){
        p=pArray.at(i);
        cout<<i<<"  "<<p.getPatientName()<<endl;
    }
    cout<<"number: ";
    cin>>index;
    pArray.erase(pArray.begin()+index);

    cout<<"patient erased"<<endl;
}

int main()
{
    vector<PatientAccount> patientArray;
    int choicePatient;
    Pharmacy Pharmacy;
    Surgery Surgery;
    char choice;
    bool terminate=false;




    do{
        if(patientArray.size()==0){
            cout<<"no patient on file, please add patients"<<endl;
            addPatientAccount(patientArray);
            continue;
        }

        choicePatient=choosePatient(patientArray);
        displayMenu();
        cin>>choice;

    while(toupper(choice)<'A'|| toupper(choice)>'G'){
        cout << "Please make a choice in the range "
        << "of A through G:";
        cin >> choice;
    }

    // Process the user's menu selection.
    switch(choice)
    {
      case 'a':
      case 'A': displayPatientAccount(patientArray.at(choicePatient));
                break;
      case 'b':
      case 'B': Pharmacy.addMedicine(patientArray.at(choicePatient));
               // cout << savings.getTransactions()
                    // << " transactions.\n";
                break;
      case 'c':
      case 'C': Surgery.addSurgery(patientArray.at(choicePatient));
               // cout << savings.getInterest() << endl;
                break;
      case 'd':
      case 'D': //makeDeposit(savings);
                break;
      case 'e':
      case 'E': addPatientAccount(patientArray);
                break;
      case 'f':
      case 'F': deletePatientAccount(patientArray);
                break;
      case 'g':
      case 'G':
                break;


    }
} while (toupper(choice) != 'G');



return 0;
}
