#include <iostream>
#include <string>

using namespace std;

//Cau truc sinh vien
struct SinhVien
{
    int maSV;
    string hoTenSV;
    float diemtb;
};

//Cau truc node
struct Node
{
    SinhVien data;
    Node* pNext;
    Node* pPre;
};

//Ham init Node
Node* initNode(SinhVien value)
{
    Node* p = new Node;
    if (p == NULL)
    {
        return NULL;
    }

    p->data = value;
    p->pNext = p->pPre = NULL;

    return p;
}

//Cau truc Queue link2
struct Queue
{
    Node* pFront;
    Node* pRear;
};

//Ham init queue
void initQueue(Queue& q)
{
    q.pFront = q.pRear = NULL;
}

//Add sv vao queue (enQueue) == add vao cuoi hang
void enQueue(Queue& q, Node* p)
{
    if (q.pFront == NULL)
    {
        q.pFront = q.pRear = p;
    }
    else
    {
        q.pRear->pNext = p;
        p->pPre = q.pRear;
        q.pRear = p;
    }
}

//Delete sv khoi queue (deQueue) == xoa sv khoi hang
bool deQueue(Queue& q)
{
    if (q.pFront == NULL)
        return false;

    Node* p = q.pFront;
    q.pFront = q.pFront->pNext;
    delete p;

    if(q.pFront == NULL)
        q.pRear = NULL;

    return true;
}

//Ham print queue
void printQueue(Queue q)
{
    cout << "Queue: front <<    ";
    if (q.pFront == NULL)
    {
        cout << "Queue rong..." << endl;
        return;
    }
    for (Node* p = q.pFront; p != NULL; p = p->pNext)
    {
        cout << "[" << p->data.maSV << ": " << p->data.hoTenSV << ", " << p->data.diemtb << "]    ";
    }
    cout << ">" << endl;
}

int main()
{
    Queue q;
    initQueue(q);

    SinhVien sv1 = {1, "Nguyen Van A", 8.5};
    SinhVien sv2 = {2, "Tran Thi B", 7.8};
    SinhVien sv3 = {3, "Le Van C", 9.0};

    enQueue(q, initNode(sv1));
    enQueue(q, initNode(sv2));
    enQueue(q, initNode(sv3));

    printQueue(q);

    deQueue(q);
    printQueue(q);

    return 0;
}
