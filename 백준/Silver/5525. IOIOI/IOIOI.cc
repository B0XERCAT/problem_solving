#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#define MAX 501
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, cnt = 0;
    string S;
    cin >> N >> M >> S;
    for (int i = 0; i < M; i++)
    {
        if (S[i] == 'I')
        {
            int len = 0;
            while (S[i + 1] == 'O' && S[i + 2] == 'I')
            {
                len++;
                if (len == N)
                {
                    cnt++;
                    len--;
                }

                i += 2;
            }
        }
    }
    cout << cnt;
    return 0;
}
