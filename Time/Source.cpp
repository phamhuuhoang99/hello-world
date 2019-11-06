#include<iostream>
#include<fstream>
using namespace std;
class Time
{
	/* Nap chong toan tu nhap xuat */
	friend ostream& operator<<(ostream& output, const Time& T)
	{
		output << T.hour << " : " << T.minute << " : " << T.second;
		return output;
	}

	friend istream& operator>>(istream& input, Time& T)
	{
		string SMS = "Du lieu dau vao bi fail!!!!\nCan chinh sua file input cho hop le!";
		input >> T.hour;
		input >> T.minute;
		input >> T.second;
		if ((T.hour < 0) || (T.minute < 0) || (T.minute >= 60) || (T.second < 0) || (T.second >= 60))
		{
			throw(SMS);
		}
		return input;
	}
private:
	int hour;
	int minute;
	int second;
public:
	Time()
	{
		hour = minute = second = 0;
	}
	Time(int h, int m, int s)
	{
		hour = h;
		minute = m;
		second = s;
	}
	/* Nap chong toan tu cong tru */
	Time operator+(Time T)
	{
		Time Kq;
		Kq.hour = T.hour + hour;
		Kq.minute = T.minute + minute;
		Kq.second = T.second + second;
		return Kq;
	}

	Time operator-(Time T)
	{
		Time Kq;
		Kq.hour = hour - T.hour;
		Kq.minute = minute - T.minute;
		Kq.second = second - T.second;
		return Kq;
	}

	Time operator+(int x)
	{
		Time Kq;
		Kq.hour = hour;
		Kq.minute = minute;
		Kq.second = second + x;
		return Kq;
	}

	Time operator-(int x)
	{
		Time Kq;
		Kq.hour = hour;
		Kq.minute = minute;
		Kq.second = second - x;
		return Kq;
	}

	Time operator++()
	{
		Time Kq;
		Kq = *this + 1;
		return Kq;
	}

	Time operator--()
	{
		Time Kq;
		Kq = *this - 1;
		return Kq;
	}
	/* Nap chong toan tu so sanh */
	bool operator==(Time T)
	{
		if ((hour * 3600 + minute * 60 + second) == (T.hour * 3600 + T.minute * 60 + T.second))
		{
			return true;
		}
		return false;
	}
	bool operator>=(Time T)
	{
		if ((hour * 3600 + minute * 60 + second) >= (T.hour * 3600 + T.minute * 60 + T.second))
		{
			return true;
		}
		return false;
	}
	bool operator<=(Time T)
	{
		if ((hour * 3600 + minute * 60 + second) <= (T.hour * 3600 + T.minute * 60 + T.second))
		{
			return true;
		}
		return false;
	}
	bool operator>(Time T)
	{
		if ((hour * 3600 + minute * 60 + second) > (T.hour * 3600 + T.minute * 60 + T.second))
		{
			return true;
		}
		return false;
	}

	bool operator<(Time T)
	{
		if ((hour * 3600 + minute * 60 + second) < (T.hour * 3600 + T.minute * 60 + T.second))
		{
			return true;
		}
		return false;
	}
	bool operator!=(Time T)
	{
		if ((hour * 3600 + minute * 60 + second) != (T.hour * 3600 + T.minute * 60 + T.second))
		{
			return true;
		}
		return false;
	}
	/* Rut gon gio */
	void Rutgon()
	{
		int n;
		if (second >= 60)
		{
			n = second / 60;
			second = second - 60 * n;
			minute = minute + n;
		}
		if (minute >= 60)
		{
			n = minute / 60;
			minute = minute - 60 * n;
			hour = hour + n;
		}
		if (second < 0)
		{
			n = 1 - second / 60;
			second = second + 60 * n;
			minute = minute - n;
		}
		if (minute < 0)
		{
			n = 1 - minute / 60;
			minute = minute + 60 * n;
			hour = hour - n;
		}
	}
};
int main()
{
	ofstream out;  ifstream in;
	out.open("output.txt");  in.open("input.txt");
	if ((!out.good()) || (!in.good()))
	{
		cout << "Khong mo duoc tep!!!";
	}

	Time T1, T2, T3;
	try
	{
		in >> T1; in >> T2;
	}
	catch (string mes)
	{
		cout << mes;
	}

	out << "- Thoi gian T1 la: " << T1;
	out << "\n- Thoi gian T2 la: " << T2;
	out << "\n\n=============KET QUA==============\n";
	T3 = T1 + T2; T3.Rutgon(); out << "\n- Tong cua T1 va T2 la: " << T3;
	T3 = T1 - T2; T3.Rutgon(); out << "\n- Hieu cua T1 va T2 la: " << T3;
	T3 = T1 + 324; T3.Rutgon(); out << "\n- Tong cua T1 va 324 giay la: " << T3;
	T3 = T1 - 55; T3.Rutgon(); out << "\n- Hieu cua T1 va 55 giay la: " << T3;

	if (T1 > T2) out << "\n--> T1 lon hon T2!!!";
	if (T1 < T2) out << "\n--> T1 nho hon T2!!!";
	if (T1 >= T2) out << "\n--> T1 lon hon hoac bang T2!!!";
	if (T1 <= T2) out << "\n--> T1 nho hon hoac bang T2!!!";
	if (T1 == T2) out << "\n--> T1 bang T2!!!";
	if (T1 != T2) out << "\n--> T1 khac T2!!!";
	out << "\n- T1 sau khi tang 1 giay la: " << ++T1;
	out << "\n- T1 sau khi giam 1 giay la:" << --T1;

	out.close(); in.close();

	return 0;
}
