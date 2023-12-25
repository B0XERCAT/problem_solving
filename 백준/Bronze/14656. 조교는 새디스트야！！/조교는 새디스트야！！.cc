#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, cnt = 0;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        if (num != i)
            cnt++;
    }
    cout << cnt << '\n';

    return 0;
}