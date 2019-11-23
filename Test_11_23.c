#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<string> split(string str, char ch)
{
	stringstream ss(str);
	string tmp;
	vector<string> res;
	while (getline(ss, tmp, ch))
	{
		res.push_back(tmp);
	}

	return res;
}




int judge_poke(vector<string> poke)
{
	int flag = -1;
	if (poke.size() == 1)
	{
		flag = 0;
	}
	else if (poke.size() == 2)
	{
		if (poke[0] == string("joker") || poke[1] == string("joker"))
			flag = 5;
		else
			flag = 1;
	}
	else if (poke.size() == 3)
		flag = 2;
	else if (poke.size() == 4)
		flag = 3;
	else if (poke.size() == 5)
		flag = 4;
	return flag;
}

int main()
{
	string str;

	vector<string> all = { "3", "4", "5", "6", "7", "8", "9", "10",
		"J", "Q", "K", "A", "2", "joker", "JOKER" };

	while (getline(cin, str))
	{
		int win = -1;
		vector<string> vec = split(str, '-');
		vector<string> poke1 = split(vec[0], ' ');
		vector<string> poke2 = split(vec[1], ' ');

		int flag1 = -1, flag2 = -1;
		flag1 = judge_poke(poke1);
		flag2 = judge_poke(poke2);

		if (flag1 == 5 || flag2 == 5 || flag1 == 3 || flag2 == 3)
		{
			if (flag1 == 5)
				win = 1;
			else if (flag2 == 5)
				win = 2;
			else if (flag1 == flag2 && flag1 == 3)
			{
				auto it1 = find(all.begin(), all.end(), poke1[0]);
				auto it2 = find(all.begin(), all.end(), poke2[0]);

				if (it1 > it2)
					win = 1;
				else
					win = 2;
			}
			else if (flag1 == 3 && flag2 != 3)
				win = 1;
			else if (flag1 != 3 && flag2 == 3)
				win = 2;
		}

		else if (flag1 == flag2)
		{
			auto it1 = find(all.begin(), all.end(), poke1[0]);
			auto it2 = find(all.begin(), all.end(), poke2[0]);

			if (it1 > it2)
				win = 1;
			else
				win = 2;
		}
		else
			win = 0;

		if (!win)
			cout << "ERROR" << endl;
		else if (win == 1)
		{
			int i = 0;
			for (; i<poke1.size() - 1; i++)
				cout << poke1[i] << " ";
			cout << poke1[i] << endl;
		}
		else if (win == 2){
			int i = 0;
			for (; i<poke2.size() - 1; i++)
				cout << poke2[i] << " ";
			cout << poke2[i] << endl;
		}
	}
	return 0;
}