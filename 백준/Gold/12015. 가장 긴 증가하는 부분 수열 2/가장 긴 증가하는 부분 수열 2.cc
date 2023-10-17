#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, idx = 0;
    cin >> N;
    vector<int> LIS, Arr(N);

    for (int i = 0; i < N; i++)
        cin >> Arr[i];

    LIS.push_back(Arr[0]);

    for (int i = 1; i < N; i++)
    {
        if (LIS[idx] < Arr[i])
        {
            LIS.push_back(Arr[i]);
            idx++;
        }
        else
        {
            int left = 0, right = LIS.size() - 1;
            while (left < right)
            {
                int mid = (left + right) / 2;
                if (LIS[mid] >= Arr[i])
                    right = mid;
                else
                    left = mid + 1;
            }
            LIS[left] = Arr[i];
        }
    }

    cout << LIS.size() << "\n";

    return 0;
}