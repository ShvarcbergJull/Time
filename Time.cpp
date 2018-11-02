#include <iostream>
#include <cstring>
#include "Time.h"

using namespace std;

Time::Time()
{
	h = 0;
	m = 0;
	s = 0;
}

Time::Time(int h1)
{
	h = h1;
	m = 0;
	s = 0;
}

Time::Time(int h1, int m1)
{
	h = h1;
	m = m1;
	s = 0;
}

Time::Time(int h1, int m1, int s1)
{
	h = h1;
	m = m1;
	s = s1;
}

Time::Time(char* a)
{
	int* arr = new int[3];
	int t = 0, i = 0, j = 0;

	while (*a != 0)
	{
		if (*a == ':')
		{
			a++;
			arr[i] = t;
			i++;
			t = 0;
			j++;
			continue;
		}

		if (!('0' < *a < '9'))
		{
			cout << "Error: Incorrect time entry" << endl;
			break;
		}

		t = t * 10 + (*a - '0');
		a++;
		if (*a == 0)
			s = t;
	}
	if (j == 0)
	{
		cout << "Error: Incorrect time entry" << endl;
		return;
	}
	h = arr[0];
	m = arr[1];
}

void Time::clockSet()
{
	m += s / 60;
	h += m / 60;
	m = m % 60;
	s = s % 60;
}

Time Time::operator +=(const Time& t)
{
	*this = *this + t;
	clockSet();
	return *this;
}

Time Time::operator +(const Time& t) const
{
	Time res;
	res.h = h + t.h;
	res.m = m + t.m;
	res.s = s + t.s;
	res.clockSet();

	return res;
}

Time Time::operator -(const Time& t) const
{
	int hour, min, sec;
	sec = s - t.s;
	min = m - t.m;
	hour = h - t.h;

	if (sec < 0)
	{
		sec = 60 + sec;
		min--;
	}
	if (min < 0)
	{
		min = 60 + min;
		hour--;
	}
	while (hour < 0)
	{
		hour = 24 + hour;
	}

	Time res(hour, min, sec);
	res.clockSet();

	return res;
}

bool Time::operator >(const Time& t) const
{
	if (h == t.h)
		if (m == t.m)
			if (s == t.s || s < t.s)
				return 0;
			else
				return 1;
		else
			if (m < t.m)
				return 0;
			else
				return 1;
	else
		if (h < t.h)
			return 0;
		else
			return 1;					
}

bool Time::operator <(const Time& t) const
{
	if (h == t.h)
		if (m == t.m)
			if (s == t.s || s > t.s)
				return 0;
			else
				return 1;
		else
			if (m > t.m)
				return 0;
			else
				return 1;
	else
		if (h > t.h)
			return 0;
		else
			return 1;
}

bool Time::operator ==(const Time& t) const
{
	return ((h == t.h) && (m == t.m) && (s == t.s));
}

bool Time::operator !=(const Time& t) const
{
	return !(*this == t);
}

bool Time::operator >=(const Time& t) const
{
	return((*this > t) || (*this == t));
}

bool Time::operator <=(const Time& t) const
{
	return ((*this < t) || (*this == t));
}

Time Time::operator +(const int& n) const
{
	int hour = h + n;

	return Time(hour, m, s);
}

Time Time::operator +(const double& f) const
{
	double n = f;
	int i = n, hour, min;
	n -= i;
	//n *= 10;
	//int p = n;
	min = (n * 60) + m;
	hour = h + i;
	Time res(hour, min, s);
	res.clockSet();

	return res;
}

/*istream& operator >>(istream& in, Time& t)
{
	in >> t.h >> t.m >> t.s;
	return in;
}

ostream& operator <<(ostream& out, const Time& t)
{
	out << t.h << ':' << t.m << ':' << t.s;
	return out;
}*/
