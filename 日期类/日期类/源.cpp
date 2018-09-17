//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	/******************日期类默认成员函数*************************/
//	Date(int year = 1990, int month = 1, int day = 1)            //构造函数
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		if (_year<1990 || _month<1 || _month >12 || _day<1 || _day > GetMonth(_year, _month))
//		{//非法日期
//			cout << "Invaid Date" << endl;
//			return;
//		}
//	}
//	bool IsLeap(int year)                 //四年一闰，百年不闰，四百年再闰
//	{
//		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//		{//判断是否为闰年
//			return true;
//		}
//		return false;
//	}
//	int GetMonth(int year, int month)      //获取该月的天数，闰年2月是29天
//	{
//		int monthday[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		if (IsLeap(year))
//		{
//			monthday[2] = 29;
//		}
//		else
//		{
//			monthday[2] = 28;
//		}
//		return monthday[month];
//	}
//	Date(const Date& d)                   //拷贝构造函数
//		:_year(d._year)
//		, _month(d._month)
//		, _day(d._day)
//	{}
//	Date& operator= (const Date& d)      //赋值操作符重载
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//	~Date()                             //析构函数
//	{}
//	/******************日期类基本操作函数*************************/
//	//比较日期
//	bool operator== (const Date& d);
//	bool operator!= (const Date& d);
//	bool operator> (const Date& d);
//	bool operator>= (const Date& d);
//	bool operator< (const Date& d);
//	bool operator<= (const Date& d);
//	//日期计算
//	Date operator+ (int day);
//	Date& operator+= (int day);
//	Date operator- (int day);
//	Date& operator-= (int day);
//	Date operator++ (int);  //后置++
//	Date& operator++ ();    //前置++
//	Date operator-- (int);
//	Date& operator-- ();
//	int operator- (const Date& d);//计算两个日期相差的天数
//
//	friend ostream& operator<< (ostream& os, const Date& d);    //输出<<重载函数
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
////类外定义成员函数如下：
//
//ostream& operator<< (ostream& os, const Date& d)//输出<<重载函数
//{
//	os << d._year << ".";
//	os << d._month << ".";
//	os << d._day << endl;
//	return os;
//}
//
////日期比较
//bool Date::operator== (const Date& d)    //==运算符重载函数
//{
//	return _year == d._year
//		&& _month == d._month
//		&& _day == d._day;
//}
//bool Date::operator!= (const Date& d)    //!=运算符重载函数
//{
//	return !(*this == d);
//}
//bool Date::operator> (const Date& d)    //>运算符重载函数
//{
//	if (_year > d._year)
//	{
//		return true;
//	}
//	if (_year == d._year)
//	{
//		if (_month > d._month)
//		{
//			return true;
//		}
//		if (_month = d._month)
//		{
//			if (_day > d._day)
//			{
//				return true;
//			}
//		}
//	}
//	return false;
//}
//bool Date::operator>= (const Date& d)     //>=运算符重载函数
//{
//	return (*this > d) || (*this == d);
//}
//bool Date::operator< (const Date& d)      //<运算符重载函数
//{
//	return !(*this >= d);
//}
//bool Date::operator<= (const Date& d)     //<=运算符重载函数
//{
//	return !(*this>d);
//}
//
////日期计算
//Date Date::operator+ (int day)   //+运算符重载函数
//{
//	if (day < 0)
//	{
//		day = _day;
//		return (*this - day); //调用-运算符重载函数
//	}
//	Date tmp(*this);
//	if (day == 0)
//	{
//		return tmp;
//	}
//	tmp._day += day;
//	int GetDay = GetMonth(tmp._year, tmp._month);//获取本月天数
//	if (tmp._day > GetDay)
//	{
//		tmp._day -= GetDay;
//		if (tmp._month == 12)
//		{
//			tmp._year++;
//			tmp._month = 1;
//		}
//		else
//		{
//			tmp._month++;
//		}
//	}
//	return tmp;
//}
//Date& Date::operator+= (int day)  //+=运算符重载函数
//{
//	Date tmp(*this);
//	tmp = (*this) + day;  //调用+运算符重载函数
//	*this = tmp;
//	return *this;
//}
//Date Date::operator- (int day)    //-运算符重载函数
//{
//	if (day < 0)
//	{
//		day = -day;
//		return (*this + day);
//	}
//	Date tmp(*this);
//	if (day == 0)
//	{
//		return tmp;
//	}
//	tmp._day -= day;
//	while (tmp._day <= 0)
//	{
//		if (tmp._month == 1)
//		{
//			tmp._year--;
//			tmp._month = 12;
//		}
//		else
//		{
//			tmp._month--;
//		}
//		tmp._day = GetMonth(tmp._year, tmp._month) + tmp._day;
//	}
//	return tmp;
//}
//Date& Date::operator-= (int day) //-=运算符重载函数
//{
//	Date tmp(*this);
//	tmp = (*this) - day;
//	*this = tmp;
//	return *this;
//}
//Date Date::operator++ (int)  //后置++
//{
//	Date tmp(*this);
//	(*this) += 1;//调用+=运算符重载函数
//	return tmp;
//}
//Date& Date::operator++ ()  //前置++
//{
//	(*this) += 1;
//	return *this;
//}
//Date Date::operator-- (int)  //后置--
//{
//	Date tmp(*this);
//	(*this) -= 1;
//	return tmp;
//}
//Date& Date::operator-- ()  //前置--
//{
//	(*this) -= 1;
//	return *this;
//}
//int Date::operator- (const Date& d)    //计算两个日期相差的天数
//{
//	Date tmp = *this;
//	Date ret = d;
//	int day = 0, flag = 0;
//	if (tmp < ret)
//	{
//		tmp = d;
//		ret = *this;
//		flag = 1;
//	}//tmp是较大的日期，ret是较小的日期
//	while (ret != tmp)
//	{
//		ret += 1;
//		day++;
//	}
//	if (flag)
//	{//说明*this比d小，相减的天数应为负数
//		day = -day;
//	}
//	return day;
//}
//int main()
//{
//	Date d1(1996,12,9);
//	Date zm = d1.operator+ (95);//计算两个日期相差的天数
//	cout << zm << endl;
//	system("pause");
//	return 0;
//}