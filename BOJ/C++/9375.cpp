#include <iostream>
#include <map>

using namespace std;

int T, n, ans;
string name, type;

int main(){
  cin >> T;

  for(int i=0; i<T; i++){
    ans = 0; // 초기화
    map<string, int> m;
    cin >> n;

    if(n == 0){
      cout << 0 << "\n";
      continue; // 혜빈이가 가진 의상의 수는 0일수도 있다.
    }

    for(int j=0; j<n; j++){
      cin >> name >> type; // 이름 저장할 필요 X 같은 이름을 가진 의상 존재 X
      m[type]++; // 수 세기 - map insert되면 0부터 시작
    }

    for(auto iter : m){
      if(ans == 0){
        ans = iter.second + 1;
      } else {
        ans *= (iter.second + 1);
      }
    }

    cout << ans - 1 << "\n";
  }

  return 0;
}