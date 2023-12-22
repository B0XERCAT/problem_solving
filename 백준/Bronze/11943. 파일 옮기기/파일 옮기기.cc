#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;
    int C, D;
    cin >> A >> B >> C >> D;
    cout << min(A + D, B + C);

    return 0;
}