// write your code here cpp
#include<iostream>
#include<string>

using namespace std;


/*int main()
{
int n,num = 0;
while(cin >> n)
{
do
{
num = 0;
while(n)
{
num += n%10;
n /= 10;
}
n = num;
}while(num > 9);
cout << num << endl;
}
return 0;
}*/
/*
int num_root(string& s)
{
int sum = 0;
auto e = s.begin();
while(e != s.end())
{
sum += (*e - '0');
}
if(sum < 10)
return sum;

return result;
}
*/

// write your code here cpp
#include<iostream>
#include<string>

using namespace std;


/*int main()
{
int n,num = 0;
while(cin >> n)
{
do
{
num = 0;
while(n)
{
num += n%10;
n /= 10;
}
n = num;
}while(num > 9);
cout << num << endl;
}
return 0;
}*/
/*
int num_root(string& s)
{
int sum = 0;
auto e = s.begin();
while(e != s.end())
{
sum += (*e - '0');
}
if(sum < 10)
return sum;

return result;
}
*/

int num_root(int sum)
{
	if (sum < 10)
		return sum;
	int result = 0;
	while (sum)
	{
		result += sum % 10;
		sum /= 10;
	}
	if (result > 9)
		result = num_root(result);
	return result;
}

int main()
{
	string s;
	while (cin >> s)
	{
		int sum = 0;
		auto e = s.begin();
		while (e != s.end())
			sum += (*e++ - '0');
		cout << num_root(sum) << endl;

	}
}