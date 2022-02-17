#include <iostream>
#include <deque>
using namespace std;

int N, M, cnt = 0, x;
deque<int> dq;
int main(int argc, char** argv){
  scanf("%d %d", &N, &M);
  
  for(int i = 1; i <= N; i++){
    dq.push_back(i); // 큐 초기화
  }

  int A[M];
  for(int i = 0; i < M; i++){
    scanf("%d", &A[i]);
  }

  for(int i = 0; i < M; i++){
    int left = 0, right = 0;

    while(1){
      if(dq.front() == A[i]){
        break;
      }
      dq.push_back(dq.front()); // 앞의 값 뒤로 넘기기
      dq.pop_front();
      left++;
    }

    for(int j = 0; j < left; j++){
      dq.push_front(dq.back());
      dq.pop_back(); // 원래대로 돌리기
    }

    right = dq.size() - left; // right 값은 자동으로 구할 수 있다.

    if(left < right){
      cnt += left;

      while(left--){
        dq.push_back(dq.front()); // 앞의 값 뒤로 넘기기
        dq.pop_front();
      }
      dq.pop_front();
    } else {
      cnt += right;

      while(right--){
        dq.push_front(dq.back()); // 뒤의 값 앞으로 넘기기
        dq.pop_back();
      }
      dq.pop_front();
    }
  }
  
  printf("%d", cnt);
  return 0;
}