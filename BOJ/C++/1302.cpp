#include <iostream>
#include <map> // hash
#include <string>

using namespace std;

int main(){
  int n;
  int maxNum = 0;
  string name;
  map<string, int> m; // key 값 오름차순 정렬

  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> name; // 이름 받아오기
    m[name]++; // 수 세기
    maxNum = max(maxNum, m[name]);
  }

  

  for(auto iter : m){
    if(iter.second == maxNum){
      cout << iter.first;
      return 0;
    }
  }

  return 0;
}