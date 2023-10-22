#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N, K;
    cin >> N >> K;

    ll s = 1, e = N * N, result;

    while (s <= e)
    {
        ll mid = (s + e) / 2;
        ll cnt = 0;

        for (ll i = 1; i <= N; i++)
            cnt += min(N, mid / i);

        if (cnt >= K)
        {
            result = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }

    cout << result;

    return 0;
}