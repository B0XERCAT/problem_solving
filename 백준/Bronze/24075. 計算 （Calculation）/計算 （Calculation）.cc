#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;
    cin >> A >> B;
    if (A + B > A - B)
        cout << A + B << "\n"
             << A - B;
    else
        cout << A - B << "\n"
             << A + B;

    return 0;
}