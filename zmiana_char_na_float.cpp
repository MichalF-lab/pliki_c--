#include <cstdlib>
#include <iostream>
using namespace std;

char** funkcja(char** tab, int g, int n) {

    char** tab2 = new char* [n];
    for (int i = 0; i < n; i++)
    {
        tab2[i] = new char[g];
        for (int j = 0; j < g; j++)
        {
            tab2[i][j] = tab[j][i];
            cout <<" "<< tab2[i][j];
        }
        cout << endl;
    }
    return tab2;
}

int main() {
    int g = 2;
    int n = 5;
    cin >> g >> n;
    char** tab = new char* [n];
    for (int i = 0; i < n; ++i)
    {
        tab[i] = new char[g];
        for (int j = 0; j < g; j++)
        {
            tab[i][j] = rand();
            cout << tab[i][j] << " ";
        }
    }
    cout << endl;
    char** cos = funkcja(tab, n, g);
    return 0;
}