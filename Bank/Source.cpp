#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class TKNganHang
{
private:
	int soTaiKhoan;
	int soDu;

public:
	void NhapTK();
	int Getter_SoTaiKhoan()
	{
		return soTaiKhoan;
	}

	void Setter_SoTaiKhoan(int STK)
	{
		soTaiKhoan = STK;
	}

	int Getter_SoDu()
	{
		return soDu;
	}

	void Setter_SoDu(int SODU)
	{
		soDu = SODU;
	}

	void DocFile(ifstream&);
	void XuatFile(ofstream&);

	friend istream& operator>>(istream& in, TKNganHang& tK);
	friend ostream& operator<<(ostream& out, const TKNganHang& tK);
	int operator+(int tienChuyen);
	bool operator==(TKNganHang tK);
};

void TKNganHang::DocFile(ifstream& filein)
{
	if (!filein.good())
		cout << "File could not be opened" << endl;
	filein >> soTaiKhoan;
	filein >> soDu;
	cout << "\nSo Tai Khoan:" << soTaiKhoan;
	cout << "\nSo Du: " << size_t(soDu);
	cout << "\nMa kiem tra: " << soTaiKhoan - (soTaiKhoan / 5) * 5;

}

void TKNganHang::XuatFile(ofstream& fileout)
{
	if (!fileout.good())
		cout << "File could not be opened" << endl;
	fileout << "\nSo Tai Khoan:" << soTaiKhoan;
	fileout << "\nSo Du: " << size_t(soDu);
	fileout << "\nMa kiem tra: " << soTaiKhoan - (soTaiKhoan / 5) * 5 << "\n";
}

ostream& operator<<(ostream& out, const TKNganHang& tK)
{
	out << "\nSo Tai Khoan:" << tK.soTaiKhoan;
	out << "\nSo Du: " << size_t(tK.soDu);
	out << "\nMa kiem tra: " << tK.soTaiKhoan - (tK.soTaiKhoan / 5) * 5;
	return out;
}

istream& operator>>(istream& in, TKNganHang& tK)
{
	cout << "So Tai Khoan: ";
	in >> tK.soTaiKhoan;
	while (tK.soTaiKhoan > 9999)
	{
		cout << "Ban da nhap sai moi ban nhap lai (So Tai Khoan co 4 chu so): ";
		in >> tK.soTaiKhoan;
	}

	cout << "So du: ";
	in >> tK.soDu;
	while (tK.soDu < 0)
	{
		cout << "Ban da nhap sai moi ban nhap lai (So Du phai lon hon 0 hoac ban khong co tien): ";
		in >> tK.soDu;
	}
	return in;
}

int TKNganHang::operator+(int tienChuyen)
{
	int soDuSau;
	soDuSau = this->soDu + tienChuyen;
	return soDuSau;
}

bool TKNganHang::operator==(TKNganHang tK)
{
	if (this->soTaiKhoan == tK.soTaiKhoan) return true;
	else return false;
}
void ChuyenTien(TKNganHang& Tk1, TKNganHang& Tk2)
{
	int TienChuyen;
	if (Tk1.Getter_SoDu() < 10000) cout << "\nTai khoan 1 chi con: " << Tk1.Getter_SoDu();
	if (Tk1.Getter_SoDu() > 100000000) cout << "\nTai khoan 1 con rat nhieu: " << Tk1.Getter_SoDu();
	cout << "\nSo Tien Chuyen tu Tk1 sang Tk2 la: ";
	cin >> TienChuyen;
	while (TienChuyen > Tk1.Getter_SoDu())
	{
		cout << "\nSo Du khong du, moi ban nhap lai: ";
		cin >> TienChuyen;
	}
	cout << "\nSo Du Tk1 con lai: " << size_t(Tk1 + (-TienChuyen));
	cout << "\nSo Du Tk2 luc nay: " << size_t(Tk2 + TienChuyen) << "\n";
	Tk2.Setter_SoDu(Tk2 + TienChuyen);
	Tk1.Setter_SoDu(Tk1 + (-TienChuyen));
	if (Tk2.Getter_SoDu() > 100000000) cout << "\nTai Khoan 2 co rat nhieu tien, chuc mung";
}

int main()
{
	ifstream filein;
	filein.open("input.txt", ios_base::in);
	ofstream fileout;
	fileout.open("BankAccount.txt", ios_base::out);
	//	TKNganHang Tk1;
	//	cout << "\nNhap Tai Khoan 1: \n";
	//	cin>>Tk1;
	//
	//	TKNganHang Tk2;
	//	cout << "\nNhap Tai Khoan 2: \n";
	//	cin>>Tk2;
	//
	//	int STK1 = 0, STK2 = 0;
	//	while (Tk1 == Tk2)
	//	{
	//		cout << "\n2 So Tai Khoan giong nhau, moi ban nhap lai: ";
	//		cout << "\nTai khoan 1:\n";
	//		cin >> Tk1;
	//
	//		cout << "\nTai khoan 2:\n";
	//		cin >> Tk2;
	//	}
	//
	//	cout << "\n==========================";
	//    cout << "\nTai Khoan 1: ";
	//	fileout << "\nTai Khoan 1: ";
	//	cout << Tk1;
	//	Tk1.XuatFile(fileout);
	//
	//	cout << "\n\nTai Khoan 2: ";
	//	fileout << "\nTai Khoan 2: ";
	//	cout << Tk2;
	//	Tk2.XuatFile(fileout);
	//
	//
	//	cout << "\n==========================";
	//	ChuyenTien(Tk1, Tk2);
	//
	//	cout << "\n==========================";
	//	cout << "\nThong tin 2 tai khoan sau khi chuyen: ";
	//
	//	fileout << "\n=========================";
	//	fileout << "\nThong tin 2 tai khoan sau khi chuyen: ";
	//
	//	cout << "\nTai Khoan 1: ";
	//	fileout << "\nTai Khoan 1: ";
	//	cout << Tk1;
	//	Tk1.XuatFile(fileout);
	//	cout << "\n\nTai Khoan 2: ";
	//	fileout << "\n\nTai Khoan 2: ";
	//	cout << Tk2;
	//	Tk2.XuatFile(fileout);

	TKNganHang Tk3;
	cout << "\n\nTai Khoan 3: ";
	Tk3.DocFile(filein);
	Tk3.XuatFile(fileout);

	string docLai;
	filein >> docLai;

	TKNganHang Tk4;
	cout << "\n\nTai Khoan 4: ";
	Tk4.DocFile(filein);

	filein >> docLai;

	TKNganHang Tk5;
	cout << "\n\nTai Khoan 5: ";
	Tk4.DocFile(filein);
	
	

	system("pause");
}