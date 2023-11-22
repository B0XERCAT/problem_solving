#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string line;
    cin >> N >> line;
    for(int i = N - 5; i < N; i++)
        cout << line[i];

    return 0;
}