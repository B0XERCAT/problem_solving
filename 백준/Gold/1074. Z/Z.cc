#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;

int z(int row, int col, int size)
{
    if (size == 1)
        return 0;

    int half = size / 2;
    int area_size = half * half;

    if (r < row + half && c < col + half)
        return z(row, col, half);
    else if (r < row + half && c >= col + half)
        return area_size + z(row, col + half, half);
    else if (r >= row + half && c < col + half)
        return 2 * area_size + z(row + half, col, half);
    else
        return 3 * area_size + z(row + half, col + half, half);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> r >> c;
    int size = pow(2, N);
    cout << z(0, 0, size);

    return 0;
}
