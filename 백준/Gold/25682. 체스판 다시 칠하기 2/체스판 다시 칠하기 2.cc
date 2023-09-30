#include <iostream>
#include <vector>
#include <string>
#define MAX 2001
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char board[MAX][MAX];
    int BSum[MAX][MAX], WSum[MAX][MAX];
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++)
        {
            if (i > 0 && j > 0)
            {
                BSum[i][j] = BSum[i - 1][j] + BSum[i][j - 1] - BSum[i - 1][j - 1];
                WSum[i][j] = WSum[i - 1][j] + WSum[i][j - 1] - WSum[i - 1][j - 1];
            }
            else if (i > 0)
            {
                BSum[i][j] = BSum[i - 1][j];
                WSum[i][j] = WSum[i - 1][j];
            }
            else if (j > 0)
            {
                BSum[i][j] = BSum[i][j - 1];
                WSum[i][j] = WSum[i][j - 1];
            }
            board[i][j] = line[j];
            if ((i + j) % 2 == 0)
            {
                if (board[i][j] == 'W')
                    BSum[i][j]++;
                else
                    WSum[i][j]++;
            }
            else
            {
                if (board[i][j] == 'B')
                    BSum[i][j]++;
                else
                    WSum[i][j]++;
            }
        }
    }
    
    int BResult = BSum[K-1][K-1], WResult = WSum[K-1][K-1];
    // (0, 0) ~ (0, M - 1)
    // (0, 0) ~ (0, N - 1) 를 포함하는 경우
    for (int i = K; i < N; i++)
    {
        BResult = min(BResult, BSum[i][K - 1] - BSum[i - K][K - 1]);
        WResult = min(WResult, WSum[i][K - 1] - WSum[i - K][K - 1]);
    }
    for (int i = K; i < M; i++)
    {
        BResult = min(BResult, BSum[K - 1][i] - BSum[K - 1][i - K]);
        WResult = min(WResult, WSum[K - 1][i] - WSum[K - 1][i - K]);
    }
    //(1, 1) ~ (N-1, M-1)
    for (int i = 1; i <= N - K; i++)
    {
        for (int j = 1; j <= M - K; j++)
        {
            BResult = min(BResult, BSum[i + K - 1][j + K - 1] - BSum[i + K - 1][j - 1] - BSum[i - 1][j + K - 1] + BSum[i - 1][j - 1]);
            WResult = min(WResult, WSum[i + K - 1][j + K - 1] - WSum[i + K - 1][j - 1] - WSum[i - 1][j + K - 1] + WSum[i - 1][j - 1]);
        }
    }

    cout << min(BResult, WResult);
    

    return 0;
}