#include <iostream>

using namespace std;

int T;
int main(){
  scanf("%d", &T);

  for(int i = 0; i < T; i++){
    string s;
    cin >> s;
    int last = s.size();

    cout << s[0] << s[last-1] << "\n";
  }

  return 0;
}