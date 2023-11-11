#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int N, max = 0;
        string result;
        cin >> N;
        while (N--)
        {
            string univ;
            int consumed;
            cin >> univ >> consumed;
            if (consumed > max)
            {
                max = consumed;
                result = univ;
            }
        }
        cout << result << "\n";
    }

    return 0;
}