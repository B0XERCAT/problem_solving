#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N, result = 6;
    cin >> N;
    for (int i = 11; i <= N; i++)
        result *= i;
    cout << result;

    return 0;
}