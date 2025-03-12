#include <iostream>

using namespace std;

struct SinhVien
{
    int maSV;
    string hoTen;
    float diemTB;
    string xepLoai;
};

//Ham print thong tin sinh vien
void printSV(SinhVien sv)
{
    cout << "Thong tin sinh vien:" << endl;
    cout << "\t-Ma sinh vien: " << sv.maSV << endl;
    cout << "\t-Ho ten sinh vien: " << sv.hoTen << endl;
    cout << "\t-Diem trung binh: " << sv.diemTB << endl;
    cout << "\t-Xep loai: " << sv.xepLoai << endl;
}

//Buoc 1: Cau truc node
struct Node
{
    SinhVien data;
    Node* pNext;
};

//Buoc 2: Khoi tao node
Node* initNode(SinhVien value)
{
    Node* p = new Node;
    p->data = value;
    p->pNext = NULL;

    return p;
}

//Buoc 3: Cau truc list sv
struct dsSV
{
    Node* pHead;
    Node* pTail;
};

//Buoc 4: Khoi tao list sv
void initdsSV(dsSV& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

//Cau 4: Add sv vao dau danh sach
void addHead(dsSV& l, Node* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
//Cau 5: add sv vao cuoi danh sach
void addTail(dsSV& l, Node* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
//Cau 6: Ham khoi tao du lieu cho danh sach sinh vien
void initDataDSSV(dsSV& l)
{
    SinhVien sv1 = {123, "Nguyen Van A", 9.1, ""};
    SinhVien sv2 = {124, "Nguyen Van B", 8.8, ""};
    SinhVien sv3 = {125, "Nguyen Van C", 9.1, ""};
    SinhVien sv4 = {126, "Nguyen Van D", 2.1, ""};
    SinhVien sv5 = {127, "Nguyen Van F", 9.7, ""};
    SinhVien sv6 = {128, "Nguyen Van G", 4.1, ""};
    SinhVien sv7 = {129, "Nguyen Van H", 8.3, ""};
    SinhVien sv8 = {130, "Nguyen Van K", 7.9, ""};

    addTail(l, initNode(sv1));
    addTail(l, initNode(sv2));
    addTail(l, initNode(sv3));
    addTail(l, initNode(sv4));
    addTail(l, initNode(sv5));
    addTail(l, initNode(sv6));
    addTail(l, initNode(sv7));
    addTail(l, initNode(sv8));
}

//Ham in dssv
void printDSSV(dsSV l)
{
    if(l.pHead == NULL)
        cout << "Danh sach rong...";
    else
    {
        for(Node* p = l.pHead; p != NULL; p = p->pNext)
            printSV(p->data);
    }
    cout << endl;
}

//Ham cap nhat xep loai va in lai dssv
void updateXepLoai(dsSV& l)
{
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        if(p->data.diemTB >= 9)
        {
            p->data.xepLoai = "Xuat sac";
        }
        else if(p->data.diemTB < 9 && p->data.diemTB >= 8)
        {
            p->data.xepLoai = "Gioi";
        }
        else if(p->data.diemTB < 8 && p->data.diemTB >=7)
        {
            p->data.xepLoai = "Kha";
        }
        else if(p->data.diemTB <7 && p->data.diemTB >= 5)
        {
            p->data.xepLoai = "Trung binh";
        }
        else if(p->data.diemTB < 5)
        {
            p->data.xepLoai = "O lai lop";
        }

    }
    printDSSV(l);
}

//Ham tim diem trung binh cao nhat
float findDiemTBMax(dsSV l)
{
    if(l.pHead == NULL)
    {
        cout << "Danh sach rong...";
        return -1;
    }

    float diemTBMax = l.pHead->data.diemTB;
    for(Node* p = l.pHead->pNext; p != NULL; p = p->pNext)
    {
        if(p->data.diemTB > diemTBMax)
            diemTBMax = p->data.diemTB;
    }
    return diemTBMax;
}
//Ham tim sinh vien theo ma sinh vien
void searchSV(dsSV l)
{
    int maSVSearch;
    if(l.pHead == NULL)
    {
        cout << "Danh sach rong...";
    }
    else
    {
        cout << "Nhap ma sinh vien can tim: ";
        cin >> maSVSearch;

        for(Node* p = l.pHead; p != NULL; p = p->pNext)
        {
            if(maSVSearch == p->data.maSV)
                {
                    cout << "Sinh vien can tim: ";
                    printSV(p->data);
                    return;
                }

        }
    }
    cout << "Khong tim thay sinh vien co ma " << maSVSearch << endl;



}

//Ham tim sinh vien co diem trung binh cao nhat
void searchSVMaxDiemTB(dsSV l)
{
    if(l.pHead == NULL)
    {
        cout << "Danh sach rong..." << endl;
        return;
    }
    Node* SVMaxDiemTB = l.pHead;
    for(Node* p = l.pHead->pNext; p != NULL; p = p->pNext)
    {
        if(p->data.diemTB > SVMaxDiemTB->data.diemTB)
            {SVMaxDiemTB = p;
            //return;
            }
    }
    printSV(SVMaxDiemTB->data);
}

//Ham tim sinh vien co diem trung binh thap nhat
void searchSVMinDiemTB(dsSV l)
{
    if(l.pHead == NULL)
    {
        cout << "Danh sach rong..." << endl;
        return;
    }
    Node* SVMinDiemTB = l.pHead;
    for(Node* p = l.pHead->pNext; p != NULL; p = p->pNext)
    {
        if(p->data.diemTB < SVMinDiemTB->data.diemTB)
            {SVMinDiemTB = p;
            //return;
            }
    }
    printSV(SVMinDiemTB->data);
}

int main()
{
    dsSV l;
    initdsSV(l);

    cout << "Cau 6. Khoi tao danh sach sinh vien:" << endl;
    initDataDSSV(l);

    cout << "===============" << endl;

    cout << "Cau 7. In danh sach sinh vien: " << endl;
    printDSSV(l);

    cout << "===============" << endl;

    cout << "Cau 8. Cap nhat xep loai sinh vien: " << endl;
    updateXepLoai(l);
    //printDSSV(l);

    cout << "===============" << endl;

    cout << "Cau 9. Tim diem trung binh cao nhat: " << findDiemTBMax(l) << endl;

    cout << "===============" << endl;

    cout << "Cau 10. Tim kiem sinh vien theo ma sinh vien: \n";
    searchSV(l);

    cout << "===============" << endl;

    cout << "Cau 11. Tim sinh vien co diem trung binh cao nhat: " << endl;
    searchSVMaxDiemTB(l);

    cout << "===============" << endl;

    cout << "Cau 12. Tim sinh vien co diem trung binh thap nhat: " << endl;
    searchSVMinDiemTB(l);

    return 0;
}
