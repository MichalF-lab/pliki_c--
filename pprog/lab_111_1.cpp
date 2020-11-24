#include <iostream>

using namespace std;

double f(double x){
    double y = ((3*(x*x))+(2*x)-4);
    //  x1 = 0,87 x2 = -1,54 
    return y;
}

double przedziały(double p1, double q1, int & poziom, double srodek=0){
    if (f(p1) == 0) return p1;
    if (poziom == 20) return p1;
    poziom++;
    // zakladamy ze p jest dodatnie a q ujemne
    
    srodek =p1 / q1;
}


int main(void){
    int p1 = -8, q1 = 8, int poziom = 0;

}