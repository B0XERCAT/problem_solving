#include <iostream>
#include <vector>

using namespace std;

struct line
{
    int dir;
    int dist;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<line> v;
    vector<int> one(5, -1);

    int K;
    cin >> K;
    int result = 1;

    for (int i = 0; i < 6; i++)
    {
        int direction, distance;
        cin >> direction >> distance;
        v.push_back({direction, distance});
        if (one[direction] != -1)
            one[direction] = 0;
        else
            one[direction] = distance;
    }
    for (int i = 1; i <= 4; i++)
    {
        if (one[i] != 0)
            result *= one[i];
    }
    for (int i = 0; i < 6; i++)
    {
        if (v[i].dir == v[(i + 2) % 6].dir)
        {
            if (v[(i + 1) % 6].dir == v[(i + 3) % 6].dir)
                result -= v[(i + 2) % 6].dist * v[(i + 1) % 6].dist;
            else
                result -= v[(i + 1) % 6].dist * v[i].dist;
            break;
        }
    }

    cout << result * K;
    return 0;
}