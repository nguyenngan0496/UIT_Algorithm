#include <iostream>

using namespace std;

struct ToaDo
{
	float x;
	float y;	
};
//Func de in toa do, dung dau cham .
void inToaDo(ToaDo a)
{
	cout << "(" << a.x << ", " << a.y << ")\n";
}

//func de in bang con tro lun, dung ->: sau nay xai nhiu
void inToaDo2(ToaDo* p)
{
	cout << "(" << p->x << ", " << p->y << ")\n"; //Dung -> nhiu hon
	//cout << "(" << (*p).x << ", " << (*p).y << ")";
}

int main()
{
	int x = 5;
	ToaDo a = {6, 7};
	
	//cout << a;
	inToaDo(a); 
	
	ToaDo* p = new ToaDo();
	
	*p = a;
	
	inToaDo(*p);
	inToaDo2(p);

	
	return 0;
}
