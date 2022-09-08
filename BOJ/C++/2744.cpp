#include <iostream>

using namespace std;

string s;
int main(int argc, char** argv){
  cin >> s;

  for(int i = 0; i < s.size(); i++){
    if(s[i] < 'a'){
      cout << char(s[i] - 'A' + 'a');
    } else {
      cout << char(s[i] - 'a' + 'A');
    }
  }

  return 0;
}