#include <iostream>

using namespace std;
//B1: Dinh nghia cau truc node
struct Node
{
    int data;
    Node* pNext;
};

//B2: Cap phat dong, init Node
Node* initNode(int value)
{
    //return new Node({value, NULL});

    Node* p = new Node;

    p->data = value;
    p->pNext = NULL;

    return p;
}

//B3: Tao cau truc bucket
struct Bucket
{
    Node* pHead;
    Node* pTail;
};

//B4: Ham khoi tao bucket
void initBucket(Bucket& bk)
{
    bk.pHead = bk.pTail = NULL;
}

//B5: define cau truc bang bam
const int Size = 5;
struct HashTable
{
    Bucket bucket[Size];
};

//B6: khoi tao hashtable
void initHashTable(HashTable& h)
{
    for(int i = 0; i < Size; i++)
    {
        initBucket(h.bucket[i]);
    }
}

int hashFunc(int value)
{
    return value%Size;
}

int hashFunc(Node* p)
{
    return (p->data)%Size;
}

void addTail(Bucket& bk, Node* p)
{
    if(bk.pHead == NULL)
    {
        bk.pHead = p;
        bk.pTail = p;
    }
    else
    {
        bk.pTail->pNext = p;
        bk.pTail = p;
    }
}

void add(HashTable& h, int value)
{
    //B1: chon vi tri bucket
    int viTri = hashFunc(value);

    //B2: add vao bucket
    addTail(h.bucket[viTri], initNode(value));
}

void add(HashTable& h, Node* p)
{
    //B1: chon vi tri bucket
    int viTri = hashFunc(p);

    //B2: add vao bucket
    addTail(h.bucket[viTri], p);
}

void printHashTable(HashTable h)
{
    cout << "HashTable.Size: " << Size << endl;
    for(int i = 0; i < Size; i++)
    {
        cout << "bucket[" << i << "] = ";
        for(Node* p = h.bucket[i].pHead; p != NULL; p = p->pNext)
        {
            cout << p->data << "\t";
        }
        cout << endl;
    }
}

int main()
{
    HashTable h;
    initHashTable(h);

    //50    73  35  36  64  28  90  21  53  13
    add(h, 50);
    add(h, initNode(73));
    add(h, 35);
    add(h, 36);
    add(h, 64);
    add(h, 28);
    add(h, 90);
    add(h, 21);
    add(h, 53);
    add(h, 13);

    printHashTable(h);

    return 0;
}
