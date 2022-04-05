#include <iostream>
#include <queue>

using namespace std;

int main(void){
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL); // printf scanf와 cin cout 같이 쓰면 안됨

    int N;
    string str;
    queue<int> queue;

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> str;
        if(str == "push"){
            int n;
            cin >> n;
            queue.push(n);
        } else if(str == "pop"){
            if(queue.empty()){
                cout << -1 << "\n";
            } else {
                cout << queue.front() << "\n";
                queue.pop();
            }
        } else if(str == "size"){
            cout << queue.size() << "\n";
        } else if(str == "empty"){
            if(queue.empty()){
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if(str == "front"){
            if(queue.empty()){
                cout << -1 << "\n";
            } else {
                cout << queue.front() << "\n";
            }
        } else if(str == "back"){
            if(queue.empty()){
                cout << -1 << "\n";
            } else {
                cout << queue.back() << "\n";
            }
        }
    }

    return 0;
}