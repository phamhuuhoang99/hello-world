#include<iostream>
#include<string.h>
#include<fstream>
#define MAX 30
using namespace std;
class HugeInt
{
private:
	short integer[MAX];
public:
	HugeInt();
	HugeInt(int);
	
	friend istream& operator >>(istream&, HugeInt&);
	friend ostream& operator <<(ostream&, const HugeInt&);

	HugeInt operator +(const HugeInt&);
	HugeInt operator +(const int&);

	HugeInt operator -(const HugeInt&);
	HugeInt operator -(const int&);


	HugeInt operator *(const HugeInt&);
	HugeInt operator *(const int&);

	bool operator >(HugeInt);

	~HugeInt();
};

HugeInt::HugeInt()
{
	for (int i = 0; i < MAX; i++) {
		integer[i] = 0;
	}
}

HugeInt::HugeInt(int x )
{
	for (int i = 0; i < MAX; i++) {
		integer[i] = 0;
	}
	int j = 0;
	while (x > 0) {
		integer[MAX - 1 - j] = x % 10;
		x /= 10;
		j++;
	}
}

istream& operator >>(istream& in , HugeInt& h) {
	//cout << "Inter HugeInt ";
	char a[MAX];
	in >> a;
	int len = strlen(a);
	for (int i = 0; i < len; i++)
	{
		h.integer[MAX - i - 1] = a[len - 1 - i] - 48;					    
	}

	return in;
}
ostream& operator << (ostream& out, const HugeInt& h)
{
	int index = 0;
	for (int i = 0; i < MAX; i++)
	{
		index++;
		if (h.integer[i] != 0) break;
	}
	// Xuat ra so nguyen lon        	
	for (int i = index - 1; i < MAX; i++)
	{
		out << h.integer[i];
	}
	return out;
}
//Cong hai so nguyen lon voi nhau 
HugeInt HugeInt::operator+(const HugeInt &h)
{
	HugeInt sum;
	int nho = 0, tong = 0;
	for (int i = 0; i < MAX; i++)
	{
		tong =integer[MAX - 1 - i] + h.integer[MAX - 1 - i] + nho;
		sum.integer[MAX - 1 - i] = tong % 10;
		nho = tong / 10;
	}
	return sum;
}
//Cong so nguyen nho voi so nguyen lon

HugeInt HugeInt::operator+(const int &sobe) {

	return *this + HugeInt(sobe);
}
HugeInt HugeInt::operator-(const HugeInt& h)
{
	HugeInt hieu;
	int nho = 0, x = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (*this > h) {
			x = this->integer[MAX - 1 - i] - h.integer[MAX - 1 - i] - nho;
		}
		else {
			x = h.integer[MAX - 1 - i] - integer[MAX - 1 - i] - nho;
		}
		nho = 0;
		if (x < 0) {
			x += 10;
			nho++;
		}
		hieu.integer[MAX - 1 - i] =x;
	}
	int index = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (hieu.integer[i] != 0) {
			index = i;
			break;
		}
	}
	if (*this > h) {

	}
	else hieu.integer[index]=hieu.integer[index] * (-1);
	return hieu;
}
HugeInt HugeInt::operator-(const int& x)
{
	return *this - HugeInt(x);
}
//Nhan vs so lon
HugeInt HugeInt::operator*(const HugeInt& h)
{
	HugeInt kq;
	
	int pos1 = 0;
	for (int i = 0; i < MAX; i++)
	{
		pos1++;
		if (this->integer[i] != 0) break;
	}
	int pos2 = 0;
	for (int i = 0; i < MAX; i++)
	{
		pos2++;
		if (h.integer[i] != 0) break;
	}

	int shift = 0, nho = 0;
	int m = 0;
	for (int i = MAX - 1; i >= pos2-1; i--) {
		
		HugeInt x;
		for (int j = MAX - 1; j >= pos1-1; j--) {
		
			int k = h.integer[i] * integer[j]+nho;
			x.integer[MAX-1-m-shift] = k % 10;
			m++;
			nho = k / 10;
			
		}
		x.integer[MAX-1-shift-m]=nho;
		m = 0;
		nho = 0;
		shift++;
		kq = kq + x;
	}
	return kq;
}

HugeInt HugeInt::operator*(const int& x) 
{
	return *this * HugeInt(x);
}

bool HugeInt::operator>(HugeInt h)
{
	int pos1 = 0;
	for (int i = 0; i < MAX; i++)
	{
		pos1++;
		if (this->integer[i] != 0) break;
	}
	int pos2 = 0;
	for (int i = 0; i < MAX; i++)
	{
		pos2++;
		if (h.integer[i] != 0) break;
	}
	if (pos1 < pos2) return true;
	if (pos1 == pos2) {
		for (int i = pos1 - 1; i < MAX - 1; i++) {
			if (integer[i] > h.integer[i]) {
				return true;
			}
		}
	}
	return false;
}

HugeInt::~HugeInt()
{
}

int main() {

	ofstream out;  ifstream in;
	out.open("output.txt");  in.open("input.txt");
	if ((!out.good()) || (!in.good()))
	{
		cout << "Khong mo duoc tep!!!";
		return 0;
	}


	HugeInt h, g;
	int x1 = 10;
	in >> h;
	in >> g;
	out << "Nhap so lon thu 1: " << h;
	
	out << "\nNhap so lon thu 2: "<<g;
	
	out << "\nTong 2 so: ";
	out << h + g;
	out << "\nTich 2 so: ";
	out << h*g;
	out << "\nHieu 2 so lon: ";
	out << h - g;
	/*
	int x2;
	HugeInt k;
	cout << "\nNhap so nguyen x: ";
	cin >> x2;
	cout << "Nhap so lon: ";
	cin >> k;
	cout << "Tong so lon voi so be: ";
	cout << k + x2;

	cout << "\nTich so lon voi so be: ";
	cout << k * x2;

	cout << "\nHieu so lon voi so be: ";
	cout << k - x2;*/

	
	
	system("pause");
	return 0;
}


