#include "stdafx.h"
#include "CChiTieu.h"


CChiTieu::CChiTieu()
{
	Loai = L"";
	NoiDung = L"";
	SoTien = 0;
}

CChiTieu::CChiTieu(wstring mLoai, wstring mNoiDung, long mSoTien)
{
	Loai = mLoai;
	NoiDung = mNoiDung;
	SoTien = mSoTien;
}

void CChiTieu::setLoai(wstring mLoai)
{
	Loai = mLoai;
}

wstring CChiTieu::getLoai()
{
	return this->Loai;
}

void CChiTieu::setNoiDung(wstring mNoiDung)
{
	NoiDung = mNoiDung;
}

wstring CChiTieu::getNoiDung()
{
	return this ->NoiDung;
}

void CChiTieu::setSoTien(long mSoTien)
{
	SoTien = mSoTien;
}

long CChiTieu::getSoTien()
{
	return this->SoTien;
}
CChiTieu::~CChiTieu()
{
}
