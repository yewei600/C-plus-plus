#include <iostream>
#include <cstring>


using namespace std;

/*
An app that verifies a password against 3 conditions.
*/

const int SIZE = 50;

bool passwordVerify(char s[]){
    bool hasUpper=false;
    bool hasLower=false;
    bool hasDigit=false;
    if(strlen(s)<6){
        cout<<"password should at least be 6 characters long"<<endl;
        return false;
    }
    for(int i=0;i<strlen(s);i++){
        if(isupper(s[i])){
            hasUpper=true;
        }
        else if(islower(s[i])){
            hasLower=true;
        }
        else if(isdigit(s[i])){
            hasDigit=true;
        }
    }
    if(!hasUpper || !hasLower){
        cout<<"password should contain at least 1 uppercase and 1 lowercase letter"<<endl;
        return false;
    }
    if(!hasDigit){
        cout<<"password should contain at least 1 digit"<<endl;
        return false;
    }

    cout<<"Valid Password!";
    return true;

}

int main()
{
    bool passwordValid=false;
    char password[SIZE];

    while(!passwordValid){
        cout<<"enter a password: ";
        cin.getline(password,SIZE);

        passwordValid=passwordVerify(password);

    }
    return 0;

}
