#include "GiaoVien.h"

void GiaoVien::output()
{
	BanDoc::xuat();
	cout << "\n\t\t\t\t\tDia chi: " << this->sDiaChi << endl;
	cout << "\t\t\t\t\tSDT: " << this->sSDT << endl;
}