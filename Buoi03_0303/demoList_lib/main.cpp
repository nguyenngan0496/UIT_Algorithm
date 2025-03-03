#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> ds;

    ds.push_front(2);
    ds.push_front(6);
    ds.push_front(9);
    ds.push_front(1);
    ds.push_front(7);

    for(int i: ds)
    {
        cout << i << "  ";
    }

    return 0;
}
