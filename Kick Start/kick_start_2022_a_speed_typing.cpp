#include <iostream>
#include <queue>
using namespace std;

int T;
string I, P;
int main(int argc, char** argv){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> T;

  for(int i = 1; i <= T; i++){
    long long ans = 0;
    queue<char> q; // I 값 하나씩 저장
    cin >> I >> P;

    for(int j = 0; j < I.size(); j++){
      q.push(I[j]); // I 값 큐에 저장
    }

    for(int j = 0; j < P.size(); j++){
      int iChar = q.front(); //ASCII
      if(iChar == P[j]){
        q.pop(); // I값과 같은 경우
      } else {
        ans++; // delete 해야하는 문자
      }
    }

    if(q.empty()){ // I값 만들 수 있는 경우
      cout << "Case #" << i << ": " << ans << "\n";
    } else {
      cout << "Case #" << i << ": " << "IMPOSSIBLE\n";
    }
  }

  return 0;
}