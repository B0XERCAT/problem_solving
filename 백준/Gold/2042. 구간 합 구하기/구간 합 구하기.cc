#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

vector<ll> tree;

void update(int index, ll val)
{
    tree[index] = val;

    while (index > 1)
    {
        index /= 2;
        tree[index] = tree[index * 2] + tree[index * 2 + 1];
    }
}

void init(int i)
{
    while (i != 1)
    {
        tree[i / 2] += tree[i];
        i--;
    }
}

ll query(int s, int e)
{
    ll partSum = 0;

    while (s <= e)
    {
        if (s % 2 == 1)
        {
            partSum += tree[s];
            s++;
        }
        if (e % 2 == 0)
        {
            partSum += tree[e];
            e--;
        }
        s /= 2;
        e /= 2;
    }
    return partSum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    int treeHeight = 0;
    int length = N;

    while (length != 0)
    {
        length /= 2;
        treeHeight++;
    }

    int treeSize = int(pow(2, treeHeight + 1));
    int leafStartIdx = treeSize / 2;

    tree.resize(treeSize + 1, 0);

    for (int i = leafStartIdx; i < leafStartIdx + N; i++)
        cin >> tree[i];

    init(treeSize - 1);

    for (int i = 0; i < M + K; i++)
    {
        ll a, s, e;
        cin >> a >> s >> e;
        if (a == 1)
            update(leafStartIdx - 1 + s, e);
        else if (a == 2)
        {
            s = s + leafStartIdx - 1;
            e = e + leafStartIdx - 1;
            cout << query(s, e) << "\n";
        }
    }

    return 0;
}
