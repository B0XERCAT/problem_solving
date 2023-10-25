#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc = 1;

    while (1)
    {
        int L, P, V;
        cin >> L >> P >> V;

        if (L == 0 && P == 0 && V == 0)
            return 0;

        int result = (V / P) * L + min(L, V % P);

        printf("Case %d: %d\n", tc++, result);
    }

    return 0;
}