#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, sum = 0, max = -1;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        sum += x;
        if (max < x)
            max = x;
    }
    cout << sum - max;

    return 0;
}