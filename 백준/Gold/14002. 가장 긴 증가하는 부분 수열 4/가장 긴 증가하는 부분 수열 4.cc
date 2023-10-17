#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, idx = 0;
    cin >> N;

    vector<int> LIS, arr(N), index(N), finalLIS;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    LIS.push_back(arr[0]);

    for (int i = 1; i < N; i++)
    {
        if (LIS[idx] < arr[i])
        {
            LIS.push_back(arr[i]);
            idx++;
            index[i] = idx;
        }
        else
        {
            int left = 0, right = LIS.size() - 1;
            while (left < right)
            {
                int mid = (left + right) / 2;
                if (LIS[mid] >= arr[i])
                    right = mid;
                else
                    left = mid + 1;
            }
            LIS[left] = arr[i];
            index[i] = left;
        }
    }

    cout << LIS.size() << "\n";

    int finalIdx = LIS.size() - 1;

    for (int i = N - 1; i >= 0; i--)
        if (index[i] == finalIdx)
        {
            finalIdx--;
            finalLIS.push_back(arr[i]);
        }
    
    reverse(finalLIS.begin(), finalLIS.end());
    
    for (int num : finalLIS)
        cout << num << " ";

    return 0;
}