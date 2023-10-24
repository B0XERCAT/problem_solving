#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct compare {
  bool operator()(int a, int b) {
    if (abs(a) == abs(b))
      return a > b;
    else
      return abs(a) > abs(b);
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  priority_queue<int, vector<int>, compare> pq;

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int cmd;
    cin >> cmd;
    if (cmd == 0) {
      if (pq.empty())
        cout << "0\n";
      else {
        cout << pq.top() << '\n';
        pq.pop();
      }
    } else
      pq.push(cmd);
  }

  return 0;
}
