#include <iostream>
#include <vector>
#include <cmath>
#define INF 987654321
using namespace std;

int dp[1001][3];
int cost[1001][3];
int result = INF;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < 3; j++)
            cin >> cost[i][j];

    for (int i = 0; i < 3; i++)
    {
        dp[0][0] = INF;
        dp[0][1] = INF;
        dp[0][2] = INF;
        dp[0][i] = cost[0][i];
        for (int j = 1; j < N; j++)
        {
            dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + cost[j][0];
            dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + cost[j][1];
            dp[j][2] = min(dp[j - 1][1], dp[j - 1][0]) + cost[j][2];
        }
        if (i == 0)
            result = min(result, min(dp[N - 1][1], dp[N - 1][2]));
        else if (i == 1)
            result = min(result, min(dp[N - 1][0], dp[N - 1][2]));
        else if (i == 2)
            result = min(result, min(dp[N - 1][1], dp[N - 1][0]));
    }

    cout << result;

    return 0;
}