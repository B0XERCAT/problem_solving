#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define ll long long
#define MAX 1000000000
using namespace std;

int N, C;
vector<ll> house;

bool moreThanC(ll distance)
{
    ll cnt = 0;
    ll start = -MAX;

    for (int i = 0; i < N; i++)
    {
        if (start + distance <= house[i])
        {
            cnt++;
            start = house[i];
        }
    }

    if (cnt >= C)
        return true;
    else
        return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;

    for (int i = 0; i < N; i++)
    {
        ll x;
        cin >> x;
        house.push_back(x);
    }

    sort(house.begin(), house.end());

    ll s = 1, e = MAX;

    while (s <= e)
    {
        ll mid = (s + e) / 2;

        if (moreThanC(mid))
            s = mid + 1;
        else
            e = mid - 1;
    }

    cout << s - 1;

    return 0;
}