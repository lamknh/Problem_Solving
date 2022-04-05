    #include <iostream>
    //10870, 2747, 2748
    using namespace std;

    long long arr[91] = {0}; // 값 급속도로 커지기에 long long 사용

    void fibonacci(){
        arr[0] = 0;
        arr[1] = 1;
        
        for(int i = 2; i <= 91; i++){
            arr[i] = arr[i-2] + arr[i-1];
        }

    }

    int main(int argc, char **argv){
        int n;  
        
        scanf("%d", &n);
        fibonacci();

        cout << arr[n];

        return 0;
    }