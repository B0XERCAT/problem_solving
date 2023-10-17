#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define MAX 100001
#define X first
#define Y second
using namespace std;

vector<int> par(MAX, -1);

int root(int x)
{
    if (par[x] == -1)
        return x;
    else
        return par[x] = root(par[x]);
}

bool issame(int x, int y) { return root(x) == root(y); }

void unite(int x, int y)
{
    x = root(x);
    y = root(y);
    par[y] = x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<double, double>> starCoordinate;
    vector<pair<double, pair<int, int>>> stars;

    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        starCoordinate.push_back({x, y});
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double distance = sqrt(pow(starCoordinate[i].X - starCoordinate[j].X, 2) + pow(starCoordinate[i].Y - starCoordinate[j].Y, 2));
            stars.push_back({distance, {i, j}});
        }
    }

    sort(stars.begin(), stars.end());

    double res = 0;

    for (int i = 0; i < stars.size() - 1; i++)
    {
        double w = stars[i].first;
        int u = stars[i].second.first;
        int v = stars[i].second.second;
        if (issame(u, v))
            continue;
        res += w;
        unite(u, v);
    }

    cout << res;

    return 0;
}