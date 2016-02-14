#ifndef PHARMACY_H
#define PHARMACY_H

#include "PatientAccount.h"

class Pharmacy{
    private:
        double medPrice[5]={10.0, 20.0, 30.0, 40.0, 50.0};
    public:
        void addMedicine(PatientAccount &pa);


        double getMedPrice(int index)const{
            return medPrice[index];
        }




};



#endif
