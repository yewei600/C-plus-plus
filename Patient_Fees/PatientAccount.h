#ifndef PATIENTACCOUNT_H
#define PATIENTACCOUNT_H

#include <string>
using namespace std;

class PatientAccount{
    private:
        string patientName;
        double charges;
        int daysInHospital;
        double dailyRate;
    public:

        PatientAccount();

        string getPatientName()const{
            return patientName;
        }

        double getPatientCharges()const{
            return charges;
        }

        int getDaysInHospital()const{
            return daysInHospital;
        }

        double getDailyRate()const{
            return dailyRate;
        }

        void setPatientName(string name);

        void updateCharges(double amt);





};





#endif
