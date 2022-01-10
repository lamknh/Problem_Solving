#include <iostream>
#include <list> // linked list

using namespace std;

int main(int argc, char **argv){
    string str; int M;
    list<char> l;
    list<char>::iterator cursor; // index

    cin >> str;
    scanf("%d", &M);

    for(int i=0; i<str.size(); i++){
		l.push_back(str.at(i)); // 이렇게 list에 string char로 하나씩 입력받을 수 있다.
	}
	
	cursor = l.end(); // list의 끝을 가리키게 함

	for(int i=0; i<M; i++){
		char c;
        cin >> c; // scanf로 c 입력받으면 갑자기 멈추네 \n 때문인가
		
		if(c=='L'){
            if(cursor!=l.begin()){ // list 시작
                cursor--;
            }
        } else if(c=='D'){
            if(cursor!=l.end()){ // list 끝
                cursor++;
            }
        } else if(c=='B'){
            if(cursor!=l.begin()){
                cursor--; // 전 문자 삭제이므로 전 문자를 가리키게 해야함
                cursor = l.erase(cursor); // list 삭제 -> cursor의 주소 반환(저장해서 갱신해야)
            }
        } else if(c=='P'){
            char x;
            cin >> x;
            l.insert(cursor,x); // list 삽입
        }
    }

    for (cursor = l.begin(); cursor!=l.end(); cursor++) {
        cout << *cursor; // 값 출력
    }

    return 0;
}