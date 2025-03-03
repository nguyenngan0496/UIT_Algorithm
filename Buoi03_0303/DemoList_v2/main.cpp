#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node *pNext;
};


Node* initNode(int value)
{
    Node* p = new Node;
    p->data = value;
    p->pNext = NULL;
    return p;
}


struct List
{
    Node* pHead;
    Node* pTail;
};


void initList(List& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

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

void addTail(List& l, Node* p)
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

void printListFor(List l)
{
    if(l.pHead == NULL)
    {
        cout << "List rong..." << endl;
        return;
    }
    for (Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->data << " ";
    }
    cout << endl << endl;
}

void printListWhile(List l)
{
    Node* p = l.pHead;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->pNext;
    }
    cout << endl << endl;
}


bool timGiaTri(List l, int value)
{
    for (Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->data == value)
        {
            return true;
        }
    }
    return false;
}


int demGiaTri(List l)
{
    int dem = 0;
    for (Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->data % 2 == 0)
        {
            dem ++;
        }
    }
    return dem;
}

//Yeu cau: tinh tong cac gia tri co trong danh sach
//Input: list l  - Output: return tong
int tongGiaTri(List l)
{
    int tong = 0;
    for (Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        tong += p->data;
    }
    return tong;
}

//Yeu cau: tim gia tri lon nhat
//Input: list l  - Output: return max

int timMax(List l)
{
    int max = l.pHead->data;
    for (Node* p = l.pHead->pNext; p != NULL; p = p->pNext)
    {
        if(p->data > max)
        {
            max = p->data;
        }
    }
    return max;
}

//Yeu cau: Viet ham xoa node dau tien
//Input: list& l - Output: return bool, x: int& (gia tri xoa dc)

bool popHead(List& l)
{
    if(l.pHead == NULL)
        return false;

    Node* p = l.pHead; //1. gan' tam pHead vao p
    l.pHead = l.pHead->pNext;//2. gan' pNext lam pHead moi'
    delete p; //3.THu hoi p

    if(l.pHead == NULL)
        l.pTail == NULL;

    return true;

}

int main()
{
    Node* p1 = initNode(10);
    Node* p2 = initNode(79);
    Node* p3 = initNode(39);

    List l;
    initList(l);

    addHead(l,p1);
    addHead(l,p2);

    addTail(l,p3);

    cout << "Test: In danh sach:" << endl;
    //79 10 39
    printListFor(l);
    printListWhile(l);
    cout << "Test: Tim(10)_(1): " << timGiaTri(l,10) << endl;
    cout << "Test: Tim(29)_(0): " << timGiaTri(l,29) << endl;

    cout << endl;
    cout << "Test: Tong: " << tongGiaTri(l) << endl;

    cout << endl;
    cout << "Test: Gia tri max: " << timMax(l) << endl;

    cout << endl;
    popHead(l);
    printListFor(l);
    popHead(l);
    printListFor(l);
    popHead(l);
    printListFor(l);
    popHead(l);
    printListFor(l);

    return 0;
}
