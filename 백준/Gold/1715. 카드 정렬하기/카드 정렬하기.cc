#include <iostream>
#include <queue>
#define ll long long
using namespace std;

struct compare
{
    bool operator()(ll a, ll b)
    {
        return a > b;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N, result = 0;
    cin >> N;
    priority_queue<ll, vector<ll>, compare> pq;

    for (int i = 0; i < N; i++)
    {
        ll x;
        cin >> x;
        pq.push(x);
    }

    if(N == 1){
        cout << 0;
        return 0;
    }

    while (1)
    {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();

        pq.push(a + b);
        result += (a + b);

        if (pq.size() == 1)
            break;
    }

    cout << result;

    return 0;
}