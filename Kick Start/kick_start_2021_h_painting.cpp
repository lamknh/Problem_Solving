#include <iostream>
#include <vector>
using namespace std;

int T, N;
vector<int> R;
vector<int> Y;
vector<int> B;
string P;
int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  cin >> T;

  for(int i = 1; i <= T; i++){
    int cnt = 0;
    R.clear(); Y.clear(); B.clear(); // 벡터 지우기

    bool flag; // true면 현재 1
    cin >> N >> P;

    for(int j = 0; j < N; j++){
      // 1이 있으면 해당 색의 칠이 필요한 것
      if(P[j] == 'U'){
        R.push_back(0);
        Y.push_back(0);
        B.push_back(0);
      } else if(P[j] == 'R'){
        R.push_back(1);
        Y.push_back(0);
        B.push_back(0);
      } else if(P[j] == 'Y'){
        R.push_back(0);
        Y.push_back(1);
        B.push_back(0);
      } else if(P[j] == 'B'){
        R.push_back(0);
        Y.push_back(0);
        B.push_back(1);
      } else if(P[j] == 'O'){
        R.push_back(1);
        Y.push_back(1);
        B.push_back(0);
      } else if(P[j] == 'P'){
        R.push_back(1);
        Y.push_back(0);
        B.push_back(1);
      } else if(P[j] == 'G'){
        R.push_back(0);
        Y.push_back(1);
        B.push_back(1);
      }  else if(P[j] == 'A'){
        R.push_back(1);
        Y.push_back(1);
        B.push_back(1);
      }
    }

    // for(int j = 0; j < N; j++){
    //   printf("%d ", Y[j]);
    // }
    // printf("\n");
    // for(int j = 0; j < N; j++){
    //   printf("%d ", B[j]);
    // }

    if(R[0] == 1){
      flag = true;
      cnt++;
    } else {
      flag = false;
    }

    for(int j = 0; j < N; j++){
      if(R[j] == 0 && flag){
        flag = false;
      } else if(R[j] == 1 && !flag){
        flag = true;
        cnt++;
      }
    }

    if(Y[0] == 1){
      flag = true;
      cnt++;
    } else {
      flag = false;
    }

    for(int j = 0; j < N; j++){
      if(Y[j] == 0 && flag){
        flag = false;
      } else if(Y[j] == 1 && !flag){
        flag = true;
        cnt++;
      }
    }

    if(B[0] == 1){
      flag = true;
      cnt++;
    } else {
      flag = false;
    }

    for(int j = 0; j < N; j++){
      if(B[j] == 0 && flag){
        flag = false;
      } else if(B[j] == 1 && !flag){
        flag = true;
        cnt++;
      }
    }

    printf("Case #%d: %d\n", i, cnt);
  }

  return 0;
}