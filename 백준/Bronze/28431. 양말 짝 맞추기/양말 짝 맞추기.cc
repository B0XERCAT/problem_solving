#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;
    for (int i = 0; i < 5; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < 4; i++)
    {
        if (v[i] == v[i + 1])
        {
            v[i] = -1;
            v[i + 1] = -1;
        }
    }
    for (int i = 0; i < 5; i++)
        if (v[i] != -1)
            cout << v[i];
    

    return 0;
}