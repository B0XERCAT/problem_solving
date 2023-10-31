#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;

int N, M;
int idx = 0, id[MAX];
bool finished[MAX];
vector<int> graph[MAX];
vector<vector<int>> SCC;
stack<int> s;
int groupID[MAX];
bool inDegree[MAX];
vector<int> result;

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
    fill(inDegree, inDegree + MAX, false);
    result.clear();

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
      graph[i].clear();

    for (int i = 0; i < M; i++)
    {
      int A, B;
      cin >> A >> B;
      graph[A + 1].push_back(B + 1);
    }

    for (int i = 1; i <= N; i++)
      if (id[i] == 0)
        dfs(i);

    for (int i = 1; i <= N; i++)
      for (auto node : graph[i])
        if (groupID[i] != groupID[node])
          inDegree[groupID[node]] = true;

    int cnt = 0;

    for (int i = 0; i < SCC.size(); i++)
      if (!inDegree[i + 1])
      {
        cnt++;
        for (auto node : SCC[i])
          result.push_back(node - 1);
      }

    sort(result.begin(), result.end());

    if (cnt != 1)
      cout << "Confused\n";
    else
      for (auto node : result)
        cout << node << "\n";
    cout << "\n";
  }

  return 0;
}