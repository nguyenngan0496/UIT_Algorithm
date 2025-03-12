#include <iostream>

using namespace std;

// Buoc 01: Tạo cấu trúc Node
struct Node
{
    int data;
    Node *pNext; // lưu trữ địa chỉ của Node phía sau
};

// Bước 2: Khởi tạo Node để lưu giá trị cần lưu.
Node* initNode(int value)
{
    Node* p = new Node;
    p->data = value;
    p->pNext = NULL; // chứa lưu trữ địa chỉ Node tiếp theo, set = NULL
    return p;
}

// Bước 3: Tạo cấu trúc danh sách
struct Queue
{
    Node* pFront;
    Node* pRear;
};


// Bước 4: Khởi tạo danh sách
void initQueue(Queue& q)
{
    q.pFront = q.pRear = NULL;
}

void enQueue(Queue& q, Node* p)
{
    if (q.pFront == NULL)
    {
        q.pFront = p;
        q.pRear = p;
    }
    else
    {
        q.pRear->pNext = p;
        q.pRear = p;
    }
}


bool deQueue(Queue& q)
{
    if(q.pFront == NULL)
        return false;

    Node* p = q.pFront; //1. gan' tam pHead vao p
    q.pFront = q.pFront->pNext;//2. gan' pNext lam pHead moi'
    delete p; //3.THu hoi p

    if(q.pFront == NULL)
        q.pRear == NULL;

    return true;

}

void printQueueFor(Queue q)
{
    cout << "Queue q = front <<    ";
    if(q.pFront == NULL)
    {
        cout << "Queue rong..." << endl;\
        return;
    }
    for (Node* p = q.pFront; p != NULL; p = p->pNext)
    {
        cout << p->data << "    ";
    }
    cout << ">" << endl << endl;
}

int main()
{
    Queue q;
    initQueue(q);

    enQueue(q, initNode(10));
    enQueue(q, initNode(79));
    enQueue(q, initNode(39));

    printQueueFor(q);

    deQueue(q);
    printQueueFor(q);

    return 0;
}
