#include <iostream>
#include <cmath> // abs
#include <algorithm> // min
using namespace std;

string S, F;
int T;

int main(int argc, char** argv){
  std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

  cin >> T; // 횟수

  for(int i=1; i<=T; i++){
    int num = 0;
    int minNum = 0;

    cin >> S >> F; // string 2개 입력받기

    for(int j=0; j<S.length(); j++){
      int a = S[j] - 'a'; // ASCII
      int tmp = 99999; // multiple 비교
      for(int k = 0; k<F.length(); k++){
        int b = F[k] - 'a'; // ASCII
        tmp = min(min(abs(a - b), (b - a + 26) % 26), tmp); // 정순, 역순
      }
      num += tmp;
    }

    cout << "Case #" << i <<": " << num << endl;
  }


  return 0;
}