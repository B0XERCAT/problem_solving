#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, M;
vector<vector<int>> tree;
vector<int> depth;
int kmax; // 최대 가능 높이
int parent[21][100001];
vector<bool> visited;

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    visited[x] = true;
    int level = 1;
    int now_size = 1; // 현재 depth(level) 크기
    int count = 0;    // 현재 depth에서 내가 몇개 노드 처리했는지

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int next : tree[cur])
        {
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
                parent[0][next] = cur; // 부모노드 저장
                depth[next] = level;   // 노드 깊이 저장
            }
        }
        count++;
        if (count == now_size)
        {
            count = 0;
            now_size = q.size();
            level++;
        }
    }
}

int LCA(int a, int b)
{
    // 무조건 b가 더 깊게 swap
    if (depth[a] > depth[b])
    {
        int temp = a;
        a = b;
        b = temp;
    }
    // b 올려서 depth 맞추기
    for (int k = kmax; k >= 0; k--)
        if (pow(2, k) <= depth[b] - depth[a])
            b = parent[k][b];
        
    // 동시에 올라가면서 조상 찾기
    for (int k = kmax; k >= 0; k--)
        if (parent[k][a] != parent[k][b])
        {
            a = parent[k][a];
            b = parent[k][b];
        }
    
    if (a != b)
        return parent[0][a];
    else
        return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    tree.resize(N + 1);
    depth.resize(N + 1);
    visited.resize(N + 1);

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int temp = 1;
    kmax = 0;
    while (temp <= N)
    {
        temp <<= 1;
        kmax++;
    }

    bfs(1);

    for (int k = 1; k <= kmax; k++)
        for (int n = 1; n <= N; n++)
            parent[k][n] = parent[k - 1][parent[k - 1][n]];

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }

    return 0;
}
