#include<iostream>
#include<fstream>
using namespace std;
class Array {
private: 
	int size;
	int *index;
public:
	Array(int =0,int* =NULL);
	Array(const Array&);
	~Array();
	
	friend istream& operator >>(istream&, Array&);
	friend ostream& operator <<(ostream&, const Array&);

	Array& operator =(Array&);

	bool operator==(const Array&);
	bool operator!=(const Array&);

	int& operator[] (int);
	
	int getSize();
};

Array::Array(int s,int *in) {
	size = s;
	index = in;
	/*if (s != 0)
	{
		index = new int[s];
		for (int i = 0; i < s; i++)
			index[i] = in[i];
	}*/
}

Array::Array(const Array& arr) {
	this->size = arr.size;
	this->index = arr.index;
}
Array::~Array(){}

ostream& operator << (ostream& out, const Array &arr)
{
	out << "size: " << arr.size;
	out << " index: ";
	for (int i = 0; i < arr.size; i++) {
		out << arr.index[i]<<" ";
	}
	return out;
}

istream& operator >> (istream& in, Array& arr)
{
	//cout << "Enter size: ";
	in >>arr.size;
	//cout << "Enter index: ";
	for (int i = 0; i < arr.size; i++) {
		in >> arr.index[i];
	}
	return in;
}

Array& Array::operator=(Array& arr) {
	this->size = arr.size;
	this->index = arr.index;
	return *this;
}
int& Array::operator[](int pos)
{
	if (pos >= size)
	{
		cout << "Array index out of bound, exiting";
		exit(0);
	}
	return index[pos];
}
bool Array::operator==(const Array& arr) {
	if (this->size == arr.size && this->index == arr.index) {
		return true;
	}
	return false;

}
bool Array::operator!=(const Array& arr) {
	if (this->size != arr.size||this->index != arr.index) {
		return true;
	}
	return false;

}

int Array::getSize() {
	return size;
}
int main() {
	ofstream out;  ifstream in;
	out.open("output.txt");  in.open("input.txt");
	if ((!out.good()) || (!in.good()))
	{
		cout << "Khong mo duoc tep!!!";
		return 0;
	}
	int ins[] = { 0,1,2 };
	Array a(3,ins),b(3,ins);
	in >> a;
	in >> b;
	out << "Array A: " << a;
	
	//cout << a;

	out << "\na[" << 1 << "] ="<<a[1];

	out << "\nArray B: " << b;

	out << "\n======================================";
	out << "\nSo Sanh 2 Array ";
	if (a != b) {
		out << "\nA khong bang B!!";
	}
	else {
		out << "\nA bang B!!";
	}


	//cout << a[1];
	
	////Array b(0,in);

	//cout << "\nNhap Array B: ";
	//cin >> b;
	//cout << b;
	//
	//if (a != b) {
	//	cout << "\nA khong bang B!!";
	//}

	//
	//if (a == b) {
	//	cout <<"\nCorrect" << endl;
	//}

	
	system("pause");
	return 0;
}