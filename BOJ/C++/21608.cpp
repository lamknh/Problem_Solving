#include <iostream>
#include <vector>
#include <algorithm> // sort

using namespace std;

// 학생 정보
struct STUDENT{
  int num; // 학생 번호
  int fav[4]; // 학생이 좋아하는 친구
};

struct POSITION{
  int x, y;
  int blanks;
  int friends;
};

int map[21][21]; // 자리
vector<STUDENT> st(401); // 학생 정보

int N;
int ans = 0;

// 인접 좌표
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

// 만족도 - 굳이 pow 쓰지말자
int score[5] = {0, 1, 10, 100, 1000};

int main(int argc, char** argv){
  scanf("%d", &N);

  for(int i = 1; i <= N * N; i++){
    scanf("%d", &st[i].num); // 학생 순서 입력받기
    for(int j = 0; j < 4; j++){
      scanf("%d", &st[i].fav[j]); // 좋아하는 학생 입력받기
    }
  }

  // 학생 앉히기
  for(int i = 1; i <= N * N; i++){
    STUDENT student = st[i];
    vector<POSITION> pos(5); // 총 주위 4칸 탐색

    int bmax = 0, fmax = 0;
    
    for(int j = 1; j <= N; j++){
      for(int k = 1; k <= N; k++){
        // 1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정함
        // 비어있지 않으면 패스 - if문 너무 많이 써서 따로 빼려고 이렇게 작성
        if(map[j][k] != 0){
          continue;
        }

        int bcnt = 0, fcnt = 0;
        
        // 좌표 방향 설정 idx값은 이렇게 설정하는게 더 확인하기 쉽다.
        for(int dir = 0; dir < 4; dir++){
          int nx = j + dx[dir];
          int ny = k + dy[dir];

          // 보드 벗어나는 좌표
          if(nx < 1 || ny < 1 || nx > N || ny > N){
            continue;
          }

          // 빈 칸인 경우와 친구의 수를 한 번에 센다!
          // 빈 칸인 경우
          if(map[nx][ny] == 0){
            bcnt++;
          } else if(map[nx][ny] == student.fav[0] || map[nx][ny] == student.fav[1]
            || map[nx][ny] == student.fav[2] || map[nx][ny] == student.fav[3]){
            fcnt++;
          }
        }

        // 친구 많은 칸을 넣음
        if(fcnt > fmax){
          pos.clear(); // 벡터 초기화 - 친구 많으면 후보 요소 없음
          pos.push_back({j, k, fcnt, bcnt});
          // 후보칸의 요소 저장
          fmax = fcnt;
          bmax = bcnt;
          continue;
        } else if(fcnt == fmax){
          // 2. 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
          if(bcnt >= bmax){
            pos.clear();
            pos.push_back({j, k, fcnt, bcnt});
            bmax = bcnt;
          } else {
            // 3. 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
            pos.push_back({j, k, fcnt, bcnt});
          }
        }
      }

      // for(int i = 1; i <= N; i++){
      //   for(int j = 1; j <= N; j++){
      //     printf("%d", map[i][j]);
      //   }
      //   printf("\n");
      // }
      // printf("------\n");
    }
    // 학생 배치
    map[pos[0].x][pos[0].y] = student.num;
  }

  // 학생 만족도 총 합
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      int cnt = 0;
      // 상하좌우 탐색
      for(int dir = 0; dir < 4; dir++){
        int nx = i + dx[dir];
        int ny = j + dy[dir];

        if(nx < 1 || ny < 1 || nx > N || ny > N){
          continue;
        }

        for(int k = 0; k < st.size(); k++){
          if(st[k].num == map[i][j]){
            if(map[nx][ny] == st[k].fav[0] || map[nx][ny] == st[k].fav[1]
              || map[nx][ny] == st[k].fav[2] || map[nx][ny] == st[k].fav[3]){
              cnt++;
            }
          }
        }
      }
      ans += score[cnt];
    }
  }

  // for(int i = 1; i <= N; i++){
  //   for(int j = 1; j <= N; j++){
  //     printf("%d", map[i][j]);
  //   }
  //   printf("\n");
  // }

  printf("%d", ans);

  return 0;
}