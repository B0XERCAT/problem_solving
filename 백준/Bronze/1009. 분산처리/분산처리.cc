#include <iostream>
using namespace std;

int last[10][4] = {
    {10},
    {1},
    {2, 4, 8, 6},
    {3, 9, 7, 1},
    {4, 6},
    {5},
    {6},
    {7, 9, 3, 1},
    {8, 4, 2, 6},
    {9, 1},
};

int sizeOfLast[10] = {
    1,
    1,
    4,
    4,
    2,
    1,
    1,
    4,
    4,
    2};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;
  while (T--)
  {
    int a, b;
    cin >> a >> b;
    cout << last[a % 10][(b - 1) % (sizeOfLast[a % 10])] << "\n";
  }

  return 0;
}