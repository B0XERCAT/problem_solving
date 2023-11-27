#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll C, K, P, result = 0;
    cin >> C >> K >> P;
    for (int i = 1; i <= C; i++)
        result += (K * i + P * i * i);

    cout << result;

    return 0;
}