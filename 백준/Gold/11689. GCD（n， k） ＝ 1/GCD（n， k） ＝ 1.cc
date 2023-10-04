#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N;
    vector<ll> v;
    cin >> N;
    ll temp = N;
        

    for (ll i = 2; i * i<= N; i++)
        if (temp % i == 0)
        {
            v.push_back(i);
            while (temp % i == 0)
                temp /= i;
        }
    if(temp != 1)
        v.push_back(temp);
    for (const auto item : v)
    {
        N /= item;
        N *= (item - 1);
    }
    cout << N;
    return 0;
}
