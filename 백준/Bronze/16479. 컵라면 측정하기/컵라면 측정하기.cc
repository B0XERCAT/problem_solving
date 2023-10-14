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

    double K, D1, D2;
    cin >> K >> D1 >> D2;
    printf("%.6f", K * K - (D1 - D2) * (D1 - D2) / 4);

    return 0;
}