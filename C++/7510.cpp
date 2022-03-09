#include <iostream>

int N;
int a, b, c;
int main(int argc, char** argv){
  scanf("%d", &N);

  for(int i=1; i<=N; i++){
    scanf("%d %d %d", &a, &b, &c);

    printf("Scenario #%d:\n", i);
    if((a <= b && b <= c) || (b <= a && a <= c)){
      if(a*a + b*b == c*c){
        printf("yes\n");
      } else {
        printf("no\n");
      }
    } else if((a <= c && c <= b) || (c <= a && a <= b)){
      if(a*a + c*c == b*b){
        printf("yes\n");
      } else {
        printf("no\n");
      }
    } else {
      if(c*c + b*b == a*a){
        printf("yes\n");
      } else {
        printf("no\n");
      }
    }
    printf("\n");
  }

  return 0;
}