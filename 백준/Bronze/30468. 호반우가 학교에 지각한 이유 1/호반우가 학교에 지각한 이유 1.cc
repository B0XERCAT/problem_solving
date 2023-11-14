#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s, d, i, l, n;
    cin >> s >> d >> i >> l >> n;
    int result = 4 * n - (s + d + i + l);
    if (result < 0)
        cout << 0;
    else
        cout << result;

    return 0;
}