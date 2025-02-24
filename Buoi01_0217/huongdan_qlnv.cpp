#include <iostream>
#include <iomanip>

using namespace std;

struct NhanVien
{
	int maNV;
	string hoTen ;//char hoTen[100]
	float luongCB;
	int soNg;
	float luongHT;

};

//Func tinh luong HT
void tinhLuongHT(NhanVien &nv)
{
    nv.luongHT = nv.luongCB + nv.soNg*1800000;
    if (nv.luongHT > 8000000)
        nv.luongHT *= 1.05;
    if (nv.luongCB < 5000000)
        nv.luongHT *= 1.1;
}

//Func dua du lieu vao
NhanVien* initArrNV(int& n)
{
    cout << "Nhap so nhan vien: ";
    cin >> n;
    cin.ignore();

    NhanVien* dsNV = new NhanVien[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap ma NV: "; cin >> dsNV[i].maNV; cin.ignore();
        cout << "Nhap ten NV: "; getline(cin, dsNV[i].hoTen);
        cout << "Nhap luong CB: "; cin >> dsNV[i].luongCB;
        cout << "Nhap so ngay: "; cin >> dsNV[i].soNg;
        cin.ignore();

        tinhLuongHT(dsNV[i]);
    }

    return dsNV;
}
//Func in du lieu ra
void outArrNV(NhanVien* dsnv, int n)
{
    cout << left << setw(10) << "Ma NV: "
        << setw(10) << "Ten NV: "
        << setw(10) << "Luong CB: "
        << setw(10) << "So ngay lam: "
        << setw(10) << "Luong thang: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << left << setw(10) << dsnv[i].maNV
        << setw(10) << dsnv[i].hoTen
        << setw(10) << dsnv[i].luongCB
        << setw(10) << dsnv[i].soNg
        << setw(10) << fixed << setprecision(0) << dsnv[i].luongHT << endl;
    }
}

//Func tong luong cty tra
float sumLuongHT(NhanVien* dsnv, int n)
{
    float sumLuongHT = 0;
    for (int i = 0; i < n; i++)
    {
        sumLuongHT += dsnv[i].luongHT;
    }

    return sumLuongHT;
}

//Func tong luong nv <5tr
float sumLuongNV5mLess(NhanVien* dsnv, int n)
{
    float sumLuongNV5mLess = 0;
    for (int i = 0; i < n; i++)
    {
        if (dsnv[i].luongCB < 5000000)
            sumLuongNV5mLess += dsnv[i].luongHT;
    }

    return sumLuongNV5mLess;
}

//Func tim nv theo ma NV
void timNV(NhanVien* dsnv, int n)
{
    int maNVTim;
    cout << "Hay nhap ma NV muon tim: "; cin >> maNVTim;

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (maNVTim == dsnv[i].maNV)
        {
            cout << "Da tim thay nhan vien" << endl;
            cout << "Ma NV: " << dsnv[i].maNV << endl;
            cout << "Ten NV: " << dsnv[i].hoTen << endl;
            cout << "Luong CB: " << dsnv[i].luongCB << endl;
            cout << "Luong HT: " << dsnv[i].luongHT << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Khong tim thay nhan vien co ma " << maNVTim << endl;


}

void timNVluongHTMin(NhanVien* dsnv, int n)
{
    NhanVien NVLuongHTMin = dsnv[0];

    for (int i = 0; i < n; i++)
    {
        if (NVLuongHTMin.luongHT < dsnv[i].luongHT)
            {
                NVLuongHTMin = dsnv[i];
            }
    }
            cout << "Nhan vien luong hang thang nho nhat la" << endl;
            cout << "Ma NV: " << NVLuongHTMin.maNV << endl;
            cout << "Ten NV: " << NVLuongHTMin.hoTen << endl;
            cout << "Luong CB: " << NVLuongHTMin.luongCB << endl;
            cout << "Luong HT: " << NVLuongHTMin.luongHT << endl;
}

void timNVLuongCBMax(NhanVien* dsnv, int n)
{
    NhanVien NVLuongCBMax = dsnv[0];

    for (int i = 0; i < n; i++)
    {
        if (NVLuongCBMax.luongCB < dsnv[i].luongCB)
        {
            NVLuongCBMax = dsnv[i];
        }
    }
            cout << "Nhan vien luong co ban cao nhat la" << endl;
            cout << "Ma NV: " << NVLuongCBMax.maNV << endl;
            cout << "Ten NV: " << NVLuongCBMax.hoTen << endl;
            cout << "Luong CB: " << NVLuongCBMax.luongCB << endl;
            cout << "Luong HT: " << NVLuongCBMax.luongHT << endl;
}

int main()
{
	int sl = 0;

    //Nhap danh sach
    NhanVien* dsNV = initArrNV(sl);

    cout << "==========" << endl;
    cout << "Danh sach nhan vien: " << endl;
    outArrNV(dsNV, sl);

    cout << "==========" << endl;
    cout << "Tong luong hang thang cty phai tra: " << sumLuongHT(dsNV, sl) << endl;

    cout << "==========" << endl;
    cout << "Tong luong hang thang cac nhan vien co luong CB it hon 5m: " << sumLuongNV5mLess(dsNV, sl) << endl;

    cout << "==========" << endl;
    timNV(dsNV, sl);

    cout << "==========" << endl;
    timNVluongHTMin(dsNV, sl);

    cout << "==========" << endl;
    timNVLuongCBMax(dsNV, sl);
	return 0;
}
