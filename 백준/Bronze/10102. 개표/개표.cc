#include <iostream>
#include <string>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, a = 0, b = 0;
  string line;
  cin >> N >> line;

  for (int i = 0; i < N; i++)
  {
    if (line[i] == 'A')
      a++;
    else
      b++;
  }

  if (a > b)
    cout << "A";
  else if (a == b)
    cout << "Tie";
  else
    cout << "B";

  return 0;
}