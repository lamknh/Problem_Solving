#include <iostream>
#include <stack>
using namespace std;
 
int main(void)
{
	int n, num, cnt = 1;
	stack<int> s;
	string result;
	scanf("%d", &n);
 
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		if (num >= cnt) { // 입력값이랑 같아질때까지 push
			while (num + 1 != cnt) {
				s.push(cnt++);
				result += "+\n";
			}
			s.pop();
			result += "-\n"; // 입력값 수열에 넣기
		}
		else {
			if (s.top() == num) { // top이 입력값과 같으면 pop
				s.pop();
				result += "-\n";
			}
			else {
				result = "NO";
				break;
			}
		}
	}
	cout << result;
 
	return 0;
}