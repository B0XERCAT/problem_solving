#include <iostream>
using namespace std;

int dp[10001] = {1};
int coins[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> coins[i];

    for (int i = 0; i < n; i++)
        for (int j = coins[i]; j <= k; j++)
            dp[j] += dp[j - coins[i]];

    cout << dp[k];

    return 0;
}