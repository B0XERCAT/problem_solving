#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> par(MAX);

int root(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = root(par[x]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int G, P, result = 0;
    vector<int> plane;
    cin >> G >> P;

    for (int i = 0; i <= G; i++)
        par[i] = i;

    for (int i = 0; i < P; i++)
    {
        int x;
        cin >> x;
        plane.push_back(x);
    }

    for (int gateNum : plane)
    {
        int remainGate = root(gateNum);
        if (remainGate == 0)
            break;
        par[remainGate]--;
        result++;
    }

    cout << result;

    return 0;
}