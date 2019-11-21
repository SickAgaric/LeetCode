#include<iostream>

using namespace std;

class Date
{
	friend istream& operator>>(istream& cin, Date& date);
public:
	int GetDay(int year, int month)
	{
		static int _Day[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
			return 29;
		else
			return _Day[month];
	}

	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	int Get_Day(Date& d)
	{
		int count = 0;
		int year = d._year;
		int month = d._month;
		int day = d._day;

		count += day;
		--month;

		while (month)
		{
			count += GetDay(year, month);
			month--;
		}

		return count;
	}


private:
	int _year;
	int _month;
	int _day;
};

istream& operator>>(istream& cin, Date& date)//istream类型
{
	cin >> date._year >> date._month >> date._day;
	return cin;
}

int main()
{
	Date d;
	while(cin >> d)
    {
	    cout << d.Get_Day(d) << endl;
    }
    
	return 0;
}

#include<iostream>

using namespace std;


int main()
{
    int num;
    while(cin >> num)
    {
        int count = 0;
        while(num)
        {
            if(num & 1 == 1)
                count++;
            num = num >> 1;
        }

        cout << count << endl;
    }

        return 0;
}

class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        /*int r_count = 0;
        int r_sum = 0;
        int l_sum = 0;
        int max = 0;
        vector<int> list;
        
        for(int i = 0;i < right.size();++i)
        {
            if(right[i] == 0)
            {
                r_count++;
                list.push_back(i);
            }
        }
        
        for(int k = 0;k < right.size();++k)
        {
            if(max < right[k])
                max = right[k];
        }
        r_sum = max + right.size() - 1 - r_count;
        
        for(size_t j = 0;j < list.size();++j)
        {
            if(left[list[j]] != right[list[j]])
                l_sum++;
        }
        
        return (r_sum + l_sum + 1);*/
		int l_sum = 0,l_min = INT_MAX,r_sum = 0,r_min = INT_MAX;
        
        int sum = 0;
        
        for(int i = 0;i < n;++i)
        {
            if(left[i]*right[i] == 0)
                sum += left[i]+right[i];//左或者右不为0的数的总和
            else
            {
                l_sum += left[i];
                r_sum += right[i];
                l_min = min(left[i],l_min);
                r_min = min(right[i],r_min);
            }
        }
        //sum + min(l_sum - l_min + 1,r_sum - r_min + 1)表示取某只手的最坏的结果，然后在另一只去一直，即可匹配
        return sum + min(l_sum - l_min + 1,r_sum - r_min + 1) + 1;
    }
    }
};