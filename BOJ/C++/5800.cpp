#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K, N;
int x;
int main(int argc, char **argv){
  scanf("%d",&K);

  for(int i=0; i<K; i++){
    int gap = -1; // 오름차순이므로 이전수 - 현재수 < 0 일 수 없다.
    vector<int> v;
    
    scanf("%d",&N);
    
    for(int j=0; j<N; j++){
      scanf("%d", &x);
      v.push_back(x);
    }
    sort(v.begin(),v.end(), greater<>()); // 내림차순 정렬

    for(int j=0; j<N-1; j++){
      if(gap < v[j] - v[j+1]){
        gap = v[j] - v[j+1];
      }
    }

    printf("Class %d\n", i + 1);
    printf("Max %d, Min %d, Largest gap %d\n", v[0], v[N-1], gap);
  }

  return 0;
}