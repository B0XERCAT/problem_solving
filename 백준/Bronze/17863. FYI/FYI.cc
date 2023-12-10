#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    if (s.substr(0, 3) == "555")
        cout << "YES";
    else
        cout << "NO";

    return 0;
}