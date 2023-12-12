#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> v;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    long long result = N;
    int B, C;
    cin >> B >> C;
    for (int i = 0; i < N; i++)
    {
        v[i] -= B;
        if (v[i] > 0)
        {
            result += v[i] / C;
            if (v[i] % C != 0)
                result++;
        }
    }
    cout << result << '\n';

    return 0;
}