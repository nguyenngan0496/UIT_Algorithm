#include <iostream>

using namespace std;

int main()
{
	int* p = new int(78);
	
	cout << "Test 1: " << *p << endl;
	
	*p = 10;
	
	cout << *p << endl;

	delete p;
	p = NULL;
	
	cout << "Test 2: " << *p << endl;
	
	return 0;
}
