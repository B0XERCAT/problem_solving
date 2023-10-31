#include <iostream>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long N, T;
  cin >> N >> T;

  long long result = T % (N * 4 - 2);

  if (result == 0)
    result = N * 4 - 2;

  if (result > 2 * N)
    result = 4 * N - result;

  cout << result;

  return 0;
}