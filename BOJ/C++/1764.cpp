#include <iostream>
#include <vector>
#include <algorithm> // 이진 탐색
using namespace std;

int N, M;
vector<string> v;
vector<string> ans;
int main(int argc, char** argv){
  std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

  string name;
  
  cin >> N >> M;
  for(int i=0; i<N; i++){
    cin >> name;
    v.push_back(name);
  }

  sort(v.begin(), v.end()); // 첫번째 입력받은 이름 정렬

  for(int i=0; i<M; i++){
    cin >> name;

    if(binary_search(v.begin(), v.end(), name)){
      ans.push_back(name);
    }
  }

  sort(ans.begin(), ans.end()); // 정답 벡터 한번 더 정렬 - 사전순 출력

  cout << ans.size() << "\n";
  for(int i=0; i<ans.size(); i++){
    cout << ans[i] << "\n";
  }

  return 0;
}