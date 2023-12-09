#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, result = 0;
    cin >> N;
    while (N--)
    {
        string s;
        cin >> s;
        s = s.erase(0, 2);
        int x = stoi(s);
        if (x <= 90)
            result++;
    }
    cout << result << '\n';

    return 0;
}