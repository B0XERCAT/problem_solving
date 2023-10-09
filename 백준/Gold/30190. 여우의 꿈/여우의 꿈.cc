#include <iostream>

#define ll long long
#define MAX 1000002
#define MOD 1000000007

using namespace std;

ll res = 0;
ll power2[MAX];
int goal[MAX], N, K;

void hanoi(int from, int to, int height)
{
    if (height == 0)
    {
        cout << res % MOD;
        exit(0);
    }
    if (from != to)
    {
        res += power2[height - 1];
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

    power2[0] = 1;
    power2[1] = 2;

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        cin >> goal[i];
        power2[i + 1] = power2[i] * 2 % MOD;
    }

    hanoi(K, goal[N], N);

    return 0;
}
