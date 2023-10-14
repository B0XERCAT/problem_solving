#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define ll long long
#define MAX 1000000001
using namespace std;

vector<pair<ll, ll>> tree;

void update(int index, ll val)
{
    tree[index] = {val, val};

    while (index > 1)
    {
        index /= 2;
        tree[index / 2].first = min(tree[index / 2].first, tree[index].first);
        tree[index / 2].second = max(tree[index / 2].second, tree[index].second);
    }
}

void init(int i)
{
    while (i != 1)
    {
        tree[i / 2].first = min(tree[i / 2].first, tree[i].first);
        tree[i / 2].second = max(tree[i / 2].second, tree[i].second);
        i--;
    }
}

pair<ll, ll> minAndMax(int s, int e)
{
    ll partMin = MAX;
    ll partMax = 0;

    while (s <= e)
    {
        if (s % 2 == 1)
        {
            partMin = min(partMin, tree[s].first);
            partMax = max(partMax, tree[s].second);
            s++;
        }
        if (e % 2 == 0)
        {
            partMin = min(partMin, tree[e].first);
            partMax = max(partMax, tree[e].second);
            e--;
        }
        s /= 2;
        e /= 2;
    }
    return {partMin, partMax};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int treeHeight = 0;
    int length = N;

    while (length != 0)
    {
        length /= 2;
        treeHeight++;
    }

    int treeSize = int(pow(2, treeHeight + 1));
    int leafNodeStartIndex = treeSize / 2;

    tree.resize(treeSize + 1, {MAX, 0});

    for (int i = leafNodeStartIndex; i < leafNodeStartIndex + N; i++)
    {
        ll x;
        cin >> x;
        tree[i] = {x, x};
    }

    init(treeSize - 1);

    for (int i = 0; i < M; i++)
    {
        ll s, e;
        cin >> s >> e;

        s = s + leafNodeStartIndex - 1;
        e = e + leafNodeStartIndex - 1;
        cout << minAndMax(s, e).first << " " << minAndMax(s, e).second << "\n";
    }

    return 0;
}
