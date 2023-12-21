#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1)
    {
        string N;
        cin >> N;
        if (N == "0")
            break;
        int sum = 0;
        for (int i = 0; i < N.length(); i++)
        {
            if(N[i] == '1')
                sum += 2;
            else if(N[i] == '0')
                sum += 4;
            else
                sum += 3;
        }
        cout << sum + N.length() + 1 << "\n";
    }

    return 0;
}