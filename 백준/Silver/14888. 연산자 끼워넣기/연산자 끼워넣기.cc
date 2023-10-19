#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#define ll long long
#define MAX 1000000001
using namespace std;

ll result, N, num[11], operators[4];
ll maxResult = -MAX, minResult = MAX;

void dfs(int index)
{
    if (index == N)
    {
        if (result > maxResult)
            maxResult = result;
        if (result < minResult)
            minResult = result;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (operators[i])
        {
            ll previous = result;
            operators[i]--;
            if (i == 0)
                result += num[index];
            else if (i == 1)
                result -= num[index];
            else if (i == 2)
                result *= num[index];
            else
                result /= num[index];
            dfs(index + 1);
            operators[i]++;
            result = previous;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> num[i];
    for (int i = 0; i < 4; i++)
        cin >> operators[i];

    result = num[0];

    dfs(1);

    cout << maxResult << "\n"
         << minResult;

    return 0;
}