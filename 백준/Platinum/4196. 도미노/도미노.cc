#include <iostream>
#include <stack>
#include <vector>
#define MAX 100001
using namespace std;

int N, M;
int idx = 0, id[MAX];
bool finished[MAX];
vector<int> graph[MAX];
vector<vector<int>> SCC;
stack<int> s;
int groupID[MAX];
bool isAutoFallen[MAX];

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
      groupID[t] = SCC.size() + 1;
      finished[t] = true;
      if (t == x)
        break;
    }
    SCC.push_back(scc);
  }

  return result;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;
  while (T--)
  {
    SCC.clear();
    fill(id, id + MAX, 0);
    fill(finished, finished + MAX, 0);
    fill(isAutoFallen, isAutoFallen + MAX, false);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
      graph[i].clear();

    for (int i = 0; i < M; i++)
    {
      int A, B;
      cin >> A >> B;
      graph[A].push_back(B);
    }

    for (int i = 1; i <= N; i++)
      if (id[i] == 0)
        dfs(i);

    for (int i = 1; i <= N; i++)
      for (auto node : graph[i])
        if (groupID[i] != groupID[node])
          isAutoFallen[groupID[node]] = true;

    int result = 0;

    for (int i = 1; i <= SCC.size(); i++)
      if (!isAutoFallen[i])
        result++;

    cout << result << "\n";
  }

  return 0;
}