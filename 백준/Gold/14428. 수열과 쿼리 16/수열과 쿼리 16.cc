#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
#define MAX 1000000001
using namespace std;

vector<pair<ll, ll>> tree;

void update(int index, ll val)
{
    tree[index].first = val;

    while (index > 1)
    {
        index /= 2;
        if (tree[index * 2].first <= tree[index * 2 + 1].first)
            tree[index] = tree[index * 2];
        else
            tree[index] = tree[index * 2 + 1];
    }
}

void init(int i)
{
    while (i != 1)
    {
        if (tree[i / 2].first >= tree[i].first)
            tree[i / 2] = tree[i];
        i--;
    }
}

ll query(int s, int e)
{
    pair<ll, ll> partMin = {MAX, 0};

    while (s <= e)
    {
        if (s % 2 == 1)
        {
            if (partMin.first > tree[s].first)
                partMin = tree[s];
            else if (partMin.first == tree[s].first)
                partMin.second = min(partMin.second, tree[s].second);
            s++;
        }
        if (e % 2 == 0)
        {
            if (partMin.first > tree[e].first)
                partMin = tree[e];
            else if (partMin.first == tree[e].first)
                partMin.second = min(partMin.second, tree[e].second);
            e--;
        }
        s /= 2;
        e /= 2;
    }
    return partMin.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;

    int treeHeight = 0;
    int length = N;

    while (length != 0)
    {
        length /= 2;
        treeHeight++;
    }

    int treeSize = int(pow(2, treeHeight + 1));
    int leafStartIdx = treeSize / 2;

    tree.resize(treeSize, {MAX, 0});

    for (int i = leafStartIdx; i < leafStartIdx + N; i++)
    {
        int x;
        cin >> x;
        tree[i] = {x, i - leafStartIdx + 1};
    }

    init(treeSize - 1);

    cin >> M;

    for (int i = 0; i < M; i++)
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