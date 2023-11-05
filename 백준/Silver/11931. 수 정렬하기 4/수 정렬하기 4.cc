#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  vector<int> v;
  while (N--)
  {
    int x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  for (int i = v.size() - 1; i >= 0; i--)
    cout << v[i] << "\n";
}