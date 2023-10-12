#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

vector<ll> tree;

void changeValue(int index, ll val)
{
    long diff = val - tree[index];
    while (index > 0)
    {
        tree[index] = tree[index] + diff;
        index = index / 2;
    }
}

void setTree(int i)
{
    while (i != 1)
    {
        tree[i / 2] += tree[i];
        i--;
    }
}

ll getSum(int s, int e)
{
    long partSum = 0;

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
    int leafNodeStartIndex = treeSize / 2;

    tree.resize(treeSize + 1);

    for (int i = leafNodeStartIndex; i < leafNodeStartIndex + N; i++)
        cin >> tree[i];

    setTree(treeSize - 1);

    for (int i = 0; i < M + K; i++)
    {
        ll a, s, e;
        cin >> a >> s >> e;
        if (a == 1)
            changeValue(leafNodeStartIndex - 1 + s, e);

        else if (a == 2)
        {
            s = s + leafNodeStartIndex - 1;
            e = e + leafNodeStartIndex - 1;
            cout << getSum(s, e) << "\n";
        }
    }

    return 0;
}
