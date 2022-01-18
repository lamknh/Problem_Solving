#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N, x, sum = 0;
int visit[8001] = {0};
int main(int argc, char **argv){
    scanf("%d",&N);
    vector<int> v;

    for(int i=0; i<N; i++){
        scanf("%d",&x);
        v.push_back(x);
        visit[v[i] + 4000]++; //개수 세기
        sum += x;
    }

    sort(v.begin(),v.end()); //정렬

    printf("%d\n", (int)round((double)sum/N)); // 산술평균 - round 반올림
    printf("%d\n", v[N/2]); //중앙값

    int idx, max = 0;
    for (int i = 0; i < 8001; i++) // -4000 ~ 4000
	{
		if (visit[i] > max){ // 최빈값 찾기
			max = visit[i]; // 비교값
			idx = i; // 최빈값 저장
		}
	}
	
	for (int i = idx + 1; i < 8001; i++) { // 최빈값 다음부터 search
		if ((visit[i] == max)){ // 최빈값 또 있을 경우
			idx = i; // 최빈값 저장
			break;
		}
	}

    printf("%d\n", idx - 4000);
    printf("%d\n", v[v.size() -1] - v[0]); // 범위

    return 0;
}