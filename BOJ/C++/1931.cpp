#include <iostream>
#include <vector>
#include <utility> // pair
#include <algorithm> // sort

using namespace std;

int N;
int maxNum = 0;
vector<pair<int, int> > v;

int main(int argc, char** argv){
  scanf("%d", &N);
  
  int a, b;
  for(int i=0; i<N; i++){
    scanf("%d %d", &a, &b);
    v.push_back({b, a}); // 종료 시간으로 기준점을 잡아야한다. 종료시간을 짧게 잡아야 많이 회의 가능
    // 시작 지점을 기준으로 정렬하면 너무 많은 반복문을 돌아야한다.
  }

  sort(v.begin(), v.end());

  int end = v[0].first; // 마지막 종료 시간  - 1번째 골라두고 시작
  int cnt = 1; // 골라지는 수 세기

  for(int i = 0; i < N; i++){
    cout << v[i].first << " " << v[i].second << endl;
  }

  for(int i = 1; i < N; i++){
    if(end <= v[i].second){
      end = v[i].first;
      cnt++;
    }
  }

  printf("%d", cnt);

  return 0;
}