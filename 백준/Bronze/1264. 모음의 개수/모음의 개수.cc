#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1)
    {
        int vowelCnt = 0;
        string line;
        getline(cin, line);
        if (line == "#")
            break;
        for (int i = 0; i < line.length(); i++)
            if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u' || line[i] == 'A' || line[i] == 'E' || line[i] == 'I' || line[i] == 'O' || line[i] == 'U')
                vowelCnt++;
        cout << vowelCnt << '\n';
    }

    return 0;
}