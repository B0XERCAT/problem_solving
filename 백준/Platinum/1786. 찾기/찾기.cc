#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cnt = 0;
vector<int> result;

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

void KMP(string parent, string pattern)
{
    vector<int> table = makeTable(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int j = 0;
    for (int i = 0; i < parentSize; i++)
    {
        while (j > 0 && parent[i] != pattern[j])
            j = table[j - 1];
        if (parent[i] == pattern[j])
        {
            if (j == patternSize - 1)
            {
                result.push_back(i - patternSize + 2);
                cnt++;
                j = table[j];
            }
            else
                j++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string parent, pattern;

    getline(cin, parent);
    getline(cin, pattern);

    KMP(parent, pattern);

    cout << cnt << "\n";

    for (auto item : result)
        cout << item << " ";

    return 0;
}
