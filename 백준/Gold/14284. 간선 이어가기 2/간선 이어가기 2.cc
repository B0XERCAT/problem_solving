#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX 5001
#define pii pair<int, int>
using namespace std;

vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX);
vector<bool> visited(MAX);
int V, E, s, t;

void dijkstra(int start)
{
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        if (visited[cur])
            continue;

        visited[cur] = true;
        
        for (auto pair : graph[cur])
        {
            int next = pair.first;
            int nextDistance = distance + pair.second;
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

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    for (int i = 1; i <= V; i++)
        dist[i] = INF;

    cin >> s >> t;
    dijkstra(s);

    cout << dist[t];

    return 0;
}