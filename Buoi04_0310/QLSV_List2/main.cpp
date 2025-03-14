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
    cout << "[" << sv.maSV << ", " <<
                   sv.hoTen << ", " <<
                   sv.diemTB << ", " <<
                   sv.xepLoai << "]" << endl;
    /*cout << "Thong tin sinh vien:" << endl;
    cout << "\t-Ma sinh vien: " << sv.maSV << endl;
    cout << "\t-Ho ten sinh vien: " << sv.hoTen << endl;
    cout << "\t-Diem trung binh: " << sv.diemTB << endl;
    cout << "\t-Xep loai: " << sv.xepLoai << endl;*/
}

//Buoc 1: Tao cau truc Node
struct Node
{
    SinhVien data;
    Node* pPre;
    Node* pNext;
};

//Buoc 2: Cap phat dong
Node* initNode(SinhVien value)
{
    Node* p = new Node;

    if(p == NULL)
    {
        return NULL;
    }
    p->data = value;
    p->pNext = NULL;
    p->pPre = NULL;

    return p;
}

//Buoc 3: Tao cau truc lien ket doi
struct List
{
    Node* pHead;
    Node* pTail;
};

//Buoc 4: Khoi tao List
void initList(List& l)
{
    l.pHead = l.pTail = NULL;
}

void pushFront(List& l, Node* p)
{
    if(l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead->pPre = p;
        l.pHead = p;
    }

}

void pushBack(List& l, Node* p)
{
    if(l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        p->pPre = l.pTail;
        l.pTail = p;
    }
}

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

    pushFront(dsSV, initNode(sv1));
    pushFront(dsSV, initNode(sv2));
    pushFront(dsSV, initNode(sv3));
    pushFront(dsSV, initNode(sv4));
    pushBack(dsSV, initNode(sv5));
    pushBack(dsSV, initNode(sv6));
    pushBack(dsSV, initNode(sv7));
    pushBack(dsSV, initNode(sv8));

    return 8;
}

void printListSV(List l)
{
    cout << "Di tu pHead den pTail: " << endl;
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        //cout << p->data << "    ";
        printSV(p->data);
    }
    cout << endl << endl;
    cout << "Di tu pTail ve pHead: " << endl;
    for(Node* p = l.pTail; p != NULL; p = p->pPre)
    {
        //cout << p->data << "    ";
        printSV(p->data);
    }
}

int main()
{
    List dsSV;
    initList(dsSV);

    cout << "Test: Cau 6. Khoi tao ds sv: " << endl;
    initDataListSV(dsSV);

    cout << "Test: Cau 7. In ds sv: " << endl;
    printListSV(dsSV);


    return 0;
}
