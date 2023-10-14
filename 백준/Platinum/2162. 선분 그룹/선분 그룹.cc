#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define ll long long
#define pll pair<ll, ll>
#define X first
#define Y second
#define MAX 3001
using namespace std;

vector<ll> par(MAX, -1);
vector<pair<pll, pll>> line;
vector<ll> lineGroupSize(MAX, 1);

ll root(ll x)
{
    if (par[x] == -1)
        return x;
    else
        return par[x] = root(par[x]);
}

bool issame(ll x, ll y) { return root(x) == root(y); }

void unite(ll x, ll y)
{
    x = root(x);
    y = root(y);
    par[y] = x;
    lineGroupSize[x] += lineGroupSize[y];
}

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

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        line.push_back({{x1, y1}, {x2, y2}});
    }

    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
        {
            if (isCrossed(line[i].first, line[i].second, line[j].first, line[j].second))
            {
                if (!issame(i, j))
                    unite(i, j);
            }
        }

    ll groupCnt = 0;
    ll groupSize = 0;

    for (int i = 0; i < N; i++)
    {
        if (root(i) == i)
        {
            groupCnt++;
            groupSize = max(groupSize, lineGroupSize[i]);
        }
    }
    
    cout << groupCnt << "\n"
         << groupSize;

    return 0;
}