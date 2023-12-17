#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    while (N--)
    {
        int x, y;
        cin >> x >> y;
        if (x >= y)
            cout << "MMM BRAINS" << '\n';
        else
            cout << "NO BRAINS" << '\n';
    }
    return 0;
}