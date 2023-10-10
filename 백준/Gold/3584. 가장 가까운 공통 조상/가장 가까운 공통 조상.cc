#include <iostream>
#define MAX 10001
using namespace std;

int parent[MAX];
bool visited[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;

        for (int i = 1; i <= N; i++)
        {
            parent[i] = i;
            visited[i] = false;
        }

        for (int i = 0; i < N - 1; i++)
        {
            int A, B;
            cin >> A >> B;
            parent[B] = A;
        }

        int a, b;
        cin >> a >> b;

        visited[a] = true;

        // a부터 root node 까지 올라가면서 전부 방문
        while (parent[a] != a)
        {
            a = parent[a];
            visited[a] = true;
        }
        // 방문한 노드: a의 부모
        // b == parent[b]: root node
        while (1)
        {
            if (visited[b] || b == parent[b])
                break;
            b = parent[b];
        }
        cout << b << "\n";
    }

    return 0;
}
