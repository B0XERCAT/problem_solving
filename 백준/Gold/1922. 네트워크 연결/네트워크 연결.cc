#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;

vector<int> par(MAX, -1);

int root(int x) {
  if (par[x] == -1)
    return x;
  else
    return par[x] = root(par[x]);
}

bool issame(int x, int y) { return root(x) == root(y); }

void unite(int x, int y) {
  x = root(x);
  y = root(y);
  par[y] = x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int V, E;
  cin >> V >> E;
	
  vector<pair<int, pair<int, int>>> edges(E);
	
  for (int i = 0; i < E; i++) {
    int A, B, C;
    cin >> A >> B >> C;
    edges[i] = {C, {A, B}};
  }
	
  sort(edges.begin(), edges.end());

  int res = 0;
  for (int i = 0; i < E; i++) {
    int w = edges[i].first;
    int u = edges[i].second.first;
    int v = edges[i].second.second;
    if (issame(u, v))
      continue;
    res += w;
    unite(u, v);
  }
	
  cout << res;
  return 0;
}