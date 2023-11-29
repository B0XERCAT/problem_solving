#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    if (M == 1 || M == 2)
        cout << "NEWBIE!";
    else if (M <= N)
        cout << "OLDBIE!";
    else
        cout << "TLE!";

    return 0;
}