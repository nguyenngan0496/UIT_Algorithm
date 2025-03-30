#include <iostream>
using namespace std;

/*
Input:
+ Đĩa A, B, C
Output:
+ dịch chuyển đĩa sao cho đĩa nằm trên < đĩa nằm dưới

*/
void move(int n,char A,char B,char C)
 {
      if(n==1){
        cout<<A<<" ==> "<<C<<"\n";// nếu n = 1 thì dịch chuyển từ A -> C
      }
      else {
        //// Nếu n > 1 thì thực hiện lần lượt các bước
        move(n - 1, A, C, B); // 1. Dịch chuyển n-1 đĩa từ A -> B
        cout<<A<<" ==> "<<C<<"\n"; //2. Dịch chuyển đĩa thứ n từ A -> C
        move(n - 1, B, A, C); // 3. Dịch chuyển n-1 đĩa từ B -> C
      }
 }

int main() {
  int n;
  cout<<"Nhap vao n la so dia: ";
  cin>>n; // Nhập vào số đĩa
  cout<<"Test 01: Dich chuyen dia A B C\n";
  move(n, 'A', 'B', 'C');
}
