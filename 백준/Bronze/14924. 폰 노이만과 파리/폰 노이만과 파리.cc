#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S, T, D;
    cin >> S >> T >> D;
    cout << (D * T) / (S * 2);
    return 0;
}