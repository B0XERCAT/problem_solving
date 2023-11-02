#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000001
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, result = 0;
  cin >> N;
  vector<pair<int, int>> v;

  for (int i = 0; i < N; i++)
  {
    int x, y;
    cin >> x >> y;
    v.push_back({x, y});
  }

  sort(v.begin(), v.end());

  int l = INF, r = -INF;

  for (int i = 0; i < N; i++)
  {
    if (v[i].first > r)
    {
      l = v[i].first;
      r = v[i].second;
      result += r - l;
    }
    else if (v[i].second > r)
    {
      result += v[i].second - r;
      r = v[i].second;
    }
  }
  
  cout << result;

  return 0;
}