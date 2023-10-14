#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
#define MAX 2001
using namespace std;

int arr[MAX];
int dp[MAX][MAX];

int palindrome(int i, int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];

    else if (arr[i] != arr[j])
        dp[i][j] = 0;
    else
    {
        if (j - i <= 2)
            dp[i][j] = 1;
        else
            dp[i][j] = palindrome(i + 1, j - 1);
    }
    return dp[i][j];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            dp[i][j] = -1;

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int S, E;
        cin >> S >> E;
        cout << palindrome(S, E) << "\n";
    }

    return 0;
}