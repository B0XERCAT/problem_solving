#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
#define MOD 1000000007
using namespace std;

vector<ll> tree;

void update(int index, ll val)
{
    tree[index] = val;

    while (index > 1)
    {
        index /= 2;
        tree[index] = tree[index * 2] * tree[index * 2 + 1];
        tree[index] %= MOD;
    }
}

void init(int i)
{
    while (i != 1)
    {
        tree[i / 2] *= tree[i];
        tree[i / 2] %= MOD;
        i--;
    }
}

ll getProduct(int s, int e)
{
    long partProduct = 1;

    while (s <= e)
    {
        if (s % 2 == 1)
        {
            partProduct *= tree[s];
            partProduct %= MOD;
            s++;
        }
        if (e % 2 == 0)
        {
            partProduct *= tree[e];
            partProduct %= MOD;
            e--;
        }
        s /= 2;
        e /= 2;
    }
    return partProduct;
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
    int leafNodeStartIndex = treeSize / 2;

    tree.resize(treeSize + 1, 1);

    for (int i = leafNodeStartIndex; i < leafNodeStartIndex + N; i++)
        cin >> tree[i];

    init(treeSize - 1);

    for (int i = 0; i < M + K; i++)
    {
        ll a, s, e;
        cin >> a >> s >> e;
        if (a == 1)
            update(leafNodeStartIndex - 1 + s, e);

        else if (a == 2)
        {
            s = s + leafNodeStartIndex - 1;
            e = e + leafNodeStartIndex - 1;
            cout << getProduct(s, e) << "\n";
        }
    }

    return 0;
}
