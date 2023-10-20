#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, result = 0;
    cin >> N;

    vector<pair<int, int>> arr(N);
    vector<int> dp(N, 0);

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
            if (arr[i].second > arr[j].second)
                if (dp[i] < dp[j])
                    dp[i] = dp[j];
        dp[i]++;
        if (result < dp[i])
            result = dp[i];
    }

    cout << N - result;

    return 0;
}