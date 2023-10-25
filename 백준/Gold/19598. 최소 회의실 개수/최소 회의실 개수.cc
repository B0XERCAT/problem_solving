#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct compare
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    priority_queue<int, vector<int>, compare> pq;
    vector<pair<int, int>> classTime;
    
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int s, t;
        cin >> s >> t;
        classTime.push_back({s, t});
    }

    sort(classTime.begin(), classTime.end());

    pq.push(classTime[0].second);

    for (int i = 1; i < N; i++)
    {
        if (pq.top() <= classTime[i].first)
            pq.pop();
        pq.push(classTime[i].second);
    }

    cout << pq.size();

    return 0;
}