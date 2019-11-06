#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;

class PhanSo
{
private:
	int Tuso;
	int Mauso;
public:
	/* Khai bao cac contrusor can thiet */
	PhanSo()
	{	}
	PhanSo(int tu, int mau)
	{
		setTu(tu);
		setMau(mau);
	}
	/* Nap chong cong */
	PhanSo operator+(PhanSo P)
	{
		PhanSo Kq;
		Kq.Tuso = Tuso * P.Mauso + Mauso * P.Tuso;
		Kq.Mauso = Mauso * P.Mauso;
		return Kq;
	}
	/* Nap chong tru */
	PhanSo operator-(PhanSo P)
	{
		PhanSo Kq;
		Kq.Tuso = Tuso * P.Mauso - Mauso * P.Tuso;
		Kq.Mauso = Mauso * P.Mauso;
		return Kq;
	}
	/* Nap chong nhan */
	PhanSo operator*(PhanSo P)
	{
		PhanSo Kq;
		Kq.Tuso = Tuso * P.Tuso;
		Kq.Mauso = Mauso * P.Mauso;
		return Kq;
	}
	/* Nap chong chia */
	PhanSo operator/(PhanSo P)
	{
		string SMS = "Khong thuc hien duoc phep chia!";
		PhanSo Kq;
		Kq.Tuso = Tuso * P.Mauso;
		Kq.Mauso = Mauso * P.Tuso;
		if (P.Tuso == 0)
		{
			throw(SMS);
		}
		return Kq;
	}
	/* Set va get cho tung thuoc tinh */
	void setTu(int tu)
	{
		Tuso = tu;
	}
	int getTu()
	{
		return Tuso;
	}
	void setMau(int mau)
	{
		Mauso = mau;
	}
	int getMau()
	{
		return Mauso;
	}
	/* Rut gon phan so */
	int UCLN()
	{
		int t, m;
		t = abs(Tuso); m = abs(Mauso);
		if (t * m == 0) return 1;// neu mot rong hai so bang 0 thi UCLN=1;
		while (t != m)
		{
			if (t > m)  t = t - m;
			else     m = m - t;
		}
		return t;
	}
	void Rutgon()
	{
		int u = UCLN();
		Tuso = Tuso / u; Mauso = Mauso / u;
	}
	/* Nap chong toan tu nhap xuat */
	friend ostream& operator<<(ostream& output, const PhanSo& Ps)
	{
		if ((Ps.Mauso == 1) || (Ps.Tuso == 0)) output << Ps.Tuso;
		else  output << Ps.Tuso << " / " << Ps.Mauso;
		return output;
	}

	friend istream& operator>>(istream& input, PhanSo& Ps)
	{
		string SMS = "Du lieu dau vao bi fail!!!!\nCan chinh sua file input cho hop le!";
		input >> Ps.Tuso;
		input >> Ps.Mauso;
		if (Ps.Mauso == 0)
		{
			throw(SMS);
		}
		return input;
	}
};
int main()
{
	ofstream out;  ifstream in;
	out.open("output.txt");  in.open("input1.txt");
	if ((!out.good()) || (!in.good()))
	{
		cout << "Khong mo duoc tep!!!";
	}

	PhanSo P1, P2, P3, P4;
	try
	{
		in >> P1; in >> P2; in >> P3;
	}
	catch (string mes)
	{
		cout << mes; out << mes;
	}
	out << "\n==========================\n";
	P1.Rutgon();
	out << "Phan so thu nhat: P1=" << P1 << endl;
	out << "\n==========================\n" << endl;
	P2.Rutgon();
	out << "Phan so thu hai: P2=" << P2 << endl;
	out << "\n==========================\n" << endl;
	P3.Rutgon();
	out << "Phan so thu ba: P3=" << P3 << endl;

	P4 = P1 + P2;//~~P4=P1.operator+(P2);
	out << "\n==========================\n" << endl;
	P4.Rutgon();
	out << "Phan so tong cua P1 va P2 la: " << P4 << endl;

	P4 = P1 - P2;//~~P4=P1.operator-(P2);
	out << "\n==========================\n" << endl;
	P4.Rutgon();
	out << "Phan so hieu cua P1 va P2 la: " << P4 << endl;

	P4 = P1 * P2;//~~P4=P1.operator*(P2);
	out << "\n==========================\n" << endl;
	P4.Rutgon();
	out << "Phan so tich cua P1 va P2 la: " << P4 << endl;

	try
	{
		P4 = P1 / P2;//~~P4=P1.operator/(P2);
		out << "\n==========================\n" << endl;
		P4.Rutgon();
		out << "Phan so thuong cua P1 va P2 la: " << P4 << endl;
	}
	catch (string mes)
	{
		cout << mes; out << mes;
	}
	in.close(); out.close();
	return 0;
}
