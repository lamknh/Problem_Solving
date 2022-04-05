#include <iostream>
using namespace std;

long long value[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
string color[10] = {"black", "brown", "red", "orange", "yellow", "green", 
  "blue", "violet", "grey", "white"};

long long ans = 0;
string str1, str2, str3;
int main(int argc, char **argv){
  cin >> str1 >> str2 >> str3;

  long long num1, num2, num3;

  for(int i = 0; i < 10; i++){
    if(str1 == color[i]){
      num1 = i;
    }
    if(str2 == color[i]){
      num2 = i;
    }
    if(str3 == color[i]){
      num3 = value[i];
    }
  }

  ans = (num1 * 10 + num2) * num3;

  cout << ans;

  return 0;
}