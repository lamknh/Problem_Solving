#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> b(5, vector<int>(8)); // 톱니바퀴 상태 저장 - 2차원 벡터 선언법
int K;
int n, d; // 톱니바퀴 번호, 방향

// 이동 배열 저장
void move(int n, int d){
  // 시계 방향
  if(d == 1){
    b[n] = {b[n][7], b[n][0], b[n][1], b[n][2], b[n][3], b[n][4], b[n][5], b[n][6]};
  } else if(d == -1){
    // 반시계 방향
    b[n] = {b[n][1], b[n][2], b[n][3], b[n][4], b[n][5], b[n][6], b[n][7], b[n][0]};
  }
}

int reverse(int d){
  if(d == 1){
    return -1;
  } else {
    return 1;
  }
}

void turn(int n, int d){
  int nd = reverse(d);
  if(n == 1){
    if(b[1][2] != b[2][6]){
      if(b[2][2] != b[3][6]){
        if(b[3][2] != b[4][6]){
          move(1, d);
          move(2, nd);
          move(3, d);
          move(4, nd);
        } else {
          move(1, d);
          move(2, nd);
          move(3, d);
        }
      } else {
        move(1, d);
        move(2, nd);
      }
    } else {
      move(1, d);
    }
  } else if(n == 4){
    if(b[3][2] != b[4][6]){
      if(b[2][2] != b[3][6]){
        if(b[1][2] != b[2][6]){
          move(4, d);
          move(3, nd);
          move(2, d);
          move(1, nd);
        } else {
          move(4, d);
          move(3, nd);
          move(2, d);
        }
      } else {
        move(4, d);
        move(3, nd);
      }
    } else {
      move(4, d);
    }
  } else if(n == 2) {
    if(b[1][2] != b[2][6]){
      move(1, nd);
    }

    if(b[2][2] != b[3][6]){
      if(b[3][2] != b[4][6]){
        move(2, d);
        move(3, nd);
        move(4, d);
      } else {
        move(2, d);
        move(3, nd);
      }
    } else {
      move(2, d);
    }
  } else if(n == 3) {
    if(b[3][2] != b[4][6]){
      move(4, nd);
    }

    if(b[2][2] != b[3][6]){
      if(b[1][2] != b[2][6]){
        move(3, d);
        move(2, nd);
        move(1, d);
      } else {
        move(3, d);
        move(2, nd);
      }
    } else {
      move(3, d);
    }
  }
}

int main(int argc, char** argv){
  for(int i = 1; i <= 4; i++){
    for(int j = 0; j < 8; j++){
      // N은 0, S는 1
      scanf("%1d", &b[i][j]);
    }
  }

  scanf("%d", &K);

  for(int i = 0; i < K; i++){
    scanf("%d %d", &n, &d);
    turn(n, d);
  }

  printf("%d", b[1][0] + (2 * b[2][0]) + (4 * b[3][0]) + (8 * b[4][0]));

  return 0;
}