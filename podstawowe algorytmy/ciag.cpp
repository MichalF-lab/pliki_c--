#include <iostream>
using namespace std;
void sumciag()
{
	int a, s=0;
	cin>>a;
	for (int i=1; i<=a; i++)
	{
		s+=i;
	}
	cout<<s;
}
int main()
{
	sumciag();
	return 0;
}
