#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    while (N--)
    {
        string name;
        cin >> name;
        for (int i = 0; i < name.length(); i++)
        {
            if (name[i] >= 'A' && name[i] <= 'Z')
                name[i] += 32;
        }
        cout << name << "\n";
    }

    return 0;
}