#include <iostream>
#include <deque> // 로봇 저장할 큐
using namespace std;

int belt[201] = {0}; // 컨베이너 벨트 1~200 || 1이면 로봇 있는 것
int A[201]; // 벨트 칸의 내구도
deque<int> q; // 로봇 위치 저장
int cnt = 0; // 현재 내구도 0인 것 개수

int N, K; // 벨트 절반, 내구도 0 개수
int main(){
  scanf("%d %d", &N, &K);

  for(int i=1; i<=N*2; i++){
    scanf("%d", &A[i]); // 내구도 값 입력받기
  }

  while(cnt < K){
    // 1. 벨트가 로봇과 함께 한 칸 회전
    for(int i=1; i<=N*2; i++){
      if(i == N*2){
        belt[1] = belt[N*2]; // N*2+1 1로 돌아감
      } else {
        belt[i+1] = belt[i]; // 벨트 1칸씩 이동
      }
    }

    while(!q.empty()){ // 로봇이 존재할 때
      int robot = q.front();
      q.pop_front();

      // 2. 가장 먼저 벨트에 올라간 로봇부터 한 칸 이동할 수 있으면 한 칸 이동
      // 이동하려는 칸 위에 로봇 없고 내구도 1 이상
      if(belt[robot + 1] != 1 && A[robot + 1] > 0){
        // 로봇 위치 이동
        belt[robot] = 0;
        belt[robot + 1] = 1;
        q.push_front(robot + 1);
        
        // 이동한 칸 내구도 -1
        A[robot + 1]--;
      }
    }
    //3. 올리는 위치(1) 칸 내구도 0 아니라면 로봇 올리기
    // 올리는 위치에 로봇이 없을 경우도 추가
    if(A[1] > 0 && belt[1] == 0){
      belt[1]++; //로봇 올리기
      q.push_back(1);
    }

    //4. 내구도 0인 칸 수 K개 이상이면 종료
    int tmp = 0;
    for(int i=1; i<=N*2; i++){
      if(A[i] == 0){
        tmp++;
      }
    }
    if(tmp >= K){
      cnt = tmp;
    }
  }

  printf("%d", cnt);

  return 0;
}