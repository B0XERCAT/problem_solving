#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> makeTable(string pattern)
{
  int patternSize = pattern.size();
  vector<int> table(patternSize, 0);
  int j = 0;
  for (int i = 1; i < patternSize; i++)
  {
    while (j > 0 && pattern[i] != pattern[j])
      j = table[j - 1];
    if (pattern[i] == pattern[j])
      table[i] = ++j;
  }
  return table;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string S;
  int K;
  cin >> S >> K;

  vector<int> pi = makeTable(S);

  cout << (S.size() - pi[S.size() - 1]) * K + pi[S.size() - 1];

  return 0;
}