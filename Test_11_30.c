#include<iostream>
#include<string>

using namespace std;


int main()
{
	int num;
	string order;
	while (cin >> num >> order)
	{
		int begin = 1;
		int end = begin + 3;
		int index = 1;
		if (num <= 4)//当num小于4时候情况
		{
			int i;
			end = num;
			for (i = 0; i<order.size(); ++i)
			{
				if (order[i] == 'U')//U时候情况
				{
					--index;
					if (index == 0)
						index = num;
				}
				else//D时的情况
				{
					++index;
					if (index>num)
						index = 1;
				}
			}
			for (i = 1; i<num; ++i)
				cout << i << " ";
			cout << num << endl;//注意输出格式的要求
			cout << index << endl;
		}
		else//当num大于4时候
		{
			int j;
			for (j = 0; j<order.size(); ++j)
			{
				if (order[j] == 'U')//向上调整U
				{
					if (index == begin)
					{
						if (begin == 1)//当index处于最顶端的时候，且第一首歌
						{
							end = num;
							begin = num - 3;
							index = end;
						}
						else//当index不在顶端
						{
							begin--;
							end--;
							index = begin;
						}
					}
					else
						index--;
				}
				else//向下调整D
				{
					if (index == end)
					{
						if (end == num)//当index处于最下端，且最后一首歌
						{
							begin = 1;
							index = begin;
							end = begin + 3;
						}
						else
						{
							end += 1;
							index = end;
							begin++;
						}
					}
					else
						index++;
				}
			}
			for (j = 0; j<3; j++)
			{
				cout << begin++ << " ";
			}
			cout << begin << endl;
			cout << index << endl;
		}
	}
	return 0;
}


#include<iostream>
#include<vector>
using namespace std;
 
int main()
{
    int T, n, k;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        int num = 2 * n;
        vector<int> table(num);
        for(int i = 0; i < num; ++i)
            cin >> table[i];
        while (k--)
        {
            vector<int> n1(table.begin(), table.end());
            for (int i = 0; i < n; ++i)
            {
                table[2 * i] = n1[i];
                table[2 * i + 1] = n1[i + n];
            }
        }
        for(int i = 0; i < num - 1; ++i)
            cout << table[i] << " ";
        cout << table[num - 1] << endl;
    }
    return 0;
}