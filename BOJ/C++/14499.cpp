#include <iostream>
#include <vector>

using namespace std;

int N, M, x, y, K;

int map[21][21];
vector<int> dice(7); // 주사위에 써 있는 수 - 배열 값 직접적으로 바꾸려면 vector 이용

// 지도 이동
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

int r = 0, c = 0; // 현재 주사위 위치

void move(int dir){
  switch(dir){
    // 동
    case 1 :
      dice = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]}; // 배열은 {}
      break;
    // 서
    case 2 :
      dice = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
      break;
    // 북
    case 3 :
      dice = {0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2]};
      break;
    // 남
    case 4 :
      dice = {0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5]};
      break;
  }
}

int main(){
  scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);

  r = y;
  c = x;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      scanf("%d", &map[i][j]); // 지도 입력받기
    }
  }

  int k;
  // 이동하는 명령어 K개 - 동 1 서 2 북 3 남 4
  for(int i = 0; i < K; i++){
    scanf("%d", &k);

    // 주사위 이동
    int nr = r + dx[k];
    int nc = c + dy[k];

    // 지도 밖을 벗어나는 경우
    if(nr < 0 || nr >= M || nc < 0 || nc >= N){
      continue;
    }
    // 벗어나지 않는 경우
    r = nr; c = nc;

    move(k);

    // 칸 0 : 주사위 바닥면 수 칸에 복사
    // y가 배열 앞에 x가 뒤에
    if(map[c][r] == 0){
      map[c][r] = dice[6];
    } else {
      // 칸 숫자 : 칸의 수 주사위에 복사
      dice[6] = map[c][r];
      // 칸 수 0 됨
      map[c][r] = 0;
    }
    // 모든 경우에 출력 x 다이스가 이동한 경우에만
    printf("%d\n", dice[1]); // 다이스 제일 윗면 출력
  }

  return 0;
}