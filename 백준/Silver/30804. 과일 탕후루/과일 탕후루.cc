#include <iostream>
#include <vector>
#include <unordered_map>
#define INF 987654321
using namespace std;

int N;
vector<int> stick;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        stick.push_back(n);
    }

    unordered_map<int, int> fruit_count;
    int lo = 0, hi = 0;
    int ans = 0;

    while (hi < N)
    {
        fruit_count[stick[hi]]++;

        while (fruit_count.size() > 2)
        {
            fruit_count[stick[lo]]--;
            if (fruit_count[stick[lo]] == 0)
                fruit_count.erase(stick[lo]);
            lo++;
        }

        ans = max(ans, hi - lo + 1);
        hi++;
    }

    cout << ans;

    return 0;
}
