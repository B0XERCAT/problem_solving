#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double T;
    cin >> T;
    cout << (int)(round((T / 2) * (T / 2)));

    return 0;
}