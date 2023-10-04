#include <iostream>
#define ll long long
#define MAX 100001
using namespace std;

int n;
ll height[MAX];

ll solve(ll left, ll right)
{
    if (left == right)
        return height[left];
    ll mid = (left + right) / 2;
    ll result = max(solve(left, mid), solve(mid + 1, right));

    // 왼쪽 오른쪽에 걸치는 경우
    ll midLeft = mid, midRight = mid + 1;
    ll midHeight = min(height[midLeft], height[midRight]);
    result = max(result, midHeight * 2);

    // 전체 너비를 덮을 때까지 탐색
    while (left < midLeft || midRight < right)
    {
        // 아직 오른쪽 끝에 도달 안했고
        // 왼쪽 끝에는 도달했거나, 오른쪽 높이가 더 클 때
        if (midRight < right && (midLeft == left || height[midLeft - 1] < height[midRight + 1]))
        {
            midRight++;
            midHeight = min(midHeight, height[midRight]);
        }
        //
        else
        {
            midLeft--;
            midHeight = min(midHeight, height[midLeft]);
        }
        result = max(result, midHeight * (midRight - midLeft + 1));
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> height[i];
    cout << solve(0, n - 1) << "\n";

    return 0;
}
