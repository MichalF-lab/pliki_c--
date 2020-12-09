#include <string>
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


wielokat f(Punkt2 *punktow,int ile_punktow){
    wielokat ten;
    ten.punktow = punktow;
    ten.ile_punktow =ile_punktow;
    ten.obwod = obwod(punktow, ile_punktow);
    ten.pole = pole(punktow, ile_punktow);
    ten.nazwa = rand();
}