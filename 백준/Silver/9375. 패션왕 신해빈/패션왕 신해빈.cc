#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T, n;
    char value[21], key[21];
    cin >> T;
    
    for(int i=0; i<T; i++){
        map<string, int> Map; //Map 선언
        int mult = 1;
        cin >> n;
        
        for(int j=0; j<n; j++){
            cin >> value >> key;
            if(Map.find(key) == Map.end()) //key의 존재여부 확인
                Map.insert({key, 1});
            else
                Map[key]++;
        }
        
        map<string, int>::iterator iter; //Map 조회
        
        for(iter = Map.begin(); iter != Map.end(); iter++)
            mult *= (iter->second)+1;
        
        cout << mult - 1 << endl;
    }

    return 0;
}