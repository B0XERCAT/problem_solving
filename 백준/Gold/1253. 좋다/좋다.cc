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

    vector<ll> v;
    int N, result = 0;
    cin >> N;

    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++)
    {
        int s = 0, e = N - 1;
        while (s < e)
        {
            if (v[s] + v[e] == v[i])
            {
                if (i != s && i != e)
                {
                    result++;
                    break;
                }
                else if(i == s)
                    s++;
                else if(i == e)
                    e--;
            }
            else if (v[s] + v[e] >= v[i])
                e--;
            else
                s++;
        }
    }

    cout << result;

    return 0;
}
