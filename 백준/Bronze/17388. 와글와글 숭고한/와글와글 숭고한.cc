#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s, k, h, res;
    cin >> s >> k >> h;

    res = s + k + h;
    
    if (res >= 100)
        cout << "OK";
    else
    {
        if (s < k && s < h)
            cout << "Soongsil";
        else if (k < s && k < h)
            cout << "Korea";
        else
            cout << "Hanyang";
    }

    return 0;
}
