#include <iostream>

using namespace std;

int main()
{
	int x = 10; //&x se la dia chi-> *(&x) la goi toi dia chi, k the viet *x dc
	
	int* p = &x; //dung bien p de luu dia chi 
	int* p1, *p2, p3; //khai bao liet ke nhiu thi phai them dau *, neu ko no chi la int
	
	int y = 20;
	
	p = &y;
	
	cout << p << endl;
	cout << &x << endl;
	cout << *p << endl;
	
//	cout << "x = " << &x << endl;
//	cout << "Dia chi x = " << &x << endl;
//	cout << *(&x);
	
	return 0;
}
