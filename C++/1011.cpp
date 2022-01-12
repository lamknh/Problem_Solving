#include <iostream>
#include <cmath>

int T, x, y;
long long len;
int cnt, lenUp, lenDown;
int main(int argc, char **argv){
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d %d", &x, &y);
        len = y - x; // 거리
        
        lenUp = ceil(sqrt(len));
        lenDown = lenUp -1;
        
        if(len <= pow(lenDown, 2) + lenDown){
            cnt = lenDown * 2;
        } else {
            cnt = lenUp * 2 - 1;
        }
        printf("%d\n", cnt);
    }

    return 0;
}