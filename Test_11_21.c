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