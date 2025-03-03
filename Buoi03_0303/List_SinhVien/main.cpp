#include <iostream>

using namespace std;

struct SinhVien
{
    int maSV;
    string hoTen;
    float diemTB;
    string xepLoai;

};

//Ham in thong tin sinh vien
void inSV(SinhVien sv)
{
    cout << "Thong tin sv: " << endl;
    cout << "\t-Ma sinh vien: " << sv.maSV << endl;
    cout << "\t-Ho ten: " << sv.hoTen << endl;
    cout << "\t-Diem trung binh: " << sv.diemTB << endl;
    cout << "\t-Xep loai: " << sv.xepLoai << endl;
}
//Buoc 1: cau truc Node
struct Node
{
    SinhVien data;
    Node* pNext;
};

//Buoc 2: khoi tao Node
Node* initNode(SinhVien value)
{
    Node* p = new Node;
    p->data = value;
    p->pNext = NULL;
    return p;
}

//Buoc 3: Tao cau truc list
struct List
{
    Node* pHead;
    Node* pTail;
};

//Buoc 4: Khoi tao list
void initList(List& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

//Ham add node vao dau list
void addHead(List& l, Node* p)
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

//Ham init du lieu sv
void initDataListSV(List& dsSV)
{
    SinhVien sv1 = {123, "Nguyen Van A", 9.1, ""};
    SinhVien sv2 = {124, "Nguyen Van B", 8.8, ""};
    SinhVien sv3 = {125, "Nguyen Van C", 9.1, ""};
    SinhVien sv4 = {126, "Nguyen Van D", 2.1, ""};
    SinhVien sv5 = {127, "Nguyen Van F", 9.7, ""};
    SinhVien sv6 = {128, "Nguyen Van G", 4.1, ""};
    SinhVien sv7 = {129, "Nguyen Van H", 8.3, ""};
    SinhVien sv8 = {130, "Nguyen Van K", 7.9, ""};

    addHead(dsSV, initNode(sv1));
    addHead(dsSV, initNode(sv3));
    addHead(dsSV, initNode(sv5));

}

//Ham in dsSV
void printListSV(List l) {
    if(l.pHead == NULL) {
        cout << "List rong ...";
    }
    for(Node* p = l.pHead; p != NULL; p=p->pNext) {
//        cout << p->data << "  ";
        inSV(p->data);
    }
    cout << endl << endl;
}
//Cau 8: Viet ham cap nhat xep loai hoc luc
//Input: list dssv (ds ban dau)
//Output: list dssv (ds da cap nhat)
void capNhatXL(List& l)
{
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        if(p->data.diemTB >= 9)
        {
            p->data.xepLoai = "Xuat sac";
        }
    }
}

int main()
{
    List dsSV;
    initList(dsSV);

    cout << "Test: Cau 6. Khoi tao ds SV: " << endl;
    initDataListSV(dsSV);

    cout << "Test: Cau 7. In ds SV: " << endl;
    printListSV(dsSV);

    cout << "Test: Cau 8. Update xep loai: " << endl;
    capNhatXL(dsSV);
    printListSV(dsSV);

    return 0;
}
