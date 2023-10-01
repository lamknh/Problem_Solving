#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int N, L;
int h;

deque<int> d;

int main(){
  scanf("%d %d",&N,&L);

  for(int i=0; i<N; i++){
    scanf("%d", &h);
    d.push_back(h);
  }

  sort(d.begin(),d.end()); // sort

  while(!d.empty()){
    // printf("%d ", d.front());
    if(d.front() <= L){
      d.pop_front();
      L++; // 뱀 길이 늘이기
    } else {
      break;
    }
  }

  printf("%d", L);

  return 0;
}