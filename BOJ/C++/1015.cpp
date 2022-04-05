#include <iostream>
#include <utility> // pair
#include <algorithm> // sort
#include <vector>
using namespace std;

int N, x;
vector<pair<int, int> > sv;
int main(int argc, char** argv){
  scanf("%d", &N);

  for(int i=0; i<N; i++){
    scanf("%d", &x);
    sv.push_back(make_pair(x, i)); // 값, 인덱스 - 원래 순서 기억
  }

  sort(sv.begin(), sv.end()); // 값 기준 정렬

  vector<int> v(N);
  for(int i=0; i<N; i++){
    v[sv[i].second] = i; // 정렬된 인덱스 할당
  }

  for(int i=0; i<N; i++){
    printf("%d ", v[i]);
  }

  return 0;
}