#include<iostream>
#include<fstream>
using namespace std;

/*Ham tinh khoang cach giua 1.1 nam nay den 1.1 nam kia*/
int KC_Nam(int Nam1, int Nam2)
{
	int i, sum;
	sum = (Nam2 - Nam1) * 365;
	for (i = Nam1; i < Nam2; i++)
	{
		if ((i % 400 == 0) || ((i % 100 != 0) && (i % 4 == 0)))
		{
			sum = sum + 1;
		}
	}
	return sum;
}
/*Ham tinh khoang cach giua 1.1 nam do den ngay do*/
int KC_Ngay(int ngay, int thang, int nam)
{
	int ngaycuoithang[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int sum, i;
	i = nam;
	if ((i % 400 == 0) || ((i % 100 != 0) && (i % 4 == 0)))
	{
		ngaycuoithang[2] = 29;
	}
	sum = ngay - 1 + (thang - 1) * 30;
	for (int i = 1; i < thang; i++)
	{
		if (ngaycuoithang[i] == 31)
		{
			sum = sum + 1;
		}
		if (i == 2)
		{
			sum = sum - (30 - ngaycuoithang[2]);
		}
	}
	return sum;
}

/* Ham kiem tra */
bool Ktra_NamNhuan(int Year)
{
	if ((Year % 400 == 0) || ((Year % 100 != 0) && (Year % 4 == 0))) return true;
	return false;
}
int SoNgayCuoiThang(int Day, int Month, int Year)
{
	switch (Month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
	case 2:
		if (Ktra_NamNhuan(Year) == true)
		{
			return 29;
		}
		else return 28;
	case 4: case 6: case 9: case 11: return 30;
	default: return -1;
	}
}
bool CheckDay(int Day, int Month, int Year)
{
	if (Month <= 0 || Month >= 13 || Year <= 1000 || Year >= 2019)
	{
		return false;
	}
	return (0 < Day && Day <= SoNgayCuoiThang(Day, Month, Year));
}

class Date
{
	friend ostream& operator<<(ostream& output, const Date& D)
	{
		output << D.Day << "/" << D.Month << "/" << D.Year;
		return output;
	}
	friend istream& operator>>(istream& input, Date& D)
	{
		string SMS = "Du lieu dau vao bi fail!!!!\nCan chinh sua file input cho hop le!";
		input >> D.Day;
		input >> D.Month;
		input >> D.Year;
		if (CheckDay(D.Day, D.Month, D.Year) == false)
		{
			throw(SMS);
		}
		return input;
	}
private:
	int Day;
	int Month;
	int Year;
public:
	/* Ham tao */
	Date()
	{
		Day = 1;
		Month = 1;
		Year = 1000;
	}
	Date(int d, int m, int y)
	{
		Day = d;
		Month = m;
		Year = y;
	}

	/* Nap chong toan tu cong tru */
	Date operator+(int x)
	{
		Day += x;
		if ((Month == 1) || (Month == 3) || (Month == 5) || (Month == 7) || (Month == 8) || (Month == 10))
		{
			if (Day > 31)
			{
				Day = Day - 31;
				Month++;
			}
		}
		if ((Month == 4) || (Month == 6) || (Month == 9) || (Month == 11))
		{
			if (Day > 30)
			{
				Day = Day - 30;
				Month++;
			}
		}
		if ((Month == 12) && (Day > 31))
		{
			Day = Day - 31;
			Month = 1;
			Year++;
		}
		if (Month == 2)
		{
			if (((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0))
			{
				if (Day > 29)
				{
					Day = Day - 29;
					Month++;
				}
			}
			else
			{
				if ((Day > 28))
				{
					Day = Day - 28;
					Month++;
				}
			}
		}
		return *this;
	}
	Date operator++()
	{
		*this = *this + 1;
		return *this;
	}
	int operator-(Date D)
	{
		int Kq = 0, Kc_Nam, KC1, KC2;
		KC1 = KC_Ngay(Day, Month, Year);
		KC2 = KC_Ngay(D.Day, D.Month, D.Year);
		if (Year < D.Year)
		{
			Kq = KC_Nam(Year, D.Year) + KC2 - KC1;
		}
		if (Year > D.Year)
		{
			Kq = KC_Nam(D.Year, Year) - KC2 + KC1;
		}
		if (Year == D.Year)
		{
			if (KC1 < KC2)
			{
				Kq = KC2 - KC1;
			}
			else Kq = KC1 - KC2;
		}
		return Kq;
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

	Date D1, D2, D3;
	try
	{
		in >> D1; in >> D2;
	}
	catch (string mes)
	{
		cout << mes;
	}
	out << "D1: " << D1 << " ;  D2: " << D2;
	int Kc = D2 - D1;
	out << "\n- Khoang cach giua Date2 va Date1 la: " << Kc;

	D3 = D1 + 10;
	out << "\n- D1 sau khi them 10 ngay la: " << D3;
	++D2;
	out << "\n- D2 sau khi tang 1 ngay la: " << D2;
	in.close(); out.close();
	return 0;
}
