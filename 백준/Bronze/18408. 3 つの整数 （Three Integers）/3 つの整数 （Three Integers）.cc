#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, sum = 0;
    cin >> a >> b >> c;
    sum = a + b + c;

    if (sum <= 4)
        cout << 1;
    else
        cout << 2;

    return 0;
}