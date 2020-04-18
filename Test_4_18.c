#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;




int main()
{
	int n, m;

	while (cin >> n >> m)
	{
		vector<int> v_money;
		v_money.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v_money[i];
		}

		int qst_num;
		cin >> qst_num;

		vector<int> v_count;
		v_count.resize(qst_num);

		for (int i = 0; i < qst_num; ++i)
		{
			cin >> v_count[i];
		}

		sort(v_money.begin(), v_money.end());

		for (int i = 0; i < v_count.size(); ++i)//开始询问数组的计算
		{
			int money = 0;
			vector<int> result;
			//将询问数量的数据加入其中
			for (int j = 0; j < v_count[i]; ++j)
			{
				result.push_back(v_money[j]);
			}

			int index = result.size();
			int day = 1;

			while (index > 0)//当股票数量为0时结束
			{
				
				//判断m是否大于数组数量
				if (index <= m)
				{
					for (int num = 0; num < index; num++)
					{
						money += result[num] * day;
					}

					
				}

				else
				{
					int n_count = m;
					int num = index - 1;
					while (n_count--)
					{
						money += result[num] * day;
						--num;
					}
				}

				

				day++;
				index -= m;
			}
			cout << money << endl;
			result.clear();
		}

	}
}













//int main()
//{
//	int n, k;
//	vector<vector<int>> v;
//	while (cin >> n >> k)
//	{
//		v.resize(n);
//		int tmp = 0;
//		for (int i = 0; i < n; ++i)
//		{
//			v[i].resize(k);
//			for (int j = 0; j < k; ++j)
//			{
//				cin >> v[i][j];
//			}
//		}
//
//
//	}
//
//	return 0;
//}













//int main()
//{
//	int n;
//	int k;
//	vector<int> v;
//	while (cin >> n >> k)
//	{
//		v.resize(n);
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> v[i];
//		}
//	
//		sort(v.begin(), v.end());
//		int index = 0;
//		for (int i = 0; i < v.size(); ++i)
//		{
//			if (v[i] == k)
//			{
//				index = i;
//				break;
//			}
//		}
//		index += 1;
//		int count = 0;
//		int mid = (n + 1) / 2;
//		if (mid == index)
//			cout << 0;
//		else if (index < mid)
//		{
//			index += 1;
//			n += 1;
//			++count;
//			int mid = (n + 1) / 2;
//			if (mid == index)
//				cout << count;
//		}
//		else
//		{
//			index -= 1;
//			n += 1;
//			++count;
//			int mid = (n + 1) / 2;
//			if (mid == index)
//				cout << count;
//		}
//
//	}
//
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//#include<iostream>
//#include<vector>
//#include<map>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	int k;
//	vector<int> v;
//	while (cin >> n >> k)
//	{
//		v.resize(n);
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> v[i];
//		}
//
//		sort(v.begin(), v.end());
//		int index = 0;
//		for (int i = 0; i < v.size(); ++i)
//		{
//			if (v[i] == k)
//			{
//				index = i;
//				break;
//			}
//		}
//		index += 1;
//		int count = 0;
//		while (true)
//		{
//			int mid = (n + 1) / 2;
//
//			if (mid == index)
//				break;
//			else
//			{
//				n++;
//				count++;
//			}
//		}
//
//		cout << count;
//	}
//
//	return 0;
//}