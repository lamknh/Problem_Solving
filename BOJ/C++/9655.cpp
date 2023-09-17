#include <iostream>
#include <string>

using namespace std;

int N;
int winner = 0;

int main(){
  scanf("%d", &N);

  while (N != 1){
    if (N-3 > 0){
      N -= 3;
    } else if (N-1 > 0){
      N -= 1;
    }
    winner++;
  }

  if(winner % 2 == 0){
    cout << "SK";
  } else {
    cout << "CY";
  }
  return 0;
}