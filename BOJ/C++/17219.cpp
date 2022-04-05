#include <iostream>
#include <map>
using namespace std;

int N, M;
map<string, string> m;
string str, str1, str2;
int main(int argc, char** argv){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;

  for(int i=0; i<N; i++){
    cin >> str1 >> str2;
    m.insert({str1, str2});
  }

  for(int i=0; i<M; i++){
    cin >> str;
    cout << m[str] << "\n";
  }

  return 0;
}