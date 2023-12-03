#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sum = 0;
    while (1)
    {
        int x;
        cin >> x;
        if (x == -1)
            break;
        sum += x;
    }
    cout << sum << '\n';
    return 0;
}