#include <iostream>
using namespace std;

int main()
{
	int i;
	cin>>i;
	while (i>1)
	{
		cout<<i%10<<"  ";
		i = i/10 ;
	}
	return 0;
}
