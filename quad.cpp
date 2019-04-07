

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

class Quadrilateral {

public:

    bool isQuadrilateral(){
        if ((((P1.getX()*(P2.getY()-P3.getY())+(P2.getX()*(P3.getY()-P1.getY()))+P3.getX()*(P1.getY()-P2.getY()))))==0){
                return false;
        } else if((((P2.getX()*(P3.getY()-P4.getY())+(P3.getX()*(P4.getY()-P2.getY()))+P4.getX()*(P2.getY()-P3.getY()))))==0) {
                 return false;
        } else if ((((P1.getX()*(P3.getY()-P4.getY())+(P3.getX()*(P4.getY()-P1.getY()))+P4.getX()*(P3.getY()-P1.getY()))))==0){
            return false;
        } else if ((((P1.getX()*(P2.getY()-P4.getY())+(P2.getX()*(P4.getY()-P1.getY()))+P4.getX()*(P1.getY()-P2.getY()))))==0){
            return false;
        }else { return true;
        }
    }
    double area(){
        double A;

        A = .5 * abs((P1.getX()*P2.getY())+(P2.getX()*P3.getY())+(P3.getX()*P4.getY())+(P4.getX()*P1.getY())-(P2.getX()*P1.getY())-(P3.getX()*P2.getY())-(P4.getX()*P3.getY())-(P1.getX()*P4.getY()));


        return A;
    }

    friend istream& operator>>(istream &input, Quadrilateral &l ) {

            Point P1 , P2 , P3, P4;
            cout<<"\n\tA point: ";
            input>>P1;
            cout<<"\n\tB point: ";
            input>>P2;
            cout<<"\n\tC point: ";
            input>>P3;
            cout<<"\n\tD point: ";
            input>>P4;
            l.P1 = P1;
            l.P2 = P2;
            l.P3 = P3;
            l.P4 = P4;
            return input;
    }

    friend ostream& operator<<(ostream &output, const Quadrilateral &P ) {
        output << "X Point : \n" << P.P1 << " and Y Point : \n" << P.P2;
        return output;

    }
    private:
        Point P1;
        Point P2;
        Point P3;
        Point P4;
};


int main() {
  Quadrilateral T1,T2;

  cout << "Q1: should have all zeros for values" << endl;
      cout << T1 << endl;

   cout << "Enter the 4 points of Q1( ex: (1,1) will be: 1 1) : ";
   cin >> T1;


   cout << endl;

   if (T1.isQuadrilateral()){
       cout << "Object 1 is a Quadrilateral."<< endl;
   } else {
        cout << "Object 1 is not a Quadrilateral."<< endl;
   }

   cout << "Area of Object 1: "<< T1.area() << endl;

  return 0;
}
