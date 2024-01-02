#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string line;
    cin >> line;
    int cnt = 0;
    for(int i = 0; i < line.size(); i++)
    {
        if(line[i] == ':')
            cnt++;
        else if(line[i] == '_')
            cnt += 5;
    }
    cout << cnt + line.size() << '\n';
}