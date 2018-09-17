#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year = 2018, int month = 6, int day = 10)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}

	// ��ǰ����days�����ʲô���ڣ� 
	Date operator+(int days);

	
	// ��ǰ����days��ǰ��ʲô���ڣ� 
	Date operator-(int days);

	// ��������֮����˶����죿 
	int operator-(Date& d);
	//����<<����
	friend ostream& operator<<(ostream& os, const Date& d);
	// ���ڱȴ�С 
	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	//Date& operator=(const Date& d);
	//����=�����
	Date& operator=(Date& tmp);
	// ����ȡ��ַ���� 
	Date* operator&();

	// ǰ��++ 
	Date& operator++();

	// ����++ 
	Date operator++(int);

	// ǰ��-- 
	Date& operator--();

	// ����++ 
	Date operator--(int);
private:
	int _year;
	int _month;
	int _day;
};
//����<<����
ostream& operator<<(ostream& os, const Date& d)
{
	os << d._year << ".";
	os << d._month << ".";
	os << d._day <<endl;
	return os;
}
//��ȡĳ��ĳ�µ�����
int GetMonthDays(int year, int month)
{
	int MonthDays[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		MonthDays[2] = 29;
	return MonthDays[month];

}
// ��ǰ����days�����ʲô���ڣ� 
Date Date::operator+(int days)
{
	if (days == 0)
		return *this;
	else if (days < 0)
	{
		days = -days;
		return *this - days;
	}
	while (1)
	{
		if (days <= (GetMonthDays(_year, _month) - _day))
		{
			_day += days;
			return *this;
		}
		else
		{
			if (_month == 12)
			{
				days -= (31 - _day);
				_year += 1;
				_month = 1;
				_day = 0;
			}
			else
			{
				days -= (GetMonthDays(_year, _month) - _day);
				_month += 1;
				_day = 0;
			}
		}
	}
}
// ��ǰ����days��ǰ��ʲô���ڣ� 
Date Date::operator-(int days)
{
	if (days == 0)
		return *this;
	else if (days < 0)
	{
		days = -days;
		return *this + days;
	}
	else
	{
		while (1)
		{
			if (days < _day)
			{
				_day -= days;
				return *this;
			}
			else
			{
				if (_month == 1)
				{
					_year -= 1;
					_month = 12;
					days = days - _day;
					_day = GetMonthDays(_year,_month);
				}
				else
				{
					_month -= 1;
					days -= _day;
					_day = GetMonthDays(_year, _month);
				}
			}
		}
	}
}
//����=�����
Date& Date::operator=(Date& tmp)
{
	_year = tmp._year;
	_month = tmp._month;
	_day = tmp._day;
	return tmp;
}
bool Date::operator>(const Date& d)
{
	if (_year > d._year)
		return true;
	else if (_year < d._year)
		return false;
	else
	{
		if (_month>d._month)
			return true;
		else if(_month < d._month)
			return false;
		else
		{
			if (_day>d._day)
				return true;
			else
				return false;
		}
	}
}
bool Date::operator<(const Date& d)
{
	if (!(Date::operator>(d)) && !(Date::operator==(d)))
		return true;
	else
		return false;
}
bool Date::operator==(const Date& d)
{
	if (_year == d._year && _month == d._month && _day == d._day)
		return true;
	else
		return false;
}
bool Date::operator!=(const Date& d)
{
	if (!(Date::operator==(d)))
		return true;
	else
		return false;
}

// ����ȡ��ַ���� 
Date* Date::operator&()
{
	return this;
}

// ǰ��++ 
Date& Date::operator++()
{
	++_day;
	if (_day > GetMonthDays(_year, _month))
	{
		++_month;
		_day = 1;
		if (_month > 12)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}

// ����++ 
Date Date::operator++(int)
{
	Date tmp(*this);
	_day++;
	if (_day > GetMonthDays(_year, _month))
	{
		_month++;
		_day = 1;
		if (_month > 12)
		{
			_year++;
			_month = 1;
		}
	}
	return tmp;
}

// ǰ��-- 
Date& Date::operator--()
{
	--_day;
	if (_day == 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}
		_day = GetMonthDays(_year, _month);
	}
	return *this;
}

// ����--
Date Date::operator--(int)
{
	Date tmp(*this);
	_day--;
	if (_day == 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day = GetMonthDays(_year, _month);
	}
	return tmp;
}
// ��������֮����˶����죿 
int Date::operator-(Date& d)
{
flag:
	int count = 0;
	if (Date::operator>(d))
	{
		while (1)
		{
				while (_month != 0)
				{
					while (_day != 0)
					{
						count++;
						_day--;
						if ((Date::operator==(d)))
							return count;
					}
					_month--;
					if (_month != 0)
						_day = GetMonthDays(_year, _month);
					else
						_day = 31;
				}
				_year--;
				_month = 12;
		}
	}
	else if (Date::operator<(d))
	{
		Date d1(*this);
		*this = d;
		d = d1;
		goto flag;
	}
	else
		return 0;
}
int main()
{
	//����
	Date d1(1976, 1, 15);
	//�ְ�
	Date d2(1973, 7, 9);
	//cout << d2-d1 << endl;
	//����+10000=2024.5.6
	Date d3(1996, 12, 19);
	Date d4(2018, 6, 26);
	//����+10000=2026.2.18
	Date d5(1998, 10, 3);
	cout << d5+10000 << endl;
	/////////////////////////////////
	cout << endl;
	cout << endl;
	int a = 1;
	Date d6(2018, 7, 6);
	for (a = 1; a < 1500; a++)
	{
		cout << ++d6 ;
	}
	system("pause");
	return 0;
}
