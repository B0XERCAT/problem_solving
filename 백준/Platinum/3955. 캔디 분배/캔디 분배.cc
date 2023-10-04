#include <iostream>
#define ll long long
#define MAX 1000000000
using namespace std;

ll EEA(ll a, ll b)
{
    ll r1 = a, r2 = b, t1 = 0, t2 = 1, r, t, q;
    while (r2)
    {
        q = r1 / r2;
        r = r1 % r2;
        if (r == 0)
            break;
        r1 = r2;
        r2 = r;
        t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }
    t = t2;
    if (t < 0)
        return t + a;
    else
        return t;
}

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    ll K, C;
    cin >> T;
    while (T--)
    {
        cin >> K >> C;
        if (C == 1)
        {
            if (K + 1 > MAX)
                cout << "IMPOSSIBLE\n";
            else
                cout << K + 1 << "\n";
        }
        else if (K == 1)
            cout << "1\n";
        else if (EEA(K, C) > MAX || gcd(K, C) != 1)
            cout << "IMPOSSIBLE\n";
        else
            cout << EEA(K, C) << "\n";
    }
    return 0;
}
