#include <iostream>
#include <deque> // 로봇 저장할 덱
using namespace std;

deque<int> belt; // 컨베이너 벨트 || 1이면 로봇 있는 것
deque<int> A; // 벨트 칸의 내구도
int cnt = 0; // 현재 내구도 0인 것 개수
int stage = 0; // 몇단계 진행중인지

int N, K; // 벨트 절반, 내구도 0 개수
int main(){
  scanf("%d %d", &N, &K);

  int x;
  for(int i=0; i<N*2; i++){
    scanf("%d", &x); // 내구도 값 입력받기
    A.push_back(x);
    belt.push_back(0);
  }

  while(cnt < K){
    // 1. 벨트가 로봇과 함께 한 칸 회전
    // 내구도도 함께 회전시킨다.
    A.push_front(A.back());
    A.pop_back();
    belt.push_front(belt.back());
    belt.pop_back();

    // N번째 칸에 로봇 있으면 로봇 내리기
    if(belt[N-1] == 1){
      belt[N-1] = 0;
    }

    // 2. 가장 먼저 벨트에 올라간 로봇부터 한 칸 이동할 수 있으면 한 칸 이동
    // 이동하려는 칸 위에 로봇 없고 내구도 1 이상
    for(int i = 2 * N; i >= 0; i--){
      if(belt[i] == 1 && A[i + 1] > 0 && belt[i + 1] != 1){
        // 로봇 위치 이동
        belt[i+1] = 1;
        belt[i] = 0;
        // 이동한 칸 내구도 -1
        A[i+1]--;
      }
      if(belt[N-1] == 1){
        belt[N-1] = 0;
      }
    }


    //3. 올리는 위치(1) 칸 내구도 0 아니라면 로봇 올리기
    // 올리는 위치에 로봇이 없을 경우도 추가
    if(A[0] > 0 && belt[0] == 0){
      belt[0] = 1; //로봇 올리기
      A[0]--; // 로봇 올리는 것도 내구도 닮
    }

    //4. 내구도 0인 칸 수 K개 이상이면 종료
    int tmp = 0;
    for(int i=0; i<N*2; i++){
      if(A[i] == 0){
        tmp++;
      }
    }
    if(tmp >= K){
      cnt = tmp;
    }

    stage++;
  }

  printf("%d", stage);

  return 0;
}