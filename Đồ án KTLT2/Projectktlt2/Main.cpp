#include <iostream>
#include "Admin.h"
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "Sach.h"
#include <list>
#include "GiaoVien.h"
#include "SinhVien.h"
#include <sstream>
#include <iomanip>
#include "PhieuMuon.h"
#include "thuvien.h"
using namespace std;

int PhieuMuon::nTongPM = 0;
//Admin
void inputData_Admin(list <Admin> &L);
int outputData_Admin(list <Admin> L);
void login_Admin(list <Admin> L, list <Sach> L3, list <BanDoc*> L2, list <PhieuMuon> L4);
string passwordInput(unsigned maxLength);
//DS ban doc
void inputData_BanDoc(list <BanDoc*> &L2);
void outputData_BanDoc_ToScreen(list <BanDoc*> L2);
void timKiemBanDoc(list <BanDoc*> L2);
bool kiemTraBD(list <BanDoc*> L2, string sMaBD);
void themBanDoc(list <BanDoc*> &L2);
int soLuongBanDocGiaoVien(list <BanDoc*> L2);
int soLuongBanDocSinhVien(list <BanDoc*> L2);
void inTheThuVien( int nLoai, string sMaBD, string HoTen, string sKhoa, int nNgay, int nThang, int nNam, string DC, string SDT, int KhoaHoc);
template <typename T>
string itos(T i)
{
	stringstream s;
	s << i;
	return s.str();
}
//DS sach
bool kiemTraSach_DuTieuChuanMuon(list <Sach> L3, string sMS);
void inputData_Sach(list <Sach> &L3);
void outputData_Sach_ToScreen(list <Sach> L3);
void outputData_Sach_File(list <Sach> L3);
int dem_Tong_So_Sach_Hien_Co(list <Sach> L3);
void themSach(list <Sach> &L3);
void xoaSach(list <Sach> &L3);
void timKiem(list <Sach> L3);
int nDemSachChuaMuon(list <Sach> L3);
int nDemSachDaMuon(list <Sach> L3);
//Phieu muon
void inputData_PhieuMuon(list <PhieuMuon> &L4);
void them_PhieuMuon(list <PhieuMuon> &L4, list <BanDoc*> L2, list <Sach> &L3);
void outputData_PhieuMuon_ToScreen(list <PhieuMuon> L4);
void outputData_PhieuMuon_File(list <PhieuMuon> L4, list <BanDoc*> L2, list <Sach> L3);
int demTongPhieuMuon(list <PhieuMuon> L4);
void traSach_PhieuMuon(list <PhieuMuon> &L4, list <BanDoc*> L2, list <Sach> &L3);
void main()
{	 
	list <Admin> L1;
	list <BanDoc*> L2;
	list <Sach> L3;
	list <PhieuMuon> L4;
	inputData_Admin(L1);
	inputData_BanDoc(L2);
	inputData_Sach(L3);
	inputData_PhieuMuon(L4);
	int nChucNang = 0;
	while( true )
	{
		clrscr();
		textcolor(1);
		gotoxy(0, 2); cout << "   _______________________________________";
		gotoxy(0, 3); cout << "  /   /                                  /";
		gotoxy(0, 4); cout << " / 1 /     HIEN THI THONG TIN SACH      /";
		gotoxy(0, 5); cout << "/___/__________________________________/";
		textcolor(3);
		gotoxy(75, 2); cout << "   _______________________________________";
		gotoxy(75, 3); cout << "  /   /                                  /";
		gotoxy(75, 4); cout << " / 2 /    HIEN THI THONG TIN BAN DOC    /";
		gotoxy(75, 5); cout << "/___/__________________________________/";
		textcolor(5);
		gotoxy(0, 7); cout << "   _______________________________________";
		gotoxy(0, 8); cout << "  /   /                                  /";
		gotoxy(0, 9); cout << " / 3 /        TIM KIEM THONG TIN        /";
		gotoxy(0, 10); cout << "/___/__________________________________/";
		textcolor(7);
		gotoxy(75, 7); cout << "   _______________________________________";
		gotoxy(75, 8); cout << "  /   /                                  /";
		gotoxy(75, 9); cout << " / 4 /            QUAN LY               /";
		gotoxy(75, 10); cout << "/___/__________________________________/";
		textcolor(12);
		gotoxy(35, 12); cout << "   _______________________________________";
		gotoxy(35, 13); cout << "  /   /                                  /";
		gotoxy(35, 14); cout << " / 0 /              THOAT               /";
		gotoxy(35, 15); cout << "/___/__________________________________/";
		textcolor(4);
		gotoxy(40, 17); cout << "Nhap Lua Chon: ";
		cin >> nChucNang;
		if (nChucNang != 1 && nChucNang != 2 && nChucNang != 3 && nChucNang != 4 && nChucNang != 0)
		{
			textcolor(4);
			gotoxy(40, 18); cout << "Nhap sai vui long lua chon lai.";
			gotoxy(40, 19); system("pause");
		}
		else if (nChucNang == 1)
		{
			clrscr();
			textcolor(1);
			gotoxy(40, 2);  cout << "* * * * * * * * * * * * * * * * * * * * ";
			gotoxy(40, 3);  cout << "*            THONG TIN SACH           * ";
			gotoxy(40, 4);  cout << "* * * * * * * * * * * * * * * * * * * * ";
			cout << endl;
			outputData_Sach_ToScreen(L3);
			system("pause");
		}
		else if (nChucNang == 2)
		{
			clrscr();
			textcolor(3);
			gotoxy(40, 2);  cout << "* * * * * * * * * * * * * * * * * * * * ";
			gotoxy(40, 3);  cout << "*          THONG TIN BAN DOC          * ";
			gotoxy(40, 4);  cout << "* * * * * * * * * * * * * * * * * * * * ";
			cout << endl;
			outputData_BanDoc_ToScreen(L2);
			system("pause");
		}
		else if (nChucNang == 3)
		{
			while(true)
			{		
				clrscr();
				textcolor(1);
				gotoxy(0, 2); cout << "   _______________________________________";
				gotoxy(0, 3); cout << "  /   /                                  /";
				gotoxy(0, 4); cout << " / 1 /      TIM SACH THEO MA SACH       /";
				gotoxy(0, 5); cout << "/___/__________________________________/";
				textcolor(3);
				gotoxy(75, 2); cout << "   _______________________________________";
				gotoxy(75, 3); cout << "  /   /                                  /";
				gotoxy(75, 4); cout << " / 2 /        TIM BAN DOC THEO MA       /";
				gotoxy(75, 5); cout << "/___/__________________________________/";
				textcolor(5);
				gotoxy(35, 7); cout << "   _______________________________________";
				gotoxy(35, 8); cout << "  /   /                                  /";
				gotoxy(35, 9); cout << " / 0 /               THOAT              /";
				gotoxy(35, 10); cout << "/___/__________________________________/";
				textcolor(4);
				gotoxy(40, 12); cout << "\t\t   Nhap Lua Chon: ";
				cin >> nChucNang;
				if (nChucNang != 1 && nChucNang != 2 && nChucNang != 0)
				{
					textcolor(4);
					gotoxy(40, 13); cout << "Nhap sai vui long lua chon lai.";
					gotoxy(40, 14); system("pause");
				}
				else if (nChucNang == 1)
				{
					clrscr();
					textcolor(1);
					gotoxy(40, 2);  cout << "* * * * * * * * * * * * * * * * * * * * ";
					gotoxy(40, 3);  cout << "*        TIM SACH THEO MA SACH        * ";
					gotoxy(40, 4);  cout << "* * * * * * * * * * * * * * * * * * * * ";
					timKiem(L3);
					gotoxy(40, 16); system("pause");
				}
				else if (nChucNang == 2)
				{
					clrscr();
					textcolor(1);
					gotoxy(40, 2);  cout << "* * * * * * * * * * * * * * * * * * * * ";
					gotoxy(40, 3);  cout << "*        TIM BAN DOC THEO MA        * ";
					gotoxy(40, 4);  cout << "* * * * * * * * * * * * * * * * * * * * ";
					timKiemBanDoc(L2);
					system("pause");				
				}
				else if (nChucNang == 0)
				{
					break;
				}
			}
			system("pause");
		}
		else if (nChucNang == 4)
		{
			login_Admin(L1, L3, L2, L4);
			system("pause");
		}
		else if (nChucNang == 0)
		{
			break;
		}
	}
	system("pause");
}
void traSach_PhieuMuon(list <PhieuMuon> &L4, list <BanDoc*> L2, list <Sach> &L3)
{
	int flag = 0;
	int nMPM = 0;
	while(true)
	{
		dd:
		system("cls");
		cout << "\t\tNhap ma phieu muon can tra sach: "; cin >> nMPM;
		list <PhieuMuon> ::iterator p = L4.begin();
		while(p != L4.end())
		{
			if (nMPM == p->getMaPM())
			{
				if (p->getTrangThai() != 0)
				{
					flag = 1;
					p->setTrangThai(0); // gán trạng thái 0 cho phiếu mượn đang muốn trả
					string sMaSach = p->getSach().getMS();
					list <Sach> ::iterator q = L3.begin();
					while(q != L3.end())
					{
						if (q->getMS() == sMaSach)
						{
							q->setTT(0);
							break;
						}
						q++;
					}
					outputData_Sach_File(L3);
					outputData_PhieuMuon_File(L4, L2, L3);
					textcolor(10);
					cout << "\t\tTra sach thanh cong!\n";
					textcolor(7);
					break;
				}
				textcolor(4);
				cout << "\t\tMa phieu muon da duoc tra!\n";
				textcolor(7);
				system("pause");
				goto dd;
			}
			p++;
		}
		if (flag == 0)
		{
			textcolor(4);
			cout << "\t\tMa phieu muon khong ton tai!\n";
			textcolor(7);
			system("pause");
		}
		else if(flag == 1)
		{
			break;
		}
	}
}
int demTongPhieuMuon(list <PhieuMuon> L4)
{
	int nDem = 0;
	list <PhieuMuon> ::iterator p = L4.begin();
	while(p != L4.end())
	{
		nDem++;
		p++;
	}
	return nDem;
}
void them_PhieuMuon(list <PhieuMuon> &L4, list <BanDoc*> L2, list <Sach> &L3)
{
	string sMBD = "";
	while(true)
	{
		clrscr();
		textcolor(4);
		cout << "\t\t\t\tNhap N de thoat!\n";
		textcolor(7);
		cin.ignore(1, '\n');
		cout << "\t\t\t\tNhap ma ban doc can muon sach: ";
		getline(cin, sMBD);
		if (sMBD == "")
		{
			textcolor(4);
			cout << "\n\t\t\t\tKhong duoc de trong ! \n";
			textcolor(7);
			system("pause");
		}
		else if (sMBD == "N")
		{
			textcolor(10);
			cout << "\t\t\t\tBan chon thoat!\n";
			textcolor(7);
			return;
		}
		else if (kiemTraBD(L2, sMBD) != true)
		{
			textcolor(4);
			cout << "\t\t\t\tMa ban doc khong ton tai!";
			textcolor(7);
			system("pause");
		}
		else
		{
			break;
		}
	}
	string sMS = "";
	while(true)
	{
		cout << "\t\t\t\tNhap ma sach: ";
		fflush(stdin);
		getline(cin, sMS);
		if (sMS == "")
		{
			textcolor(4);
			cout << "\t\t\t\tKhong duoc de trong ! \n";
			textcolor(7);
			system("pause");
		}
		else if (kiemTraSach_DuTieuChuanMuon(L3, sMS) == true)
		{
			break;
		}
		else 
		{
			textcolor(4);
			cout << "\t\t\t\tMa sach khong ton tai! hoac dang co ban doc muon.\n";
			textcolor(7);
			system("pause");
		}	
	}
	PhieuMuon pm(sMBD, sMS);
	L4.push_back(pm);
	textcolor(10);
	cout << "\t\t\t\tTao phieu muon thanh cong!\n";
	textcolor(7);
	ofstream File;
	File.open("PhieuMuon.txt", ios::app);
	File << "\n" << L4.rbegin()->getMaPM() << "," << L4.rbegin()->getBanDoc().getMBD() << "," << L4.rbegin()->getSach().getMS() << "," << L4.rbegin()->getNgayMuon().getNgay() << "," << L4.rbegin()->getNgayMuon().getThang() << "," << L4.rbegin()->getNgayMuon().getNam() << ","  << L4.rbegin()->getNgayTra().getNgay() << "," << L4.rbegin()->getNgayTra().getThang() << "," << L4.rbegin()->getNgayTra().getNam() << "," << L4.rbegin()->getTrangThai();
	File.close();
	int nTT = L4.rbegin()->getMaPM();
	list <Sach> ::iterator p = L3.begin();
	while(p != L3.end())
	{
		if (p->getMS() == sMS)
		{
			p->setTT(nTT);
			break;
		}
		p++;
	}
	outputData_Sach_File(L3);

}
void outputData_PhieuMuon_File(list <PhieuMuon> L4, list <BanDoc*> L2, list <Sach> L3)
{
	
	int nTongPM = demTongPhieuMuon(L4);
	int nDem = 1;
	ofstream File;
	File.open("PhieuMuon.txt");
	list <PhieuMuon> ::iterator p = L4.begin();
	while (p != L4.end())
	{
		File << p->getMaPM() << "," << p->getBanDoc().getMBD() << "," << p->getSach().getMS() << "," << p->getNgayMuon().getNgay() << "," << p->getNgayMuon().getThang() << "," << p->getNgayMuon().getNam() << "," << p->getNgayTra().getNgay() << "," << p->getNgayTra().getThang() << "," << p->getNgayTra().getNam() << "," << p->getTrangThai();
		if (nDem < nTongPM)
		{
			File << endl;
			nDem++;
		}
		p++;
	}
	File.close();
}
void outputData_PhieuMuon_ToScreen(list <PhieuMuon> L4)
{
	list <PhieuMuon> ::iterator p = L4.begin();
	while(p != L4.end())
	{
		p->xuat();
		p++;
	}
}
void inputData_PhieuMuon(list <PhieuMuon> &L4)
{
	int nSPM = 0;
	string sMBD = "";
	string sMS = "";
	int nNgayMuon = 0;
	int nThangMuon = 0;
	int nNamMuon = 0;
	int nNgayTra = 0;
	int nThangTra = 0;
	int nNamTra = 0;
	int nTrangThai = 0;
	ifstream File;
	File.open("PhieuMuon.txt");
	while(!File.eof())
	{
		File >> nSPM;
		File.ignore(1, ',');
		getline(File, sMBD, ',');
		getline(File, sMS, ',');
		File >> nNgayMuon;
		File.ignore(1, ',');
		File >> nThangMuon;
		File.ignore(1, ',');
		File >> nNamMuon;
		File.ignore(1, ',');
		File >> nNgayTra;
		File.ignore(1, ',');
		File >> nThangTra;
		File.ignore(1, ',');
		File >> nNamTra;
		File.ignore(1, ',');
		File >> nTrangThai;
		File.ignore(1, '\n');
		PhieuMuon pm(nSPM, sMBD,sMS,nNgayMuon,nThangMuon,nNamMuon,nNgayTra,nThangTra,nNamTra,nTrangThai);
		L4.push_back(pm);
	}
	File.close();
}
//DS Ban Doc

void inTheThuVien(int nLoai, string sMaBD, string HoTen, string sKhoa, int nNgay, int nThang, int nNam, string DC, string SDT, int KhoaHoc)
{
	if (nLoai == 1)
	{
		textcolor(10);
		cout << "\n\t\tDang in the thu vien vui long doi !\n";
		textcolor(9);
		Sleep(500);
		cout << "\t*************************************************\n";
		Sleep(500);
		cout << "\t*             THE THU VIEN-GIAO VIEN            *\n";
		Sleep(500);
		cout << "\t*************************************************\n";
		Sleep(500);
		textcolor(11);
		cout << "\t* Ten : " << HoTen << "  -  Ma So: " << sMaBD << "           *\n";
		Sleep(500);
		cout << "\t* Khoa: " << sKhoa << "            -  SDT: " << SDT << "      *\n";
		Sleep(500);
		cout << "\t* Dia Chi: " << DC << "                               *\n";
		Sleep(500);
		cout << "\t* Ngay Dang Ky: " << nNgay << "/" << nThang << "/" << nNam << "                        *\n";
		Sleep(500);
		cout << "\t*************************************************\n";
		Sleep(200);
		textcolor(10);
		cout << "\n\n\t\t In the thanh cong !\n";
		textcolor(7);
	}
	else if (nLoai == 2)
	{
		textcolor(10);
		cout << "\n\t\tDang in the thu vien vui long doi !\n";
		textcolor(9);
		Sleep(500);
		cout << "\t*************************************************\n";
		Sleep(500);
		cout << "\t*           THE THU VIEN - SINH VIEN            *\n";
		Sleep(500);
		cout << "\t*************************************************\n";
		Sleep(500);
		textcolor(11);
		cout << "\t* Ten : " << HoTen << "       Ma So: " << sMaBD << "           *\n";
		Sleep(500);
		cout << "\t* Khoa:" << sKhoa <<  "               Khoa Hoc: " << KhoaHoc << setw(10) << "*\n";
		Sleep(500);
		cout << "\t* Ngay Dang Ky: " << nNgay << "/" << nThang << "/" << nNam << setw(26) << "*\n";
		Sleep(500);
		cout << "\t*************************************************\n";
		Sleep(500);
		textcolor(10);
		cout << "\n\n\t\t In the thanh cong !\n";
		textcolor(7);
	}
}
int soLuongBanDocSinhVien(list <BanDoc*> L2)
{
	int nDem = 0;
	int nLoai = 0;
	string sMaBD = "";
	ifstream File;
	File.open("BanDoc.txt");
	while(!File.eof())
	{
		File >> nLoai;
		File.ignore(1, ',');
		if (nLoai == 1)
		{
			getline(File, sMaBD, '\n');
		}
		else if(nLoai == 2)
		{
			nDem++;
			getline(File, sMaBD, '\n');
		}
	}
	return nDem;
}
int soLuongBanDocGiaoVien(list <BanDoc*> L2)
{
	int nDem = 0;
	int nLoai = 0;
	string sMaBD = "";
	string sHoTen = "";
	string sKhoa = "";
	int nNgay = 0;
	int nThang = 0;
	int nNam = 0;
	string sDC = "";
	string sSDT = "";
	int nKhoaHoc = 0;
	ifstream File;
	File.open("BanDoc.txt");
	while(!File.eof())
	{
		File >> nLoai;
		File.ignore(1, ',');
		if (nLoai == 1)
		{
			nDem++;
			getline(File, sMaBD, ',');
			getline(File, sHoTen, ',');
			getline(File, sKhoa, ',');
			File >> nNgay;
			File.ignore(1, ',');
			File >> nThang;
			File.ignore(1, ',');
			File >> nNam;
			File.ignore(1, ',');
			getline(File, sDC, ',');
			getline(File, sSDT, '\n');
		}
		else if (nLoai == 2)
		{
			getline(File, sMaBD, ',');
			getline(File, sHoTen, ',');
			getline(File, sKhoa, ',');
			File >> nNgay;
			File.ignore(1, ',');
			File >> nThang;
			File.ignore(1, ',');
			File >> nNam;
			File.ignore(1, ',');
			File >> nKhoaHoc;
			File.ignore(1, '\n');
		}
	}
	File.close();
	return nDem;
}
void themBanDoc(list <BanDoc*> &L2)
{
	int nLoaiBD = 0;
	string sMaBD = "";
	string sHoTen = "";
	string sKhoa = "";
	int nNgay = 0;
	int nThang = 0;
	int nNam = 0;
	string sDC = "";
	string sSDT = "";
	int nKhoaHoc = 0;
	while(true)
	{
		clrscr();
		textcolor(1);
		gotoxy(0, 2); cout << "   _______________________________________";
		gotoxy(0, 3); cout << "  /   /                                  /";
		gotoxy(0, 4); cout << " / 1 /    THEM BAN DOC LA GIAO VIEN     /";
		gotoxy(0, 5); cout << "/___/__________________________________/";
		textcolor(3);
		gotoxy(75, 2); cout << "   _______________________________________";
		gotoxy(75, 3); cout << "  /   /                                  /";
		gotoxy(75, 4); cout << " / 2 /    THEM BAN DOC LA SINH VIEN     /";
		gotoxy(75, 5); cout << "/___/__________________________________/";
		textcolor(12);
		gotoxy(35, 6); cout << "   _______________________________________";
		gotoxy(35, 7); cout << "  /   /                                  /";
		gotoxy(35, 8); cout << " / 0 /              THOAT               /";
		gotoxy(35, 9); cout << "/___/__________________________________/";
		gotoxy(40, 10); cout << "Nhap chuc nang: ";
		cin >> nLoaiBD;
		cout << endl;
		if (nLoaiBD == 1)
		{
			nLoaiBD = 1;
			int nTongSL = soLuongBanDocGiaoVien(L2);
			string str = itos(nTongSL+1);
			sMaBD = "GV" + str;
			cin.ignore(1, '\n');
			cout << "\t\tNhap ho va ten: "; getline(cin, sHoTen);
			cout << "\t\tNhap Khoa: "; fflush(stdin); getline(cin, sKhoa);
			cout << "\t\tNhap ngay lam the: \n";
			cout << "\t\t\tNhap Ngay: "; cin >> nNgay;
			cout << "\t\t\tNhap Thang: "; cin >> nThang;
			cout << "\t\t\tNhap Nam: "; cin >> nNam;
			cin.ignore(1, '\n');
			cout << "\t\tNhap dia chi: "; getline(cin, sDC);
			cout << "\t\tNhap so dien thoai: "; fflush(stdin); getline(cin, sSDT);
			BanDoc * gv = new GiaoVien(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, sDC, sSDT);
			L2.push_back(gv);
			ofstream File;
			File.open("BanDoc.txt", ios::app);
			File << "\n" << nLoaiBD << "," << sMaBD << "," << sHoTen << "," << sKhoa << "," << nNgay << "," << nThang << "," << nNam << "," << sDC << "," << sSDT;
			File.close();
			textcolor(10);
			cout << "\t\tThem ban doc thanh cong!\n ";
			textcolor(7);
			inTheThuVien(1, sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, sDC, sSDT, 0);
			system("pause");
			break;
		}
		else if (nLoaiBD == 2)
		{
			nLoaiBD = 2;
			int nTongSL = soLuongBanDocSinhVien(L2);
			string str = itos(nTongSL+1);
			sMaBD = "SV" + str;
			cin.ignore(1, '\n');
			cout << "\t\tNhap ho va ten: "; getline(cin, sHoTen);
			cout << "\t\tNhap Khoa: "; fflush(stdin); getline(cin, sKhoa);
			cout << "\t\tNhap ngay lam the: \n";
			cout << "\t\t\tNhap Ngay: "; cin >> nNgay;
			cout << "\t\t\tNhap Thang: "; cin >> nThang;
			cout << "\t\t\tNhap Nam: "; cin >> nNam;
			cout << "\t\t\tNhap Khoa Hoc: "; cin >> nKhoaHoc;
			BanDoc *  sv = new SinhVien(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, nKhoaHoc);
			L2.push_back(sv);
			ofstream File;
			File.open("BanDoc.txt", ios::app);
			File << "\n" << nLoaiBD << "," << sMaBD << "," << sHoTen << "," << sKhoa << "," << nNgay << "," << nThang << "," << nNam << "," << nKhoaHoc;
			File.close();
			textcolor(10);
			cout << "\t\tThem ban doc thanh cong!\n ";
			textcolor(7);
			inTheThuVien(2, sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, "", "", nKhoaHoc);
			system("pause");
			break;
		}
		else if (nLoaiBD == 0)
		{
			break;
		}
		else
		{
			cout << "Nhap sai! Vui long nhap lai. \n";
		}
	}
}
void timKiemBanDoc(list <BanDoc*> L2)
{
	string sMBD = "";
	textcolor(4);
	gotoxy(40, 5); cout << "Nhap N de thoat!\n";
	textcolor(3);
dd:
	list <BanDoc*>::iterator p = L2.begin();
	cout << "\t\t\t\tNhap ma ban doc can tim thong tin: ";
	cin >> sMBD;
	if (sMBD == "N")
	{
		textcolor(4);
		cout << "\t\t\t\tBan da chon thoat!\n";
		textcolor(3);
		return;
	}
	while(p != L2.end())
	{
		if (sMBD == (*p)->getMBD())
		{
			(*p)->output();
			return;
		}
		p++;
	}
	textcolor(4);
	cout << "\t\t\t\tMa ban doc khong ton tai!\n";
	textcolor(3);
	goto dd;
}
bool kiemTraBD(list <BanDoc*> L2, string sMaBD)
{
	list <BanDoc*>::iterator p = L2.begin();
	while(p != L2.end())
	{
		if (sMaBD == (*p)->getMBD())
		{
			return true;
		}
		p++;
	}
	return false;
}
void outputData_BanDoc_ToScreen(list <BanDoc*> L2)
{
	list <BanDoc*> ::iterator p = L2.begin();
	while(p!= L2.end())
	{
		(*p)->output();
		p++;
	}
}
void inputData_BanDoc(list <BanDoc*> &L2)
{
	int nLoai = 0;
	string sMaBD = "";
	string sHoTen = "";
	string sKhoa = "";
	int nNgay = 0;
	int nThang = 0;
	int nNam = 0;
	string sDC = "";
	string sSDT = "";
	int nKhoaHoc = 0;
	ifstream File;
	File.open("BanDoc.txt");
	while(!File.eof())
	{
		File >> nLoai;
		File.ignore(1, ',');
		if (nLoai == 1)
		{
			getline(File, sMaBD, ',');
			getline(File, sHoTen, ',');
			getline(File, sKhoa, ',');
			File >> nNgay;
			File.ignore(1, ',');
			File >> nThang;
			File.ignore(1, ',');
			File >> nNam;
			File.ignore(1, ',');
			getline(File, sDC, ',');
			getline(File, sSDT, '\n');
			BanDoc * gv = new GiaoVien(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, sDC, sSDT);
			L2.push_back(gv);
		}
		else if (nLoai == 2)
		{
			getline(File, sMaBD, ',');
			getline(File, sHoTen, ',');
			getline(File, sKhoa, ',');
			File >> nNgay;
			File.ignore(1, ',');
			File >> nThang;
			File.ignore(1, ',');
			File >> nNam;
			File.ignore(1, ',');
			File >> nKhoaHoc;
			File.ignore(1, '\n');
			BanDoc * sv = new SinhVien(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, nKhoaHoc);
			L2.push_back(sv);
		}
	}
	File.close();
}
//DS Sách
int nDemSachDaMuon(list <Sach> L3)
{
	int nDem = 0;
	list <Sach>::iterator p = L3.begin();
	while(p != L3.end())
	{
		if (p->getTinhTrang() != 0)
		{
			nDem++;
		}
		p++;
	}
	return nDem;
}
int nDemSachChuaMuon(list <Sach> L3)
{
	int nDem = 0;
	list <Sach>::iterator p = L3.begin();
	while(p != L3.end())
	{
		if (p->getTinhTrang() == 0)
		{
			nDem++;
		}
		p++;
	}
	return nDem;
}
void timKiem(list <Sach> L3)
{
	textcolor(4);
	gotoxy(40, 5); cout << "Nhap N de thoat!";
	textcolor(1);
	string sTimKiem = "";
	int flag = 0;
	cin.ignore(1, '\n');
	gotoxy(40, 6); cout << "Nhap ma sach can tim: ";
	getline(cin, sTimKiem);
	if (sTimKiem == "N" || sTimKiem == "n")
	{
		textcolor(4);
		gotoxy(40, 7); cout << "Ban da chon thoat!";
	}
	else 
	{
		list <Sach>::iterator p = L3.begin();
		while(p != L3.end())
		{
			if (sTimKiem == p->getMS())
			{
				flag = 0;
				gotoxy(40, 7); cout << "THONG TIN SACH";
				cout << endl;
				p->outputSach();
				break;
			}
			else
			{
				flag = 1;
			}
			p++;
		}
		if (flag == 1)
		{
			textcolor(4);
			gotoxy(40, 7); cout << "Ma sach khong ton tai !";
		}
	}

}
void xoaSach(list <Sach> &L3)
{
	cout << "\t\tNhap N de thoat! \n";
	string sSachCanXoa = "";
	dd:
	cin.ignore(1, '\n');
	cout << "\t\tNhap ma so sach can xoa: ";
	getline(cin, sSachCanXoa);
	if (sSachCanXoa == "N" || sSachCanXoa == "n")
	{
		textcolor(10);
		cout << "\t\tBan da chon thoat! \n";
		textcolor(7);
	}
	else 
	{
		int flag = 0;
		list <Sach>::iterator p = L3.begin();
		while(p != L3.end())
		{
			if (sSachCanXoa == p->getMS() && p->getTinhTrang() == 0)
			{
				flag = 0;
				textcolor(10);
				cout << "\t\t\tXoa sach thanh cong!";
				textcolor(7);
				L3.erase(p);
				outputData_Sach_File(L3);
				break;
			}
			else
			{
				flag = 1;
			}
			p++;
		}
		if (flag == 1)
		{
			textcolor(4);
			cout << "\t\tMa so sach khong ton tai, hoac sach dang duoc muon!\n";
			textcolor(7);
			goto dd;
		}
	}

}
void themSach(list <Sach> &L3)
{
	string sMS = "";
	string sTD = "";
	string sTG = "";
	string sNXB = "";
	float fGia = NULL;
	int nNPH = 0;
	int nST = 0;
	int nNgay = 0;
	int nThang = 0;
	int nNam = 0;
	int nTT = 0;
	dd:
	cin.ignore(1, '\n');
	cout << "\t\tNhap ma so sach: ";
	getline(cin, sMS);
	list <Sach>::iterator p = L3.begin();
	while(p != L3.end())
	{
	
		if (sMS == p->getMS() || sMS == "")
		{
			textcolor(4);
			cout << "\t\t\tMa so sach da ton tai hoac chua nhap ma so sach !!!\n";
			textcolor(7);
			system("pause");
			goto dd;
		}
		p++;
	}
	td:
	cout << "\t\tNhap tua de sach: ";
	fflush(stdin);
	getline(cin, sTD);
	if (sTD == "")
	{
		textcolor(4);
		cout << "\t\t\tKhong duoc de trong !\n";
		textcolor(7);
		goto td;
	}
	tg:
	cout << "\t\tNhap ten tac gia: ";
	fflush(stdin);
	getline(cin, sTG);
		if (sTG == "")
	{
		textcolor(4);
		cout << "\t\t\tKhong duoc de trong !\n";
		textcolor(7);
		goto tg;
	}
	nxb:
	cout << "\t\tNhap nha xuat ban: ";
	fflush(stdin);
	getline(cin, sNXB);
	if (sNXB == "")
	{
		textcolor(4);
		cout << "\t\t\tKhong duoc de trong !\n";
		textcolor(7);
		goto nxb;
	}
	cout << "\t\tNhap gia cuon sach: ";
	cin >> fGia;
	cout << "\t\tNhap nam phat hanh: ";
	cin >> nNPH;
	cout << "\t\tNhap so trang: ";
	cin >> nST;
	cout << "\t\tNgay nhap kho: ";
	cout << "\n\t\t\t\tNhap ngay: ";
	cin >> nNgay;
	cout << "\t\t\t\tNhap thang: ";
	cin >> nThang;
	cout << "\t\t\t\tNhap nam: ";
	cin >> nNam;
	nTT = 0;
	Sach s(sMS, sTD, sTG, sNXB, fGia, nNPH, nST, nNgay, nThang, nNam, nTT);
	L3.push_back(s);
	textcolor(10);
	cout << "\t\tthem sach thanh cong !\n";
	textcolor(7);
}
void outputData_Sach_File(list <Sach> L3)
{
	ofstream File;
	File.open("Sach.txt");
	int nDem = 1;
	int nTongSoSach = dem_Tong_So_Sach_Hien_Co(L3);
	list <Sach>::iterator p = L3.begin();
	while(p != L3.end())
	{
		File << p->getMS() << "," << p->getTD() << "," << p->getTG() << "," << p->getNXB() << "," << p->getGia() << "," << p->getNPH() << "," << p->getST() << "," << p->getNgayNK() << "," << p->getThangNK() << "," << p->getNamNK() << "," << p->getTinhTrang();		
		if (nDem < nTongSoSach)
		{
			File << endl;
			nDem++;
		}	
		p++;
	}
	File.close();
}
void outputData_Sach_ToScreen(list <Sach> L3)
{
	list <Sach>::iterator p = L3.begin();
	while (p != L3.end())
	{
		p->outputSach();
		p++;
	}
}
void inputData_Sach(list <Sach> &L3)
{
	string sMS = "";
	string sTD = "";
	string sTG = "";
	string sNXB = "";
	float fGia = 0.0;
	int nNPH = 0;
	int nST = 0;
	int nNgay = 0;
	int nThang = 0;
	int nNam = 0;
	int nTT = 0;
	ifstream File;
	File.open("Sach.txt");
	while(!File.eof())
	{
		getline(File, sMS, ',');
		getline(File, sTD, ',');
		getline(File, sTG, ',');
		getline(File, sNXB, ',');
		File >> fGia;
		File.ignore(1, ',');
		File >> nNPH;
		File.ignore(1, ',');
		File >> nST;
		File.ignore(1, ',');
		File >> nNgay;
		File.ignore(1, ',');
		File >> nThang;
		File.ignore(1, ',');
		File >> nNam;
		File.ignore(1, ',');
		File >> nTT;
		File.ignore(1, '\n');
		Sach s(sMS, sTD, sTG, sNXB, fGia, nNPH, nST, nNgay, nThang, nNam, nTT);
		L3.push_back(s);
	}
	File.close();
}
int dem_Tong_So_Sach_Hien_Co(list <Sach> L3)
{
	int nDem = 0;
	list <Sach>::iterator p = L3.begin();
	while (p != L3.end())
	{
		nDem++;
		p++;
	}
	return nDem;
}
bool kiemTraSach_DuTieuChuanMuon(list <Sach> L3, string sMS)
{
	list <Sach> ::iterator p = L3.begin();
	while(p != L3.end())
	{
		if(sMS == p->getMS() && p->getTinhTrang() == 0)
		{
			return true;
		}
		p++;
	}
	return false;
}
//Admin
string passwordInput(unsigned maxLength)
{
	string pw = "";
	for (char c; (c = _getch()); )
	{
		if (c == '\n' || c == '\r') { // \n là phím phím enter + \r là Nhảy về đầu hàng, không xuống hàng
			cout << "\n";
			break;
		} else if (c == '\b') { //phím backspace
			cout << "\b \b";
			if (!pw.empty()) pw.erase(pw.size()-1);
		} else if (c == -32) { //phím mũi tên
			_getch(); //bỏ qua kí tự tiếp theo (hướng mũi tên)
		} else if (isprint(c) && pw.size() < maxLength) { //isprint tức là chỉ nhận những ký tự in ra được (có tính khoảng trắng)
			cout << '*';
			pw += c;
		}
	}
	return pw;
}
void login_Admin(list <Admin> L, list <Sach> L3, list <BanDoc*> L2, list <PhieuMuon> L4)
{
	int nChucNang = 0;
	string sU = "";
	string sP = "";
	int flag = 0;
	while (true)
	{
		clrscr();
		textcolor(10);
		gotoxy(40, 2);  cout << "* * * * * * * * * * * * * * * * * * * * * * ";
		gotoxy(40, 3);  cout << "*                  LOGIN                  * ";
		gotoxy(40, 4);  cout << "* * * * * * * * * * * * * * * * * * * * * * ";
		textcolor(4);
		gotoxy(40, 5); cout << "Nhap N de thoat!";
		textcolor(10);
		cin.ignore(1,'\n');
		gotoxy(40, 6);  cout << "Nhap Username: ";
		fflush(stdin);
		getline(cin, sU);
		if(sU == "N" || sU == "n")
		{
			flag = 1;
			break;
		}
		gotoxy(40, 7); cout << "Nhap Password: ";
		fflush(stdin);
		sP = passwordInput(6);
		list <Admin>::iterator p = L.begin();
		while(p != L.end())
		{
			if(sU == p->getUser() && sP == p->getPass())
			{
				flag = 1;
				gotoxy(40, 8); cout << "Login thanh cong !\n";
				while(true)
				{
					clrscr();
					textcolor(1);
					gotoxy(0, 2); cout << "   _______________________________________";
					gotoxy(0, 3); cout << "  /   /                                  /";
					gotoxy(0, 4); cout << " / 1 /        QUAN LY PHIEU MUON        /";
					gotoxy(0, 5); cout << "/___/__________________________________/";
					textcolor(3);
					gotoxy(75, 2); cout << "   _______________________________________";
					gotoxy(75, 3); cout << "  /   /                                  /";
					gotoxy(75, 4); cout << " / 2 /           QUAN LY SACH           /";
					gotoxy(75, 5); cout << "/___/__________________________________/";
					textcolor(5);
					gotoxy(0, 7); cout << "   _______________________________________";
					gotoxy(0, 8); cout << "  /   /                                  /";
					gotoxy(0, 9); cout << " / 3 /          QUAN LY BAN DOC         /";
					gotoxy(0, 10); cout << "/___/__________________________________/";
					textcolor(7);
					gotoxy(75, 7); cout << "   _______________________________________";
					gotoxy(75, 8); cout << "  /   /                                  /";
					gotoxy(75, 9); cout << " / 4 /           THONG KE               /";
					gotoxy(75, 10); cout << "/___/__________________________________/";
					textcolor(12);
					gotoxy(35, 12); cout << "   _______________________________________";
					gotoxy(35, 13); cout << "  /   /                                  /";
					gotoxy(35, 14); cout << " / 0 /              THOAT               /";
					gotoxy(35, 15); cout << "/___/__________________________________/";
					gotoxy(40, 16); cout << "Nhap Lua Chon: ";
					cin >> nChucNang;
					if (nChucNang != 1 && nChucNang != 2 && nChucNang != 3 && nChucNang != 4 && nChucNang != 0)
					{
						gotoxy(35, 17); cout << "Nhap sai vui long lua chon lai.\n";
						gotoxy(35, 18); system("pause");
					}
					else if (nChucNang == 1)
					{
						while(true)
						{
							clrscr();
							textcolor(1);
							gotoxy(0, 2); cout << "   _______________________________________";
							gotoxy(0, 3); cout << "  /   /                                  /";
							gotoxy(0, 4); cout << " / 1 /          THEM PHIEU MUON         /";
							gotoxy(0, 5); cout << "/___/__________________________________/";
							textcolor(3);
							gotoxy(75, 2); cout << "   _______________________________________";
							gotoxy(75, 3); cout << "  /   /                                  /";
							gotoxy(75, 4); cout << " / 2 /             TRA SACH             /";
							gotoxy(75, 5); cout << "/___/__________________________________/";
							textcolor(5);
							gotoxy(0, 7); cout << "   _______________________________________";
							gotoxy(0, 8); cout << "  /   /                                  /";
							gotoxy(0, 9); cout << " / 3 /        XUAT DS PHIEU MUON        /";
							gotoxy(0, 10); cout << "/___/__________________________________/";
							textcolor(7);
							gotoxy(75, 7); cout << "   _______________________________________";
							gotoxy(75, 8); cout << "  /   /                                  /";
							gotoxy(75, 9); cout << " / 0 /             THOAT                /";
							gotoxy(75, 10); cout << "/___/__________________________________/";
							gotoxy(40, 11); cout << "Nhap Lua Chon: ";
							cin >> nChucNang;
							if (nChucNang == 1)
						{
							them_PhieuMuon(L4, L2, L3);
							system("pause");
						}
						else if (nChucNang == 2)
						{
							traSach_PhieuMuon(L4, L2, L3);
							system("pause");
						}
						else if (nChucNang == 3)
						{
							outputData_PhieuMuon_ToScreen(L4);
							system("pause");
						}
						else if (nChucNang == 0)
						{
							break;
						}
						else
						{
							gotoxy(75, 12); cout << "Nhap sai vui long lua chon lai.";
							gotoxy(75, 13); system("pause");
						}
						}
					}
					else if (nChucNang == 2)
					{
						cout << "2. Quan ly sach.\n"; 
						while(true)
						{
							clrscr();
							textcolor(1);
							gotoxy(0, 2); cout << "   _______________________________________";
							gotoxy(0, 3); cout << "  /   /                                  /";
							gotoxy(0, 4); cout << " / 1 /            THEM SACH MOI         /";
							gotoxy(0, 5); cout << "/___/__________________________________/";
							textcolor(3);
							gotoxy(75, 2); cout << "   _______________________________________";
							gotoxy(75, 3); cout << "  /   /                                  /";
							gotoxy(75, 4); cout << " / 2 /             XOA SACH             /";
							gotoxy(75, 5); cout << "/___/__________________________________/";
							textcolor(5);
							gotoxy(35, 7); cout << "   _______________________________________";
							gotoxy(35, 8); cout << "  /   /                                  /";
							gotoxy(35, 9); cout << " / 0 /               THOAT              /";
							gotoxy(35, 10); cout << "/___/__________________________________/";
							gotoxy(40, 11); cout << "Nhap chuc nang can chon: ";
							cin >> nChucNang;
							if (nChucNang != 1 && nChucNang != 2 && nChucNang != 0)
							{
								gotoxy(40, 12); cout << "Nhap sai vui long lua chon lai.";
								gotoxy(40, 13); system("pause");
							}
							else if (nChucNang == 1)
							{
								clrscr();
								themSach(L3);
								outputData_Sach_File(L3);
								system("pause");
							}
							else if (nChucNang == 2)
							{
								clrscr();
								xoaSach(L3);
								system("pause");
							}
							else if (nChucNang == 0)
							{
								break;
							}
						}

						system("pause");
					}
					else if (nChucNang == 3)
					{
						cout << "\t\t  *Quan ly ban doc*\n";
						while(true)
						{
							clrscr();
							textcolor(1);
							gotoxy(0, 2); cout << "   _______________________________________";
							gotoxy(0, 3); cout << "  /   /                                  /";
							gotoxy(0, 4); cout << " / 1 /            THEM BAN DOC          /";
							gotoxy(0, 5); cout << "/___/__________________________________/";
							textcolor(3);
							gotoxy(75, 2); cout << "   _______________________________________";
							gotoxy(75, 3); cout << "  /   /                                  /";
							gotoxy(75, 4); cout << " / 0 /               THOAT              /";
							gotoxy(75, 5); cout << "/___/__________________________________/";
							gotoxy(40, 6); cout << "Nhap chuc nang can chon: ";
							cin  >> nChucNang;
							if (nChucNang == 1)
							{
								themBanDoc(L2);
							}
							else if (nChucNang == 0)
							{
								break;
							}
							else
							{
								textcolor(4);
								gotoxy(40, 7); cout << "Nhap sai! Vui long nhap lai.";
								textcolor(7);
								gotoxy(40, 8); system("pause");
							}
						}
						system("pause");
					}
					else if (nChucNang == 4)
					{
						while(true)
						{
							clrscr();
							int luachon;
							int tien, tiennap = 0;
							textcolor(1);
							gotoxy(0, 2); cout << "   ________________________________________";
							gotoxy(0, 3); cout << "  /   /                                   /";
							gotoxy(0, 4); cout << " / 1 /TONG SO SACH CON LAI CHUA DUOC MUON/";
							gotoxy(0, 5); cout << "/___/___________________________________/";
							textcolor(3);
							gotoxy(75, 2); cout << "   _______________________________________";
							gotoxy(75, 3); cout << "  /   /                                  /";
							gotoxy(75, 4); cout << " / 2 /      TONG SO SACH DA MUON        /";
							gotoxy(75, 5); cout << "/___/__________________________________/";
							textcolor(5);
							gotoxy(0, 7); cout << "   _______________________________________";
							gotoxy(0, 8); cout << "  /   /                                  /";
							gotoxy(0, 9); cout << " / 3 /   TONG SO BAN DOC LA GIAO VIEN   /";
							gotoxy(0, 10); cout << "/___/__________________________________/";
							textcolor(7);
							gotoxy(75, 7); cout << "   _______________________________________";
							gotoxy(75, 8); cout << "  /   /                                  /";
							gotoxy(75, 9); cout << " / 4 /   TONG SO BAN DOC LA SINH VIEN   /";
							gotoxy(75, 10); cout << "/___/__________________________________/";
							textcolor(12);
							gotoxy(35, 12); cout << "   _______________________________________";
							gotoxy(35, 13); cout << "  /   /                                  /";
							gotoxy(35, 14); cout << " / 0 /              THOAT               /";
							gotoxy(35, 15); cout << "/___/__________________________________/";
							gotoxy(40, 17); cout << "Nhap chuc nang: ";
							cin >> nChucNang;
							if (nChucNang != 1 && nChucNang != 2 && nChucNang != 3 && nChucNang != 0 && nChucNang != 4)
							{
								textcolor(4);
								gotoxy(40, 18); cout << "Nhap sai! Vui long nhap lai.";
								textcolor(7);
								gotoxy(40, 19); system("pause");
							}
							else if (nChucNang == 1)
							{
								clrscr();
								textcolor(10);
								cout << "\t\tTong so sach con lai trong thu vien chua duoc muon la: " << nDemSachChuaMuon(L3) << endl;
								textcolor(7);
								system("pause");
							}
							else if (nChucNang == 2)
							{
								clrscr();
								textcolor(10);
								cout << "\t\tTong so sach da duoc muon la: " << nDemSachDaMuon(L3) << endl;
								textcolor(7);
								system("pause");
							}
							else if (nChucNang == 3)
							{
								clrscr();
								textcolor(10);
								cout << "\t\tTong so ban doc la giao vien: " << soLuongBanDocGiaoVien(L2) << endl;
								textcolor(7);
								system("pause");
							}
							else if (nChucNang == 4)
							{
								clrscr();
								textcolor(10);
								cout << "\t\tTong so ban doc la sinh vien: " << soLuongBanDocSinhVien(L2) << endl;
								textcolor(7);
								system("pause");
							}
							else if (nChucNang == 0)
							{
								break;
							}
						}
					}
					else if (nChucNang == 0)
					{
						break;
					}
				}
				system("pause");
			}
			p++;
		}
		if (flag == 0)
		{
			gotoxy(40, 8); cout << "Nhap sai! Vui Long nhap lai.";
			system("pause");
		}
	}

}
int outputData_Admin(list <Admin> L)
{
	int nDem = 0;
	Admin Ad;
	list <Admin>::iterator p = L.begin();
	int dem = 1;
	while (p != L.end())
	{
		cout << "Ad Thu " << dem++ << endl;
		cout << "TK: " << p->getUser() << endl;
		cout << "MK: " << p->getPass() << endl;
		p++;
		nDem++;
	}
	return nDem;
}
void inputData_Admin(list <Admin> &L)
{
	ifstream File;
	File.open("Admin.txt");
	while(!File.eof())
	{
		Admin Ad;
		string u = "";
		string p = "";
		getline(File, u, ',');
		Ad.setUser(u);
		getline(File, p);
		Ad.setPass(p);
		L.push_back(Ad);
		File.ignore(0,'\n');
	}
	File.close();
	
}