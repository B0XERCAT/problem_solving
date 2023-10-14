#include <iostream>
#include <vector>
#define ll long long
using namespace std;
const ll MOD = 1000000007;

ll fact[4000002];

ll power(ll a, ll x)
{
    ll result = 1;
    while (x)
    {
        if (x % 2 == 1)
            result = result * a % MOD;
        x /= 2;
        a = a * a % MOD;
    }
    return result;
}

// 페르마 소정리를 이용한 조합
ll comb(ll n, ll k)
{
    ll a = fact[n], b = fact[n - k], c = fact[k];
    return a * power((b * c % MOD), MOD - 2) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fact[0] = 1;
    for (int i = 1; i < 4000002; i++)
        fact[i] = fact[i - 1] * i % MOD;

    int T;
    cin >> T;
    while (T--)
    {
        ll N, K;
        cin >> N >> K;
        cout << comb(N, K) << "\n";
    }

    return 0;
}
