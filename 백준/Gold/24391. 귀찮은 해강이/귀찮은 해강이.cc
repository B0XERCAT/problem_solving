#include <iostream>
#include <vector>
#define MAX 100001

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

    int N, M, res = 0;
    int arr[MAX];
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        if (!issame(u, v))
            unite(u, v);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < N - 1; i++)
    {
        if (!issame(arr[i], arr[i + 1]))
            res++;
    }
    cout << res;
    return 0;
}
