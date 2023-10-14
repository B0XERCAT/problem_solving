#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

vector<pair<ll, ll>> coordinate;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll area = 0;
    ll N, firstX, firstY, x, y;

    cin >> N;

    cin >> firstX >> firstY;
    coordinate.push_back({firstX, firstY});
    for (int i = 0; i < N - 1; i++)
    {
        cin >> x >> y;
        coordinate.push_back({x, y});
    }
    coordinate.push_back({firstX, firstY});

    for (int i = 0; i < N; i++)
    {
        area += coordinate[i].first * coordinate[i + 1].second;
        area -= coordinate[i + 1].first * coordinate[i].second;
    }

    if (abs(area) % 2 == 0)
        printf("%lld.0", abs(area) / 2);
    else
        printf("%lld.5", abs(area) / 2);

    return 0;
}