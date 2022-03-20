#include <iostream>
#include <utility> //pair
using namespace std;

int N, M; // 세로, 가로
int r, c, d; // 좌표, 방향 : 북0 동1 남2 서3
int map[51][51]; // 빈칸 : 0, 벽 1, 청소됨 2

int dx[4] = {-1, 0, 1, 0}; // 왼쪽 방향으로 회전
int dy[4] = {0, 1, 0, -1};

int cnt = 0; // 청소한 칸 수
bool back; // 뒤로 갔는지 여부 - false면 이동 불가, true면 이동

int main(int argc, char** argv){
  scanf("%d %d", &N, &M);
  scanf("%d %d %d", &r, &c, &d);

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      scanf("%d", &map[i][j]); // map 입력받기
    }
  }

  while(1){
    if(map[r][c] == 0){ // 빈칸인 경우
      map[r][c] = 2; // 청소
      cnt++;
    }

    back = false; // 돌아가기 초기화

    for(int i=0; i<4; i++){ // 4방향 탐색
      d = (d+3) % 4; // 방향 전환
      int nx = r + dx[d];
      int ny = c + dy[d]; // 주변 좌표값 보기 위해 이동

      if(map[nx][ny] == 0){ // 청소하지 않은 공간 있을 때
        back = true; // 뒤로 돌아가기 성공
        r = nx;
        c = ny; // 이동
        break;
      }
    }

    if(!back){ // 네 방향 모두 청소 x
      int nd = (d+2) % 4;
      int nx = r + dx[nd];
      int ny = c + dy[nd]; // 방향 유지한 후 반대로 이동
      if(map[nx][ny] == 1){ // 뒤에 벽이 있을 경우
        break; // 종료
      }
      // 벽이 아닌 경우
      r = nx;
      c = ny; // 뒤로 이동
    }
  }

  printf("%d", cnt);

  return 0;
}