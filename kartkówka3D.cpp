#include <cstdlib>
#include <iostream>
using namespace std;

float funkcja(char** tab){
	int n=5;
    float** tab2 = new float* [n];
	for (int i = 0; i < 2; ++i)
	{
    	tab2[i] = new float[n];
        for(int j=0;j<5;j++)
            tab2[i][j]=float(tab[i][j]); 
    }
    return **tab2;
}

int main(){
    int parametr = 0;
	int n = 5;
	char** tab = new char* [n];
	for (int i = 0; i < 2; ++i)
	{
    	tab[i] = new char[n];
        for(int j=0;j<5;j++)
            tab[i][j]=rand();
    }
    float cos = funkcja(tab);
    return 0;
}