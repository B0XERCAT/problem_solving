#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    ll dist = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    ll radiusSum = (r1 + r2) * (r1 + r2);
    
    if (dist >= radiusSum)
        cout << "NO";
    else
        cout << "YES";

    return 0;
}