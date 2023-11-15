#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll R, C, N, result = 1;
    cin >> R >> C >> N;
    if (R % N != 0)
        result *= (R / N + 1);
    else
        result *= R / N;
    if (C % N != 0)
        result *= (C / N + 1);
    else
        result *= C / N;

    cout << result;

    return 0;
}