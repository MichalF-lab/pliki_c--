#include <iostream>
using namespace std;

int main()
{
	int i;
	cin>>i;
	do
	{
		cout<<i%10<<"  ";
		i = i/10 ;
	} while (i>1);
	return 0;
}
