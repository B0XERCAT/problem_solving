#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt = 0;
    for (int i = 0; i < 6; i++)
    {
        char x;
        cin >> x;
        if (x == 'W')
            cnt++;
    }
    if(cnt >= 5)
        cout << 1;
    else if(cnt >= 3)
        cout << 2;
    else if(cnt >= 1)
        cout << 3;
    else
        cout << -1;
}