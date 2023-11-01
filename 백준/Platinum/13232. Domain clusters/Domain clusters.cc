#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define MAX 5001
using namespace std;

int idx = 0, id[MAX];
bool finished[MAX];
vector<int> graph[MAX];
vector<vector<int>> SCC;
stack<int> s;

int dfs(int x)
{
  id[x] = ++idx;
  s.push(x);

  int result = id[x];

  for (auto next : graph[x])
  {
    if (id[next] == 0)
      result = min(result, dfs(next));
    else if (!finished[next])
      result = min(result, id[next]);
  }

  if (result == id[x])
  {
    vector<int> scc;
    while (1)
    {
      int t = s.top();
      s.pop();
      scc.push_back(t);
      finished[t] = true;
      if (t == x)
        break;
    }
    sort(scc.begin(), scc.end());
    SCC.push_back(scc);
  }

  return result;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int V, E;
  cin >> V >> E;

  for (int i = 0; i < E; i++)
  {
    int A, B;
    cin >> A >> B;
    graph[A].push_back(B);
  }

  for (int i = 1; i <= V; i++)
    if (id[i] == 0)
      dfs(i);

  int answer = 0;

  for (auto scc : SCC)
    if (scc.size() > answer)
      answer = scc.size();

  cout << answer;

  return 0;
}