#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, A, result = 0;
    cin >> T;
    for (int i = 0; i < 5; i++)
    {
        cin >> A;
        if (T == A)
            result++;
    }
    cout << result;

    return 0;
}