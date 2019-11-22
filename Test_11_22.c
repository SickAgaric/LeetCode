//
#include<iostream>
#include<vector>

using namespace std;

int count(int n)
{
	vector<int> list;
	int num = 1, tmp, sum = 0, _count = 0;
	while (num < n)
	{
		sum = 0;
		tmp = 1;
		while (tmp <= num)
		{
			if (num % tmp == 0)
				list.push_back(tmp);
			tmp++;
		}
		for (size_t i = 0; i < list.size()-1; ++i)
		{
			sum += list[i];
		}
		list.clear();
		if (sum == num)
			_count++;
		num++;
	}
	return _count;
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		cout << count(n) << endl;
	}

	return 0;
}