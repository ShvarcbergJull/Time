#include <iostream>
#include "Time.h"

using namespace std;

istream& operator >>(istream& in, Time& t)
{
	in >> t.h >> t.m >> t.s;
	return in;
}

ostream& operator <<(ostream& out, Time& t)
{
	out << t.h << ':' << t.m << ':' << t.s;
	return out;
}

int main()
{
	Time c1, c2, s;
	cout << "t1 = ";
	cin >> c1;
	cout << "t2 = ";
	cin >> c2;

	s = c1 + c2;

	cout << "t1 + t2 = " << s << endl;

	s = c1 - c2;

	cout << "t1 - t2 = " << s << endl;

	s = c1 + 2;

	cout << "t1 + 2 = " << s << endl;

	s = c2 + 3.5;

	cout << "t2 + 3.5 = " << s << endl;

	cout << "t1 = t2? ";
	if (c1 == c2)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	if (c1 != c2)
	{
		cout << "t1 ? t2 : ";

		if (c1 < c2)
			cout << "t1 < t2" << endl;
		if (c1 > c2)
			cout << "t1 > t2" << endl;
		if (c1 == c2)
			cout << "t1 = t2" << endl;
	}

	system("pause");
	return 0;
}
