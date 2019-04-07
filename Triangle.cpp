#include <iostream>
#include<math.h>

using namespace std;
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

class Triangle {

public:
    bool isTriangle(){
        if ((((P1.getX()*(P2.getY()-P3.getY())+(P2.getX()*(P3.getY()-P1.getY()))+P3.getX()*(P1.getY()-P2.getY()))))==0){
                return false;
        } else{
                return true;
        }
    }

    double legAlength() {
        double a;
        double b;
        double legA;

        a =   pow((P2.getY() - P1.getY()),2);
        b =   pow((P2.getX() - P1.getX()),2);

        legA = pow(a+b,.5);
        return legA;
    }
    double legBlength() {
        double a;
        double b;
        double legB;

        a =   pow((P3.getY() - P1.getY()),2);
        b =   pow((P3.getX() - P1.getX()),2);

        legB = pow(a+b,.5);
        return legB;
    }
    double legClength() {
        double a;
        double b;
        double legC;

        a =   pow((P3.getY() - P2.getY()),2);
        b =   pow((P3.getX() - P2.getX()),2);

        legC = pow(a+b,.5);
        return legC;
    }

    double perimeter(){
        return legAlength()+legBlength()+legClength();
    }

    double area(){
        double P = perimeter() / 2;
        double A;
        A = sqrt(P*(P-legAlength())*(P-legBlength())*(P-legClength()));
        return A;
    }

    bool equilateral(){
        if ((legAlength()==legBlength() ) && (legBlength() == legClength())){
            return true;
        }else{
            return false;
        }
    }


    friend istream& operator>>(istream &input, Triangle &l ) {

            Point P1 , P2 , P3;
            cout<<"\n\tA point: ";
            input>>P1;
            cout<<"\n\tB point: ";
            input>>P2;
            cout<<"\n\tC point: ";
            input>>P3;
            l.P1 = P1;
            l.P2 = P2;
            l.P3 = P3;
            return input;
    }

    friend ostream& operator<<(ostream &output, const Triangle &P ) {
        output << "X Point : \n" << P.P1 << " and Y Point : \n" << P.P2;
        return output;

    }

    bool operator==(Triangle &rhs) {
        if((rhs.P1 == P1) || (rhs.P2 == P1) || (rhs.P3 == P1)){
            if((rhs.P1 == P2) || (rhs.P2 == P2) || (rhs.P3 == P2)){
                if((rhs.P1 == P3) || (rhs.P2 == P3) || (rhs.P3 ==P3)){
                    return true;
                }
            }
        }
        else{ return false;
        }
    }

    private:
        Point P1;
        Point P2;
        Point P3;
};


int main() {
  Triangle T1,T2;

  cout << "T1: should have all zeros for values" << endl;
      cout << T1 << endl;

   cout << "Enter the 3 points of T1( ex: (1,1) will be: 1 1) : ";
   cin >> T1;


   cout << endl;

   if (T1.isTriangle()){
       cout << "Object 1 is a Triangle."<< endl;
   } else {
        cout << "Object 1 is not a Triangle."<< endl;
   }

   cout << "Area of Object 1: "<< T1.area() << endl;
   cout << "Perimeter of Object 1: " << T1.perimeter() << endl;

   if (T1.equilateral()){
       cout << "Object 1 is an equilateral triangle"<< endl;
   }else{
       cout << "Object 1 is not an equilateral triangle"<< endl;
   }

   cout << "Enter the 3 points of T2: ";
   cin >> T2;


   cout << endl;

   if (T2.isTriangle()){
       cout << "Object 2 is a Triangle."<< endl;
   } else {
        cout << "Object 2 is not a Triangle."<< endl;
   }

   cout << "Area of Object 2: "<< T2.area() << endl;
   cout << "Perimeter of Object 2: " << T2.perimeter() << endl;

   if (T2.equilateral()){
       cout << "Object 2 is an equilateral triangle"<< endl;
   }else{
       cout << "Object 2 is not an equilateral triangle"<< endl;
}
bool x = T1==T2;

if (T1.isTriangle()&&T2.isTriangle()){
    if ( x ==0){
    cout << "They're not the same."<< endl;
    }else{
    cout << "They're the same" << endl;
    }
}else{}

}
