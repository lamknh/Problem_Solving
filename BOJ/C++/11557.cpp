#include <iostream>
#include <vector>
#include <utility> //pair
using namespace std;

int T, N;
string name; int amount;
int main(int argc, char **argv){
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        scanf("%d", &N);
        vector<pair<string, int> > v;
        int max = 0; string maxName = "";

        for(int j=0; j<N; j++){
            cin >> name >> amount;
            v.push_back(make_pair(name, amount));
        }
        
        for(int j=0; j<N; j++){
            if(max < v[j].second){
                max = v[j].second;
                maxName = v[j].first;
            }
        }

        cout << maxName << "\n";
    }

    return 0;
}