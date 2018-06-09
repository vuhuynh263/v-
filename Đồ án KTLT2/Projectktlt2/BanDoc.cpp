#include "BanDoc.h"

void BanDoc::xuat()
{
	cout << "\t\t\t\t*******************************************************\n";
	cout << "\t\t\t\t\tMa doc gia: " << this->sMaBD << endl;
	cout << "\t\t\t\t\tNgay dang ky the: ";
	xNgay.xuat();
	cout << endl;
	cout << "\t\t\t\t\tHo va Ten: " << this->sHoTen << endl;
	cout << "\t\t\t\t\tKhoa: " << this->sKhoa;
}

string BanDoc::getMBD()
{
	return this->sMaBD;
}