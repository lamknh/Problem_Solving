#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N, M;
string str;
map<string, int> m; // map 찾기 O(logN) - string으로 int 찾기
vector<string> v; // int로 string 찾기
int main(int argc, char** argv){
  ios::sync_with_stdio(false);
  cin.tie(NULL); // cin, cout 시간 줄이기

  cin >> N >> M;

  for(int i=1; i<=N; i++){
    cin >> str;
    m.insert(make_pair(str, i));
    v.push_back(str);
  }

  for(int i=0; i<M; i++){
    cin >> str;
    int n = atoi(str.c_str());
    if(n){ // 숫자인지 판별 - 0이면 문자열 or 0 (도감은 1부터 시작)
      cout << "!" << v[n-1] << "\n";
    } else {
      cout << m[str] << "\n";
    }
  }

  return 0;
}