#include <iostream>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int M, result = 1;
  cin >> M;

  while (M--)
  {
    int x, y;
    cin >> x >> y;
    if (x == result)
      result = y;
    else if (y == result)
      result = x;
  }
  cout << result;

  return 0;
}