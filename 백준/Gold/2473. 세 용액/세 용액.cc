#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define MAX 5001
#define INF 9876543219
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<ll> ph(MAX);
    pair<pair<ll, ll>, ll> answer;
    ll result = INF;

    ph.resize(N);
    for (int i = 0; i < N; i++)
        cin >> ph[i];

    sort(ph.begin(), ph.end());

    for (int i = 0; i < N - 2; i++)
    {
        int start = i + 1, end = N - 1;
        while (start < end)
        {
            if (result > abs(ph[i] + ph[start] + ph[end]))
            {
                result = abs(ph[i] + ph[start] + ph[end]);
                answer = {{i, start}, end};
            }
            if (ph[i] + ph[start] + ph[end] > 0)
                end--;
            else
                start++;
        }
    }

    printf("%lld %lld %lld", ph[answer.first.first], ph[answer.first.second], ph[answer.second]);

    return 0;
}