#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char **argv){
    int arr[3] = {0};

    for(int i=0; i<3; i++){
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + 3);

    for(int i=0; i<3; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}