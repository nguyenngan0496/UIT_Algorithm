#include <iostream>

using namespace std;
//B1: tao cau truc node
struct Node
{
    int data;
    Node* pNext;
};

//B2: Khoi tao node - cap phat dong
Node* initNode(int value)
{
    Node* p = new Node;
    p->data = value;
    p->pNext = NULL;

    return p;
}

//B3: Dinh nghia stack
struct Stack
{
    Node* pTop;
};

//B4: Khoi tao stack
void initStack(Stack& s)
{
    s.pTop = NULL;
}

void push(Stack& s, Node* p)
{
    if(s.pTop == NULL)
    {
        s.pTop = p;
    }
    else
    {
        p->pNext = s.pTop;
        s.pTop = p;
    }
}

void printStack(Stack s)
{
    cout << "Stack = Top << ";

    for(Node* p = s.pTop; p != NULL; p = p->pNext)
    {
        cout << p->data << "    ";
    }
    cout << " >>" << endl;
}

void pop(Stack& s)
{
    if(s.pTop == NULL)
        return;

    Node* p = s.pTop;
    s.pTop = s.pTop->pNext;
    delete p;
}

int getValue(Stack s)
{
    if(s.pTop != NULL)
        return s.pTop->data;

}

int main()
{
    Node* p1 = initNode(10);
    Node* p2 = initNode(79);
    Node* p3 = initNode(39);

    Stack s;
    initStack(s);

    push(s, p1);
    push(s, p2);
    push(s, p3);

    printStack(s);

    cout << "Test: 1. Lay: " << getValue(s) << endl;
    pop(s);
    printStack(s);

    cout << "Test: 2. Lay: " << getValue(s) << endl;
    pop(s);
    printStack(s);

    cout << "Test: 3. Lay: " << getValue(s) << endl;
    pop(s);
    printStack(s);

    cout << "Test: 4. Lay: " << getValue(s) << endl;
    pop(s);
    printStack(s);

    return 0;
}
