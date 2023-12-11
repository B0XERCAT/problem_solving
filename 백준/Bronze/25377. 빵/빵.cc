#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, min = 3000;
    cin >> N;
    while (N--)
    {
        int A, B;
        cin >> A >> B;
        if (A <= B && min > B)
            min = B;
    }
    if (min == 3000)
        cout << -1;
    else
        cout << min;

    return 0;
}