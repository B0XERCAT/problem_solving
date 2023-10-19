#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define MAX 1000000001
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, result = 0;
    cin >> N;
    vector<int> arr(N), arrReverse(N), dp(N), dpReverse(N);
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
        arrReverse[N - 1 - i] = x;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
                if (dp[i] < dp[j])
                    dp[i] = dp[j];
            if (arrReverse[i] > arrReverse[j])
                if (dpReverse[i] < dpReverse[j])
                    dpReverse[i] = dpReverse[j];
        }
        dp[i]++;
        dpReverse[i]++;
    }
    for (int i = 0; i < N; i++)
        if (dp[i] + dpReverse[N - 1 - i] > result)
            result = dp[i] + dpReverse[N - 1 - i];

    cout << result - 1;

    return 0;
}