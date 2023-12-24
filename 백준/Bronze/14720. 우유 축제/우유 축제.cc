#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int milk[3] = {0, 1, 2};
    vector<int> store;
    int N, result = 0, target = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        store.push_back(x);
    }
    for(int i=0; i<N; i++){
        if(milk[target] == store[i]){
            result++;
            target = (target + 1) % 3;
        }
    }
    cout << result << '\n';

    return 0;
}