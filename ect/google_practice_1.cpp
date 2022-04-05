#include <iostream>
#include <cmath> // abs 절댓값 구하기
#include <algorithm> // sort
using namespace std;

int A[100]; // 배열 A
int main() {
	int num;
	cin >> num;    // Reading input from STDIN - size of array A
	for(int i = 0; i < num; i++){
		cin >> A[i];
		A[i] = abs(A[i]); // 절댓값 화 - 모든 절댓값은 양수로 0 이상의 값을 가진다 - 반환값 int 저장해줘야함
	}

	sort(A, A + num); // 배열 A 정렬 - 절댓값 정렬시 제일 첫 항이 가장 0에 가까운 값

	num = A[0];
	cout << num << endl;	// Writing output to STDOUT
}