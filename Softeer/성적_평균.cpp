#include<iostream>


using namespace std;

int N, K;
int A, B;

int arr[1000001];

int main(int argc, char** argv)
{
	scanf("%d %d", &N, &K);

	for(int i = 1; i <= N; i++){
		scanf("%d", &arr[i]);
	}

	for(int i = 0; i < K; i++){
		scanf("%d %d", &A, &B);
		int sum = 0;
		for(int j = A; j <= B; j++){
			sum += arr[j];
		}
		printf("%.2lf\n", (double)sum / (B-A + 1));
	}

	return 0;
}