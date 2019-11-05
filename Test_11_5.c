#include<iostream>
#include<algorithm>

using namespace std;


int main()
{
	int n;
	while(cin>>n)
	{
		long long sum = 0;
		vector<int> v;
		for(int i = 0;i<n*3;i++)
		{
			cin >> v[i];
		}
		
		sort(v.begin(),v.end());
		
		for(int i = n;i<n*3;i++)
		{
			sum+=v[i];
		}
		
		cout << sum;
	}
	return 0;
}