#include <iostream>
#include "Time.h"

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
		sec = 60 - sec;
		min--;
	}
	if (min < 0)
	{
		min = 60 - min;
		hour--;
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

Time Time::operator +(int& n) const
{
	int hour = h + n;

	return Time(hour, m, s);
}

Time Time::operator +(double& n) const
{
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
