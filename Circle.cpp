#include <iostream>
#include<math.h>

using namespace std;
const double PI = 3.14159;
class Point {

public:
    Point() {
        x = 0;
        y = 0;
    }

    Point(int a,int b) {
        x = a;
        y = b;
    }

    friend ostream& operator<<(ostream &output, const Point &P ) {

        output << "x: " << P.x << "y: " << P.y << endl;
        return output;
    }

    friend istream& operator>>(istream &input, Point &P ) {
            input >> P.x >> P.y;
            return input;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    bool operator==(Point &rhs) {
        return (rhs.x == x && rhs.y == y);
    }


private:
    int x;
    int y;
};

class Circle {

public:

    bool isCircle(){
        if ((P2.getY() == P1.getY())&&((P2.getX() == P1.getX()))){
            return false;
        }
        else {
            return true;
        }
    }

    double radius() {
        double a;
        double b;

        a =   pow((P2.getY() - P1.getY()),2);
        b =   pow((P2.getX() - P1.getX()),2);

        l_var = pow(a+b,.5);
        return l_var;
    }
    double diameter() {
        double dia = 2*radius();
        return dia;
    }
    double area(){
        double A = pow(radius(), 2)*PI;
        return A;
    }
    double circumference(){
        double circum = diameter()*PI;
        return circum;
    }

    friend istream& operator>>(istream &input, Circle &l ) {

            Point P1 , P2 , P3;
            cout<<"\n\tCenter point: ";
            input>>P1;
            cout<<"\n\tPoint on circle: ";
            input>>P2;
            l.P1 = P1;
            l.P2 = P2;
            return input;
    }

    friend ostream& operator<<(ostream &output, const Circle &P ) {
        output << "Center Point : \n" << P.P1 << "Point on circle: \n" << P.P2;
        return output;
    }
    bool operator==(Circle &rhs) {
        return(rhs.P1 == P1 && rhs.l_var == l_var);
    }

    private:
        Point P1;
        Point P2;
        double l_var;
};


int main() {
  Circle C1,C2;

  cout << "C1: should have all zeros for values" << endl;
      cout << C1 << endl;

   cout << "Enter the points of C1: ";
   cin >> C1;


   if (C1.isCircle()){
       cout << "The object is a circle."<< endl;
   }
   else{
       cout << "The object is not a circle."<< endl;
   }
   cout<< "Radius of circle 1 : " << C1.radius() << endl;
   cout<< "Diameter of circle 1 : " << C1.diameter() << endl;
   cout<< "Area of circle 1 : " << C1.area() << endl;
   cout<< "Circumference of circle 1 : " << C1.circumference() << endl;

   cout << "Enter first point of C2: ";
   cin >> C2;

   if (C2.isCircle()){
       cout << "The object is a circle."<< endl;
   }
   else{
       cout << "The object is not a circle."<< endl;
   }
   cout<< "Radius of circle 2 : " << C2.radius() << endl;
   cout<< "Diameter of circle 2: " << C2.diameter() << endl;
   cout<< "Area of circle 2 : " << C2.area() << endl;
   cout<< "Circumference of circle 2 : " << C2.circumference() << endl;

    bool x = C1==C2;

    if(C1.isCircle()&&C2.isCircle()){
    if(x == 1){
    cout << "They are the same." << endl;
    } else{
    cout << "They are not the same." << endl;
    }
    }else{}
  return 0;
}
