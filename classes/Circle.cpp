#include <iostream>

using namespace std;

class Circle{
private:
    double radius;
    double pi=3.14159;

public:
    Circle(){
        radius=0.0;
    }
    Circle(double r){
        radius=r;
    }

    void setRadius(int r){
        radius=r;
    }

    double getRadius()const{
        return radius;
    }

    double getArea()const{
        return pi*radius*radius;
    }

    double getDiameter()const{
        return radius*2;
    }

    double getCircumference()const{
        return 2*pi*radius;
    }

};

int main() {
    Circle circle;
    double radius;
    cout<<"enter the circle's radius: ";
    cin>>radius;

    circle.setRadius(radius);

    cout<<"the circle's area is "<<circle.getArea()<<endl;
    cout<<"the circle's diameter is "<<circle.getDiameter()<<endl;
    cout<<"the circle's circumference is "<<circle.getCircumference()<<endl;

   return 0;
}
