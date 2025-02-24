#include <iostream>

using namespace std;

// Bước 1: Tạo cấu trúc node
struct Node
{
    int data;
    Node* pNext; // Phải là kiểu node* thì mới lưu được địa chỉ
};

// Bước 2: Cấp phát node để lưu trữ dữ liệu
Node* initNode(int value)
{
    Node* p = new Node;
    p->data = value;
    p->pNext = NULL;
    return p;
}

// Bước 3: Tạo cấu trúc danh sách
struct List
{
    Node* pHead;
    Node* pTail;
};

// Bước 4: Hàm khởi tạo danh sách
void initList(List& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

// Thêm node vào đầu danh sách
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

// Thêm node vào cuối danh sách
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

// Duyệt danh sách và in dữ liệu bằng vòng for
void printListFor(List l)
{
    for (Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->data << "  ";
    }
    cout << endl << endl;
}

// Duyệt danh sách và in dữ liệu bằng vòng while (sửa lỗi)
void printListWh(List l)
{
    Node* p = l.pHead;
    while (p != NULL)
    {
        cout << p->data << "  ";
        p = p->pNext; // Cập nhật con trỏ để duyệt qua danh sách
    }
    cout << endl << endl;
}

int main()
{
    Node* p1 = initNode(10);
    Node* p2 = initNode(79);
    Node* p3 = initNode(39);

    List l;
    initList(l); // Danh sách rỗng

    addHead(l, p1);
    addHead(l, p2);
    addTail(l, p3);

    printListFor(l);
    printListWh(l);

    return 0;
}
