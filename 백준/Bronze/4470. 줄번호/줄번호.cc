#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    cin.ignore();
    for (int i = 1; i <= N; i++)
    {
        string line;
        getline(cin, line);
        cout << i << ". " << line << "\n";
    }
    return 0;
}