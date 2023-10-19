#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define MAX 1000000001
using namespace std;

int N, S[20][20];
int result = MAX, startSum = 0;
bool inStart[20];

void dfs(int index, int nextIdx)
{
    int linkSum = 0, startSum = 0;
    if (index * 2 == N)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                if (inStart[i] && inStart[j])
                    startSum += S[i][j];
                if (!inStart[i] && !inStart[j])
                    linkSum += S[i][j];
            }

        if (abs(startSum - linkSum) < result)
            result = abs(startSum - linkSum);

        return;
    }

    for (int i = nextIdx; i < N; i++)
    {
        if (inStart[i])
            continue;
        inStart[i] = true;
        dfs(index + 1, i + 1);
        inStart[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> S[i][j];

    dfs(0, 0);

    cout << result;

    return 0;
}