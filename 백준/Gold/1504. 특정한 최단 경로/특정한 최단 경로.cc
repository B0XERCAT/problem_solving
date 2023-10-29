#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define INF 9876543219
#define MAX 200010
#define pll pair<ll, ll>
using namespace std;

vector<pll> graph[MAX];
vector<ll> dist(MAX);
vector<bool> visited(MAX);
ll V, E, result1 = 0, result2 = 0, v1, v2;

void dijkstra(ll start)
{
  for (ll i = 1; i <= V; i++)
  {
    dist[i] = INF;
    visited[i] = false;
  }
  dist[start] = 0;
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  pq.push({0, start});

  while (!pq.empty())
  {
    ll cur = pq.top().second;
    ll distance = pq.top().first;
    pq.pop();

    if (visited[cur])
      continue;

    visited[cur] = true;

    for (auto pair : graph[cur])
    {
      ll next = pair.first;
      ll nextDistance = distance + pair.second;
      if (nextDistance < dist[next])
      {
        dist[next] = nextDistance;
        pq.push({nextDistance, next});
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> V >> E;

  for (ll i = 0; i < E; i++)
  {
    ll u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }

  // result1 : 1 => v1 => v2 => V
  // result2 : 1 => v2 => v1 => V
  dijkstra(1);
  cin >> v1 >> v2;
  result1 += dist[v1];
  result2 += dist[v2];
  dijkstra(v1);
  result1 += dist[v2];
  result2 += dist[V];
  dijkstra(v2);
  result1 += dist[V];
  result2 += dist[v1];

  ll answer = min(result1, result2);
  if (answer >= INF)
    cout << -1;
  else
    cout << answer;

  return 0;
}