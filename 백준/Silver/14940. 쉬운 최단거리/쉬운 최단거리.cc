#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int N, M, x, y, nx, ny;
int dist[MAX][MAX];
bool visited[MAX][MAX];

queue<pair<int, int>> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> dist[i][j];
            if (dist[i][j] == 2)
            {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        visited[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (dist[nx][ny] == 1 && !visited[nx][ny])
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!visited[i][j] && dist[i][j] != 0)
            {
                cout << -1 << " ";
                continue;
            }
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
