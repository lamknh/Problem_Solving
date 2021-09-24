#include <iostream>

using namespace std;

int main()
{
	int a, b;

	//종료 조건 주어지지 않으면 EOF 신경써서 만들어야한다.

	while (cin >> a >> b) { // while 안에 입력 받게 해도 된다
		cout << a + b << endl;
	}
	return 0;
}