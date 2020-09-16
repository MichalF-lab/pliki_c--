#include <iostream>
using namespace std;
int main()
{
	int a,b;
	cin>>a;
	cin>>b;
	for (int i=1; i<=a; i++)
	{
		while (i==1 || i==a)
		{
			for (int o=1; o<=b; o++)
			{
				cout<<"X";
			}
			cout<<endl;
			i++;
		}
		
	}
	return 0;
}
