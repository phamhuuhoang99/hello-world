#include<iostream>
#include<fstream>
using namespace std;
class PhanSo {
private:
	int tuSo;
	int mauSo;
	
	
public:

	PhanSo(int = 0, int = 1);
	~PhanSo();

	friend istream& operator >>(istream&, PhanSo&);
	friend ostream& operator <<(ostream&, const PhanSo&);

};
PhanSo::PhanSo(int tu, int mau) {
	tuSo = tu;
	mauSo = mau;
}

PhanSo::~PhanSo(){}

int UCLN(int a, int b) {
	while (a!=b) {
		if (a > b) a -= b;
		else b -= a;
	}
	return a;
}

ostream& operator << (ostream& out, const PhanSo& ps)
{
	out << ps.tuSo << "/" << ps.mauSo;
	return out;
}

istream& operator >> (istream& in, PhanSo& ps)
{
	//cout << "Nhap tu so: ";
	in >> ps.tuSo;
	//cout << "Nhap mau so: ";
	in >> ps.mauSo;


	return in;
}




int main() {
	ofstream out;  ifstream in;
	out.open("output.txt");  in.open("input.txt");
	if ((!out.good()) || (!in.good()))
	{
		cout << "Khong mo duoc tep!!!";
		return 0;
	}
	PhanSo ps;
	in >> ps;
	out << ps;
}