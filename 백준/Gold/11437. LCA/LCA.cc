#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> tree;
vector<int> depth;
vector<int> parent;
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
                parent[next] = cur;  // 부모노드 저장
                depth[next] = level; // 노드 깊이 저장
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

int LCA(int a, int b){
    if(depth[a] < depth[b]){
        int temp = a;
        a = b;
        b = temp;
    }
    // depth 맞추기
    while(depth[a]!=depth[b]){
        a = parent[a];
    }
    // 같은 조상이 나올 때까지 두 노드 같이 한칸 올라감
    while(a!=b){
        a = parent[a];
        b = parent[b];
    }
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
    parent.resize(N + 1);
    visited.resize(N + 1);

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    bfs(1);

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }

    return 0;
}
