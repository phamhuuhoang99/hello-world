#include<iostream>
#include<fstream>
using namespace std;

class Complex {
private:
	double real;
	double img;
public:
	Complex(double = 0, double = 0);
	~Complex();

	friend istream& operator >>(istream&, Complex&);
	friend ostream& operator <<(ostream&, const Complex&);

	Complex operator +(Complex);
	Complex operator -(Complex);
	Complex operator *(Complex);

	bool operator==(const Complex&);
	bool operator!=(const Complex&);

	Complex& operator =(Complex&);
};

Complex::Complex(double real, double img) {
	this->img = img;
	this->real = real;
}
Complex::~Complex() {}

ostream& operator << (ostream& out, const Complex& com)
{
	 //if(com.img>0)
	out << com.real << "+" << com.img << "i";
	//else out << com.real << com.img << "i";
	return out;
}

istream& operator >> (istream& in, Complex& com)
{
	//cout << "Input real: ";
	in >> com.img;

	//cout << "Input img: ";
	in >> com.real;
	return in;
}
Complex Complex::operator+(Complex com) {
	this->img = this->img + com.img;
	this->real = this->real + com.real;
	return *this;
}
Complex Complex::operator-(Complex com) {
	this->img = this->img - com.img;
	this->real = this->real - com.real;
	return *this;
}
Complex Complex::operator*(Complex com) {
	Complex kq;
	 kq.real= this->real * com.real - this->img * com.img;
	kq.img = this->real * com.img + this->img * com.real;
	return kq;
}

bool Complex::operator==(const Complex& com) {
	return this->real == com.real && this->img == com.img;
}

bool Complex::operator!=(const Complex& com) {
	return this->real != com.real || this->img != com.img;
}

Complex& Complex::operator=(Complex& com) {
	this->real = com.real;
	this->img = com.img;
	return *this;
}

int main() {
	
	ofstream out;  ifstream in;
	out.open("output.txt");  in.open("input.txt");
	if ((!out.good()) || (!in.good()))
	{
		cout << "Khong mo duoc tep!!!";
		return 0;
	}

	Complex com1, com2;
	in >> com1;
	in >> com2;
	//Complex com2 = com1;
	//Complex com3(1, 2);
	//Complex com4;
	//cout << com1;
	/*cin >> com4;
	cout << com4;*/
	//cout << com2;
	//cout << com1 + com2 << endl;
	//cout << com1 * com3;
	out << "So phuc 1: " << com1;
	out << "\nSo phuc 2: " << com2;
	out << "\nTich 2 so phuc : "<<com1 * com2;
	out << "\nTong 2 so phuc: " << com1 + com2;
	/*if (com1 == com2) {
		cout << "Correct";
	}
	else
	{
		cout << "Wrong";
	}*/
	/*if (com1 != com3) {
		cout << "Correct";
	}
	else
	{
		cout << "Wrong";
	}*/
	//cout << com2 == com1;
	system("pause");
	return 0;

}