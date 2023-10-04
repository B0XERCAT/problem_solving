#include <iostream>
#include <vector>
#define MAX 500001

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

    int n, m, result = 0;
    bool foundResult = false;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (issame(u, v))
        {
            if (foundResult)
                continue;
            result = i + 1;
            foundResult = true;
        }
        else
            unite(u, v);
    }
    cout << result;
    return 0;
}
