#include <iostream>
#include <string>

using namespace std;

class Employee{
private:
    string name;
    int idNumber;
    string department;
    string position;
public:
    Employee(string name,int idNumber,string department,string position){
        this->name=name;
        this->idNumber=idNumber;
        this->department=department;
        this->position=position;
    }

      Employee(string name,int idNumber){
        this->name=name;
        this->idNumber=idNumber;
        this->department="";
        this->position="";
    }

     Employee(){
        name="";
        idNumber=0;
        department="";
        position="";
    }

    string getName()const{
        return name;
    }

    int getIdNumber()const{
        return idNumber;
    }

    string getDepartment()const{
        return department;
    }

    string getPosition()const{
        return position;
    }
};
int main() {

    Employee employee[3]={Employee("Susan Meyers",11111,"Accounting","VP"),
    Employee("Mark Jones",22222),
    Employee()};

    for(int i=0;i<3;i++){
        cout<<"Employee "<<i+1<<" info"<<endl;
        cout<<"name: "<<employee[i].getName()<<endl;
        cout<<"id Number: "<<employee[i].getIdNumber()<<endl;
        cout<<"department: "<<employee[i].getDepartment()<<endl;
        cout<<"position: "<<employee[i].getPosition()<<endl;
        cout<<'\n'<<endl;
    }
    return 0;
}
