#include <iostream>

using namespace std;

//Buoc 1: Tao cau truc Node
struct Node
{
    int data;
    Node* pPre;
    Node* pNext;
};

//Buoc 2: Cap phat dong
Node* initNode(int value)
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

void printList(List l)
{
    cout << "Di tu pHead den pTail: " << endl;
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->data << "    ";
    }
    cout << endl << endl;
    cout << "Di tu pTail ve pHead: " << endl;
    for(Node* p = l.pTail; p != NULL; p = p->pPre)
    {
        cout << p->data << "    ";
    }
}

int main()
{
    //10  79  39
    Node* p1 = initNode(10);
    Node* p2 = initNode(79);
    Node* p3 = initNode(39);
    Node* p4 = initNode(18);
    Node* p5 = initNode(12);

    List l;
    initList(l); //danh sach rong

    pushFront(l, p1);
    pushBack(l, p2);
    pushBack(l, p3);
    pushFront(l, p4);
    pushBack(l, p5);

    //18  10  79  39
    printList(l);

    return 0;
}
