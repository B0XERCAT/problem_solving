#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define pii pair<int, int>
#define X first
#define Y second
using namespace std;

int ccw(pii A, pii B, pii C)
{
    int temp = A.X * B.Y + B.X * C.Y + C.X * A.Y;
    temp -= B.X * A.Y + C.X * B.Y + A.X * C.Y;

    if (temp > 0)
        return 1;
    else if (temp < 0)
        return -1;
    else
        return 0;
}

bool isCrossed(pii A, pii B, pii C, pii D)
{
    int check1 = ccw(A, B, C) * ccw(A, B, D);
    int check2 = ccw(C, D, A) * ccw(C, D, B);

    if (check1 == 0 && check2 == 0)
    {
        if (A > B)
            swap(A, B);
        if (C > D)
            swap(C, D);
        if (A <= D && B >= C)
            return true;
    }
    else if (check1 <= 0 && check2 <= 0)
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    while (N--)
    {
        char result = 'F';
        vector<pii> coordinate;

        int x1, y1, x2, y2, xLeft, yTop, xRight, yBottom;
        
        cin >> x1 >> y1 >> x2 >> y2;
        coordinate.push_back({x1, y1});
        coordinate.push_back({x2, y2});

        cin >> xLeft >> yTop >> xRight >> yBottom;
        if(xLeft > xRight)
            swap(xLeft, xRight);
        for (int x = xLeft; x <= xRight; x++)
        {
            coordinate.push_back({x, yTop});
            coordinate.push_back({x, yBottom});
        }

        for (int i = 0; i < xRight - xLeft + 1; i++)
        {
            if (isCrossed(coordinate[0], coordinate[1], coordinate[2 + 2 * i], coordinate[3 + 2 * i]))
            {
                result = 'T';
                break;
            }
        }

        cout << result << "\n";
    }

    return 0;
}