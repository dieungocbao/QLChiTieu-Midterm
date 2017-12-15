#include "stdafx.h"
#include "CDSChiTieu.h"

wstring ComboBoxItems[6] = { _T("Ăn uống"), _T("Di chuyển"), _T("Nhà cửa"),_T("Xe cộ"), _T("Nhu yếu phẩm"), _T("Dịch vụ") };

CDSChiTieu::CDSChiTieu()
{
	countItem = 0;
}
CDSChiTieu::~CDSChiTieu()
{
}


void CDSChiTieu::setCountItem(int count)
{
	this->countItem = count;
}

int CDSChiTieu::getCountItem()
{
	return this->countItem;
}
void CDSChiTieu::themChiTieu(CChiTieu chitieu)
{
	dsChiTieu.push_back(chitieu);
	countItem++;
}
long CDSChiTieu::getTongTien()
{
	long tongtien = 0;
	for (int i = 0; i < dsChiTieu.size(); i++)
	{
		tongtien += dsChiTieu[i].getSoTien();
	}
	return tongtien;
}
CChiTieu CDSChiTieu::getChiTieu(int pos)
{
	return dsChiTieu[pos];
}
float CDSChiTieu::getTiLeMotLoai(int loai)
{
	long tongtien = 0;
	for (int i = 0; i<dsChiTieu.size(); i++)
	{
		if (dsChiTieu[i].getLoai().compare(ComboBoxItems[loai]) == 0)
		{
			tongtien += dsChiTieu[i].getSoTien();
		}
	}
	return 1.0*tongtien / this->getTongTien();
}
void CDSChiTieu::getdsChiTieu(string filename)
{
	wfstream fin;
	fin.open(filename, ios::in);
	std::locale loc(std::locale(), new std::codecvt_utf8<wchar_t>);
	fin.imbue(loc);

	while (!fin.eof())
	{
		fflush(stdin);
		CChiTieu chiTieu;
		wstring data;
		wstring temp;
		getline(fin, data);
		if (data == L"")
			continue;
		int pos1 = data.find_first_of(',');
		temp = data.substr(0, pos1);
		chiTieu.setLoai(temp);
		int pos2 = data.find_last_of(',');
		temp = data.substr(pos1 + 1, pos2 - pos1 - 1);
		chiTieu.setNoiDung(temp);
		temp = data.substr(pos2 + 1);
		long soTien = _wtol(temp.c_str());
		chiTieu.setSoTien(soTien);

		themChiTieu(chiTieu);
	}
	fin.close();
}
void CDSChiTieu::setdsChiTieu(string filename)
{
	wfstream fout;
	fout.open(filename, ios::out);
	std::locale loc(std::locale(), new std::codecvt_utf8<wchar_t>);
	fout.imbue(loc);
	int count = 0;
	while (count < dsChiTieu.size() - 1)
	{
		CChiTieu chiTieu = getChiTieu(count);
		fout << chiTieu.getLoai() << L"," << chiTieu.getNoiDung() << L"," << chiTieu.getSoTien();
		fout << endl;
		count++;
	}
	if (count == dsChiTieu.size() - 1)
	{
		CChiTieu chiTieu = getChiTieu(count);
		fout << chiTieu.getLoai() << L"," << chiTieu.getNoiDung() << L"," << chiTieu.getSoTien();
	}

	fout.close();
}
