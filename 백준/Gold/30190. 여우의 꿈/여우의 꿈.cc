#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#define ll long long
#define MAX 1000002
#define MOD 1000000007

using namespace std;

ll res = 0;
ll dp[MAX];
int goal[MAX], N, K;

ll recPower(ll a, ll x)
{
    if (x == 0)
        return 1;
    if (x == 1)
        return a;
    if (dp[x] != -1)
        return dp[x];

    ll half = recPower(a, x / 2) % MOD;

    if (x % 2 == 0)
        dp[x] = (half * half) % MOD;

    else
        dp[x] = (((half * half) % MOD) * a) % MOD;

    return dp[x];
}

void hanoi(int from, int to, int height)
{
    if (height == 0)
    {
        cout << res % MOD;
        exit(0);
    }
    if (from != to)
    {
        res += recPower(2, height - 1);
        res %= MOD;
        hanoi(6 - (from + to), goal[height - 1], height - 1);
    }
    else
        hanoi(from, goal[height - 1], height - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> goal[i];

    hanoi(K, goal[N], N);

    return 0;
}
