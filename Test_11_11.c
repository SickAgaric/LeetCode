#include<iostream>
#include<string>

using namespace std;

bool Judge_str(string str)
{
	int n = str.size() / 2;
	int begin = 0;
	int end = str.size() - 1;
	while (n--)
	{
		if (str[begin++] != str[end--])
			return false;
	}
	return true;
}

int main()
{
	string A, B;
	string a;
	string c;
	cin >> A;
	cin >> B;

	a = A;

	int count = 0;

	for (int i = 0; i < A.size() + 1; i++)
	{
		if (i == 0)
		{
			c = B + A;
			if (Judge_str(c))
				count++;
			c = "";
		}
		else
		{
			c = a.insert(i, B);
			if (Judge_str(c))
				count++;
			c = "";
			a = A;
		}
	}
	cout << count;
	return 0;
}