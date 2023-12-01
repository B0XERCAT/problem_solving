#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, A, B, C, result = 0;
    cin >> N >> A >> B >> C;
    result += min(N, A);
    result += min(N, B);
    result += min(N, C);
    cout << result;
    return 0;
}