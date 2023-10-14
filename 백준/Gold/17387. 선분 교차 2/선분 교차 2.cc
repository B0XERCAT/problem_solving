#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
#define pll pair<ll, ll>
#define X first
#define Y second
using namespace std;

ll ccw(pll A, pll B, pll C)
{
    ll temp = A.X * B.Y + B.X * C.Y + C.X * A.Y;
    temp -= B.X * A.Y + C.X * B.Y + A.X * C.Y;

    if (temp > 0)
        return 1;
    else if (temp < 0)
        return -1;
    else
        return 0;
}

bool isCrossed(pll A, pll B, pll C, pll D)
{
    ll check1 = ccw(A, B, C) * ccw(A, B, D);
    ll check2 = ccw(C, D, A) * ccw(C, D, B);

    if (check1 == 0 && check2 == 0)
    {
        if (A > B)
            swap(A, B);
        if (C > D)
            swap(C, D);
        if (A <= D && B >= C)
            return true;
    }
    else if (check1 <= 0 && check2 <= 0)
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pll> coordinate;

    for (int i = 0; i < 4; i++)
    {
        ll x, y;
        cin >> x >> y;
        coordinate.push_back({x, y});
    }

    if (isCrossed(coordinate[0], coordinate[1], coordinate[2], coordinate[3]))
        cout << 1;
    else
        cout << 0;

    return 0;
}