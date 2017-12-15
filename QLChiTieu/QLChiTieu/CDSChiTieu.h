#include <vector>
#include <fstream>
#include <codecvt>
#include <locale>
#include "CChiTieu.h"
using namespace std;

class CDSChiTieu
{
private:
	vector<CChiTieu>dsChiTieu;
	int countItem;
public:
	CDSChiTieu();
	void setCountItem(int count);
	int getCountItem();
	void themChiTieu(CChiTieu);
	long getTongTien();
	CChiTieu getChiTieu(int pos);
	float getTiLeMotLoai(int loai);
	void getdsChiTieu(string filename);
	void setdsChiTieu(string filename);
	~CDSChiTieu();
};

