#include <iostream>
#include <vector>
#include <string>
#define MAX 200001
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sum[26][MAX];
    string S;
    int q, l, r;
    char a;

    cin >> S >> q;

    for (int i = 0; i < S.length(); i++)
    {
        if(i == 0){
            sum[S[i] - 'a'][i]++;
            continue;
        }
        for (int j = 0; j < 26; j++)
            sum[j][i] = sum[j][i - 1];
        sum[S[i] - 'a'][i]++;
    }

    while (q--)
    {
        cin >> a >> l >> r;
        if (l == 0)
            cout << sum[a - 'a'][r] << "\n";
        else
            cout << sum[a - 'a'][r] - sum[a - 'a'][l - 1] << "\n";
    }

    return 0;
}