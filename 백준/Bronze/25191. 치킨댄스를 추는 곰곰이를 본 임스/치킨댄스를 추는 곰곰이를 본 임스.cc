#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, A, B;
    cin >> N >> A >> B;
    cout << min(N, A / 2 + B);

    return 0;
}