#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double A, B;
    cin >> A >> B;
    double M = (B - A) / 400;
    cout << 1 / (1 + pow(10, M));

    return 0;
}