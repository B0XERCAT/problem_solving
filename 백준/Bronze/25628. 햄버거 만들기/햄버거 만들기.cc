#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;
    cin >> A >> B;
    if (A >= 2 * B)
        cout << B;
    else
        cout << A / 2;
    return 0;
}
