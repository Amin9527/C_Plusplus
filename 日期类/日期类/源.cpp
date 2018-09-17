//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	/******************������Ĭ�ϳ�Ա����*************************/
//	Date(int year = 1990, int month = 1, int day = 1)            //���캯��
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		if (_year<1990 || _month<1 || _month >12 || _day<1 || _day > GetMonth(_year, _month))
//		{//�Ƿ�����
//			cout << "Invaid Date" << endl;
//			return;
//		}
//	}
//	bool IsLeap(int year)                 //����һ�򣬰��겻���İ�������
//	{
//		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//		{//�ж��Ƿ�Ϊ����
//			return true;
//		}
//		return false;
//	}
//	int GetMonth(int year, int month)      //��ȡ���µ�����������2����29��
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
//	Date(const Date& d)                   //�������캯��
//		:_year(d._year)
//		, _month(d._month)
//		, _day(d._day)
//	{}
//	Date& operator= (const Date& d)      //��ֵ����������
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//	~Date()                             //��������
//	{}
//	/******************�����������������*************************/
//	//�Ƚ�����
//	bool operator== (const Date& d);
//	bool operator!= (const Date& d);
//	bool operator> (const Date& d);
//	bool operator>= (const Date& d);
//	bool operator< (const Date& d);
//	bool operator<= (const Date& d);
//	//���ڼ���
//	Date operator+ (int day);
//	Date& operator+= (int day);
//	Date operator- (int day);
//	Date& operator-= (int day);
//	Date operator++ (int);  //����++
//	Date& operator++ ();    //ǰ��++
//	Date operator-- (int);
//	Date& operator-- ();
//	int operator- (const Date& d);//��������������������
//
//	friend ostream& operator<< (ostream& os, const Date& d);    //���<<���غ���
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
////���ⶨ���Ա�������£�
//
//ostream& operator<< (ostream& os, const Date& d)//���<<���غ���
//{
//	os << d._year << ".";
//	os << d._month << ".";
//	os << d._day << endl;
//	return os;
//}
//
////���ڱȽ�
//bool Date::operator== (const Date& d)    //==��������غ���
//{
//	return _year == d._year
//		&& _month == d._month
//		&& _day == d._day;
//}
//bool Date::operator!= (const Date& d)    //!=��������غ���
//{
//	return !(*this == d);
//}
//bool Date::operator> (const Date& d)    //>��������غ���
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
//bool Date::operator>= (const Date& d)     //>=��������غ���
//{
//	return (*this > d) || (*this == d);
//}
//bool Date::operator< (const Date& d)      //<��������غ���
//{
//	return !(*this >= d);
//}
//bool Date::operator<= (const Date& d)     //<=��������غ���
//{
//	return !(*this>d);
//}
//
////���ڼ���
//Date Date::operator+ (int day)   //+��������غ���
//{
//	if (day < 0)
//	{
//		day = _day;
//		return (*this - day); //����-��������غ���
//	}
//	Date tmp(*this);
//	if (day == 0)
//	{
//		return tmp;
//	}
//	tmp._day += day;
//	int GetDay = GetMonth(tmp._year, tmp._month);//��ȡ��������
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
//Date& Date::operator+= (int day)  //+=��������غ���
//{
//	Date tmp(*this);
//	tmp = (*this) + day;  //����+��������غ���
//	*this = tmp;
//	return *this;
//}
//Date Date::operator- (int day)    //-��������غ���
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
//Date& Date::operator-= (int day) //-=��������غ���
//{
//	Date tmp(*this);
//	tmp = (*this) - day;
//	*this = tmp;
//	return *this;
//}
//Date Date::operator++ (int)  //����++
//{
//	Date tmp(*this);
//	(*this) += 1;//����+=��������غ���
//	return tmp;
//}
//Date& Date::operator++ ()  //ǰ��++
//{
//	(*this) += 1;
//	return *this;
//}
//Date Date::operator-- (int)  //����--
//{
//	Date tmp(*this);
//	(*this) -= 1;
//	return tmp;
//}
//Date& Date::operator-- ()  //ǰ��--
//{
//	(*this) -= 1;
//	return *this;
//}
//int Date::operator- (const Date& d)    //��������������������
//{
//	Date tmp = *this;
//	Date ret = d;
//	int day = 0, flag = 0;
//	if (tmp < ret)
//	{
//		tmp = d;
//		ret = *this;
//		flag = 1;
//	}//tmp�ǽϴ�����ڣ�ret�ǽ�С������
//	while (ret != tmp)
//	{
//		ret += 1;
//		day++;
//	}
//	if (flag)
//	{//˵��*this��dС�����������ӦΪ����
//		day = -day;
//	}
//	return day;
//}
//int main()
//{
//	Date d1(1996,12,9);
//	Date zm = d1.operator+ (95);//��������������������
//	cout << zm << endl;
//	system("pause");
//	return 0;
//}