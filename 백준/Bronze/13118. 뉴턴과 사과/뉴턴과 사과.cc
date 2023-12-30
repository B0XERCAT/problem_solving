#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int result = 0;
    vector<int> p(4);
    for (int i = 0; i < 4; i++)
        cin >> p[i];
    int x, y, r;
    cin >> x >> y >> r;
    for (int i = 0; i < 4; i++)
    {
        if (p[i] == x)
            result = i + 1;
    }
    cout << result << '\n';

    return 0;
}