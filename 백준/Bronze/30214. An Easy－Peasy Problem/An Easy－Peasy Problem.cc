#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;
    if (2 * a >= b)
        cout << 'E';
    else
        cout << 'H';

    return 0;
}
