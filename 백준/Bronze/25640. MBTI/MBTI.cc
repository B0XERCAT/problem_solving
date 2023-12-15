#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt = 0;
    string mbti;
    cin >> mbti;
    int N;
    cin >> N;
    while (N--)
    {
        string _mbti;
        cin >> _mbti;
        if (mbti == _mbti)
            cnt++;
    }
    cout << cnt << '\n';

    return 0;
}