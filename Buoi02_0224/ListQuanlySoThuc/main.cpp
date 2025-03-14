#include <iostream>

using namespace std;

//Tao cau truc Node
struct Node
{
    float data;
    Node* pNext;
};

//Ham init Node
Node* initNode(float value) //Node* chu khong phai void vi data type duoc return la Node (khi nao k xac dinh type thi void)
{
    Node* p = new Node;
    p->data = value;
    p->pNext = NULL;
    return p;
}

//Tao cau truc list/singly list
struct List
{
    Node* pHead;
    Node* pTail;
};

//Ham tao danh sach rong
void initList(List& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

//Ham add Node vao Head
void addHead(List& l, Node* p)
{
    if (l.pHead == NULL) //kiem tra xem co rong ko, co thi cho p lam Head&Tail
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead; //khong rong nen p lam Head -> Next cua p la Head truoc do, p lam Head moi
        l.pHead = p;
    }
}

//Ham add Node vao Tail
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

//Ham in List
void printList(List l)
{
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->data << "    ";
        //cout << endl << endl;
    }
}

//Ham tim gia tri
bool timGiaTri(List l, float value)
{
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->data == value)
            return true;
    }
    return false;
}
//Ham dem gia tri chan trong list
//Input: list  Output: return int

int demGiaTri(List l)
{
    int countChan = 0;
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        if((int)p->data % 2 == 0)
        {
            countChan++;
        }
    }

    return countChan;

}

//Ham in gia tri & dia chi tung node trong list
void printNodeofList(List l)
{
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << "\nData: " << p->data << " - Address: " << p << endl;
    }
}

//Ham tim gia tri node ke cuoi
float timNodeKeCuoi(List l)
{
    Node* NodeKC = l.pHead;
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->pNext == l.pTail)
        {
            NodeKC = p;
        }

    }
    return NodeKC->data;
}

int main()
{
    Node* p1 = initNode(3.2);
    Node* p2 = initNode(4.9);
    Node* p3 = initNode(292.2);

    List l;
    initList(l);

    //add p1 vao head
    addHead(l, p1); //3.2

    //add p3 vao head
    addHead(l, p3); //292.2  3.2

    //add p2 vao Tail
    addTail(l, p2); //292.2  3.2  4.9

    printList(l);

    //Test tim gia tri
    cout << "\nTest_Tim (3)_(0): " << timGiaTri(l, 3);
    cout << "\nTest_Tim (4.9)_(1): " << timGiaTri(l, 4.9);


    cout << "\nSo luong gia tri chan: " << demGiaTri(l);

    printNodeofList(l);
    cout << "Gia tri node ke cuoi: " << timNodeKeCuoi(l);

    return 0;


}
