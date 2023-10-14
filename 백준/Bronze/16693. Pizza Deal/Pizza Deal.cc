#include <iostream>

#define pi 3.14159265358979323846
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double A1, P1, R1, P2;
    cin >> A1 >> P1 >> R1 >> P2;
    double priceSlice = A1 / P1;
    double priceWhole = pi * (R1 * R1) / P2;

    if(priceSlice > priceWhole)
        cout << "Slice of pizza";
    else
        cout << "Whole pizza";

    return 0;
}