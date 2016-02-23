#ifndef SURGERY_H
#define SURGERY_H

#include "PatientAccount.h"

class Surgery{
    private:
        double surgeryPrice[5]={110.0, 220.0, 330.0, 440.0, 550.0};
    public:
        void addSurgery(PatientAccount &pa);

        double getSurgeryPrice(int index)const{
            return surgeryPrice[index];
        }





};

#endif
