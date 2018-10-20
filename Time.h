#pragma once
class Time
{
public:
	int h, m, s;
	Time();
	Time(int h1);
	Time(int h1, int m1);
	Time(int h1, int m1, int s1);

	void clockSet();

	Time operator +=(const Time& t);

	Time operator +(const Time& t) const;

	Time operator -(const Time& t) const;

	bool operator >(const Time& t) const;
	bool operator <(const Time& t) const;
	bool operator ==(const Time& t) const;
	bool operator !=(const Time& t) const;
	bool operator >=(const Time& t) const;
	bool operator <=(const Time& t) const;

	Time operator +(const int& n) const;
	Time operator +(const double& n) const;
};
