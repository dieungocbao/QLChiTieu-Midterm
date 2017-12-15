#include <string>
using namespace std;

class CChiTieu
{
private:
	wstring Loai;
	wstring NoiDung;
	long SoTien;

public:
	CChiTieu();
	CChiTieu(wstring mLoai, wstring mNoiDung, long mSoTien);
	void setLoai(wstring mLoai);
	wstring getLoai();
	void setNoiDung(wstring mNoiDung);
	wstring getNoiDung();
	void setSoTien(long mSoTien);
	long getSoTien();

	~CChiTieu();
};

