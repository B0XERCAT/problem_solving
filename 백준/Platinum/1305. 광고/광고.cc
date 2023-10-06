#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> makeTable(string pattern)
{
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0);
    int j = 0;
    for (int i = 1; i < patternSize; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
            j = table[j - 1];
        if (pattern[i] == pattern[j])
            table[i] = ++j;
    }
    return table;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string str;

    cin >> N >> str;

    vector<int> pi = makeTable(str);

    cout << N - pi[N - 1];

    return 0;
}
