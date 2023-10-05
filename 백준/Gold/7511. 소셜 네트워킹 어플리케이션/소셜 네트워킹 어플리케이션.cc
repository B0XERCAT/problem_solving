#include <iostream>
#include <vector>
#include <cstring>
#define MAX 100001

using namespace std;

int n, k, a, b, m, u, v;
int par[MAX];

int root(int x)
{
    if (par[x] == -1)
        return x;
    else
        return root(par[x]);
}

bool issame(int x, int y) { return root(x) == root(y); }

void unite(int x, int y)
{
    x = root(x);
    y = root(y);
    if (x != y)
        par[y] = x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++)
    {
        cout << "Scenario " << testcase << ":\n";

        cin >> n >> k;
        for (int i = 0; i < n; i++)
            par[i] = -1
            ;
        for (int i = 0; i < k; i++)
        {
            cin >> a >> b;
            unite(a, b);
        }

        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            if (issame(u, v))
                cout << "1\n";
            else
                cout << "0\n";
        }
        cout << "\n";
    }

    return 0;
}
