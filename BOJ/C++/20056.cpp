#include <iostream>
#include <vector>

using namespace std;

struct fireball{
  int x, y;
  int m;
  int d;
  int s;
};

vector<fireball> map[51][51];

int N, M, K;
int r, c, m, d, s; // (r, c), 질량, 방향, 속력
int ans = 0;

// 격자 방향
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int main(){
  scanf("%d %d %d", &N, &M, &K);

  for(int i = 0; i < M; i++){
    scanf("%d %d %d %d %d", &r, &c, &m, &d, &s);

    // s만큼 이동
    for(int j = 0; j < s; j++){
      // d 방향으로 이동
      r += dx[d];
      c += dy[d];

      if(r <= 0){
        r = N;
      } else if(c <= 0){
        c = N;
      } else if(r > N){
        r = 1;
      } else if(c > N){
        c = 1;
      }
    }

    map[r][c].push_back({r, c, m, d, s}); // 2차원 벡터에 할당시
  }

  for(int y = 1; y <= N; y++) {
    for(int x = 1; x <= N; x++){
      printf("%lu", map[x][y].size());
    }
    printf("\n");
  }
  printf("초기-------\n");

  // 이동이 모두 끝난 뒤, 2개 이상의 파이어볼이 있는 칸에서는 다음과 같은 일이 일어난다.
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      // 2개 이상의 파이어볼
      if(map[i][j].size() >= 2){
        int newm = 0, news; // 새 질량, 속력, 방향
        bool oddFlag = false, evenFlag = false;

        for(int k = 0; k < map[i][j].size(); k++){
          newm += map[i][j][k].m; // k 빼먹지 말기
          news += map[i][j][k].s;
          
          // 짝수
          if(map[i][j][k].m % 2 == 0){
            evenFlag = true;
          } else {
            oddFlag = true;
          }
        }

        newm /= 5;
        news /= map[i][j].size();

        // 질량이 0인 파이어볼은 소멸되어 없어진다.
        if(newm == 0){
          continue;
        }

        // 모두 홀수이거나 모두 짝수이면, 방향은 0, 2, 4, 6이 되고, 그렇지 않으면 1, 3, 5, 7
        if((evenFlag && !oddFlag) || (oddFlag && !evenFlag)){
          map[i][j].push_back({i, j, newm, 0, news});
          map[i][j].push_back({i, j, newm, 2, news});
          map[i][j].push_back({i, j, newm, 4, news});
          map[i][j].push_back({i, j, newm, 6, news});
        } else {
          map[i][j].push_back({i, j, newm, 1, news});
          map[i][j].push_back({i, j, newm, 3, news});
          map[i][j].push_back({i, j, newm, 5, news});
          map[i][j].push_back({i, j, newm, 7, news});
        }

        for(int y = 1; y <= N; y++) {
          for(int x = 1; x <= N; x++){
            printf("%lu", map[y][x].size());
          }
          printf("\n");
        }
        printf("-------\n");
      }
    }
  }

  // K번 명령한 후, 남아있는 파이어볼 질량의 합
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++){
      if(map[i][j].size() > 0){
        for(int k = 0; i < map[i][j].size(); k++){
          ans += map[i][j][k].m;
          cout << map[i][j][k].m;
        }
      }
    }
  }

  printf("%d", ans);

  return 0;
}