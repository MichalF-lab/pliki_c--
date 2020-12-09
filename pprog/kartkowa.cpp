#include <stdlib.h>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

struct Punkt2
{
double x;
double y;
};

struct wielokat
{
    Punkt2 *punktow;
    int ile_punktow;
    double obwod;
    double pole;
    string nazwa;
};

double dlugosc(Punkt2 punkt_1, Punkt2 punkt_2){
    return sqrt((punkt_1.x + punkt_2.x)*(punkt_1.x + punkt_2.x)+(punkt_1.y + punkt_2.y)*(punkt_1.y + punkt_2.y));
}

double obwod (Punkt2 *punktow,int ile_punktow, Punkt2 punkt_0){
    if (ile_punktow == 0) return dlugosc(*punktow,punkt_0);
    return (dlugosc(punktow[0],punktow[1]) + obwod(punktow++, ile_punktow--, punkt_0));
}

double pole (Punkt2 *punktow,int ile_punktow, Punkt2 punkt_0){
    if (ile_punktow == 1) return 0;
    if (ile_punktow == 2) return 0;
    
    double p =dlugosc(punkt_0,punktow[0])+dlugosc(punkt_0,punktow[1])+dlugosc(punktow[1],punktow[0])/2;
    double a =dlugosc(punkt_0,punktow[0]);
    double b =dlugosc(punkt_0,punktow[1]);
    double c =dlugosc(punktow[1],punktow[0]);

    if (ile_punktow == 3) return (sqrt(p*(p-a)*(p-b)*(p-c)));
    return (sqrt(p*(p-a)*(p-b)*(p-c)) + pole(punktow++,ile_punktow--,punkt_0));
}

wielokat f(Punkt2 *punktow,int ile_punktow, string nazwa){
    wielokat ten;
    ten.punktow = punktow;
    ten.ile_punktow =ile_punktow;
    Punkt2 punkt_0 = *punktow;
    ten.obwod = obwod(punktow, ile_punktow, punkt_0);
    ten.pole = pole(punktow++, ile_punktow, punkt_0);
    ten.nazwa = nazwa;
    return ten;
}

int main(){
    int x=5;
    Punkt2 * punktow = new Punkt2 [5];
    while ( x-- ){
        punktow[x].x=rand();
        punktow[x].y=rand();
    }
    wielokat pieciokat = f(punktow, 5, "pieciokat");
    cout<<pieciokat.obwod<<"   "<<pieciokat.pole;
}