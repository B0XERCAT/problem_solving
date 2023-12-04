#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int X, L, R;
    cin >> X >> L >> R;
    if (X <= L)
        cout << L;
    else if (X >= R)
        cout << R;
    else
        cout << X;

    return 0;
}