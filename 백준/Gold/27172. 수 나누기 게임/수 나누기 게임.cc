#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> card(N);
    vector<int> result(MAX, 0);
    vector<bool> inGame(MAX, false);
    
    for (int i = 0; i < N; i++)
    {
        cin >> card[i];
        inGame[card[i]] = true;
    }

    for (int i = 0; i < N; i++)
    {
        int curNum = card[i];
        for (int oppNum = curNum * 2; oppNum <= 1000000; oppNum += curNum)
        {
            if (inGame[oppNum]){
                result[curNum]++;
                result[oppNum]--;
            }
        }
    }

    for (int i = 0; i < N; i++)
        cout << result[card[i]] << " ";

    return 0;
}